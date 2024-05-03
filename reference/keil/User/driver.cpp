#include "driver.h"

inline float Constraint(float _val)
{
    if (_val > 1)
        _val = 1;
    else if (_val < 0)
        _val = 0;

    return _val;
}

bool Driver::ConfigTimerForPwm()
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);

    SetPwmDutyByRegister(0, 0, 0);

    return true;
}

void Driver::SetPwmDutyByRegister(float _dutyA, float _dutyB, float _dutyC)
{
    _dutyA = Constraint(_dutyA);
    _dutyB = Constraint(_dutyB);
    _dutyC = Constraint(_dutyC);

    TIM1->CCR1 = _dutyA;
    TIM1->CCR2 = _dutyB;
    TIM1->CCR3 = _dutyC;
}
