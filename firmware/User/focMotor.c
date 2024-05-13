#include "focMotor.h"
#include "math_utils.h"
#include "mt6701.h"
#include "voltage.h"
#include "current.h"
#include "time_utils.h"
#include "comm.h"
#include "encoder.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "app.h"

void getZeroElecAngle(FocMotor *motor)
{
    setTorque(motor, 0.0f, U_DC / 4, 0.0f);
    delay(500);
    encoderUpdate(&motor->magEncoder);
    motor->zeroElectricAngleOffSet = _normalizeAngle(motor->pole_pairs * motor->magEncoder.shaftAngle); // 测量电角度零位偏差
    setTorque(motor, 0.0f, 0.0f, 0.0f);
}

void getElecAngle(FocMotor *motor)
{
    motor->angle_el = _normalizeAngle(motor->pole_pairs * motor->magEncoder.shaftAngle - motor->zeroElectricAngleOffSet);
}

void foc(FocMotor *motor, uint32_t adc_a, uint32_t adc_b)
{
    if (motor->state == MOTOR_CALIBRATE)
    {
        getCurrentOffsets(motor, adc_a, adc_b, 100);
        FOC_log("[offset_ia]:%f  [offset_ib]:%f\r\n", motor->offset_ia, motor->offset_ib);
        getZeroElecAngle(motor);
        encoderUpdate(&motor->magEncoder);
        getElecAngle(motor);
        FOC_log("[zeroAngleOffset]:%f  [zeroAngle]:%f\r\n", motor->zeroElectricAngleOffSet, motor->angle_el);
        motor->stopPwm();
        motor->state = MOTOR_READY;
    }
    else
    {
        float IqRef;
        float velocityErr, angleErr;

        getPhaseCurrents(motor, adc_a, adc_b);
        getABCurrents(motor);
        getDQCurrents(motor);
        motor->Iq = lpfOperator(&motor->IqFilter, motor->Iq);

        encoderUpdate(&motor->magEncoder);
        motor->magEncoder.velocity = lpfOperator(&motor->velocityFilter, motor->magEncoder.velocity);
        getElecAngle(motor);

        if (motor->state == MOTOR_START)
        {
            switch (motor->controlType)
            {
            // case TORQUE:

            //     // motor->Ud = pidOperator(&motor->pidId, 0 - motor->Id);
            //     motor->Uq = pidOperator(&motor->pidIq, motor->target - motor->Iq);
            //     // motor->Uq = 3;
            //     break;
            case VELOCITY_OPEN_LOOP: // 用于验证setTorque（SVPWM)函数及编码器测速（驱动）方向
                static float shaftAngle;
                shaftAngle = _normalizeAngle(shaftAngle + motor->target * motor->Ts);
                motor->angle_el = _electricalAngle(shaftAngle, motor->pole_pairs);
                motor->Uq = -U_DC / 4;
                break;
            case VELOCITY:
                if (motor->torqueType == VOLTAGE)
                {
                    velocityErr = motor->target - motor->magEncoder.velocity;
                    motor->Uq = pidOperator(&motor->velocityPID, velocityErr);
                }
                else
                {
                    velocityErr = (motor->target - motor->magEncoder.velocity) * 180 / _PI;
                    IqRef = pidOperator(&motor->velocityPID, velocityErr);
                    motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
                }
                // setTorque(motor, motor->Uq, 0, motor->angle_el);
                break;

            case ANGLE:
                if (motor->torqueType == VOLTAGE)
                {
                    angleErr = motor->target - motor->magEncoder.fullAngle;
                    motor->Uq = pidOperator(&motor->anglePID, angleErr);
                }
                else
                {
                    float velocityRef = pidOperator(&motor->anglePID, motor->target - motor->magEncoder.fullAngle);
                    velocityErr = (velocityRef - motor->magEncoder.velocity) * 180 * _PI;
                    IqRef = pidOperator(&motor->velocityPID, velocityErr);
                    motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
                }
                // IqRef = pidOperator(&motor->anglePID, motor->target - motor->magEncoder.fullAngle);
                // motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);

                break;
            }

            setTorque(motor, motor->Uq, 0, motor->angle_el);
        }
    }
}
