#include "voltage.h"
#include "foc_utils.h"
#include "comm.h"


 const char sectorRemap[] = {0, 2, 6, 1, 4, 3, 5};
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

void setPhaseVoltage(FocParameters *fp, float Uq, float Ud, float angle_el)
{

    Uq = _constrain(Uq, -UqMAX, UqMAX);

    float ct;
    float st;
    _sincos(angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = -Uq * st + Ud * ct;
    float Ubeta = Uq * ct + Ud * st;

    uint32_t d1, d2, d3;
    float tFirst = 0, tSecond = 0;
    float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
    float X = K * Ubeta;
    float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

    switch (sector)
    {
    case 1:
        tFirst = Y;
        tSecond = X;
        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d1 + tFirst;
        d3 = d2 + tSecond;

        break;
    case 2:
        tFirst = -Y;
        tSecond = -Z;
        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d2 + tFirst;
        d3 = d1 + tSecond;

        break;
    case 3:
        tFirst = X;
        tSecond = Z;
        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d2 + tFirst;
        d1 = d3 + tSecond;

        break;
    case 4:
        tFirst = -X;
        tSecond = -Y;
        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d3 + tFirst;
        d1 = d2 + tSecond;

        break;

    case 5:
        tFirst = Z;
        tSecond = Y;
        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d3 + tFirst;
        d2 = d1 + tSecond;

        break;

    case 6:
        tFirst = -Z;
        tSecond = -X;
        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d1 + tFirst;
        d2 = d3 + tSecond;

        break;
    }
#if SHOW_WAVE
    fp->d1 = d1;
    fp->d2 = d2;
    fp->d3 = d3;
#endif

    fp->setPwm(d1, d2, d3);
}

// void currentLoop(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
// {
//     float ct;
//     float st;
//     _sincos(fp->angle_el, &st, &ct);
//     //  getPhaseCurrents
//     float Ia = (adc_a - fp->offset_ia) * VLOTS_AMPS_RATIO;
//     float Ib = (adc_b - fp->offset_ib) * VLOTS_AMPS_RATIO;
//     //  clarke
//     float Ialpha = Ia;
//     float Ibeta = _1_SQRT3 * Ia + _2_SQRT3 * Ib;
//     // park
//     float Id = Ialpha * ct + Ibeta * st;
//     float Iq = Ibeta * ct - Ialpha * st;
//     // low pass filter
//     Id = lpfOperator(&fp->lpf, Id);
//     Iq = lpfOperator(&fp->lpf, Iq);
//     // PID
//     float Ud = pidOperator(&fp->pid_id, fp->IdGoal - Id);
//     float Uq = pidOperator(&fp->pid_iq, fp->IqGoal - Iq);
//     // revPark + SVPWM
//     setPhaseVoltage(fp, Uq, Ud, fp->angle_el);
// }
#if 0
void setPhaseVoltage1(float Uq, float Ud, float angle_el)
{

    Uq = _constrain(Uq, -UqMAX, UqMAX);

    float ct;
    float st;
    _sincos(angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = -Uq * st + Ud * ct;
    float Ubeta = Uq * ct + Ud * st;

    uint32_t d1, d2, d3;
    float tFirst = 0, tSecond = 0;
    float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
    float X = K * Ubeta;
    float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

    switch (sector)
    {
    case 1:
        tFirst = Y;
        tSecond = X;
        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d1 + tFirst;
        d3 = d2 + tSecond;

        break;
    case 2:
        tFirst = -Y;
        tSecond = -Z;
        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d2 + tFirst;
        d3 = d1 + tSecond;

        break;
    case 3:
        tFirst = X;
        tSecond = Z;
        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d2 + tFirst;
        d1 = d3 + tSecond;

        break;
    case 4:
        tFirst = -X;
        tSecond = -Y;
        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d3 + tFirst;
        d1 = d2 + tSecond;

        break;

    case 5:
        tFirst = Z;
        tSecond = Y;
        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d3 + tFirst;
        d2 = d1 + tSecond;

        break;

    case 6:
        tFirst = -Z;
        tSecond = -X;
        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d1 + tFirst;
        d2 = d3 + tSecond;

        break;
    }
    // #if SEND_RCC_DATA
    load_data[0] = d1;
    load_data[1] = d2;
    load_data[2] = d3;
    //    load_data[3] = Uq;
    // #endif
    PWM_GENERATE(d1, d2, d3);
}
#else

// void setPhaseVoltage1(float Uq, float Ud, float angle_el)
// {

//     Uq = _constrain(Uq, -UqMAX, UqMAX);

//     float ct;
//     float st;
//     _sincos(angle_el, &st, &ct);
//     // Park逆变换
//     float Ualpha = -Uq * st + Ud * ct;
//     float Ubeta = Uq * ct + Ud * st;

//     uint32_t d1, d2, d3;
//     float tFirst = 0, tSecond = 0;
//     float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
//     float X = K * Ubeta;
//     float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
//     float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);

//     uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

//     switch (sector)
//     {
//     case 1:
//         tFirst = Y;
//         tSecond = X;
//         d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d2 = d1 + tFirst;
//         d3 = d2 + tSecond;

//         break;
//     case 2:
//         tFirst = -Y;
//         tSecond = -Z;
//         d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d1 = d2 + tFirst;
//         d3 = d1 + tSecond;

//         break;
//     case 3:
//         tFirst = X;
//         tSecond = Z;
//         d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d3 = d2 + tFirst;
//         d1 = d3 + tSecond;

//         break;
//     case 4:
//         tFirst = -X;
//         tSecond = -Y;
//         d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d2 = d3 + tFirst;
//         d1 = d2 + tSecond;

//         break;

//     case 5:
//         tFirst = Z;
//         tSecond = Y;
//         d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d1 = d3 + tFirst;
//         d2 = d1 + tSecond;

//         break;

//     case 6:
//         tFirst = -Z;
//         tSecond = -X;
//         d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
//         d3 = d1 + tFirst;
//         d2 = d3 + tSecond;

//         break;
//     }

//     load_data[0] = d1;
//     load_data[1] = d2;
//     load_data[2] = d3;
// //    load_data[3] = Uq;

//     PWM_GENERATE(d1, d2, d3);
// }
#endif
