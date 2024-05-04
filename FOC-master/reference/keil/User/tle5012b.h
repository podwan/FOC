/**
 ******************************************************************************
 * @file    spi_TLE5012B.h
 * @author  Keith Cheung
 * @version V3.5.0
 * @date    13-MAY-2017
 * @brief   This file contains the headers of the spi_TLE5012B.
 ******************************************************************************
 * @attention
 *
 *
 * https://blog.csdn.net/keith_cheung/article/details/71883155
 ******************************************************************************
 */

#ifndef _TLE5012B_H_
#define _TLE5012B_H_

#include "userMain.h"

// SPI5012B_Init() 时钟需另外加上
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
// 以下内容需按实际更改
// #define SPI_TX_OFF            \
//   {                           \
//     GPIOA->OTYPER &= (1<<4); \
//     GPIOA->CRL |= 0x40000000; \
//   } // 把PA7（MOSI）配置成开漏--输入模式
// #define SPI_TX_ON             \
//   {                           \
//     GPIOA->CRL &= 0x0FFFFFFF; \
//     GPIOA->CRL |= 0xB0000000; \
//   } // 把PA7（MOSI）配置成推挽--输出模式（50MHz）

#define GPIO_CS_Pin_Name GPIO_PIN_4
#define GPIO_CS_Pin_Type GPIOA

// 以下内容一般不需变动
#define SPI_CS_ENABLE HAL_GPIO_WritePin(GPIO_CS_Pin_Type, GPIO_CS_Pin_Name, GPIO_PIN_RESET) // 片选脚电平拉低
#define SPI_CS_DISABLE HAL_GPIO_WritePin(GPIO_CS_Pin_Type, GPIO_CS_Pin_Name, GPIO_PIN_SET)  // 片选脚电平拉高
// #define INDEX_ENABLE   GPIO_SetBits(GPIOA, GPIO_Pin_4)/* for incremental signal index */

// #define CLK_H GPIO_SetBits(GPIOA, GPIO_Pin_5)                 //时钟脚PA5电平拉高
// #define CLK_L GPIO_ResetBits(GPIOA, GPIO_Pin_5)               //时钟脚PA5电平拉低

// #define DATA_H	GPIO_SetBits(GPIOA, GPIO_Pin_6)                         //PA6（MISO）电平拉高
// #define DATA_L	GPIO_ResetBits(GPIOA, GPIO_Pin_6)                       //PA6（MISO）电平拉低
// #define READ_DATA	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)

/* SPI command for TLE5012 */
#define READ_STATUS 0x8001      // 8000


#define WRITE_MOD1_VALUE 0x5060 // 0_1010_0_000110_0001
#define MOD1_VALUE 0x0001

#define WRITE_MOD2_VALUE 0x5080 // 0_1010_0_001000_0001
#define MOD2_VALUE 0x0801

#define WRITE_MOD3_VALUE 0x5091 // 0_1010_0_001001_0001
#define MOD3_VALUE 0x0000

#define WRITE_MOD4_VALUE 0x50E0 // 0_1010_0_001110_0001
#define MOD4_VALUE 0x0098       // 9bit 512

#define WRITE_IFAB_VALUE 0x50B1
#define IFAB_VALUE 0x000D
/* Functionality mode */
#define REFERESH_ANGLE 0

void SPI5012B_Init(void);
void SPI_SendData16(uint16_t SendData);
uint16_t SPI_ReadData16(void);
uint16_t ReadAngle(void);
uint16_t ReadSpeed(void);
uint16_t ReadValue(uint16_t u16Value);
uint16_t SPIx_ReadWriteByte(uint16_t byte);
uint16_t TlE5012W_Reg(uint16_t Reg_CMD, uint16_t Reg_Data);
#endif
