
#include "comm.h"
#include "mt6701.h"
#include "pid.h"
#include "app.h"

char txBuffer[USART_BUFFER_SIZE];
char rxBuffer[USART_BUFFER_SIZE];
static Uart rxUart;
uint8_t aRxBuffer;
float comm1, comm2, comm3, comm4, comm5, comm6, comm7, comm8, comm9, comm10, comm11;
float load_data[5];
uint8_t tempData[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x7F};

// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
//   if (huart->Instance == USART3)
//   {
//     // uartRcv(aRxBuffer);

//     // HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);
//   }
// }

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  if (huart == &huart3)
  {
    HAL_UART_Transmit_DMA(&huart3, rxBuffer, Size);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart3, rxBuffer, sizeof(rxBuffer));
  }
}
/**
 * @brief DMA方式发送数据
 */
void log_DMA_TX(const char *format, ...)
{
  va_list args;           // 定义参数列表变量
  va_start(args, format); // 从format位置开始接收参数表，放在arg里面

  char strBuf[256];               // 定义输出的字符串，缓冲区的区间不能太小，否则会出现错误
  vsprintf(strBuf, format, args); // 使用vsprintf将格式化的数据写入缓冲区
  va_end(args);                   // 结束可变参数的使用

  // 等待上次的数据发送完成，避免新的数据覆盖正在传输的数据，导致混乱
  while (HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX)
  {
    // Wait for DMA transfer to complete
  }

  HAL_UART_Transmit_DMA(&huart3, (uint8_t *)strBuf, strlen(strBuf));
}

// DMA模式
void FOC_log(const char *format, ...)
{
  va_list args;           // 定义参数列表变量
  va_start(args, format); // 从format位置开始接收参数表，放在arg里面

  char strBuf[256];               // 定义输出的字符串
  vsprintf(strBuf, format, args); // 使用vsprintf将格式化的数据写入缓冲区
  va_end(args);                   // 结束可变参数的使用

  // 等待上次的数据发送完成，避免新的数据覆盖正在传输的数据，导致混乱
  while (HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX)
  {
    // Wait for DMA transfer to complete
  }
  HAL_UART_Transmit(&huart3, (uint8_t *)strBuf, strlen(strBuf), 1000);
}

void printLog()
{
#if CALI_PID
  printf("bldcMotor.focTarget=%.2f, velocity=%.2f, ShaftAngle=%.2f\n", bldcMotor.focTarget, shaftVelocity, shaftAngle);
  // printf("bldcMotor.focTarget=%.2f, RPM=%d\n", bldcMotor.focTarget, getRPM());
#elif SHOW_WAVE == 0
  // HAL_UART_Transmit(&huart3, (uint8_t *)txBuffer, strlen(txBuffer), 100);
  HAL_UART_Transmit_DMA(&huart3, (uint8_t *)txBuffer, strlen(txBuffer));
  // memset(txBuffer, '\0', sizeof(txBuffer));
#endif
}

/*接收中断调用*/
void uartRcv(const char buf)
{
  if (rxUart.toProcessData == 0)
  {
    if (rxUart.index < MAX_LEN)
    {
      if (buf == '\n' || buf == '\r')
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

void commander_run(FocMotor *motor)
{
  if (rxUart.toProcessData == 1)
  {

    rxUart.toProcessData = 0;
    switch (rxUart.buf[0])
    {
    case 'H':
      // sprintf(sndBuff, "Hello World!\r\n");
      // HAL_UART_Transmit_DMA(&huart3, (uint8_t *)sndBuff, sizeof(sndBuff));
      sprintf(txBuffer, "Hello World!\r\n");
      printLog();
      break;
    case 'T': // T6.28

      motor->target = atof((const char *)(rxUart.buf + 1));
      sprintf(txBuffer, "Target=%.2f\r\n", focTarget);
      printLog();
      // printf("%s", sndBuff);
      // HAL_UART_Transmit_DMA(&huart3, (uint8_t *)sndBuff, sizeof(sndBuff));
      break;
      // case 'P': // P0.5
      //   bldcMotor.pidVelocity.P = atof((const char *)(rxUart.buf + 1));
      //   sprintf(sndBuff, "P=%.2f\r\n", bldcMotor.pidVelocity.P);
      //   printf("%s", sndBuff);
      //   break;
      // case 'I': // I0.2
      //   bldcMotor.pidVelocity.I = atof((const char *)(rxUart.buf + 1));
      //   sprintf(sndBuff, "I=%.2f\r\n", bldcMotor.pidVelocity.I);
      //   printf("%s", sndBuff);
      //   break;
      // case 'V': // V
      //   sprintf(sndBuff, "Vel=%.2f\r\n", shaftVelocity);
      //   printf("%s", sndBuff);
      //   break;
      // case 'A': // A
      //   sprintf(sndBuff, "Ang=%.2f\r\n", shaftAngle);
      //   printf("%s", sndBuff);
      //   break;
    }
    memset(rxUart.buf, '\0', sizeof(rxUart.buf));
  }
}
