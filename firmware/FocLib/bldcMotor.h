#ifndef __BLDCMOTOR_H
#define __BLDCMOTOR_H
#include "focLib.h"
#include "math_utils.h"
#include "pid.h"
#include "lowpass_filter.h"
#include "encoder.h"

typedef enum
{
    TORQUE,
    VELOCITY_OPEN_LOOP,
    VELOCITY,
    ANGLE,
} ControlType;

typedef enum
{
    VOLTAGE,
    CURRENT,
} TorqueType;

typedef enum
{
    MOTOR_CALIBRATE,
    MOTOR_READY,
    MOTOR_START,
} MotorState;

typedef struct
{
    MagEncoder magEncoder;
    MotorState state;
    ControlType controlType;
    TorqueType torqueType;
    float Ts;
    float target;
    //  angle
    float zeroElectricAngleOffSet;
    unsigned char pole_pairs;
    float angle_el;
    // currents
    float offset_ia;
    float offset_ib;
    float Ia;
    float Ib;
    float Ialpha;
    float Ibeta;
    float Id;
    float Iq;
    // pid
    PidController pidId;
    PidController pidIq;
    PidController velocityPID;
    PidController anglePID;
    // filter
    LowPassFilter IqFilter;
    LowPassFilter IdFilter;
    LowPassFilter velocityFilter;

    // volatges
    float Ud;
    float Uq;
    float Ualpha;
    float Ubeta;
    float Ta, Tb, Tc;
    void (*updatePwm)(unsigned short int, unsigned short int, unsigned short int);
    void (*startPwm)();
    void (*stopPwm)();
} BldcMotor;

void getElecAngle(BldcMotor *motor);
void foc(BldcMotor *motor, uint32_t adc_a, uint32_t adc_b);
// void getZeroElecAngle(BldcMotor *motor);
void setPhaseVoltage1(BldcMotor *motor, float Uq, float Ud, float angle_el);
void goToZeroElecAngle(BldcMotor *motor);
#endif
