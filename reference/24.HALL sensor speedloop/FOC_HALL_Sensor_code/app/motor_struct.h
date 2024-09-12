/**
  ******************************************************************************
  * @file    motor_struct.h
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

#ifndef MOTOR_STRUCT_H
#define MOTOR_STRUCT_H

#include "stm32g4xx_hal.h"

#define UART_BUFFER_SIZE 256
#define PI					3.14159265358979f
#define PHASE_SHIFT_ANGLE (float)(218.0f/360.0f*2.0f*PI)

typedef enum
{
    Motor_UART_Stop = 0x00U,
    Motor_UART_Start = 0x01U,
}Motor_UART_TurnOnOFF_t;

typedef struct
{
    Motor_UART_TurnOnOFF_t Motor_UART_TurnOnOFF;
    int16_t Speed_ref;
    float Iq_ref;
    float Speed_KP;
    float Speed_KI;
    float Curr_KP;
    float Curr_KI;
    uint16_t IA_Offset;
    uint16_t IB_Offset;
    uint16_t IC_Offset;
}Motor_UART_Control_t;

typedef struct
{
    float Ia;
    float Ib;
    float Ic;
    float Iq_ref;
    float Iq;
    int16_t Speed_ref;
    int16_t Speed;
		float Torque;
		float Power;
}Motor_UART_LoadData_t;

typedef struct
{
    uint8_t uart_rx_buffer[UART_BUFFER_SIZE];
    uint8_t uart_rx_data;
    uint16_t uart_rx_index;
    uint8_t uart_rx_complete;
		uint8_t Data_Decoding_state;
}Motor_UART_RxBuff_t;

typedef struct
{
    uint8_t HallState;
    float AvrElSpeedDpp;
    float MeasuredElAngle;
    float HallElAngle;
    int8_t Direction;
    float HallSpeed;
    float DeltaAngle;
		uint8_t	bPrevHallState;
		float hHighSpeedCapture;
		float MeasureTest;
}HALL_Handle_t;

typedef struct
{
    Motor_UART_Control_t Motor_UART_Control;
    Motor_UART_LoadData_t Motor_UART_LoadData;
    Motor_UART_RxBuff_t Motor_UART_RxBuff;
    HALL_Handle_t HALL_Handle;
}Motor_App_t;

extern Motor_App_t Motor_App;
void Motor_app_init(void);

 #endif /*MOTOR_STRUCT_H*/