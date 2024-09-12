/**
  ******************************************************************************
  * @file    hall_speed_pos_fdbk.h
  * @author  Euler
  * @brief   This file provides firmware functions that implement the features of
  *          the Hall Speed & Position Feedback.
  ******************************************************************************
  * @attention
  * This software component is licensed by Euler
  *
  ******************************************************************************
  */
#ifndef HALL_SPEEDNPOSFDBK_H
#define HALL_SPEEDNPOSFDBK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "motor_struct.h"
#include "tim.h"

void HALL_Init_Electrical_Angle(void);
void HALL_Get_Electrical_Angle(void *pHandleVoid);
#endif /*HALL_SPEEDNPOSFDBK_H*/