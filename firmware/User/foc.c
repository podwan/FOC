#include "foc.h"
#include "foc_utils.h"
// Function finding zero offsets of the ADC
void calibrateOffsets(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
{
    const int calibration_rounds = 100;
    // find adc offset = zero current voltage
    fp->offset_ia = 0;
    fp->offset_ib = 0;
    // read the adc voltage 1000 times ( arbitrary number )
    for (int i = 0; i < calibration_rounds; i++)
    {
        fp->offset_ia += adc_a;
        fp->offset_ib += adc_b;
    }
    // calculate the mean offsets
    fp->offset_ia = fp->offset_ia / calibration_rounds;
    fp->offset_ib = fp->offset_ib / calibration_rounds;
}

// read all three phase currents (if possible 2 or 3)
static void getPhaseCurrents(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
{
    fp->Ia = (adc_a - fp->offset_ia) * VLOTS_AMPS_RATIO; // amps
    fp->Ib = (adc_b - fp->offset_ib) * VLOTS_AMPS_RATIO; // amps
}

/*============================================================================*/
// Clarke变换，计算公式
// Ialpha = Ia
// Ibeta = (Ia + 2Ib)/sqrt(3)
// Ibeta = 1/sqrt(3) * Ia + 1/sqrt(3) * 2Ib
/*============================================================================*/
//   calculating Alpha Beta currents from phase currents
//   - function calculating Clarke transform of the phase currents
static void getABCurrents(FocParameters *fp)
{
    fp->Ialpha = fp->Ia;
    fp->Ibeta = _1_SQRT3 * fp->Ia + _2_SQRT3 * fp->Ib;
}
/*============================================================================*/
// Park变换
// Id = Ialpha * Cosθr + Ibeta * Sinθr
// Iq =Ibeta * Cosθr -Ialpha * Sinθr
/*============================================================================*/
// function used with the foc algorihtm
//   calculating D and Q currents from Alpha Beta currents and electrical angle
//   - function calculating Clarke transform of the phase currents
static void getDQCurrents(FocParameters *fp)
{
    float ct;
    float st;
    _sincos(fp->angle_el, &st, &ct);
    fp->Id = fp->Ialpha * ct + fp->Ibeta * st;
    fp->Iq = fp->Ibeta * ct - fp->Ialpha * st;
}

void getDQVoltages(FocParameters *fp)
{

    fp->Id = lpfOperator(&fp->lpf, fp->Id);
    fp->Iq = lpfOperator(&fp->lpf, fp->Iq);

    fp->Ud = pidOperator(&fp->pid_id, fp->IdGoal - fp->Id);
    fp->Uq = pidOperator(&fp->pid_iq, fp->IqGoal - fp->Iq);
}
/*============================================================================*/
// Park逆变换
// Ualpha = Ud * Cosθr + Uq * Sinθr
// Ubeta = Uq * Cosθr + Ud * Sinθr
/*============================================================================*/
void getABVoltages(FocParameters *fp)
{
    fp->Ualpha = fp->Ud * _cos(fp->angle_el) - fp->Uq * _sin(fp->angle_el);
    fp->Ubeta = fp->Uq * _cos(fp->angle_el) + fp->Ud * _sin(fp->angle_el);
}

const char sectorRemap[] = {0, 2, 6, 1, 4, 3, 5};

// 输入Uq、Ud和电角度，输出三路PWM
static void SVPWM(FocParameters *fp)
{
    float tFirst, tSecond;
    int d1, d2, d3;

    float K = _SQRT3 * PWM_PERIOD_VALUE / U_DC;
    float X = fp->Ubeta * K;
    float Y = (_SQRT3 * fp->Ualpha / 2.0f + fp->Ubeta / 2.0f) * K;
    float Z = (-_SQRT3 * fp->Ualpha / 2.0f + fp->Ubeta / 2.0f) * K;

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

    switch (sector)
    {
    case 1:
        tFirst = -Z;
        tSecond = X;

        d1 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d2 = d1 + tFirst;
        d3 = d2 + tSecond;
        break;
    case 2:
        tFirst = Z;
        tSecond = Y;

        d2 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d1 = d2 + tFirst;
        d3 = d1 + tSecond;
        break;
    case 3:
        tFirst = X;
        tSecond = -Y;

        d2 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d3 = d2 + tFirst;
        d1 = d3 + tSecond;

        break;
    case 4:
        tFirst = -X;
        tSecond = Z;

        d3 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d2 = d3 + tFirst;
        d1 = d2 + tSecond;
        break;

    case 5:
        tFirst = -Y;
        tSecond = -Z;

        d3 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d1 = d3 + tFirst;
        d2 = d1 + tSecond;
        break;

    case 6:
        tFirst = Y;
        tSecond = -X;

        d1 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d3 = d1 + tFirst;
        d2 = d3 + tSecond;
        break;
    }
    load_data[0] = d1;
    load_data[1] = d2;
    load_data[2] = d3;
    load_data[3] = 0;
    load_data[4] = 0;
    fp->setPwm(d1, d2, d3); // 输出三路PWM，驱动无刷电机转动
}

void currentLoop(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
{
    float ct;
    float st;
    _sincos(fp->angle_el, &st, &ct);
    //  getPhaseCurrents
    fp->Ia = (adc_a - fp->offset_ia) * VLOTS_AMPS_RATIO;
    fp->Ib = (adc_b - fp->offset_ib) * VLOTS_AMPS_RATIO;
    //  clarke
    fp->Ialpha = fp->Ia;
    fp->Ibeta = _1_SQRT3 * fp->Ia + _2_SQRT3 * fp->Ib;
    // park
    fp->Id = fp->Ialpha * ct + fp->Ibeta * st;
    fp->Iq = fp->Ibeta * ct - fp->Ialpha * st;
    // PID
    fp->Id = lpfOperator(&fp->lpf, fp->Id);
    fp->Iq = lpfOperator(&fp->lpf, fp->Iq);
    fp->Ud = pidOperator(&fp->pid_id, fp->IdGoal - fp->Id);
    fp->Uq = pidOperator(&fp->pid_iq, fp->IqGoal - fp->Iq);
    // revPark
    fp->Ualpha = fp->Ud * ct - fp->Uq * st;
    fp->Ubeta = fp->Uq * ct + fp->Ud * st;
    // SVPWM
    SVPWM(fp);
}