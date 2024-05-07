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

void setZeroElecAngle(FocMotor *motor)
{
    setTorque(motor, 0.0f, 2.0f, 0.0f);
    delay(1500);
    setTorque(motor, 0.0f, 0.0f, 0.0f);
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

    // static bool calibrateOffset;

    // if (!calibrateOffset)
    // {
    //     getCurrentOffsets(motor, adc_a, adc_b, 100);
    //     calibrateOffset = 1;
    // }
    // else
    // {
    getPhaseCurrents(motor, adc_a, adc_b);
    getABCurrents(motor);
    getDQCurrents(motor);
    motor->Iq = lpfOperator(&motor->IqFilter, motor->Iq);
    // static float elecAngle;
    // elecAngle += 0.01;

    // if (elecAngle >= _2PI)
    //     elecAngle = 0;

    // setTorque(motor, 2, 0, elecAngle);

    encoderUpdate(&motor->magEncoder);
    getVelocity(&motor->magEncoder);
    getElecAngle(motor);
    float IqRef;
    switch (motor->controlType)
    {
    case TORQUE:
        if (motor->torqueType == VOLTAGE)
        {
            motor->target = _constrain(motor->target, -UqMAX, UqMAX);
            setTorque(motor, motor->target, 0, motor->angle_el);
        }
        else // CURRENT
        {
            motor->Uq = pidOperator(&motor->currentPID, motor->target - motor->Iq);
            setTorque(motor, motor->Uq, 0, motor->angle_el);
        }
        break;

        // case VELOCITY_OPEN_LOOP:
        //     // 开环速度函数
        //     velocityOpenloop(motor, motor->target);
        //     break;

    case VELOCITY:
        float velocityErr = (motor->target - motor->magEncoder.velocity) * 180 * _PI;
        IqRef = pidOperator(&motor->velocityPID, velocityErr);
        motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
        setTorque(motor, motor->Uq, 0, motor->angle_el);
        break;

    case ANGLE:
        IqRef = pidOperator(&motor->velocityPID, motor->target - motor->magEncoder.fullAngle);
        motor->Uq = pidOperator(&motor->currentPID, IqRef - motor->Iq);
        setTorque(motor, motor->Uq, 0, motor->angle_el);
        break;
    }

    // getABCurrents(motor);
    // getDQCurrents(motor);
    // getDQVoltages(motor);
    // getABVoltages(motor);
    // setSVPWM(motor);
    // }
}

// static float velocityOpenloop(FocMotor *motor, float target_velocity)
// {
//     static float shaft_angle;
//     //   通过乘以时间间隔和目标速度来计算需要转动的机械角度，存储在 shaft_angle 变量中。在此之前，还需要对轴角度进行归一化，以确保其值在 0 到 2π 之间。
//     shaft_angle = _normalizeAngle(shaft_angle + target_velocity * motor->Ts);
//     // 以目标速度为 10 rad/s 为例，如果时间间隔是 1 秒，则在每个循环中需要增加 10 * 1 = 10 弧度的角度变化量，才能使电机转动到目标速度。
//     // 如果时间间隔是 0.1 秒，那么在每个循环中需要增加的角度变化量就是 10 * 0.1 = 1 弧度，才能实现相同的目标速度。因此，电机轴的转动角度取决于目标速度和时间间隔的乘积。
//     // load_data[3] = shaft_angle;

//     if (motor->torqueType == VOLTAGE)
//     {
//         float Uq = U_DC / 3;
//         setTorque(motor, Uq, 0, _electricalAngle(shaft_angle, 7));
//     }
//     else // CURRENT
//     {
//         motor->Iq = lpfOperator(&motor->IqFilter, motor->Iq);
//         motor->Uq = pidOperator(&motor->currentPID, motor->IqGoal - motor->Iq);
//         setTorque(motor, motor->Uq, 0, _electricalAngle(shaft_angle, 7));
//     }
// }
// float angleOpenloop(FocMotor *motor, float target_angle)
// {
//     static float shaft_angle, shaft_velocity;
//     // calculate the necessary angle to move from current position towards motor->target angle
//     // with maximal velocity (velocity_limit)
//     // TODO sensor precision: this calculation is not numerically precise. The angle can grow to the point
//     //                        where small position changes are no longer captured by the precision of floats
//     //                        when the total position is large.
//     if (abs(target_angle - shaft_angle) > abs(motor->velocity_limit * motor->Ts))
//     {
//         shaft_angle += _sign(target_angle - shaft_angle) * abs(motor->velocity_limit) * motor->Ts;
//         shaft_velocity = motor->velocity_limit;
//     }
//     else
//     {
//         shaft_angle = target_angle;
//         shaft_velocity = 0;
//     }

//     // use voltage limit or current limit
//     float Uq = voltage_limit;
//     if (_isset(phase_resistance))
//     {
//         Uq = _constrain(current_limit * phase_resistance + fabs(voltage_bemf), -voltage_limit, voltage_limit);
//         // recalculate the current
//         current.q = (Uq - fabs(voltage_bemf)) / phase_resistance;
//     }
//     // set the maximal allowed voltage (voltage_limit) with the necessary angle
//     // sensor precision: this calculation is OK due to the normalisation
//     setTorque(Uq, 0, _electricalAngle(_normalizeAngle(shaft_angle), pole_pairs));

//     // save timestamp for next call
//     open_loop_timestamp = now_us;

//     return Uq;
// }
