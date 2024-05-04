#include "encoder_as5407.h"

void EncoderAS5047Base::Init()
{
    SpiInit();
    VarInit();
}

float EncoderAS5047Base::GetRawAngle()
{
    return ((float)GetRawData() / (float)COUNT_PER_ROTATE) * _2PI;
}

uint16_t EncoderAS5047Base::GetRawData()
{
    uint16_t data, add;
    add = 0x3FFF;
    add |= 0x4000;
    // 读指令 bit14 置1
    if (SpiCalcEvenParity(add) == 1)
        add = add | 0x8000;
    // 如果前15位 1的个数位偶数，则Bit15 置1
    SpiTransmitAndRead16Bits(add);
    // 发送一条指令，不管读回的数据
    data = SpiTransmitAndRead16Bits(0x0000 | 0x4000);
    // 发送一条空指令，读取上一次指令返回的数据。
    data &= 0x3fff;
    return data;
}

uint8_t EncoderAS5047Base::SpiCalcEvenParity(uint16_t value)
{

    uint16_t parity_bit_value = 0;
    while (value != 0)
    {
        parity_bit_value ^= value;
        value >>= 1;
    }
    return (parity_bit_value & 0x1);
}
