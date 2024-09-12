#include "userTimer.h"
static bool _1s, _1ms;

static bool _5msFlag, _10msFlag, _20msFlag, _30msFlag, _100msFlag, _500msFlag, _1s;
static void dealPerMs();
void dealPer100us()
{
    static unsigned char cnt;
    if (++cnt >= 10)
    {
        cnt = 0;
        dealPerMs();
    }
}

static void dealPerMs()
{
    static unsigned char _5msCnt, _30msCnt, _20msCnt, _100msCnt, _10msCnt;
    static uint _500msCnt, _1000msCnt;
    if (++_5msCnt >= 5)
    {
        _5msCnt = 0;
        _5msFlag = 1;
    }

    if (++_10msCnt >= 10)
    {
        _10msCnt = 0;
        _10msFlag = 1;
    }

    if (++_20msCnt >= 20)
    {
        _20msCnt = 0;
        _20msFlag = 1;
    }

    if (++_30msCnt >= 30)
    {
        _30msCnt = 0;
        _30msFlag = 1;
    }

    if (++_100msCnt >= 100)
    {
        _100msCnt = 0;
        _100msFlag = 1;
    }

    if (++_500msCnt >= 500)
    {
        _500msCnt = 0;
        _500msFlag = 1;
    }
    if (++_1000msCnt >= 1000)
    {
        _1000msCnt = 0;
        _1s = 1;
    }
}



bool getOneSecFlag()
{
    if (_1s)
    {
        _1s = 0;
        return 1;
    }
    else
        return 0;
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


bool get5MsFlag()
{
    if (_5msFlag)
    {
        _5msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool get10MsFlag()
{
    if (_10msFlag)
    {
        _10msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool get20MsFlag()
{
    if (_20msFlag)
    {
        _20msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool get30MsFlag()
{
    if (_30msFlag)
    {
        _30msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool get100MsFlag()
{
    if (_100msFlag)
    {
        _100msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool get500MsFlag()
{
    if (_500msFlag)
    {
        _500msFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}
