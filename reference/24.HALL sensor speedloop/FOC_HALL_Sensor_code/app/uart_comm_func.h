/**
  ******************************************************************************
  * @file    uart_comm_func.h
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

#ifndef UART_COMM_FUNC_H
#define UART_COMM_FUNC_H

#include "motor_struct.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Motor_Load_UART_Tx_Buff(void);
void Motor_UART_Rx_Job(void);
uint8_t split_string(const char *str, char delimiter, char **left, char **right);
float my_strtof(const char *str);
void Motor_UART_Rx_Data_Decoding(void);


#endif /*UART_COMM_FUNC_H*/