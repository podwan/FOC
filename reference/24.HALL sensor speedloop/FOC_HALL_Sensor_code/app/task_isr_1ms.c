/**
  ******************************************************************************
  * @file    task_isr_1ms.c
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

#include "uart_comm_func.h"
void task_isr_1ms(void)
{
    Motor_Load_UART_Tx_Buff();
}