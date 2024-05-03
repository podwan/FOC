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

void revParkOperate(float uD, float uQ, float theta, float *Ualpha, float *Ubeta)
{
    *Ualpha = uD * _cos(theta) - uQ * _sin(theta);
    *Ubeta = uD * _sin(theta) + uQ * _cos(theta);
}

static void setPhaseVoltage1(float Uq, float Ud, float angle_el)
{
    float ct;
    float st;
    uchar sector;
    uint32_t d1, d2, d3, pwm1Duty, pwm2Duty, pwm3Duty;

    Uq = _constrain(Uq, -Q_MAX, Q_MAX);
    _sincos(angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = -Uq * st + Ud * ct;
    float Ubeta = Uq * ct + Ud * st;

    float tFirst = 0, tSecond = 0;
    float K = _SQRT3 * HALP_PWM_PERIOD / U_DC;
    float X = K * Ubeta;
    float Y = K * (_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    float Z = K * (-_SQRT3 * Ualpha / 2.0f - Ubeta / 2.0f);
    //  i = Y;
    //  j = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f);
    sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

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

    load_data[0] = d1;
    load_data[1] = d2;
    load_data[2] = d3;
    load_data[3] = Uq;
    PWM_GENERATE(d1, d2, d3);
}

static float A, B, C;

void SVPWM(float uAlpha, float uBeta)
{
    uchar sec;
    A = uBeta;
    B = _SQRT3 / 2.0f * uAlpha - uBeta / 2.0f;
    C = -_SQRT3 / 2.0f * uAlpha - uBeta / 2.0f;

    char N = 0;

    if (A > 0)
        N++;

    if (B > 0)
        N += 2;

    if (C > 0)
        N += 4;

    sec = sectorRemap[N];

    float tFirst = 0, tSecond = 0;

    float X = _SQRT3 * HALP_PWM_PERIOD * uBeta / U_DC;
    float Y = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);
    float Z = _SQRT3 * HALP_PWM_PERIOD / U_DC * (-_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);
    //  i = Y;
    //  j = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);

    switch (sec)
    {
    case 1:
        tFirst = -Z;
        tSecond = X;
        break;
    case 2:
        tFirst = Z;
        tSecond = Y;
        break;
    case 3:
        tFirst = X;
        tSecond = -Y;
        break;
    case 4:
        tFirst = -X;
        tSecond = Z;
        break;

    case 5:
        tFirst = -Y;
        tSecond = -Z;
        break;

    case 6:
        tFirst = Y;
        tSecond = -X;
        break;
    }

    float t = tFirst + tSecond;

    if (t > HALP_PWM_PERIOD)
    {
        tFirst = tFirst / t * HALP_PWM_PERIOD;
        tSecond = tSecond / t * HALP_PWM_PERIOD;
    }

    int d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
    int d2 = d1 + tFirst;
    int d3 = d2 + tSecond;

    int pwm1Duty, pwm2Duty, pwm3Duty;

    switch (sec)
    {
    case 1:
        pwm1Duty = d1;
        pwm2Duty = d2;
        pwm3Duty = d3;
        break;

    case 2:
        pwm1Duty = d2;
        pwm2Duty = d1;
        pwm3Duty = d3;
        break;

    case 3:
        pwm1Duty = d3;
        pwm2Duty = d1;
        pwm3Duty = d2;
        break;

    case 4:
        pwm1Duty = d3;
        pwm2Duty = d2;
        pwm3Duty = d1;
        break;

    case 5:
        pwm1Duty = d2;
        pwm2Duty = d3;
        pwm3Duty = d1;
        break;

    case 6:
        pwm1Duty = d1;
        pwm2Duty = d3;
        pwm3Duty = d2;
        break;
    }
    load_data[0] = pwm1Duty;
    load_data[1] = pwm2Duty;
    load_data[2] = pwm3Duty;

    PWM_GENERATE(pwm1Duty, pwm2Duty, pwm3Duty);
    // PWM_GENERATE(pwm1Duty, pwm2Duty, pwm3Duty);
}

void openLoopFoc(float uQ, float theta)
{
    float uAlpha, uBeta;

    // revParkOperate(0, uQ, theta, &uAlpha, &uBeta);

    // char sector = getSector(uAlpha, uBeta);

    // SVPWM(uAlpha, uBeta);
    setPhaseVoltage1(-Q_MAX * 2, 0, theta);
}

// void setPhaseVoltage1(float Uq, float Ud, float angle_el)

#if 0
    float ct;
    float st;
    _sincos(angle_el, &st, &ct);
    float Ualpha = -Uq * st + Ud * ct;
    float Ubeta = Uq * ct + Ud * st;

    uchar sector;
    float A, B, C;
    A = Ubeta;
    B = _SQRT3 / 2.0f * Ualpha - Ubeta / 2.0f;
    C = -_SQRT3 / 2.0f * Ualpha - Ubeta / 2.0f;

    char N = 0;

    if (A > 0)
        N++;

    if (B > 0)
        N += 2;

    if (C > 0)
        N += 4;

    sector = sectorRemap[N];

    float tFirst = 0, tSecond = 0;

    float X = _SQRT3 * HALP_PWM_PERIOD * Ubeta / U_DC;
    float Y = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f);
    float Z = _SQRT3 * HALP_PWM_PERIOD / U_DC * (-_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f);
    //  i = Y;
    //  j = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f);

    switch (sector)
    {
    case 1:
        tFirst = -Z;
        tSecond = X;
        break;
    case 2:
        tFirst = Z;
        tSecond = Y;
        break;
    case 3:
        tFirst = X;
        tSecond = -Y;
        break;
    case 4:
        tFirst = -X;
        tSecond = Z;
        break;

    case 5:
        tFirst = -Y;
        tSecond = -Z;
        break;

    case 6:
        tFirst = Y;
        tSecond = -X;
        break;
    }

    float t = tFirst + tSecond;

    if (t > HALP_PWM_PERIOD)
    {
        tFirst = tFirst / t * HALP_PWM_PERIOD;
        tSecond = tSecond / t * HALP_PWM_PERIOD;
    }

    int d1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
    int d2 = d1 + tFirst;
    int d3 = d2 + tSecond;

    int pwm1Duty, pwm2Duty, pwm3Duty;

    switch (sector)
    {
    case 1:
        pwm1Duty = d1;
        pwm2Duty = d2;
        pwm3Duty = d3;
        break;

    case 2:
        pwm1Duty = d2;
        pwm2Duty = d1;
        pwm3Duty = d3;
        break;

    case 3:
        pwm1Duty = d3;
        pwm2Duty = d1;
        pwm3Duty = d2;
        break;

    case 4:
        pwm1Duty = d3;
        pwm2Duty = d2;
        pwm3Duty = d1;
        break;

    case 5:
        pwm1Duty = d2;
        pwm2Duty = d3;
        pwm3Duty = d1;
        break;

    case 6:
        pwm1Duty = d1;
        pwm2Duty = d3;
        pwm3Duty = d2;
        break;
    }

    float ct;
    float st;
    _sincos(angle_el, &st, &ct);
    // Park逆变换
    float Ualpha = -Uq * st + Ud * ct;
    float Ubeta = Uq * ct + Ud * st;

    float tFirst, tSecond;
    int d1, d2, d3;

    float K = _SQRT3 * PWM_PERIOD_VALUE / U_DC;
    float X = Ubeta * K;
    float Y = (_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f) * K;
    float Z = (-_SQRT3 * Ualpha / 2.0f + Ubeta / 2.0f) * K;

    uint8_t sector = sectorRemap[(X > 0.0f) + ((Y > 0.0f) << 1) + ((Z > 0.0f) << 2)]; // sector = A + 2B + 4C

    switch (sector)
    {
    case 1:
        tFirst = -Z;
        tSecond = X;

        d1 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d2 = d1 + tFirst;
        d3 = d2 + tSecond;
        break;
    case 2:
        tFirst = Z;
        tSecond = Y;

        d2 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d1 = d2 + tFirst;
        d3 = d1 + tSecond;
        break;
    case 3:
        tFirst = X;
        tSecond = -Y;

        d2 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d3 = d2 + tFirst;
        d1 = d3 + tSecond;

        break;
    case 4:
        tFirst = -X;
        tSecond = Z;

        d3 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d2 = d3 + tFirst;
        d1 = d2 + tSecond;
        break;

    case 5:
        tFirst = -Y;
        tSecond = -Z;

        d3 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d1 = d3 + tFirst;
        d2 = d1 + tSecond;
        break;

    case 6:
        tFirst = Y;
        tSecond = -X;

        d1 = (PWM_PERIOD_VALUE - tFirst - tSecond) / 2.0f;
        d3 = d1 + tFirst;
        d2 = d3 + tSecond;
        break;
    }

#endif
//     load_data[0] = d1;
//     load_data[1] = d2;
//     load_data[2] = d3;
//     load_data[3] = 0;
//     load_data[4] = 0;
//     setPwm1(d1, d2, d3); // 输出三路PWM，驱动无刷电机转动
// }
