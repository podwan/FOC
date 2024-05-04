#include "encoder.h"

// void Encoder::spiSelect()
// {
//     CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select
// }
// void Encoder::spiUnselect()
// {
//     CS_GPIO_Port->BSRR = CS_Pin;
// }

void Encoder::SpiInit()
{
    MX_SPI1_Init();
}

uint16_t Encoder::SpiTransmitAndRead16Bits(uint16_t _dataTx)
{
    CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select
                                                  // AS5407P_CS_L // cs拉低
    uint16_t rxdata;

    if (HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)&_dataTx, (uint8_t *)&rxdata, 1, 1000) != HAL_OK)
        rxdata = 0;
    //   AS5407P_CS_H // cs拉高 return rxdata;

    CS_GPIO_Port->BSRR = CS_Pin;
    return rxdata;
}
