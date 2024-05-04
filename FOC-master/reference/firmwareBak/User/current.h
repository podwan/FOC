#ifndef __CURRENT_H
#define __CURRENT_H
#include "userMain.h"

#define SHUNT_RESISTOR 0.1f // 100mR
#define GAIN 100.0f         // opAmp
#define VLOTS_AMPS_RATIO 1.0f / SHUNT_RESISTOR / GAIN

void getCurrentOffsets(FocParameters *fp, uint32_t adc_a, uint32_t adc_b, uint32_t rounds);
void getPhaseCurrents(FocParameters *fp, uint32_t adc_a, uint32_t adc_b);
#endif