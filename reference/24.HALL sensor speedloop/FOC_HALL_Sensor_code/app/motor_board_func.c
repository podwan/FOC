/**
  ******************************************************************************
  * @file    motor_board_func.c
  * @author  Motor Control Team, Euler[https://space.bilibili.com/458115745?spm_id_from=333.337.0.0]
  * @brief   Motor Control can communicarion functions.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) [2024] [Euler].
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Euler.
  *
  ******************************************************************************
  */

#include "motor_board_func.h"
#include "adc.h"
#include "tim.h"
#include "FOC_Model.h"

uint8_t uart_debug_buff[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80,0x7F};

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  if (hadc == &hadc1)
  {
    task_isr_10kHZ();
  }
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  if (Button3_Pin == GPIO_Pin)
  {
    Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF = ~Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF & Motor_UART_Start;
  }
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}

void motor_stop(void)
{
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
  HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
  HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
  HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
  HAL_TIMEx_HallSensor_Stop_IT(&htim4);
	Motor_App.HALL_Handle.DeltaAngle = 0;
  Motor_App.HALL_Handle.AvrElSpeedDpp = 0;
  Motor_App.HALL_Handle.HallSpeed = 0;
}

void motor_start(void)
{
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIMEx_HallSensor_Start_IT(&htim4);
  HALL_Init_Electrical_Angle();
}

void task_isr_1kHZ(void)
{
	static uint8_t motor_state = 0;
	Motor_Load_UART_Tx_Buff();
	if(motor_state != Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF)
	{
		if(Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF == Motor_UART_Start)
		{
			motor_start();
		}
		else
		{
			motor_stop();
		}
	}
	motor_state = Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF;
}

void task_isr_10kHZ(void)
{
  static uint8_t cnt;
  static uint8_t ADC_offset;
  static uint16_t IaU16, IbU16, IcU16;
  if (ADC_offset == 0)
  {
    cnt++;
    Motor_App.Motor_UART_Control.IA_Offset += hadc1.Instance->JDR1;
    Motor_App.Motor_UART_Control.IB_Offset += hadc2.Instance->JDR1;
    Motor_App.Motor_UART_Control.IC_Offset += hadc1.Instance->JDR2;
    if (cnt >= 10)
    {
      ADC_offset = 1;
      Motor_App.Motor_UART_Control.IA_Offset = Motor_App.Motor_UART_Control.IA_Offset / 10;
      Motor_App.Motor_UART_Control.IB_Offset = Motor_App.Motor_UART_Control.IB_Offset / 10;
      Motor_App.Motor_UART_Control.IC_Offset = Motor_App.Motor_UART_Control.IC_Offset / 10;
    }
  }
  else
  {
    if (Motor_App.HALL_Handle.MeasuredElAngle == PHASE_SHIFT_ANGLE && Motor_App.HALL_Handle.Direction == 1)
    {
      Motor_App.HALL_Handle.HallElAngle = Motor_App.HALL_Handle.MeasuredElAngle;
      Motor_App.HALL_Handle.MeasuredElAngle = Motor_App.HALL_Handle.MeasuredElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp;
      Motor_App.HALL_Handle.HallElAngle = Motor_App.HALL_Handle.HallElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp;
    }
    else if (Motor_App.HALL_Handle.MeasuredElAngle == PHASE_SHIFT_ANGLE + PI / 3 && Motor_App.HALL_Handle.Direction == -1)
    {
      Motor_App.HALL_Handle.HallElAngle = Motor_App.HALL_Handle.MeasuredElAngle;
      Motor_App.HALL_Handle.MeasuredElAngle = Motor_App.HALL_Handle.MeasuredElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp;
      Motor_App.HALL_Handle.HallElAngle = Motor_App.HALL_Handle.HallElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp;
    }
    else
    {
      Motor_App.HALL_Handle.MeasuredElAngle = Motor_App.HALL_Handle.MeasuredElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp;
      Motor_App.HALL_Handle.HallElAngle = Motor_App.HALL_Handle.HallElAngle + Motor_App.HALL_Handle.AvrElSpeedDpp + Motor_App.HALL_Handle.DeltaAngle;
    }
    if (Motor_App.HALL_Handle.HallElAngle < 0.0f)
    {
      Motor_App.HALL_Handle.HallElAngle += 2.0f * PI;
    }
    else if (Motor_App.HALL_Handle.HallElAngle > (2.0f * PI))
    {
      Motor_App.HALL_Handle.HallElAngle -= 2.0f * PI;
    }
    IaU16 = hadc1.Instance->JDR1;
    IbU16 = hadc2.Instance->JDR1;
    IcU16 = hadc1.Instance->JDR2;
    Motor_App.Motor_UART_LoadData.Ia = (IaU16 - Motor_App.Motor_UART_Control.IA_Offset) * 0.02197265625f;
    Motor_App.Motor_UART_LoadData.Ib = (IbU16 - Motor_App.Motor_UART_Control.IB_Offset) * 0.02197265625f;
    Motor_App.Motor_UART_LoadData.Ic = (IcU16 - Motor_App.Motor_UART_Control.IC_Offset) * 0.02197265625f;
    rtU.ia = Motor_App.Motor_UART_LoadData.Ia;
    rtU.ib = Motor_App.Motor_UART_LoadData.Ib;
    rtU.ic = Motor_App.Motor_UART_LoadData.Ic;
    rtU.theta = Motor_App.HALL_Handle.HallElAngle;
    rtU.Speed = Motor_App.HALL_Handle.HallSpeed;
    FOC_Model_step();
    TIM1->CCR1 = rtY.tABC[0];
    TIM1->CCR2 = rtY.tABC[1];
    TIM1->CCR3 = rtY.tABC[2];
  }
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(htim);
	if (htim == &htim4)
	{
		HALL_Get_Electrical_Angle(&Motor_App.HALL_Handle);
	}
}

void Motor_Load_UART_Tx_Buff(void)
{
    uint32_t temp;
    float temp_f[7];
    temp_f[0] = (float)Motor_App.Motor_UART_LoadData.Ia;
    temp_f[1] = (float)Motor_App.Motor_UART_LoadData.Ib;
    temp_f[2] = (float)Motor_App.Motor_UART_LoadData.Ic;
    temp_f[3] = (float)Motor_App.HALL_Handle.HallSpeed;
    temp_f[4] = (float)rtU.SpeedRef;
    temp_f[5] = (float)Motor_App.HALL_Handle.HallElAngle;;
    temp_f[6] = (float)0;
    memcpy(uart_debug_buff, (uint8_t *)&temp_f, sizeof(temp_f));
    HAL_UART_Transmit_DMA(&huart3,(uint8_t *)uart_debug_buff,8*4);
}