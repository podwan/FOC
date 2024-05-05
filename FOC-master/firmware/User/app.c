
#include "app.h"
#include "led.h"
#include "key.h"
#include "comm.h"
#include "mt6701.h"
#include "focMotor.h"
#include "as5407.h"

static DevState devState;
static KeyState keyState;
static uchar flashCnt;
static void txDataProcess();
float txA, txB, txC;

static void standingBy();
static void working(void);

void appInit()
{
    motorInit();
}

void appRunning()
{

    getKeyState(&keyState);

    if (++flashCnt >= 10)
        flashCnt = 0;

    led1On = 0;
    led2On = 0;

    // switch (devState)
    // {
    // case STANDBY:
    //     standingBy();
    //     break;

    // case WORK:
    //     working();
    //     break;
    // }

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
#include "mt6701.h"
static void txDataProcess()
{

    // uint rawData;
    // float fullAngle;
    // getZeroElecAngle(&motor1);
    // getElecAngle(&motor1);
    // float rawAngle = MT6701_GetRawAngle();
    //  sprintf(txBuffer, " rawAnle: %f\n", rawAngle);
    // sprintf(txBuffer, "zeroAngle: %f, rawAngle: %f\n", motor1.zeroElectricAngleOffSet, motor1.angle_el);
    // sprintf(txBuffer, "rawData: %u, rawAnle: %f, fullAngle: %f\n", rawData, rawAngle, fullAngle);
    // sprintf(txBuffer, "rawAnle: %f, eAngle: %f\n", rawAngle, motor1.angle_el);

    sprintf(txBuffer, " offset_ia: %f, offset_ib: %f\n", motor1.offset_ia, motor1.offset_ib);
}
