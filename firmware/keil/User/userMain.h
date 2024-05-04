#ifndef __USERMAIN_H
#define __USERMAIN_H

#include "stm32g4xx_hal.h"
#include "tim.h"
#include "usart.h"
#include "spi.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define FOC_PERIOD 100.0f // foc algorithm compute period in microsecond
#define PWM_PERIOD 16000.0f
#define HALP_PWM_PERIOD (PWM_PERIOD / 2.0f) // PWM period * 2
#define U_DC 12.0f
#define Q_MAX (U_DC * _1_SQRT3)
// #define FACTOR _SQRT3 * PWM_PERIOD / U_DC

typedef unsigned int uint;
typedef unsigned char uchar;


typedef union
{
    unsigned char byte;
    struct
    {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    } bits;
} Byte;

typedef enum
{
    NONE_KEY,
    USER1_SHORT,
    USER2_SHORT,
    USER3_SHORT,
} KeyState;

#ifdef __cplusplus // 使用C语言的方式编译方法名。
extern "C"
{
#endif

    void userMain();
#ifdef __cplusplus
}
#endif
#endif
