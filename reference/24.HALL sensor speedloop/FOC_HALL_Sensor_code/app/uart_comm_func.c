/**
  ******************************************************************************
  * @file    can_comm_func.c
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

uint8_t uart_debug_buff[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80,0x7F};

void Motor_Load_UART_Tx_Buff(void)
{
    uint32_t temp;
    float temp_f[7];
    temp_f[0] = (float)Motor_App.Motor_UART_LoadData.Ia;
    temp_f[1] = (float)Motor_App.Motor_UART_LoadData.Ib;
    temp_f[2] = (float)Motor_App.Motor_UART_LoadData.Ic;
    temp_f[3] = (float)Motor_App.Motor_UART_LoadData.Torque;
    temp_f[4] = (float)Motor_App.Motor_UART_LoadData.Power;
    temp_f[5] = (float)Motor_App.Motor_UART_LoadData.Speed_ref;
    temp_f[6] = (float)Motor_App.Motor_UART_LoadData.Speed;
    memcpy(uart_debug_buff, (uint8_t *)&temp_f, sizeof(temp_f));
    HAL_UART_Transmit_DMA(&huart3,(uint8_t *)uart_debug_buff,8*4);
}

void Motor_UART_Rx_Job(void)
{
    if (Motor_App.Motor_UART_RxBuff.uart_rx_data == 0x21) 
    {
        Motor_App.Motor_UART_RxBuff.uart_rx_buffer[Motor_App.Motor_UART_RxBuff.uart_rx_index] = '\0'; // 添加字符串结束符
        Motor_App.Motor_UART_RxBuff.uart_rx_complete = 1; // 标记接收完成
        Motor_App.Motor_UART_RxBuff.uart_rx_index = 0; // 重置索引
				Motor_App.Motor_UART_RxBuff.Data_Decoding_state = 1;
    } 
    else 
    {
        Motor_App.Motor_UART_RxBuff.uart_rx_buffer[Motor_App.Motor_UART_RxBuff.uart_rx_index++] = Motor_App.Motor_UART_RxBuff.uart_rx_data;
        if (Motor_App.Motor_UART_RxBuff.uart_rx_index >= UART_BUFFER_SIZE) 
        {
            Motor_App.Motor_UART_RxBuff.uart_rx_index = 0; // 防止缓冲区溢出
        }
    }
    HAL_UART_Receive_IT(&huart3, (uint8_t *)&Motor_App.Motor_UART_RxBuff.uart_rx_data, 1);
}

uint8_t split_string(const char *str, char delimiter, char **left, char **right) 
{
    *left = (char *)str;
    *right = NULL;

    for (; *str != '\0'; str++) {
        if (*str == delimiter) {
            *right = (char *)(str + 1);
            // *((char *)str) = '\0'; // 将分隔符替换为字符串结束符
            return 0; // 成功找到分隔符
        }
    }

    return 1; // 没有找到分隔符
}

float my_strtof(const char *str) 
{
    float result = 0.0f;
    float sign = 1.0f;
    float fraction = 1.0f;
    int exponent = 0;
    int exp_sign = 1;
    int state = 0; // 0: integer part, 1: fractional part, 2: exponent part

    // 跳过前导空格
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r') {
        str++;
    }

    // 处理符号
    if (*str == '-') {
        sign = -1.0f;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // 处理数字部分
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            if (state == 0) {
                result = result * 10.0f + (*str - '0');
            } else if (state == 1) {
                fraction /= 10.0f;
                result += (*str - '0') * fraction;
            } else if (state == 2) {
                exponent = exponent * 10 + (*str - '0');
            }
        } else if (*str == '.' && state == 0) {
            state = 1;
        } else if ((*str == 'e' || *str == 'E') && state < 2) {
            state = 2;
            str++;
            if (*str == '-') {
                exp_sign = -1;
                str++;
            } else if (*str == '+') {
                str++;
            }
            continue;
        } else {
            break;
        }
        str++;
    }

    // 计算最终结果
    if (state == 2) {
        while (exponent > 0) {
            if (exp_sign > 0) {
                result *= 10.0f;
            } else {
                result /= 10.0f;
            }
            exponent--;
        }
    }

    return sign * result;
}

void Motor_UART_Rx_Data_Decoding(void)
{
	char *Frame_header;
	char *Frame_data;
	float strtof;
	if(Motor_App.Motor_UART_RxBuff.Data_Decoding_state == 1)
	{
		if(split_string((char *)Motor_App.Motor_UART_RxBuff.uart_rx_buffer,'=',&Frame_header,&Frame_data) == 0x00)
		{
			strtof = my_strtof(Frame_data);
			if(Motor_App.Motor_UART_RxBuff.uart_rx_buffer[0] == 'P' && Motor_App.Motor_UART_RxBuff.uart_rx_buffer[1] == 0x31)
			{
				if((uint8_t)strtof == 0x01)
				{
					Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF = Motor_UART_Start;
				}
				else
				{
					Motor_App.Motor_UART_Control.Motor_UART_TurnOnOFF = Motor_UART_Stop;
				}
			}
			if(Motor_App.Motor_UART_RxBuff.uart_rx_buffer[0] == 'P' && Motor_App.Motor_UART_RxBuff.uart_rx_buffer[1] == 0x32)
			{
				Motor_App.Motor_UART_Control.Speed_ref = (int16_t)strtof;
			}	
			Motor_App.Motor_UART_RxBuff.Data_Decoding_state = 0;
			memset(Motor_App.Motor_UART_RxBuff.uart_rx_buffer, 0 , 256);
		}
	}   
}

