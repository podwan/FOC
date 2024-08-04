#include "pll.h"
#include "bldcMotor.h"
#include "pid.h"
// Ualpha = R x Ialpha + L x dIalpha / dt + Ealpha

// void pllInit(PLL *pll, float R, float L, float limit, float Ts, float Kp, float Ki)
// {
//     pll->Ealpha = 0;
//     pll->Ebeta = 0;
//     pll->lastIalpha = 0;
//     pll->lastIbeta = 0;
//     pidInit(pll->pid, Kp, Ki, 0, 0, limit, Ts);
//     pll->resistance = R;
//     pll->inductance = L;
//     pll->Ts = Ts;
// }




void anglePLL(PLL *pll, BldcMotor *motor)
{
    static float lastIalpha, lastIbeta;
    pll->Ealpha = motor->Ualpha - (pll->R * motor->Ialpha + pll->L * (motor->Ialpha - lastIalpha) / pll->Ts);
    pll->Ebeta = motor->Ubeta - (pll->R * motor->Ibeta + pll->L * (motor->Ibeta - lastIbeta) / pll->Ts);

    float ct;
    float st;
    _sincos(pll->theta, &st, &ct);
    pll->Ed = pll->Ealpha * ct + pll->Ebeta * st;
    if (pll->direction == CCW)
        pll->error = -pll->Ed;
    else
        pll->error = pll->Ed;
    pll->theta += pidOperator(&pll->pid, pll->error);
}