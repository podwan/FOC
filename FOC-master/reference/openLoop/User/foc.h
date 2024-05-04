#ifndef __FOC_H
#define __FOC_H

#include "main.h"

#define PWM_PERIOD 8000.0f // PWM period * 2
#define U_DC 24.0f
// #define FACTOR _SQRT3 * PWM_PERIOD / U_DC

#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

// void revParkOperate(float uD, float uQ, float theta, float *uAlpha, float *uBeta);
// char getSector(float uAlpha, float uBeta);
// void SVPWM(char sector, float uAlpha, float uBeta);
void FOC(float uD, float uQ, float theta);
#endif
		

		