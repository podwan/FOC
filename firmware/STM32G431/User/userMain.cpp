#include "userMain.h"
#include "userTimer.h"
#include "comm.h"
#include "app.h"


void userMain()
{
    if (getOneMsFlag())
    {
        static uint _500msCnt;
        static uchar _100msCnt, _20msCnt;

        if (++_500msCnt >= 500)
        {
            _500msCnt = 0;
            printLog();
        }

        if (++_100msCnt >= 100)
        {
            _100msCnt = 0;
            appRunning();
        }

        // if (++_20msCnt >= 20)
        // {
        //     _20msCnt = 0;
        //     keyScan();
        // }
    }
}
