
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
    commander_run();
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
    // setZeroElecAngle(&motor1);
    // getElecAngle(&motor1);
    // float rawAngle = MT6701_GetRawAngle();
    //  sprintf(txBuffer, " rawAnle: %f\n", rawAngle);
    // sprintf(txBuffer, "zeroAngle: %f, rawAngle: %f\n", motor1.zeroElectricAngleOffSet, motor1.angle_el);
    // sprintf(txBuffer, "rawData: %u, rawAnle: %f, fullAngle: %f\n", rawData, rawAngle, fullAngle);
    // sprintf(txBuffer, "rawAnle: %f, eAngle: %f\n", rawAngle, motor1.angle_el);

    // sprintf(txBuffer, " offset_ia: %f, offset_ib: %f\n", motor1.offset_ia, motor1.offset_ib);

    uint32_t Vpoten, adc_vbus;
    float Vbus, goalVelocity;
    HAL_ADC_Start(&hadc1);
    HAL_ADC_Start(&hadc2);
    Vpoten = HAL_ADC_GetValue(&hadc1);
    goalVelocity = Vpoten / 4095.0f * GET_MAX_VELOCITY(MOTOR1_MAX_RPM);
    adc_vbus = HAL_ADC_GetValue(&hadc2);
    Vbus = adc_vbus * 3.3f / 4096 * 26;
    sprintf(txBuffer, "Vpoten: %u,goalVelocity:%f Vbus:%f\n", Vpoten, goalVelocity, Vbus);
    target = goalVelocity;

    // float velocity = motor1.getVelocity(100);
    sprintf(txBuffer, " velocity: %f\n", motor1.magEncoder.velocity);

    // float x = 100 * 1e-3f;
    // sprintf(txBuffer, " x: %f\n", x);
}
