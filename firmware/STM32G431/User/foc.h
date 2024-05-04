#ifndef __FOC_H
#define __FOC_H

#include "userMain.h"
#include "math_utils.h"
#include "comm.h"



typedef struct
{
    float a;
    float b;
    float c;
} PhaseCurrent_t;

#define PWM_GENERATE(p1, p2, p3) \
    {                            \
        TIM1->CCR1 = p1;         \
        TIM1->CCR2 = p2;         \
        TIM1->CCR3 = p3;         \
    }

void openLoopFoc(float uQ, float theta);
#endif
