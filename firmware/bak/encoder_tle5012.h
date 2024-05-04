#ifndef __ENCODER_TLE5012_H__
#define __ENCODER_TLE5012_H__

#include "../encoder_base.h"

// declare sensor relative interface
#define READ_ANGLE_VALUE 0x8020 // 8020
#define READ_SPEED_VALUE 0x8030 // 8030

class EncoderAS5047Base : public EncoderBase
{
public:
    EncoderAS5047Base()
    {
        countPerRotary = 32768;
    }

    float getRawAngle();
    float getVelocity();

protected:
    virtual uint16_t SpiTransmitAndRead16Bits(uint16_t _dataTx) = 0;
    virtual void spiSelect() = 0;
    virtual void spiUnselect() = 0;

private:
    uint16_t getRawData();
    uint16_t countPerRotary;
};

#endif
