#ifndef __USER_TIMER_H
#define __USER_TIMER_H

#include "userMain.h"

/*---------------------------------------------------------------------------*/
#define PWM_NUM_1MS (160000.0f / PWM_PERIOD)
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus // 使用C语言的方式编译方法名。
extern "C"
{
#endif
    void dealPer100us();
#ifdef __cplusplus
}
#endif

bool getOneMsFlag();

#endif /* XC_HEADER_TEMPLATE_H */
