

#ifndef __VOLTAGE_H
#define __VOLTAGE_H

#include "userMain.h"

#define CARRIER_FREQUENCY 10000                          // PWM载波频率
#define PWM_PERIOD_VALUE (160000000 / CARRIER_FREQUENCY) // 6400
#define DEAD_TIME (160000000 / CARRIER_FREQUENCY / 25)   // DT/1.6 = 6400 / 40	DT = 256
#define HALP_PWM_PERIOD (PWM_PERIOD_VALUE / 2.0f)        // PWM period * 2
#define U_DC 12.0f
#define UqMAX (U_DC * _1_SQRT3)

#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

void getDQVoltages(FocParameters *fp);
void getABVoltages(FocParameters *fp);
void setPhaseVoltage(FocParameters *fp, float Uq, float Ud, float angle_el);
void setPhaseVoltage1(float Uq, float Ud, float angle_el);
extern const char sectorRemap[];
#endif