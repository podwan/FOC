#ifndef __BLDCMOTOR_H
#define __BLDCMOTOR_H
#include "userMain.h"

#define FOC_PERIOD 100.0f // foc algorithm compute period in microsecond
#define PWM_PERIOD 16000.0f



void motorInit();
void getElecAngle(BldcMotor *motor);
void foc(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b);
extern BldcMotor motor1;
void getZeroElecAngle(BldcMotor *motor);
void setPhaseVoltage1(BldcMotor *motor, float Uq, float Ud, float angle_el);
#endif