

#include "userMain.h"
#include "userTimer.h"
#include "motor.h"
#include "foc_utils.h"
#define PI 3.14159265358979f
#define PHASE_SHIFT_ANGLE (float)(120.0f / 360.0f * 2.0f * PI)

extern DMA_HandleTypeDef hdma_usart3_tx;
uint8_t DataB1[32] = "LED1 Toggle\r\n";
uint8_t DataB2[32] = "LED2 Toggle\r\n";
uint8_t DataB3[32] = "LED1 and LED2 Open\r\n";

#define RXBUFFERSIZE 256
char RxBuffer[RXBUFFERSIZE];
uint8_t aRxBuffer;
uint8_t Uart1_Rx_Cnt = 0;

float load_data[5];
uint8_t tempData[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x7F};

uint16_t DAC_temp = 0;

float Vbus, Ia, Ib, Ic;
uint8_t Motor_state = 0;
uint16_t IA_Offset, IB_Offset, IC_Offset;
uint16_t adc1_in1, adc1_in2, adc1_in3, Vpoten, adc_vbus;
uint8_t ADC_offset = 0;

FDCAN_RxHeaderTypeDef RxHeader;
FDCAN_TxHeaderTypeDef TxHeader;
uint8_t RxData[8] = {NULL};
uint8_t TxData[8] = {NULL};

float HallTemp = 0;
float HallThetaAdd = 0;
float HallTheta = 0;
float HallSpeed = 0;
uint8_t HallReadTemp = 0;
static bool powerLost;
void userMain(void)
{

#if NEED_POWER_OFF_MEMORY
#include "memory.h"
	static bool memorized, recalled;
	if (!recalled)
	{
		recalled = 1;
		recall();
	}
	if (powerLost && !memorized)
	{
		memorize();
		memorized = 1;
	}
#endif

	// if (_10ms)
	// {

	// 	_10ms = 0;
	// 	display();
	// }

	// if (_20ms)
	// {
	// 	_20ms = 0;
	// 	beepPolling();
	// }

	// if (_5ms)
	// {
	// 	_5ms = 0;
	// 	keyScan();
	// }

	// if (_30ms)
	// {
	// 	_30ms = 0;
	// 	sensoring();
	// }

	if (get100MsFlag())
	{
		appRunning();
	}
}

void setPowerLost()
{
	powerLost = 1;
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(GPIO_Pin);
	if (Button3_Pin == GPIO_Pin)
	{
		Motor_state = ~Motor_state;
		if (0 == Motor_state)
		{
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
		}
		else
		{
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
		}
	}
	/* NOTE: This function should not be modified, when the callback is needed,
			 the HAL_GPIO_EXTI_Callback could be implemented in the user file
	 */
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(huart);
	if (Uart1_Rx_Cnt >= 255)
	{
		Uart1_Rx_Cnt = 0;
		memset(RxBuffer, 0x00, sizeof(RxBuffer));
		HAL_UART_Transmit(&huart3, (uint8_t *)"????", 10, 0xFFFF);
	}
	else
	{
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;
		//		Uart1_Rx_Cnt = 0;
		//		memset(RxBuffer,0x00,sizeof(RxBuffer));
	}
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);
	/* NOTE: This function should not be modified, when the callback is needed,
			 the HAL_UART_TxHalfCpltCallback can be implemented in the user file.
	 */
}

