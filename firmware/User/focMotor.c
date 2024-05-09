#include "focMotor.h"
#include "math_utils.h"
#include "mt6701.h"
#include "voltage.h"
#include "current.h"
#include "time_utils.h"
#include "as5407.h"
#include "comm.h"
#include "encoder.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "app.h"

void getZeroElecAngle(FocMotor *motor)
{
    setTorque(motor, 0.0f, 2.0f, 0.0f);
    delay(1000);
    setTorque(motor, 0.0f, 0.0f, 0.0f);
    encoderUpdate(&motor->magEncoder);
    motor->zeroElectricAngleOffSet = _normalizeAngle(motor->pole_pairs * motor->magEncoder.shaftAngle); // 测量电角度零位偏差
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
        motor->state = MOTOR_READY;
    }
    else
    {
        getPhaseCurrents(motor, adc_a, adc_b);
        getABCurrents(motor);
        getDQCurrents(motor);
        motor->Iq = lpfOperator(&motor->IqFilter, motor->Iq);

        encoderUpdate(&motor->magEncoder);
        getVelocity(&motor->magEncoder);
        getElecAngle(motor);
        float IqRef;
        if (motor->state == MOTOR_START)
        {
            switch (motor->controlType)
            {
            case TORQUE:
                if (motor->torqueType == VOLTAGE)
                {
                    motor->Uq = motor->target;
                    // motor->Uq = UqMAX;
                }
                else // CURRENT
                {
                    motor->Uq = pidOperator(&motor->currentPID, motor->target - motor->Iq);
                    // setTorque(motor, motor->Uq, 0, motor->angle_el);
                }
                break;

            case VELOCITY:
                float velocityErr = (motor->target - motor->magEncoder.velocity) * 180 * _PI;
                IqRef = pidOperator(&motor->velocityPID, velocityErr);
                motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
                // setTorque(motor, motor->Uq, 0, motor->angle_el);
                break;

            case ANGLE:

                float velocityRef = pidOperator(&motor->anglePID, motor->target - motor->magEncoder.fullAngle);
                velocityErr = (velocityRef - motor->magEncoder.velocity) * 180 * _PI;
                IqRef = pidOperator(&motor->velocityPID, velocityErr);
                motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);

                // IqRef = pidOperator(&motor->anglePID, motor->target - motor->magEncoder.fullAngle);
                // motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);

                break;
            }

            setTorque(motor, motor->Uq, 0, motor->angle_el);
        }
    }
}
