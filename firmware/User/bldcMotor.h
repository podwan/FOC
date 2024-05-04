#ifndef __BLDCMOTOR_H
#define __BLDCMOTOR_H
#include "userMain.h"

#define FOC_PERIOD 100.0f // foc algorithm compute period in microsecond
#define PWM_PERIOD 16000.0f



void motorInit();
void foc(FocParameters *fp, uint32_t adc_a, uint32_t adc_b);
extern FocParameters fp1;
void getZeroElecAngle(FocParameters *fp);
void setPhaseVoltage1(FocParameters *fp, float Uq, float Ud, float angle_el);
#endif