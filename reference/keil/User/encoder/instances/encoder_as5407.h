#ifndef __AS5407_H
#define __AS5407_H

#include "../encoder_base.h"

class EncoderAS5047Base : public EncoderBase
{
public:
    const static uint8_t RESOLUTION_BITS = 14;
    const static uint16_t COUNT_PER_ROTATE = 16384;
    const static uint16_t ANGLE_REG = 0x3FFF;
    const static uint8_t COMMAND_PARITY_BIT = 15;
    const static uint8_t COMMAND_RW_BIT = 14;
    const static uint8_t DATA_START_BIT = 13;
    const static uint16_t DATA_MASK = 0xFFFF >> (16 - RESOLUTION_BITS);

    EncoderAS5047Base() = default;

    void Init();
    //  uint16_t GetRawData();

private:
    float GetRawAngle();
    uint16_t GetRawData();
    uint8_t SpiCalcEvenParity(uint16_t value);

    /***** Platform Specified Implements *****/
    virtual void SpiInit() = 0;
    virtual uint16_t SpiTransmitAndRead16Bits(uint16_t _dataTx) = 0;
};
#endif
