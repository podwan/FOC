#ifndef __COMM_H
#define __COMM_H

#include "userMain.h"

#define UART_SEND_BYTE(STUFF) UART0_Send_Byte(STUFF)

#define MAX_LEN 10
#define USART_BUFFER_SIZE 24

typedef struct
{
    unsigned char index;
    unsigned char buf[MAX_LEN];
    unsigned char len;
    unsigned char toProcessData;
} Uart;

void printLog(void);
void uartRcv(const char buf);
void commander_run(void);
void communicationLoop(void *argument);

extern Uart rxUart;
extern char sendStuff[MAX_LEN];
extern float temp[5];
extern uint8_t tempData[24];
extern float comm1, comm2, comm3, comm4, comm5, comm6, comm7, comm8, comm9, comm10, comm11;
extern char txBuffer[256];
#endif
