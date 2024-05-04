#include "foc.h"
#include <cmath>
char sector;

char getSector(float _angleElectrical)
{
    sector = (char)(std::floor(_angleElectrical / _PI_3)) + 1;
    return sector;
}

void getIabc(float Ia, float Ib, float Ic)
{
    // 根据扇区，计算电流
    if ((sector == 1) || (sector == 6))
        Ia = 0 - Ib - Ic;
    if ((sector == 2) || (sector == 3))
        Ib = 0 - Ia - Ic;
    if ((sector == 4) || (sector == 5))
        Ic = 0 - Ia - Ib;
    // // 获取电流值
    // current.a = Ia;
    // current.b = Ib;
    // current.c = Ic;
}

/*----------------------------------------------------------------------------*/
// Clarke变换，计算公式
// Ialpha = Ia
// Ibeta = (Ia + 2Ib)/sqrt(3)
// Ibeta = 1/sqrt(3) * Ia + 1/sqrt(3) * 2Ib
/*----------------------------------------------------------------------------*/
void clarke(void)
{

    // curr_alfa_beta.component1 = current.a;

    //  curr_alfa_beta.component2 = _1_SQRT3 * current.a + _1_SQRT3 * 2.0f * current.b;
}

/*----------------------------------------------------------------------------*/
// Park变换
// Id = Ialpha * Cosγ + Ibeta * Sinγ
// Iq = -Ialpha * Sinγ + Ibeta * Cosγ
/*----------------------------------------------------------------------------*/
void park(float _angleElectrical)
{
    // curr_d_q.component1 = curr_alfa_beta.component1 * CosApprox(_angleElectrical) + curr_alfa_beta.component2 * SinApprox(_angleElectrical);
    // curr_d_q.component2 = -curr_alfa_beta.component1 * SinApprox(_angleElectrical) + curr_alfa_beta.component2 * CosApprox(_angleElectrical);
}

void revParkOperate(float uD, float uQ, float theta, float *uAlpha, float *uBeta)
{
    *uAlpha = uD * CosApprox(theta) - uQ * SinApprox(theta);
    *uBeta = uD * SinApprox(theta) + uQ * CosApprox(theta);
}

const char sectorRemap[] = {0, 2, 6, 1, 4, 3, 5};

static float A, B, C;

char getSector(float uAlpha, float uBeta)
{
    return 0;
}

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

    float tFirst = 0, tSecond = 0, t;

    float X = _SQRT3 * HALP_PWM_PERIOD * uBeta / U_DC;
    float Y = _SQRT3 * HALP_PWM_PERIOD / U_DC * (_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);
    float Z = _SQRT3 * HALP_PWM_PERIOD / U_DC * (-_SQRT3 * uAlpha / 2.0f + uBeta / 2.0f);

    int pwm1Duty, pwm2Duty, pwm3Duty;
    int v1, v2, v3;
    switch (sec)
    {
    case 1:
        tFirst = -Z;
        tSecond = X;
        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;

        pwm1Duty = v1;
        pwm2Duty = v2;
        pwm3Duty = v3;
        break;
    case 2:
        tFirst = Z;
        tSecond = Y;

        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;

        pwm1Duty = v2;
        pwm2Duty = v1;
        pwm3Duty = v3;
        break;
    case 3:
        tFirst = X;
        tSecond = -Y;
        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;

        pwm1Duty = v3;
        pwm2Duty = v1;
        pwm3Duty = v2;
        break;
    case 4:
        tFirst = -X;
        tSecond = Z;
        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;

        pwm1Duty = v3;
        pwm2Duty = v2;
        pwm3Duty = v1;

        break;

    case 5:
        tFirst = -Y;
        tSecond = -Z;
        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;
        pwm1Duty = v2;
        pwm2Duty = v3;
        pwm3Duty = v1;
        break;

    case 6:
        tFirst = Y;
        tSecond = -X;
        t = tFirst + tSecond;

        if (t > HALP_PWM_PERIOD)
        {
            tFirst = tFirst / t * HALP_PWM_PERIOD;
            tSecond = tSecond / t * HALP_PWM_PERIOD;
        }

        v1 = (HALP_PWM_PERIOD - tFirst - tSecond) / 2.0f;
        v2 = v1 + tFirst;
        v3 = v2 + tSecond;
        pwm1Duty = v1;
        pwm2Duty = v3;
        pwm3Duty = v2;
        break;
    }

    temp[2] = pwm1Duty;
    temp[3] = pwm2Duty;
    temp[4] = pwm3Duty;

    PWM_GENERATE(pwm1Duty, pwm2Duty, pwm3Duty);
}

void openLoopFoc(float Uq, float Ud, float theta)
{
    float uAlpha, uBeta;

    revParkOperate(Ud, Uq, theta, &uAlpha, &uBeta);

    SVPWM(uAlpha, uBeta);
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
