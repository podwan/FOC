#ifndef __FOC_LIB_H
#define __FOC_LIB_H

#include "userMain.h"
/////////////////////motor parameter//////////////////////
#define MOTOR1_MAX_RPM 3000.0f
#define GET_MAX_VELOCITY(MAX_RPM) MAX_RPM / 60.0f * _2PI

////////////////////driver parameter//////////////////
#define CARRIER_FREQUENCY 10000                          // PWM载波频率
#define PWM_PERIOD_VALUE (160000000 / CARRIER_FREQUENCY) // 16000
#define HALP_PWM_PERIOD (PWM_PERIOD_VALUE / 2.0f)        // PWM period * 2
#define U_DC 12.0f
#define UqMAX (U_DC * _1_SQRT3)
#define OPEN_LOOP_TORQUE UqMAX / 2.0
#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

void FOC_log(const char *format, ...);
void delay(uint32_t ms);

////////////above is user port code/////////////////////

#include <math.h>
#include "bldcMotor.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "encoder.h"

#endif