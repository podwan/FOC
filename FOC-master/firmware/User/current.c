
#include "current.h"
#include "foc_utils.h"
// Function finding zero offsets of the ADC
void getCurrentOffsets(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b, uint32_t rounds)
{
    // find adc offset = zero current voltage
    motor->offset_ia = 0;
    motor->offset_ib = 0;
    // read the adc voltage  times ( arbitrary number )
    for (int i = 0; i < rounds; i++)
    {
        motor->offset_ia += adc_a;
        motor->offset_ib += adc_b;
    }
    // calculate the mean offsets
    motor->offset_ia = motor->offset_ia / rounds;
    motor->offset_ib = motor->offset_ib / rounds;
}
// read all three phase currents (if possible 2 or 3)
void getPhaseCurrents(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b)
{
    motor->Ia = (adc_a - motor->offset_ia) * ADC_VLOTS_RADIO * VLOTS_AMPS_RATIO; // amps
    motor->Ib = (adc_b - motor->offset_ib) * ADC_VLOTS_RADIO * VLOTS_AMPS_RATIO; // amps
}

/*============================================================================*/
// Clarke变换，计算公式
// Ialpha = Ia
// Ibeta = (Ia + 2Ib)/sqrt(3)
// Ibeta = 1/sqrt(3) * Ia + 1/sqrt(3) * 2Ib
/*============================================================================*/
//   calculating Alpha Beta currents from phase currents
//   - function calculating Clarke transform of the phase currents
void getABCurrents(BldcMotor *motor)
{
    motor->Ialpha = motor->Ia;
    motor->Ibeta = _1_SQRT3 * motor->Ia + _2_SQRT3 * motor->Ib;
}
/*============================================================================*/
// Park变换
// Id = Ialpha * Cosθr + Ibeta * Sinθr
// Iq =Ibeta * Cosθr -Ialpha * Sinθr
/*============================================================================*/
// function used with the foc algorihtm
//   calculating D and Q currents from Alpha Beta currents and electrical angle
//   - function calculating Clarke transform of the phase currents
void getDQCurrents(BldcMotor *motor)
{
    float ct;
    float st;
    _sincos(motor->angle_el, &st, &ct);
    motor->Id = motor->Ialpha * ct + motor->Ibeta * st;
    motor->Iq = motor->Ibeta * ct - motor->Ialpha * st;
}