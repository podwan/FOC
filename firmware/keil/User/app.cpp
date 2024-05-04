
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

Encoder encoder(&hspi1, 100);

void appInit()
{
    encoder.Init();
    encoder.Update();
}

void appRunning()
{

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

static void txDataProcess()
{
    // uint val;
    uint angle;

    // val = Read_Form_AS5047P(ANGLECOM_ADDR);
    // angle = (double)val * 360.0 / 16384.0;
    //  angle = AS5047_read(ANGLECOM);
    //  sprintf(txBuffer, "%d\n", angle);
    //  sprintf(txBuffer, "AS5047P = %u %.2f\n", val, angle);

    // x = 0;
    // HAL_SPI_Transmit(&hspi1, &x, 1, 1000);
    // sprintf(txBuffer, "hello\n");
    // sprintf(txBuffer, "%d\n", encoder.GetRawData());
    //  sprintf(txBuffer, "%d,%f\n", GetRawData(), getRawAngle());
    sprintf(txBuffer, "fullAngle: %f, velocity: %f\n");
    // sprintf(txBuffer, "txA: %f, txB: %f, txC: %f\n", txA, txB, txC);

    // sprintf(txBuffer, "velocity: %f\n", encoder.GetLapAngle());
}
