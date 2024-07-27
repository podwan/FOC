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
#define U_DC 8.0f
#define UqMAX (U_DC * _1_SQRT3)
#define OPEN_LOOP_TORQUE UqMAX / 3.0
#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

#define SHUNT_RESISTOR 0.01f                          // 10mR
#define GAIN 10.0f                                    // opAmp
#define VLOTS_AMPS_RATIO 1.0f / SHUNT_RESISTOR / GAIN // 27.27

#define ADC_MAX 4095.0
#define ADC_REF 3.3f
#define ADC_VLOTS_RADIO ADC_REF / ADC_MAX // 0.0008

#define ADC_2_CURRENT(adc) adc *ADC_VLOTS_RADIO *VLOTS_AMPS_RATIO

#define IqMax 0.06f
#define VELOCITY_MAX 400

void printLog(const char *format, ...);
void delay(uint32_t ms);

////////////above is user port code/////////////////////

#include <math.h>
#include "bldcMotor.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "encoder.h"

#endif