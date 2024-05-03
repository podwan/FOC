#include "as5407.h"
#include "encoder.h"

// https://blog.csdn.net/weixin_42416680/article/details/132197502
//  计算奇偶函数
uint16_t Parity_bit_Calculate(uint16_t data_2_cal)
{
    uint16_t parity_bit_value = 0;
    while (data_2_cal != 0)
    {
        parity_bit_value ^= data_2_cal;
        data_2_cal >>= 1;
    }
    return (parity_bit_value & 0x1);
}
// SPI发送读取函数
uint16_t SPI_ReadWrite_OneByte(uint16_t _txdata)
{
    CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select
                                                  // AS5407P_CS_L // cs拉低
    uint16_t rxdata;

    if (HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)&_txdata, (uint8_t *)&rxdata, 1, 1000) != HAL_OK)
        rxdata = 0;
    //   AS5407P_CS_H // cs拉高 return rxdata;

    CS_GPIO_Port->BSRR = CS_Pin;
    return rxdata;
}

uint16_t AS5047_read(uint16_t add)
{
    uint16_t data;
    add |= 0x4000;
    // 读指令 bit14 置1
    if (Parity_bit_Calculate(add) == 1)
        add = add | 0x8000;
    // 如果前15位 1的个数位偶数，则Bit15 置1
    SPI_ReadWrite_OneByte(add);
    // 发送一条指令，不管读回的数据
    data = SPI_ReadWrite_OneByte(NOP | 0x4000);
    // 发送一条空指令，读取上一次指令返回的数据。
    data &= 0x3fff;
    return data;
}
