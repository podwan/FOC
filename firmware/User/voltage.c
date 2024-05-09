#include "voltage.h"
#include "math_utils.h"
#include "comm.h"
#include "focMotor.h"
#include "pid.h"
#include "app.h"
const char sectorRemap[] = {0, 2, 6, 1, 4, 3, 5};
void getDQVoltages(FocMotor *motor)
{

    //    motor->Id = lpfOperator(&motor->lpf, motor->Id);
    //    motor->Iq = lpfOperator(&motor->lpf, motor->Iq);

    //    motor->Ud = pidOperator(&motor->pid_id, motor->IdGoal - motor->Id);
    //    motor->Uq = pidOperator(&motor->pid_iq, motor->IqGoal - motor->Iq);
}
/*============================================================================*/
// Park逆变换
// Ualpha = Ud * Cosθr - Uq * Sinθr
// Ubeta = Uq * Cosθr + Ud * Sinθr
/*============================================================================*/
void getABVoltages(FocMotor *motor)
{
    float ct;
    float st;
    _sincos(motor->angle_el, &st, &ct);
    motor->Ualpha = motor->Ud * ct - motor->Uq * st;
    motor->Ubeta = motor->Uq * ct + motor->Ud * st;
}

// Park逆变换*SVPWM
void setTorque(FocMotor *motor, float Uq, float Ud, float angle_el)
{

    Uq = _constrain(Uq, -UqMAX, UqMAX);

    float ct;
    float st;
    _sincos(angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = Ud * ct - Uq * st;
    float Ubeta = Uq * ct + Ud * st;

    float tFirst, tSecond;
    float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
    float X = K * Ubeta;
    float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C
    static uint32_t d1, d2, d3;
    switch (sector)
    {
    case 1:
        tFirst = Y;
        tSecond = X;

        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d1 + tFirst;
        d3 = d2 + tSecond;

        break;
    case 2:
        tFirst = -Y;
        tSecond = -Z;

        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d2 + tFirst;
        d3 = d1 + tSecond;

        break;
    case 3:
        tFirst = X;
        tSecond = Z;

        d2 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d2 + tFirst;
        d1 = d3 + tSecond;

        break;
    case 4:
        tFirst = -X;
        tSecond = -Y;

        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d2 = d3 + tFirst;
        d1 = d2 + tSecond;

        break;

    case 5:
        tFirst = Z;
        tSecond = Y;

        d3 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d1 = d3 + tFirst;
        d2 = d1 + tSecond;

        break;

    case 6:
        tFirst = -Z;
        tSecond = -X;

        d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        d3 = d1 + tFirst;
        d2 = d3 + tSecond;

        break;
    }

#if SHOW_WAVE
  
    motor->d1 = d1;
    motor->d2 = d2;
    motor->d3 = d3;
#endif
    motor->updatePwm(d1, d2, d3);
}
