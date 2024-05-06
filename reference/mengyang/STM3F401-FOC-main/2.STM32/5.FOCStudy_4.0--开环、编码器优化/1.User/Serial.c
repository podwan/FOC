#include <stdio.h>
#include "usart.h"
#include <string.h>
#include <stdarg.h>

// DMA模式
void FOC_log(const char *format, ...)
{
	va_list args;			// 定义参数列表变量
	va_start(args, format); // 从format位置开始接收参数表，放在arg里面

	char strBuf[256];				// 定义输出的字符串
	vsprintf(strBuf, format, args); // 使用vsprintf将格式化的数据写入缓冲区
	va_end(args);					// 结束可变参数的使用

	// 等待上次的数据发送完成，避免新的数据覆盖正在传输的数据，导致混乱
	while (HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX)
	{
		// Wait for DMA transfer to complete
	}
	HAL_UART_Transmit_DMA(&huart1, (uint8_t *)strBuf, strlen(strBuf));
}
