#include "focMotor.h"
#include "math_utils.h"
#include "mt6701.h"
#include "voltage.h"
#include "current.h"
#include "time_utils.h"
#include "as5407.h"
#include "comm.h"
#include "encoder.h"
FocMotor motor1;
float target;
static void updatePwm1(unsigned short int a, unsigned short int b, unsigned short int c);
static void getElecAngle1(FocMotor *motor);
static void startPwm1();
static void stopPwm1();

// should be called before interruption enabled
void motorInit()
{
    motor1.pole_pairs = 7;
    motor1.startPwm = startPwm1;
    motor1.stopPwm = stopPwm1;
    motor1.updatePwm = updatePwm1;
    motor1.zeroElectricAngleOffSet = 0;
    motor1.Ts = 100 * 1e-6f;
    motor1.torqueType = VOLTAGE;
    motor1.controlType = VELOCITY_OPEN_LOOP;
    encoderInit(&motor1.magEncoder, motor1.Ts, MT6701_GetRawAngle);

    motor1.startPwm();
    setZeroElecAngle(&motor1);
    motor1.stopPwm();

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

void setZeroElecAngle(FocMotor *motor)
{
    setPhaseVoltage(motor, 0.0f, 2.0f, 0.0f);
    delay(1500);
    setPhaseVoltage(motor, 0.0f, 0.0f, 0.0f);
    encoderUpdate(&motor->magEncoder);
    motor->zeroElectricAngleOffSet = _normalizeAngle(motor->pole_pairs * motor->magEncoder.shaftAngle); // 测量电角度零位偏差
}

void getElecAngle(FocMotor *motor)
{
    motor->angle_el = _normalizeAngle(motor->pole_pairs * motor->magEncoder.shaftAngle - motor->zeroElectricAngleOffSet);
}

static float velocityOpenloop(FocMotor *motor, float target_velocity);

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
        getPhaseCurrents(motor, adc_a, adc_b);
        // static float elecAngle;
        // elecAngle += 0.01;

        // if (elecAngle >= _2PI)
        //     elecAngle = 0;

        // setPhaseVoltage(motor, 2, 0, elecAngle);

        encoderUpdate(&motor->magEncoder);
        getVelocity(&motor->magEncoder);
        getElecAngle(motor);
        switch (motor->controlType)
        {
        case VELOCITY_OPEN_LOOP:
            // 开环速度函数
            velocityOpenloop(motor, target);
        }

        // getABCurrents(motor);
        // getDQCurrents(motor);
        // getDQVoltages(motor);
        // getABVoltages(motor);
        // setSVPWM(motor);

#if SHOW_WAVE

        load_data[0] = motor1.d1;
        load_data[1] = motor1.d2;
        load_data[2] = motor1.d3;
        // load_data[0] = motor->offset_ia;
        // load_data[1] = motor->offset_ib;
        // load_data[3] = motor1.Ia;
        load_data[4] = motor1.Ib;
        memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
        HAL_UART_Transmit_DMA(&huart3, (uint8_t *)tempData, 6 * 4);
#endif
    }
}

static float velocityOpenloop(FocMotor *motor, float target_velocity)
{
    static float shaft_angle;
    //   通过乘以时间间隔和目标速度来计算需要转动的机械角度，存储在 shaft_angle 变量中。在此之前，还需要对轴角度进行归一化，以确保其值在 0 到 2π 之间。
    shaft_angle = _normalizeAngle(shaft_angle + target_velocity * motor->Ts);
    // 以目标速度为 10 rad/s 为例，如果时间间隔是 1 秒，则在每个循环中需要增加 10 * 1 = 10 弧度的角度变化量，才能使电机转动到目标速度。
    // 如果时间间隔是 0.1 秒，那么在每个循环中需要增加的角度变化量就是 10 * 0.1 = 1 弧度，才能实现相同的目标速度。因此，电机轴的转动角度取决于目标速度和时间间隔的乘积。
    load_data[3] = shaft_angle;
    float Uq = U_DC / 3;
    if (motor->torqueType == VOLTAGE)
    {
        setPhaseVoltage(motor, Uq, 0, _electricalAngle(shaft_angle, 7));
    }
    else // CURRENT
    {
    }
}
