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

void goToZeroElecAngle(FocMotor *motor)
{
    setTorque(motor, 0, OPEN_LOOP_TORQUE, 0);
    delay(700);
}
void alignSensor(FocMotor *motor)
{
    for (int i = 0; i <= 500; i++)
    {
        float angle = _3PI_2 + _2PI * i / 500.0f;
        setTorque(motor, OPEN_LOOP_TORQUE, 0, angle);
        encoderUpdate(&motor->magEncoder);
        delay(2);
    }
    encoderUpdate(&motor->magEncoder);
    float mid_angle = motor->magEncoder.fullAngle;
    // move one electrical revolution backwards
    for (int i = 500; i >= 0; i--)
    {
        float angle = _3PI_2 + _2PI * i / 500.0f;
        setTorque(motor, OPEN_LOOP_TORQUE, 0, angle);
        encoderUpdate(&motor->magEncoder);
        delay(2);
    }
    encoderUpdate(&motor->magEncoder);
    float end_angle = motor->magEncoder.fullAngle;
    // setPhaseVoltage(0, 0, 0);
    delay(200);

    // determine the direction the sensor moved
    float moved = fabs(mid_angle - end_angle);
    if (moved < MIN_ANGLE_DETECT_MOVEMENT)
    { // minimum angle to detect movement
        FOC_log("Failed to notice movement\n");
        return 0; // failed calibration
    }
    else if (mid_angle < end_angle)
    {
        FOC_log("sensor_direction==CCW\n");
        motor->magEncoder.direction = CCW;
    }
    else
    {
        FOC_log("sensor_direction==CW\n");
        motor->magEncoder.direction = CW;
    }
    // check pole pair number
    bool pp_check_result = !(fabs(moved * motor->pole_pairs - _2PI) > 0.5f); // 0.5f is arbitrary number it can be lower or higher!
    if (pp_check_result == false)
    {
        FOC_log("PP check: fail - estimated pp: \n", _2PI / moved);
    }
    else
    {
        FOC_log("PP check: OK!\n");
    }

    // align the electrical phases of the motor and sensor
    // set angle -90(270 = 3PI/2) degrees
    goToZeroElecAngle(motor);
    // read the sensor
    encoderUpdate(&motor->magEncoder);
    // get the current zero electric angle
    motor->zeroElectricAngleOffSet = 0;
    getElecAngle(motor);
    motor->zeroElectricAngleOffSet = motor->angle_el;
    // zero_electric_angle =  _normalizeAngle(_electricalAngle(sensor_direction*sensor->getAngle(), pole_pairs));
    // delay(20);
    // encoderUpdate(&motor->magEncoder);
    getElecAngle(motor);
    // motor->zeroElectricAngleOffSet = 0;
    // FOC_log("[zeroAngleOffset]:%f  [zeroAngle]:%f\r\n", motor->zeroElectricAngleOffSet, motor->angle_el);
    FOC_log("[zeroAngleOffset]:%f\n", motor->zeroElectricAngleOffSet);
    FOC_log("[zeroAngle]:%f\n", motor->angle_el);
    // // make sure the angle_el is about zero
  
    // delay(200);
}

void getElecAngle(FocMotor *motor)
{
    motor->angle_el = _normalizeAngle(motor->magEncoder.direction * motor->pole_pairs * motor->magEncoder.shaftAngle - motor->zeroElectricAngleOffSet);
}

void foc(FocMotor *motor, uint32_t adc_a, uint32_t adc_b)
{

    if (motor->state == MOTOR_CALIBRATE)
    {
        getCurrentOffsets(motor, adc_a, adc_b, 100);
        alignSensor(motor);
        motor->state = MOTOR_READY;
        motor->stopPwm();
    }
    else
    {

        float IqRef;
        float velocityErr, angleErr;

        getPhaseCurrents(motor, adc_a, adc_b);
        getABCurrents(motor);
        getDQCurrents(motor);
        motor->Iq = lpfOperator(&motor->IqFilter, motor->Iq);
        motor->Id = lpfOperator(&motor->IdFilter, motor->Id);
        encoderUpdate(&motor->magEncoder);
        motor->magEncoder.velocity = lpfOperator(&motor->velocityFilter, motor->magEncoder.velocity);

        getElecAngle(motor);

        if (motor->state == MOTOR_READY)
        {
            // if (zeroReset == 0)
            // {
            //     zeroReset = 1;
            //     setTorque(motor, 0, OPEN_LOOP_TORQUE, 0);
            // }
            // else
            // {
            //     motor->stopPwm();
            // }
        }
        else if (motor->state == MOTOR_START)
        {

            switch (motor->controlType)
            {
            case TORQUE:

                if (motor->torqueType == VOLTAGE)
                {
                    motor->Uq = motor->target;
                }
                else
                {
                    // motor->Uq = 0;
                    // motor->Ud = pidOperator(&motor->pidId, motor->target - motor->Id);
                    motor->Ud = pidOperator(&motor->pidId, 0 - motor->Id);
                    motor->Uq = pidOperator(&motor->pidIq, motor->target - motor->Iq);
                }
                break;
            case VELOCITY_OPEN_LOOP: // 用于验证setTorque（SVPWM)函数及编码器测速（驱动）方向
                static float shaftAngle;
                shaftAngle = _normalizeAngle(shaftAngle + motor->target * motor->Ts);
                motor->angle_el = _electricalAngle(shaftAngle, motor->pole_pairs);
                motor->Uq = OPEN_LOOP_TORQUE;
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
                    //                    motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
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
                    //                    motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
                }
                // IqRef = pidOperator(&motor->anglePID, motor->target - motor->magEncoder.fullAngle);
                // motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);

                break;
            }
            setTorque(motor, motor->Uq, motor->Ud, motor->angle_el);
        }
        // setTorque(motor, OPEN_LOOP_TORQUE, 0, _3PI_2);
    }
}
