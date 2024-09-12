/**
  ******************************************************************************
  * @file    hall_speed_pos_fdbk.c
  * @author  Euler
  * @brief   This file provides firmware functions that implement the features of
  *          the Hall Speed & Position Feedback.
  ******************************************************************************
  * @attention
  * This software component is licensed by Euler
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "hall_speed_pos_fdbk.h"
#include "motor_struct.h"

//#define PI					3.14159265358979f
//#define PHASE_SHIFT_ANGLE (float)(218.0f/360.0f*2.0f*PI)
#define STATE_0 (uint8_t)0
#define STATE_1 (uint8_t)1
#define STATE_2 (uint8_t)2
#define STATE_3 (uint8_t)3
#define STATE_4 (uint8_t)4
#define STATE_5 (uint8_t)5
#define STATE_6 (uint8_t)6
#define STATE_7 (uint8_t)7

#define NEGATIVE          (int8_t)-1
#define POSITIVE          (int8_t)1

void HALL_Get_Electrical_Angle(void *pHandleVoid)
{
	HALL_Handle_t *phandle = (HALL_Handle_t *)pHandleVoid;
	phandle->hHighSpeedCapture = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
	phandle->bPrevHallState = phandle->HallState;
	phandle->HallState = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	phandle->HallState |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) << 1;
	phandle->HallState |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) << 2;
	switch (phandle->HallState)
	{
	case STATE_5:
	{
		if (STATE_1 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_4 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + PI / 3.0f;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	case STATE_4:
	{
		if (STATE_5 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + PI / 3.0f;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_6 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 2 * PI / 3.0f;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	case STATE_6:
	{
		if (STATE_4 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 2 * PI / 3.0f;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_2 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + PI;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	case STATE_2:
	{
		if (STATE_6 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + PI;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_3 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 4 * PI / 3.0f;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	case STATE_3:
	{
		if (STATE_2 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 4 * PI / 3.0f;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_1 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 5 * PI / 3.0f;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	case STATE_1:
	{
		if (STATE_3 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE + 5 * PI / 3.0f;
			phandle->Direction = POSITIVE;
		}
		else if (STATE_5 == phandle->bPrevHallState)
		{
			phandle->MeasuredElAngle = PHASE_SHIFT_ANGLE;
			phandle->Direction = NEGATIVE;
		}
		else
		{
		}; // nothing
		break;
	}
	default:
	{
		break;
	}
	}
	if (phandle->MeasuredElAngle < 0.0f)
	{
		phandle->MeasuredElAngle += 2.0f * PI;
	}
	else if (phandle->MeasuredElAngle > (2.0f * PI))
	{
		phandle->MeasuredElAngle -= 2.0f * PI;
	}
	phandle->AvrElSpeedDpp = (PI/3)/((phandle->hHighSpeedCapture/3200000)*10000);
	phandle->HallSpeed = (PI/3)/(phandle->hHighSpeedCapture/3200000)*30/(2*PI);
	phandle->HallSpeed = phandle->HallSpeed * phandle->Direction;
	phandle->AvrElSpeedDpp = phandle->AvrElSpeedDpp * phandle->Direction;
	phandle->DeltaAngle = (phandle->MeasuredElAngle - phandle->HallElAngle) / 10000;
}

void HALL_Init_Electrical_Angle(void)
{
	HALL_Handle_t *phandle = &Motor_App.HALL_Handle;
	phandle->HallState = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	phandle->HallState |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) << 1;
	phandle->HallState |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) << 2;
	switch (phandle->HallState)
		{
			case STATE_5:
			{
				phandle->HallElAngle = PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			case STATE_4:
			{
				phandle->HallElAngle = (PI/3.0f)+PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			case STATE_6:
			{
				phandle->HallElAngle = (PI*2.0f/3.0f)+PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			case STATE_2:
			{
				phandle->HallElAngle = PI + PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			case STATE_3:
			{
				phandle->HallElAngle = (PI*4.0f/3.0f)+PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			case STATE_1:
			{
				phandle->HallElAngle = (PI*5.0f/3.0f)+PHASE_SHIFT_ANGLE + PI/6;
				break;
			}
			default:
		 {
			 break;
		 }
	 }
}