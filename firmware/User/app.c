
#include "app.h"
#include "led.h"
#include "key.h"
#include "comm.h"
#include "mt6701.h"
#include "as5407.h"
#include "focMotor.h"
#include "encoder.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "current.h"
static DevState devState;
static KeyState keyState;
static uchar flashCnt;
static void txDataProcess();
float txA, txB, txC;
static FocMotor motor1;
float target;

static void standingBy();
static void working(void);
static void updatePwm1(unsigned short int a, unsigned short int b, unsigned short int c);
static void startPwm1();
static void stopPwm1();

static void startPwm1()
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
}
static void stopPwm1()
{
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
}

static void updatePwm1(unsigned short int a, unsigned short int b, unsigned short int c)
{
    TIM1->CCR1 = a;
    TIM1->CCR2 = b;
    TIM1->CCR3 = c;
}
// should be called before interruption enabled
static void motorInit()
{
    motor1.pole_pairs = 7;
    // motor1.startPwm = startPwm1;
    // motor1.stopPwm = stopPwm1;
    motor1.updatePwm = updatePwm1;
    motor1.zeroElectricAngleOffSet = 0;
    motor1.Ts = 100 * 1e-6f;
    motor1.torqueType = CURRENT;
    motor1.controlType = TORQUE;
    encoderInit(&motor1.magEncoder, motor1.Ts, MT6701_GetRawAngle);
    motor1.velocity_limit = 200.0f;
    //    motor1.startPwm();
    setZeroElecAngle(&motor1);
    // motor1.stopPwm();
    pidInit(&motor1.currentLoopPID, 5, 200, 0, 100000, 12.4, motor1.Ts);
    lpfInit(&motor1.IqFilter, 0.05, motor1.Ts);
    encoderUpdate(&motor1.magEncoder);
    getElecAngle(&motor1);

    FOC_log("[zeroAngleOffset]:%f\r\n", motor1.zeroElectricAngleOffSet);
    FOC_log("[zeroAngle]:%f\r\n", motor1.angle_el);
    // while (1)
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    //     delay(1000);
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
    //     encoderUpdate(&motor1.magEncoder);
    //     getElecAngle(&motor1); // 观察电角度是否为0
    //     FOC_log("[zeroAngleOffset]:%f\r\n", motor1.zeroElectricAngleOffSet);
    //     FOC_log("[zeroAngle]:%f\r\n", motor1.angle_el);
    // }
}
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
    if (keyState == USER3_SHORT)
    {
        WORK_INIT;
    }
}

static void working(void)
{
    if (flashCnt < 5)
        led2On = 1;

    if (keyState == USER3_SHORT)
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
    float goalTorqueV = Vpoten / 4095.0f * UqMAX;
    float goalTorqueC = Vpoten / 4095.0f * CURRENT_MAX;
    adc_vbus = HAL_ADC_GetValue(&hadc2);
    Vbus = adc_vbus * 3.3f / 4096 * 26;

    if (motor1.controlType == VELOCITY || motor1.controlType == VELOCITY_OPEN_LOOP)
    {
        target = goalVelocity;
        sprintf(txBuffer, "goalVelocity:%f angle:%f, velocity:%f\n", goalVelocity, motor1.magEncoder.fullAngle, motor1.magEncoder.velocity);
    }
    else if (motor1.controlType == TORQUE)
    {
        if (motor1.torqueType == VOLTAGE)
        {
            target = goalTorqueV;
            sprintf(txBuffer, "goalTorqueV:%f angle:%f, velocity:%f\n", goalTorqueV, motor1.magEncoder.fullAngle, motor1.magEncoder.velocity);
        }
        else
        {
            target = goalTorqueC;
            sprintf(txBuffer, "goalTorqueC:%f angle:%f, velocity:%f\n", goalTorqueC, motor1.magEncoder.fullAngle, motor1.magEncoder.velocity);
            // sprintf(txBuffer, "eAngle:%f\n", motor1.angle_el);
        }
    }
    // float velocity = motor1.getVelocity(100);
    // sprintf(txBuffer, " velocity: %f\n", motor1.magEncoder.velocity);

    // float x = 100 * 1e-3f;
    // sprintf(txBuffer, " x: %f\n", x);
}
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc == &hadc1)
    {
        static bool gotCurrentOffset;
        if (!gotCurrentOffset)
        {
            getCurrentOffsets(&motor1, hadc1.Instance->JDR1, hadc2.Instance->JDR1, 100);
            gotCurrentOffset = 1;
        }
        if (devState == WORK)
            foc(&motor1, hadc1.Instance->JDR1, hadc2.Instance->JDR1);

        dealPer100us();

#if SHOW_WAVE
        load_data[0] = motor1.d1;
        load_data[1] = motor1.d2;
        load_data[2] = motor1.d3;
        // load_data[0] = motor1.Ialpha;
        // load_data[1] = motor1.Ibeta;

        load_data[3] = motor1.Iq;
        load_data[4] = motor1.Id;
        // load_data[3] = motor1.offset_ia;
        // load_data[4] = motor1.offset_ib;

        memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
        HAL_UART_Transmit_DMA(&huart3, (uint8_t *)tempData, 6 * 4);
#endif
    }
}
