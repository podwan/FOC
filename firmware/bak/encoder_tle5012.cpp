#include "encoder_tle5012.h"

uint16_t EncoderAS5047Base::getRawData(void)
{
    uint16_t data;

    spiSelect();

    // TLE5012
    SpiTransmitAndRead16Bits(0x8020); // read

    data = (SpiTransmitAndRead16Bits(0xff) & 0x7fff);

    spiUnselect();
    return data;
}
float EncoderAS5047Base::getRawAngle()
{
    return ((float)getRawData() / (float)countPerRotary) * _2PI;
}

float EncoderAS5047Base::getVelocity()
{

    uint16_t speed_reg_v = READ_SPEED_VALUE, data;
    spiSelect();
    SpiTransmitAndRead16Bits(0x8030); // read

    data = (SpiTransmitAndRead16Bits(0xff) & 0x7fff);
    spiUnselect();
    data = (data & 0x7fff);
    uint16_t sign = data & 0x4000;
    if (sign == 0x4000)
    {
        data = data | 0x8000;
    }
    int16_t speed = (int16_t)data;
    speed = speed * 1000;
    float tupd = 2.0 * 42.7 / 1000;
    float speed_v = (float)(speed * 2 * 3.14) / 0x7fff; // rad/s
    speed_v = speed_v / tupd;
    return speed_v;
}
