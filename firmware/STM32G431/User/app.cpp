
#include "app.h"
#include "led.h"
#include "key.h"
#include "comm.h"
#include "encoder.h"
#include "motor.h"

static DevState devState;
static KeyState keyState;
static uchar flashCnt;
static void txDataProcess();
float txA, txB, txC;

static void standingBy();
static void working(void);

void appRunning()
{
    encoder.update();
    getKeyState(&keyState);

    if (++flashCnt >= 10)
        flashCnt = 0;

    led1On = 0;
    led2On = 0;

    switch (devState)
    {
    case STANDBY:
        standingBy();
        break;

    case WORK:
        working();
        break;
    }

    txDataProcess();

    LED_drive();
}
static void standingBy()
{
    led1On = 1;
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
    if (keyState == USER1_SHORT)
    {
        WORK_INIT;
    }
}

static void working(void)
{
    if (flashCnt < 5)
        led2On = 1;

    if (keyState == USER1_SHORT)
    {
        STANDBY_INIT;
    }
    else if (keyState == USER2_SHORT)
    {
        //  if (bldcMotor.controlMode == VELOCITY)
        // {
        //     if (bldcMotor.target == 0)
        //     {
        //         bldcMotor.target = 23;
        //     }
        //     else if (bldcMotor.target == 23)
        //     {
        //         bldcMotor.target = -23;
        //     }
        //     else if (bldcMotor.target == -23)
        //     {
        //         bldcMotor.target = 23;
        //     }
        // }
    }
}
SPI_HandleTypeDef *spiHandle = &hspi1;

static uint16_t SpiTransmitAndRead16Bits(uint16_t _dataTx)
{
    uint16_t dataRx;
    // CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select
#if 0
    HAL_SPI_TransmitReceive(&hspi1, (uint8_t*) &_dataTx, (uint8_t*) &dataRx, 1, HAL_MAX_DELAY);
#else
    /* Set the transaction information */
    spiHandle->pRxBuffPtr = (uint8_t *)(&dataRx);
    spiHandle->RxXferCount = 1;
    spiHandle->pTxBuffPtr = (uint8_t *)(&_dataTx);
    spiHandle->TxXferCount = 1;
    bool txAvailable = true;

    /* Check if the SPI is already enabled */
    if ((spiHandle->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
        __HAL_SPI_ENABLE(spiHandle);

    /* Transmit and Receive data in 16 Bit mode */
    spiHandle->Instance->DR = *((uint16_t *)spiHandle->pTxBuffPtr);
    spiHandle->pTxBuffPtr += sizeof(uint16_t);
    spiHandle->TxXferCount--;

    while ((spiHandle->TxXferCount > 0U) || (spiHandle->RxXferCount > 0U))
    {
        /* Check TXE flag */
        if ((__HAL_SPI_GET_FLAG(spiHandle, SPI_FLAG_TXE)) &&
            (spiHandle->TxXferCount > 0U) &&
            (txAvailable == 1U))
        {
            spiHandle->Instance->DR = *((uint16_t *)spiHandle->pTxBuffPtr);
            spiHandle->pTxBuffPtr += sizeof(uint16_t);
            spiHandle->TxXferCount--;
            /* Next Data is a reception (Rx). Tx not allowed */
            txAvailable = false;
        }
        /* Check RXNE flag */
        if ((__HAL_SPI_GET_FLAG(spiHandle, SPI_FLAG_RXNE)) && (spiHandle->RxXferCount > 0U))
        {
            *((uint16_t *)spiHandle->pRxBuffPtr) = (uint16_t)spiHandle->Instance->DR;
            spiHandle->pRxBuffPtr += sizeof(uint16_t);
            spiHandle->RxXferCount--;
            /* Next Data is a Transmission (Tx). Tx is allowed */
            txAvailable = true;
        }
    }
#endif
    //  CS_GPIO_Port->BSRR = CS_Pin;
    return dataRx;
}

uint16_t getRawData(void)
{
    uint16_t data;

    CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select

    // TLE5012
    SpiTransmitAndRead16Bits(0x8020); // read

    data = (SpiTransmitAndRead16Bits(0xff) & 0x7fff);
    CS_GPIO_Port->BSRR = CS_Pin;

    return data;
}
float getRawAngle()
{
    return ((float)getRawData() / 32768.0f) * _2PI;
}

static void txDataProcess()
{
    // sprintf(txBuffer, "hello\n");
    // sprintf(txBuffer, "%f\n", encoder.getLapAngle());
    //  sprintf(txBuffer, "%d,%f\n", getRawData(), getRawAngle());
    sprintf(txBuffer, "lapAngle: %f, velocity: %f\n", encoder.getLapAngle(), encoder.getVelocity());
    // sprintf(txBuffer, "txA: %f, txB: %f, txC: %f\n", txA, txB, txC);

    // sprintf(txBuffer, "velocity: %f\n", encoder.getVelocity());
}
