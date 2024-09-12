/**
  ******************************************************************************
  * @file    motor_struct.c
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

#include "motor_struct.h"

Motor_App_t Motor_App;

void Motor_app_init(void)
{
  Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF = Motor_UART_Stop;
  Motor_App.Motor_UART_Control.Iq_ref = 0;
  Motor_App.Motor_UART_Control.Speed_ref = 0;
  Motor_App.Motor_UART_Control.Speed_KP = 0.003389F;
  Motor_App.Motor_UART_Control.Speed_KI = 0.00144F;
  Motor_App.Motor_UART_Control.Speed_ref = 1200;

  Motor_App.Motor_UART_RxBuff.uart_rx_data = 0;
  Motor_App.Motor_UART_RxBuff.uart_rx_complete = 0;
  Motor_App.Motor_UART_RxBuff.uart_rx_index = 0;
  Motor_App.Motor_UART_RxBuff.Data_Decoding_state = 0;
}
