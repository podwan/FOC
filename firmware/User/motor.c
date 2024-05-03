#include "motor.h"
#include "foc.h"
#include "foc_utils.h"

FocParameters fp1;

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c);

void motorInit()
{
    fp1.shaft_angle = 0;
    fp1.Uq = 2.0f;
    fp1.pole_pairs = 7;
    fp1.setPwm = setPwm1;
}

// param: velocity is radius per sector
void velocityOpenLoop(FocParameters *fp, float target_velocity, float Ts)
{
    Ts *= 1e-6f;
    fp->shaft_angle = _normalizeAngle(fp->shaft_angle + target_velocity * Ts);
    fp->angle_el = _electricalAngle(fp->shaft_angle, fp->pole_pairs);
    SVPWM(fp);
}

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c)
{
    TIM1->CCR1 = a;
    TIM1->CCR2 = b;
    TIM1->CCR3 = c;
}

void setPhaseVoltage(FocParameters *fp)
{

    fp->Uq = _constrain(fp->Uq, -Q_MAX, Q_MAX);

    float ct;
    float st;
    _sincos(fp->angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = -fp->Uq * st + fp->Ud * ct;
    float Ubeta = fp->Uq * ct + fp->Ud * st;

    uint32_t d1, d2, d3;
    float tFirst = 0, tSecond = 0;
    float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
    float X = K * Ubeta;
    float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

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
#if SEND_RCC_DATA
    load_data[0] = d1;
    load_data[1] = d2;
    load_data[2] = d3;
//    load_data[3] = Uq;
#endif
    PWM_GENERATE(d1, d2, d3);
}
