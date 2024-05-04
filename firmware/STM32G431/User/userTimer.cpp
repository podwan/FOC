/*
 * File:   timer.c
 * Author: reborn
 *
 * Created on March 9, 2024, 3:39 PM
 */

#include "userTimer.h"
#include "motor.h"
static bool _1ms;

void dealPer100us()
{
    static uchar cnt;

    if (++cnt >= PWM_NUM_1MS)
    {
     
        cnt = 0;
        _1ms = 1;
    }
}

bool getOneMsFlag()
{

    if (_1ms)
    {
        _1ms = 0;
        return 1;
    }
    else
        return 0;
}
