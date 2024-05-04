#ifndef CTRL_FOC_LITE_FW_DRIVER_M0_H
#define CTRL_FOC_LITE_FW_DRIVER_M0_H

#include "driver/driver_base.h"
#include "userMain.h"

class Driver : public DriverBase
{
public:
    // Configured in STM32CubeMX
    static const int PERIOD_COUNT = 8000;

    explicit Driver(float _voltagePowerSupply) : DriverBase(_voltagePowerSupply)
    {
    }

private:
    /***** Platform Specified Implements *****/
    bool ConfigTimerForPwm();
    void SetPwmDutyByRegister(float _dutyA, float _dutyB, float _dutyC);
};

#endif
