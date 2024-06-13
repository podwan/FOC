#include "hall.h"

float HallTemp = 0;
float HallThetaAdd = 0;
float HallTheta = 0;
float HallSpeed = 0;
uint8_t HallReadTemp = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(htim);
    if (htim == &htim4)
    {
        HallTemp = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
        ;
        HallThetaAdd = (_PI / 3) / (HallTemp / 1000000) / 10000;
        HallSpeed = (_PI / 3) / (HallTemp / 1000000) * 30 / _PI;
        HallReadTemp = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
        HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) << 1;
        HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) << 2;
        if (HallReadTemp == 0x05)
        {
            HallTheta = 0.0f + PHASE_SHIFT_ANGLE;
        }
        else if (HallReadTemp == 0x04)
        {
            HallTheta = (_PI / 3.0f) + PHASE_SHIFT_ANGLE;
        }
        else if (HallReadTemp == 0x06)
        {
            HallTheta = (_PI * 2.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        }
        else if (HallReadTemp == 0x02)
        {
            HallTheta = _PI + PHASE_SHIFT_ANGLE;
        }
        else if (HallReadTemp == 0x03)
        {
            HallTheta = (_PI * 4.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        }
        else if (HallReadTemp == 0x01)
        {
            HallTheta = (_PI * 5.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        }
        if (HallTheta < 0.0f)
        {
            HallTheta += 2.0f * _PI;
        }
        else if (HallTheta > (2.0f * _PI))
        {
            HallTheta -= 2.0f * _PI;
        }
    }

    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_TIM_IC_CaptureCallback could be implemented in the user file
     */
}