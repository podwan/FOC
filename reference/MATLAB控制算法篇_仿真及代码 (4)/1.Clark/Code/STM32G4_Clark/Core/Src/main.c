/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "opamp.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "Clark_test.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern DMA_HandleTypeDef hdma_usart3_tx;
uint8_t DataB1[32] = "LED1 Toggle\r\n";
uint8_t DataB2[32] = "LED2 Toggle\r\n";
uint8_t DataB3[32] = "LED1 and LED2 Open\r\n";

#define RXBUFFERSIZE  256   
char RxBuffer[RXBUFFERSIZE];  
uint8_t aRxBuffer;			   
uint8_t Uart1_Rx_Cnt = 0;	

float temp[5];
static uint8_t tempData[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80,0x7F};
extern ExtY rtY;
extern real32_T ib;                    /* '<S3>/Sin1' */
extern real32_T ic;                    /* '<S3>/Sin2' */
extern real32_T ia;                    /* '<S3>/Sin' */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_OPAMP1_Init();
  MX_OPAMP2_Init();
  MX_OPAMP3_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	HAL_OPAMP_Start(&hopamp1);
	HAL_OPAMP_Start(&hopamp2);
	HAL_OPAMP_Start(&hopamp3);
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);
	HAL_ADCEx_Calibration_Start( &hadc1, ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start( &hadc2, ADC_SINGLE_ENDED);
	TIM1->ARR = 8000 - 1;
	TIM1->CCR4 = 8000 - 2;
	HAL_TIM_Base_Start( &htim1);
//	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
//	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
//	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
//	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
//	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
//	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
	HAL_ADCEx_InjectedStart_IT(&hadc1);
	HAL_ADCEx_InjectedStart(&hadc2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//		HAL_ADC_Start(&hadc1);
//		HAL_ADC_Start(&hadc2);
//		temp[3] = HAL_ADC_GetValue(&hadc1);
//		temp[3] = temp[3]*3.3f/4096;
//		temp[4] = HAL_ADC_GetValue(&hadc2);
//		temp[4] = temp[4]*3.3f/4096*26;
//		HAL_Delay(10);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV3;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the peripherals clocks
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_ADC12;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12CLKSOURCE_SYSCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//  /* Prevent unused argument(s) compilation warning */
//  UNUSED(GPIO_Pin);
//	if(Button1_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
//		printf("LED1 Toggle\r\n");
//	}
//	if(Button2_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
//		printf("LED2 Toggle\r\n");
//	}
//	if(Button3_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
//		printf("LED1 and LED2 Open\r\n");
//	}
//  /* NOTE: This function should not be modified, when the callback is needed,
//           the HAL_GPIO_EXTI_Callback could be implemented in the user file
//   */
//}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
	if(Button1_Pin == GPIO_Pin)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
		while(HAL_DMA_GetState(&hdma_usart3_tx) != HAL_DMA_STATE_READY);
		HAL_UART_Transmit_DMA(&huart3,DataB1,sizeof(DataB1));
	}
	if(Button2_Pin == GPIO_Pin)
	{
		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
		while(HAL_DMA_GetState(&hdma_usart3_tx) != HAL_DMA_STATE_READY);
		HAL_UART_Transmit_DMA(&huart3,DataB2,sizeof(DataB1));
	}
	if(Button3_Pin == GPIO_Pin)
	{
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
		while(HAL_DMA_GetState(&hdma_usart3_tx) != HAL_DMA_STATE_READY);
		HAL_UART_Transmit_DMA(&huart3,DataB3,sizeof(DataB1));
	}
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
	if(Uart1_Rx_Cnt >= 255)
	{
		Uart1_Rx_Cnt = 0;
		memset(RxBuffer,0x00,sizeof(RxBuffer));
		HAL_UART_Transmit(&huart3, (uint8_t *)"????", 10,0xFFFF); 	        
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
 while ((USART3->ISR & 0X40) == 0); 
 USART3->TDR = (uint8_t)ch; 
 return ch;
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
	if(hadc == &hadc1)
	{
//		temp[0] = hadc1.Instance->JDR1;
//		temp[0] = (temp[0] - 0x7ef)*0.02197f;
//		temp[1] = hadc1.Instance->JDR2;
//		temp[1] = (temp[1] - 0x7f5)*0.02197f;
//		temp[2] = hadc2.Instance->JDR1;
//		temp[2] = (temp[2] - 0x7e8)*0.02197f;
//		TIM1->CCR1 = 2000;
//		TIM1->CCR2 = 4000;
//		TIM1->CCR3 = 6000;
		Clark_test_step();
		temp[3] = rtY.ialpha;
		temp[4] = rtY.ibeta;
		temp[0] = ia;
		temp[1] = ib;
		temp[2] = ic;
		memcpy(tempData, (uint8_t *)&temp, sizeof(temp));
		HAL_UART_Transmit_DMA(&huart3,(uint8_t *)tempData,6*4);
	}

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
