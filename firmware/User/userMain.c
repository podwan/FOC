#include "userMain.h"
#include "userTimer.h"
#include "comm.h"
#include "app.h"
#include "key.h"

#define PHASE_SHIFT_ANGLE (float)(120.0f / 360.0f * 2.0f * PI)

extern DMA_HandleTypeDef hdma_usart3_tx;

uint16_t DAC_temp = 0;

float Vbus, Ia, Ib, Ic;
uint8_t Motor_state = 0;
uint16_t IA_Offset, IB_Offset, IC_Offset;
uint16_t adc1_in1, adc1_in2, adc1_in3, Vpoten, adc_vbus;
uint8_t ADC_offset = 0;

uint8_t RxData[8] = {NULL};
uint8_t TxData[8] = {NULL};

// static bool powerLost;
void userMain(void)
{

	if (get5MsFlag())
	{
		keyScan();
	}

	if (get100MsFlag())
	{
		appRunning();
	}
#if SHOW_WAVE == 0 //&& COMMAMNDER == 0
	// if (get500MsFlag())
	if (getOneSecFlag())
	{
		printLog();
	}
#endif
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int fputc(int ch, FILE *f)
{
	while ((USART3->ISR & 0X40) == 0)
		;
	USART3->TDR = (uint8_t)ch;
	return ch;
}
