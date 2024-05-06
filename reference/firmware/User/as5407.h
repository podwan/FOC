#ifndef __AS5407_H
#define __AS5407_H

#include "userMain.h"

// AS5047p 地址
#define NOP 0x0000
#define ERRFL 0x0001
#define PROG 0x0003
#define DIAAGC 0x3FFC
#define MAG 0x3FFD
#define ANGLEUNC 0x3FFE
#define ANGLECOM 0x3FFF

#define ZPOSM 0x0016
#define ZPOSL 0x0017
#define SETTINGS1 0x0018
#define SETTINGS2 0x0019
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
uint16_t as5047readRawData(uint16_t add);
float as5047GetRawAngle(void);
#endif