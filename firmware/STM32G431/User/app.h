#ifndef __APP_H
#define __APP_H

#include "userMain.h"

typedef enum
{
    STANDBY,
    WORK,
    CLEAN,
    TEST,
    FAULT,
    VERSION
} DevState;

#define WORK_INIT                                    \
    {                                                \
        devState = WORK;                             \
        flashCnt = 0;                                \
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);    \
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);    \
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);    \
        HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1); \
        HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2); \
        HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3); \
    }

#define STANDBY_INIT        \
    {                       \
        devState = STANDBY; \
        flashCnt = 0;       \
    }

void appRunning();
extern float txA, txB, txC;

#endif
