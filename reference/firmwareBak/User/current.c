
#include "current.h"
#include "foc_utils.h"
// Function finding zero offsets of the ADC
void getCurrentOffsets(FocParameters *fp, uint32_t adc_a, uint32_t adc_b, uint32_t rounds)
{
    // find adc offset = zero current voltage
    fp->offset_ia = 0;
    fp->offset_ib = 0;
    // read the adc voltage  times ( arbitrary number )
    for (int i = 0; i < rounds; i++)
    {
        fp->offset_ia += adc_a;
        fp->offset_ib += adc_b;
    }
    // calculate the mean offsets
    fp->offset_ia = fp->offset_ia / rounds;
    fp->offset_ib = fp->offset_ib / rounds;
}
// read all three phase currents (if possible 2 or 3)
void getPhaseCurrents(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
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