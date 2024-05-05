#include "focMotor.h"
#include "math_utils.h"
#include "mt6701.h"
#include "voltage.h"
#include "current.h"
#include "time_utils.h"
#include "as5407.h"
#include "comm.h"
FocMotor motor1;

static void updatePwm1(unsigned short int a, unsigned short int b, unsigned short int c);
static void getElecAngle1(FocMotor *motor);
static void startPwm1();
static void stopPwm1();
void motorInit()
{
    motor1.pole_pairs = 7;
    motor1.startPwm = startPwm1;
    motor1.stopPwm = stopPwm1;
    motor1.updatePwm = updatePwm1;
    motor1.getShaftAngle = MT6701_GetRawAngle;
    motor1.zeroElectricAngleOffSet = 0;

    motor1.startPwm();
    getZeroElecAngle(&motor1);
    // motor1.stopPwm();
    getElecAngle(&motor1); // 观察电角度是否为0
                           //   log_DMA_TX("[zeroAngleOffset,zeroAngle]:%f,%f\r\n", motor1.zeroElectricAngleOffSet, motor1.angle_el);
    FOC_log("[zeroAngleOffset]:%f\r\n", motor1.zeroElectricAngleOffSet);
    FOC_log("[zeroAngle]:%f\r\n", motor1.angle_el);
    // while (1)
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    //     delay(1000);
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

    //     getElecAngle(&motor1); // 观察电角度是否为0
    //     FOC_log("[zeroAngleOffset]:%f\r\n", motor1.zeroElectricAngleOffSet);
    //     FOC_log("[zeroAngle]:%f\r\n", motor1.angle_el);
    // }
}

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

void getZeroElecAngle(FocMotor *motor)
{
    setPhaseVoltage(motor, 0.0f, 2.0f, 0.0f);
    delay(500);
    setPhaseVoltage(motor, 0.0f, 0.0f, 0.0f);
    // getElecAngle(motor);
    motor->zeroElectricAngleOffSet = _normalizeAngle(motor->pole_pairs * motor->getShaftAngle()); // 测量电角度零位偏差
}

void getElecAngle(FocMotor *motor)
{
    motor->angle_el = _normalizeAngle(motor->pole_pairs * motor->getShaftAngle() - motor->zeroElectricAngleOffSet);
}

void foc(FocMotor *motor, uint32_t adc_a, uint32_t adc_b)
{

    static bool calibrateOffset;

    if (!calibrateOffset)
    {
        getCurrentOffsets(&motor1, adc_a, adc_b, 100);
        calibrateOffset = 1;
    }
    else
    {

        static float elecAngle;
        elecAngle += 0.01;
        if (elecAngle >= _2PI)
            elecAngle = 0;
        setPhaseVoltage(&motor1, 2, 0, elecAngle);

        // getElecAngle(motor);
        getPhaseCurrents(motor, adc_a, adc_b);
        // getABCurrents(motor);
        // getDQCurrents(motor);
        // getDQVoltages(motor);
        // getABVoltages(motor);
        // setSVPWM(motor);

#if SHOW_WAVE

        load_data[0] = motor1.d1;
        load_data[1] = motor1.d2;
        load_data[2] = motor1.d3;
        load_data[3] = motor1.Ia;
        load_data[4] = motor1.Ib;
        memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
        HAL_UART_Transmit_DMA(&huart3, (uint8_t *)tempData, 6 * 4);
#endif
    }
}
