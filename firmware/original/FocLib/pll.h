#ifndef __PLL_H
#define __PLL_H
#include "pid.h"
#include "encoder.h"
// #define R 9.5  // Ω
// #define L 2.03 // mH

typedef struct
{
    float Ealpha;
    float Ebeta;
    float lastIalpha;
    float lastIbeta;
    float theta;
    float Ed;
    float error;
    float Ts;
    PidController pid;
    float factor;
} PLL;

#endif