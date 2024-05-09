
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
#include "userTimer.h"
static DevState devState;
static KeyState keyState;
static uchar flashCnt;
float load_data[7];
uint8_t tempData[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x7F};

float txA, txB, txC;
static FocMotor motor1;

static void standingBy();
static void working(void);
static void updatePwm1(unsigned short int a, unsigned short int b, unsigned short int c);

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

    motor1.updatePwm = updatePwm1;
    motor1.zeroElectricAngleOffSet = 0;
    motor1.Ts = 100 * 1e-6f;
    motor1.torqueType = CURRENT;
    motor1.controlType = TORQUE;
    motor1.state = MOTOR_CALIBRATE;
    encoderInit(&motor1.magEncoder, motor1.Ts, MT6701_GetRawAngle);

    if (motor1.controlType == TORQUE && motor1.torqueType == CURRENT)
        pidInit(&motor1.currentPID, 5, 200, 0, 100000, 12.4, motor1.Ts);
    else if (motor1.controlType == VELOCITY && motor1.torqueType == CURRENT)
    {
        pidInit(&motor1.currentPID, 0.5, 50, 0, 100000, 12.4, motor1.Ts);
        pidInit(&motor1.velocityPID, 3, 2, 0, 100000, 0.5, motor1.Ts);
    }
    else if (motor1.controlType == ANGLE && motor1.torqueType == CURRENT)
    {

        pidInit(&motor1.currentPID, 5, 200, 0, 100000, 12.4, motor1.Ts);
        pidInit(&motor1.velocityPID, 0.02, 1, 0, 100000, 0.5, motor1.Ts);
        pidInit(&motor1.anglePID, 1, 0, 0, 100000, 30, motor1.Ts);

        // pidInit(&motor1.currentPID, 1.25, 50, 0, 100000, 12.4, motor1.Ts);
        // pidInit(&motor1.anglePID, 0.5, 0, 0.003, 100000, 0.2, motor1.Ts);
    }

    lpfInit(&motor1.IqFilter, 0.05, motor1.Ts);

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
    commander_run(&motor1);
    if (++flashCnt >= 10)
        flashCnt = 0;

    led1On = 0;
    led2On = 0;

    uint32_t Vpoten, adc_vbus;
    float Vbus, goalVelocity;
    HAL_ADC_Start(&hadc1);
    HAL_ADC_Start(&hadc2);
    Vpoten = HAL_ADC_GetValue(&hadc1);

    goalVelocity = Vpoten / 4095.0f * MAX_VELOCITY;
    float goalTorqueV = Vpoten / 4095.0f * UqMAX;
    float goalTorqueC = Vpoten / 4095.0f * CURRENT_MAX;
    adc_vbus = HAL_ADC_GetValue(&hadc2);
    Vbus = adc_vbus * 3.3f / 4096 * 26;

    if (motor1.controlType == VELOCITY)
    {
        motor1.target = goalVelocity;
    }
    else if (motor1.controlType == TORQUE)
    {
        if (motor1.torqueType == VOLTAGE)
        {
            motor1.target = goalTorqueV;
        }
        else
        {
            motor1.target = goalTorqueC;
        }
    }
    else if (motor1.controlType == ANGLE)
    {
        // motor1.target = Vpoten;
    }

    switch (devState)
    {
    case STANDBY:
        standingBy();
        break;

    case WORK:
        working();
        break;
    }

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
        //     if (bldcMotor.focTarget == 0)
        //     {
        //         bldcMotor.focTarget = 23;
        //     }
        //     else if (bldcMotor.focTarget == 23)
        //     {
        //         bldcMotor.focTarget = -23;
        //     }
        //     else if (bldcMotor.focTarget == -23)
        //     {
        //         bldcMotor.focTarget = 23;
        //     }
        // }
    }
}

void txDataProcess()
{
    sprintf(txBuffer, "target:%f fullAngle:%f, velocity:%f\n", motor1.target, motor1.magEncoder.fullAngle, motor1.magEncoder.velocity);

    // sprintf(txBuffer, "offset_ia:%f offset_ib:%f, Ia:%f, Ib:%f\n", motor1.offset_ia, motor1.offset_ib, motor1.Ia, motor1.Ib);
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, GPIO_PIN_SET);
    if (hadc == &hadc1)
    {
        // static bool gotCurrentOffset;
        // if (!gotCurrentOffset)
        // {
        //     getCurrentOffsets(&motor1, hadc1.Instance->JDR1, hadc2.Instance->JDR1, 100);
        //     getZeroElecAngle(&motor1);
        //     encoderUpdate(&motor1.magEncoder);
        //     getElecAngle(&motor1);
        //     FOC_log("[zeroAngleOffset]:%f  [zeroAngle]:%f\r\n", motor1.zeroElectricAngleOffSet, motor1.angle_el);
        //     gotCurrentOffset = 1;
        // }
        // if (devState == WORK)
        foc(&motor1, hadc1.Instance->JDR1, hadc2.Instance->JDR1);

        dealPer100us();

#if SHOW_WAVE
        // load_data[0] = motor1.d1;
        // load_data[1] = motor1.d2;
        // load_data[2] = motor1.d3;
        // load_data[3] = motor1.Uq;
        // load_data[4] = motor1.Iq;
        // load_data[5] = motor1.magEncoder.velocity;

        // load_data[0] = motor1.Ia;
        // load_data[1] = motor1.Ib;

        load_data[0] = hadc1.Instance->JDR1;
        load_data[1] = hadc2.Instance->JDR1;
        load_data[2] = hadc1.Instance->JDR2;

        load_data[3] = motor1.Ialpha;
        load_data[4] = motor1.Ibeta;

        load_data[5] = motor1.Id;
        load_data[6] = motor1.Iq;

        memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
        HAL_UART_Transmit_DMA(&huart3, (uint8_t *)tempData, 8 * 4);
#endif
    }
    HAL_GPIO_WritePin(TEST_GPIO_Port, TEST_Pin, GPIO_PIN_RESET);
}
