#include "bldcMotor.h"
#include "foc_utils.h"
#include "mt6701.h"
#include "voltage.h"
#include "current.h"
#include "time_utils.h"
#include "as5407.h"
BldcMotor motor1;

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c);
static void getElecAngle1(BldcMotor *motor);

void motorInit()
{
    motor1.pole_pairs = 7;
    motor1.setPwm = setPwm1;
    motor1.getShaftAngle = as5047GetRawAngle;
    motor1.zeroElectricAngleOffSet = 0;
    getZeroElecAngle(&motor1);

    getElecAngle(&motor1); // 观察电角度是否为0
    FOC_log("[zeroAngleOffset,zeroAngle]:%f,%f\r\n", motor1.zeroElectricAngleOffSet, motor1.angle_el);
}

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c)
{
    TIM1->CCR1 = a;
    TIM1->CCR2 = b;
    TIM1->CCR3 = c;
}

void getZeroElecAngle(BldcMotor *motor)
{
    setPhaseVoltage(motor, 0.0f, 2.0f, 0.0f);
    delay(1000);
    getElecAngle(motor);
    motor->zeroElectricAngleOffSet = motor->angle_el; // 测量电角度零位偏差
}

void getElecAngle(BldcMotor *motor)
{
    motor->angle_el = _normalizeAngle(motor->pole_pairs * motor->getShaftAngle() - motor->zeroElectricAngleOffSet);
}

void foc(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b)
{

    static bool calibrateOffset;

    if (!calibrateOffset)
    {
        getCurrentOffsets(&motor1, adc_a, adc_b, 100);
        calibrateOffset = 1;
    }
    else
    {
        getElecAngle(motor);
        getPhaseCurrents(motor, adc_a, adc_b);
        getABCurrents(motor);
        getDQCurrents(motor);
        getDQVoltages(motor);
        getABVoltages(motor);
        setSVPWM(motor);
    }
}
