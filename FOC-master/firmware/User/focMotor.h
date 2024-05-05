#ifndef __BLDCMOTOR_H
#define __BLDCMOTOR_H
#include "userMain.h"

#define FOC_PERIOD 100.0f // foc algorithm compute period in microsecond
#define PWM_PERIOD 16000.0f



void motorInit();
void getElecAngle(FocMotor *motor);
void foc(FocMotor *motor, uint32_t adc_a, uint32_t adc_b);
extern FocMotor motor1;
void getZeroElecAngle(FocMotor *motor);
void setPhaseVoltage1(FocMotor *motor, float Uq, float Ud, float angle_el);
#endif