int fputc(int ch, FILE *f)
{
	while ((USART3->ISR & 0X40) == 0)
		;
	USART3->TDR = (uint8_t)ch;
	return ch;
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	static uint8_t cnt;
	/* Prevent unused argument(s) compilation warning */
	UNUSED(hadc);
	if (hadc == &hadc1)
	{
		if (ADC_offset == 0)
		{
			cnt++;
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in2 = hadc2.Instance->JDR1;
			adc1_in3 = hadc1.Instance->JDR2;
			IA_Offset += adc1_in1;
			IB_Offset += adc1_in2;
			IC_Offset += adc1_in3;
			if (cnt >= 10)
			{
				ADC_offset = 1;
				IA_Offset = IA_Offset / 10;
				IB_Offset = IB_Offset / 10;
				IC_Offset = IC_Offset / 10;
			}
		}
		else
		{

			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in3 = hadc1.Instance->JDR2;
			adc1_in2 = hadc2.Instance->JDR1;

			Ia = (adc1_in1 - IA_Offset) * 0.02197f;
			Ib = (adc1_in2 - IB_Offset) * 0.02197f;
			Ic = (adc1_in3 - IC_Offset) * 0.02197f;
			static float elecAngle;
			elecAngle += 0.01;
			if (elecAngle >= _2PI)
				elecAngle = 0;

//			setPhaseVoltage1(2, 0, elecAngle);
			// setPhaseVoltage1(2, 0, elecAngle);
			//  load_data[0] = Ia;
			//  load_data[1] = Ib;
			//  load_data[2] = Ic;
			//  load_data[3] = 0;
			//  load_data[4] = 0;
			dealPer100us();
			// velocityOpenLoop(&fp1, 2, 100);

			memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
			HAL_UART_Transmit_DMA(&huart3, (uint8_t *)tempData, 6 * 4);
		}
	}

	/* NOTE : This function should not be modified. When the callback is needed,
			  function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
	*/
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	/* Prevent unused argument(s) compilation warning */
	// UNUSED(htim);
	// if (htim == &htim4)
	// {
	// 	HallTemp = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
	// 	;
	// 	HallThetaAdd = (PI / 3) / (HallTemp / 1000000) / 10000;
	// 	HallSpeed = (PI / 3) / (HallTemp / 1000000) * 30 / PI;
	// 	HallReadTemp = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	// 	HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) << 1;
	// 	HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) << 2;
	// 	if (HallReadTemp == 0x05)
	// 	{
	// 		HallTheta = 0.0f + PHASE_SHIFT_ANGLE;
	// 	}
	// 	else if (HallReadTemp == 0x04)
	// 	{
	// 		HallTheta = (PI / 3.0f) + PHASE_SHIFT_ANGLE;
	// 	}
	// 	else if (HallReadTemp == 0x06)
	// 	{
	// 		HallTheta = (PI * 2.0f / 3.0f) + PHASE_SHIFT_ANGLE;
	// 	}
	// 	else if (HallReadTemp == 0x02)
	// 	{
	// 		HallTheta = PI + PHASE_SHIFT_ANGLE;
	// 	}
	// 	else if (HallReadTemp == 0x03)
	// 	{
	// 		HallTheta = (PI * 4.0f / 3.0f) + PHASE_SHIFT_ANGLE;
	// 	}
	// 	else if (HallReadTemp == 0x01)
	// 	{
	// 		HallTheta = (PI * 5.0f / 3.0f) + PHASE_SHIFT_ANGLE;
	// 	}
	// 	if (HallTheta < 0.0f)
	// 	{
	// 		HallTheta += 2.0f * PI;
	// 	}
	// 	else if (HallTheta > (2.0f * PI))
	// 	{
	// 		HallTheta -= 2.0f * PI;
	// 	}
	// }

	/* NOTE : This function should not be modified, when the callback is needed,
			  the HAL_TIM_IC_CaptureCallback could be implemented in the user file
	 */
}

void FDCAN_Config(void)
{
	// FDCAN_FilterTypeDef sFilterConfig;

	// HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

	// sFilterConfig.IdType = FDCAN_EXTENDED_ID;
	// sFilterConfig.FilterIndex = 0;
	// sFilterConfig.FilterType = FDCAN_FILTER_RANGE;
	// sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
	// sFilterConfig.FilterID1 = 0x00000000;
	// sFilterConfig.FilterID2 = 0x01ffffff;
	// HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig);

	// TxHeader.Identifier = 0x1B;
	// TxHeader.IdType = FDCAN_EXTENDED_ID;
	// TxHeader.TxFrameType = FDCAN_DATA_FRAME;
	// TxHeader.DataLength = FDCAN_DLC_BYTES_8;
	// TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	// TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
	// TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
	// TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	// TxHeader.MessageMarker = 0x52;

	// HAL_FDCAN_Start(&hfdcan1);
}
