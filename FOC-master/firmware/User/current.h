#ifndef __CURRENT_H
#define __CURRENT_H
#include "userMain.h"

#define SHUNT_RESISTOR 0.1f // 100mR
#define GAIN 100.0f         // opAmp
#define VLOTS_AMPS_RATIO 1.0f / SHUNT_RESISTOR / GAIN

#define ADC_MAX 4095.0
#define ADC_REF 3.3f
#define ADC_VLOTS_RADIO ADC_REF / ADC_MAX

void getCurrentOffsets(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b, uint32_t rounds);
void getPhaseCurrents(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b);
void getABCurrents(BldcMotor *motor);
void getDQCurrents(BldcMotor *motor);
#endif