#ifndef __COMM_H
#define __COMM_H

#include "userMain.h"

#define UART_SEND_BYTE(STUFF) UART0_Send_Byte(STUFF)

#define USART_BUFFER_SIZE 24

void printLog(void);
void uartRcv(const char buf);
void commander_run(void);
void communicationLoop(void *argument);
void FOC_log(const char *format, ...);
void log_DMA_TX(const char *format, ...);
extern Uart rxUart;
extern float comm1, comm2, comm3, comm4, comm5, comm6, comm7, comm8, comm9, comm10, comm11;
extern char txBuffer[];
extern float load_data[5];
extern uint8_t tempData[24];
extern uint8_t aRxBuffer;
extern float target;
#endif
