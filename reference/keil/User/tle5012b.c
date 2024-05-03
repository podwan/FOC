#if 0
#include "tle5012b.h"

uint16_t SPIx_ReadWriteByte(uint16_t byte)
{
    uint16_t retry = 0;
    while ((SPI1->SR & 1 << 1) == 0) // 发送缓冲区非空
    {
        if (++retry > 200)
            return 0; // 延迟一段时间后返回
    }
    SPI1->DR = byte; // 发送数据

    retry = 0;
    while ((SPI1->SR & 1 << 0) == 0) // 接收缓冲区为空
    {
        if (++retry > 200)
            return 0; // 延迟一段时间后返回
    }
    return SPI1->DR; // 读一下缓冲区，清标志
}

// 得到 0~359 度
uint16_t ReadAngle(void)
{
    return (ReadValue(READ_ANGLE_VALUE) * 360 / 0x10000);
}

// 得到角速度
uint16_t ReadSpeed(void)
{
    return ReadValue(READ_SPEED_VALUE);
}

uint16_t ReadValue(uint16_t u16RegValue)
{
    uint16_t u16Data;

    SPI_CS_ENABLE;

    SPIx_ReadWriteByte(u16RegValue);
    // SPI_TX_OFF;

    // 发送 0xFFFF 是无用的，可能是为了有时钟
    u16Data = (SPIx_ReadWriteByte(0xffff) & 0x7FFF) << 1; // 0x12/0xff*100k

    SPI_CS_DISABLE;
    // SPI_TX_ON;

    return (u16Data);
}
#endif