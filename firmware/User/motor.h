#ifndef __MOTOR_H
#define __MOTOR_H
#include "userMain.h"

#define FOC_PERIOD 100.0f // foc algorithm compute period in microsecond
#define PWM_PERIOD 16000.0f
#define HALP_PWM_PERIOD (PWM_PERIOD / 2.0f) // PWM period * 2
#define Q_MAX (U_DC * _1_SQRT3)
#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

void motorInit();
void velocityOpenLoop(FocParameters *fp, float target_velocity, float Ts);
// void setPhaseVoltage1(float Uq, float Ud, float angle_el);
void openLoopFoc(float uQ, float theta);
extern FocParameters fp1;
#endif