
#include "comm.h"
#include "encoder.h"
#include "pid.h"

float temp[5];
uint8_t tempData[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x7F};
char txBuffer[256];
Uart rxUart;
char sendStuff[MAX_LEN];
uint8_t aRxBuffer;
char sndBuff[USART_BUFFER_SIZE];
float comm1, comm2, comm3, comm4, comm5, comm6, comm7, comm8, comm9, comm10, comm11;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART3)
  {
    uartRcv(aRxBuffer);

    HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);
  }
}


void printLog()
{
#if CALI_PID
  printf("bldcMotor.target=%.2f, velocity=%.2f, ShaftAngle=%.2f\n", bldcMotor.target, shaftVelocity, shaftAngle);
  // printf("bldcMotor.target=%.2f, RPM=%d\n", bldcMotor.target, getRPM());
#elif SEND_RCC_DATA == 0
 // HAL_UART_Transmit(&huart3, (uint8_t *)txBuffer, sizeof(txBuffer), 1000);
 HAL_UART_Transmit_DMA(&huart3, (uint8_t *)txBuffer, sizeof(txBuffer));
 memset(txBuffer, '\0', sizeof(txBuffer));
#endif
}

/*接收中断调用*/
void uartRcv(const char buf)
{
  if (rxUart.toProcessData == 0)
  {
    if (rxUart.index < MAX_LEN)
    {
      if (buf == '\n') // || buf == '\r')
      {
        rxUart.toProcessData = 1;
        rxUart.index = 0;
      }
      else
      {
        rxUart.buf[rxUart.index] = buf;
        rxUart.index++;
        rxUart.len++;
      }
    }
    else // 接收的数据过长，无效
    {
      memset(rxUart.buf, '\0', MAX_LEN);
      rxUart.index = 0;
      rxUart.len = 0;
    }
  }
}
#if 0
void commander_run(void)
{
  if (rxUart.toProcessData == 1)
  {

    rxUart.toProcessData = 0;
    switch (rxUart.buf[0])
    {
    case 'H':
      // sprintf(sndBuff, "Hello World!\r\n");
      // HAL_UART_Transmit_DMA(&huart3, (uint8_t *)sndBuff, sizeof(sndBuff));
      sprintf(sndBuff, "Hello World!\r\n", bldcMotor.target);
      printf("%s", sndBuff);
      break;
    case 'T': // T6.28

      bldcMotor.target = atof((const char *)(rxUart.buf + 1));
      sprintf(sndBuff, "Target=%.2f\r\n", bldcMotor.target);
      printf("%s", sndBuff);
      // HAL_UART_Transmit_DMA(&huart3, (uint8_t *)sndBuff, sizeof(sndBuff));
      break;
    case 'P': // P0.5
      bldcMotor.pidVelocity.P = atof((const char *)(rxUart.buf + 1));
      sprintf(sndBuff, "P=%.2f\r\n", bldcMotor.pidVelocity.P);
      printf("%s", sndBuff);
      break;
    case 'I': // I0.2
      bldcMotor.pidVelocity.I = atof((const char *)(rxUart.buf + 1));
      sprintf(sndBuff, "I=%.2f\r\n", bldcMotor.pidVelocity.I);
      printf("%s", sndBuff);
      break;
    case 'V': // V
      sprintf(sndBuff, "Vel=%.2f\r\n", shaftVelocity);
      printf("%s", sndBuff);
      break;
    case 'A': // A
      sprintf(sndBuff, "Ang=%.2f\r\n", shaftAngle);
      printf("%s", sndBuff);
      break;
    }
    memset(rxUart.buf, '\0', sizeof(rxUart.buf));
  }
}
#endif
