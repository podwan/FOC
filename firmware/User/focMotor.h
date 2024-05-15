#ifndef __BLDCMOTOR_H
#define __BLDCMOTOR_H
#include "userMain.h"
#include "math_utils.h"
#define CARRIER_FREQUENCY 10000                          // PWM载波频率
#define PWM_PERIOD_VALUE (160000000 / CARRIER_FREQUENCY) // 16000
#define DEAD_TIME (160000000 / CARRIER_FREQUENCY / 25)   // DT/1.6 = 6400 / 40	DT = 256
#define HALP_PWM_PERIOD (PWM_PERIOD_VALUE / 2.0f)        // PWM period * 2
#define U_DC 12.0f
#define UqMAX (U_DC * _1_SQRT3)
#define OPEN_LOOP_TORQUE UqMAX / 2.0f

#define MOTOR1_MAX_RPM 3000.0f
#define GET_MAX_VELOCITY(MAX_RPM) MAX_RPM / 60.0f * _2PI

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

void getElecAngle(FocMotor *motor);
void foc(FocMotor *motor, uint32_t adc_a, uint32_t adc_b);
// void getZeroElecAngle(FocMotor *motor);
void setPhaseVoltage1(FocMotor *motor, float Uq, float Ud, float angle_el);
void goToZeroElecAngle(FocMotor *motor);
#endif