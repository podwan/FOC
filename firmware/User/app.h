#ifndef __APP_H
#define __APP_H

#include "userMain.h"

#define CURRENT_MAX 1.0f
#define MAX_VELOCITY 300

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
        motor1.state = MOTOR_START;                  \
    }

#define STANDBY_INIT        \
    {                       \
        devState = STANDBY; \
        flashCnt = 0;       \
    }
#ifdef __cplusplus // 使用C语言的方式编译方法名。
extern "C"
{
#endif

    void appInit();
#ifdef __cplusplus
}
#endif

void appRunning();
// void txDataProcess();
extern float txA, txB, txC;
// extern float focTarget;
#endif
