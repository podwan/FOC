#ifndef CTRL_STEP_FW_AS5047_M0_STM32_H
#define CTRL_STEP_FW_AS5047_M0_STM32_H

#include "encoder/instances/encoder_as5407.h"

#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
// declare MCU relative interface
class Encoder : public EncoderAS5047Base
{
public:
    Encoder(SPI_HandleTypeDef *_spi, uint32_t period) : EncoderAS5047Base()
    {
        spiHandle = _spi;
        updatePeriod = period;
    }

    SPI_HandleTypeDef *spiHandle = nullptr;

private:
    uint16_t SpiTransmitAndRead16Bits(uint16_t _data);
    void spiSelect();
    void spiUnselect();
    void SpiInit() ;

};

#endif
