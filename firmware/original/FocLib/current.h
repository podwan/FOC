#ifndef __CURRENT_H
#define __CURRENT_H
#include "bldcMotor.h"

void getCurrentOffsets(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b, uint32_t rounds);
void getPhaseCurrents(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b);
void getABCurrents(BldcMotor *motor);
void getDQCurrents(BldcMotor *motor);
#endif