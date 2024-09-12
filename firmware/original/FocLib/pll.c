#include "pll.h"
#include "bldcMotor.h"
#include "pid.h"

void pllInit(PLL *pll, float limit, float Ts, float Kp, float Ki, float factor)
{
    pll->Ealpha = 0;
    pll->Ebeta = 0;
    pll->lastIalpha = 0;
    pll->lastIbeta = 0;
    pidInit(&pll->pid, Kp, Ki, 0, 0, limit, Ts);
    pll->Ts = Ts;
    pll->factor = factor;
}
// Ualpha = R x Ialpha + L x dIalpha / dt + Ealpha
void anglePLL(PLL *pll, BldcMotor *motor)
{
    // 根据电机模型求Ealpha, Ebeta;
    pll->Ealpha = motor->Ualpha - (motor->resistance * motor->Ialpha + motor->inductance * (motor->Ialpha - pll->lastIalpha) / pll->Ts);
    pll->Ebeta = motor->Ubeta - (motor->resistance * motor->Ibeta + motor->inductance * (motor->Ibeta - pll->lastIbeta) / pll->Ts);

    pll->lastIalpha = motor->Ialpha;
    pll->lastIbeta = motor->Ibeta;

    float ct;
    float st;
    _sincos(pll->theta, &st, &ct);
    pll->Ed = pll->Ealpha * ct + pll->Ebeta * st;

    pll->error = pll->Ed * pll->factor;

    pll->theta += pidOperator(&pll->pid, pll->error);
}