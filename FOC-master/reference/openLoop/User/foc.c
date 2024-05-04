#include "foc.h"
// #include "arm_math.h"
#include "math_utils.h"
#include <cmath>
float i, j;
void revParkOperate(float uD, float uQ, float theta, float *uAlpha, float *uBeta)
{
    *uAlpha = uD * CosApprox(theta) - uQ * SinApprox(theta);
    *uBeta = uD * SinApprox(theta) + uQ * CosApprox(theta);
}

const char sectorRemap[] = {0, 2, 6, 1, 4, 3, 5};

static float A, B, C;

char getSector(float uAlpha, float uBeta)
{
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

    temp[4] = N;

    return sectorRemap[N];
}

void SVPWM(char sector, float uAlpha, float uBeta)
{
    float tFirst = 0, tSecond = 0;

    float X = _SQRT3 * PWM_PERIOD * uBeta / U_DC;
    float Y = _SQRT3 * PWM_PERIOD / U_DC * (_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);
    float Z = _SQRT3 * PWM_PERIOD / U_DC * (-_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);
    //  i = Y;
    //  j = _SQRT3 * PWM_PERIOD / U_DC * (_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);

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

    if (t > PWM_PERIOD)
    {
        tFirst = tFirst / t * PWM_PERIOD;
        tSecond = tSecond / t * PWM_PERIOD;
    }

    int v1 = (PWM_PERIOD - tFirst - tSecond) / 2.0f;
    int v2 = v1 + tFirst;
    int v3 = v2 + tSecond;

    int pwm1Duty, pwm2Duty, pwm3Duty;

    switch (sector)
    {
    case 1:
        pwm1Duty = v1;
        pwm2Duty = v2;
        pwm3Duty = v3;
        break;

    case 2:
        pwm1Duty = v2;
        pwm2Duty = v1;
        pwm3Duty = v3;
        break;

    case 3:
        pwm1Duty = v3;
        pwm2Duty = v1;
        pwm3Duty = v2;
        break;

    case 4:
        pwm1Duty = v3;
        pwm2Duty = v2;
        pwm3Duty = v1;
        break;

    case 5:
        pwm1Duty = v2;
        pwm2Duty = v3;
        pwm3Duty = v1;
        break;

    case 6:
        pwm1Duty = v1;
        pwm2Duty = v3;
        pwm3Duty = v2;
        break;
    }
    temp[2] = pwm1Duty;
    temp[3] = pwm2Duty;
    temp[4] = pwm3Duty;

    // PWM_GENERATE(pwm1Duty, pwm2Duty, pwm3Duty);
    PWM_GENERATE(pwm1Duty, pwm2Duty, pwm3Duty);
}

void FOC(float uD, float uQ, float theta)
{
    float uAlpha, uBeta;

    revParkOperate(uD, uQ, theta, &uAlpha, &uBeta);

    char sector = getSector(uAlpha, uBeta);

    SVPWM(sector, uAlpha, uBeta);
}

void clark(float iA, float iB, float *iAlpha, float *iBeta)
{
    *iAlpha = 3 / 2 * iA;
    *iBeta = _SQRT3 * iB + _SQRT3 / 2.0f * iA;
}

void park(float iAlpha, float iBeta, float theta, float *iD, float *iQ)
{
    *iD = iAlpha * CosApprox(theta) + iBeta * SinApprox(theta);
    *iQ = -iAlpha * SinApprox(theta) + iBeta * CosApprox(theta);
}

// void vectorsCompute(char sector, float uAlpha, float uBeta, float period, char Udc, float *tFirst, float *tSecond)
// {

//     float X = FACTOR * A;
//     float Y = FACTOR * B;
//     float Z = FACTOR * C;

//     switch (sector)
//     {
//     case 1:
//         *tFirst = -Z;
//         *tSecond = X;
//         break;
//     case 2:
//         *tFirst = Z;
//         *tSecond = Y;
//         break;
//     case 3:
//         *tFirst = X;
//         *tSecond = -Y;
//         break;
//     case 4:
//         *tFirst = -X;
//         *tSecond = Z;
//         break;

//     case 5:
//         *tFirst = -Y;
//         *tSecond = -Z;
//         break;

//     case 6:
//         *tFirst = Y;
//         *tSecond = -X;
//         break;
//     }
// }

// void pwmGenerate(float tFirst, float tSecond)
// {
// }
