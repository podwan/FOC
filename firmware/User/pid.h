#ifndef PID_H
#define PID_H

#include "userMain.h"
void pidInit(PidController *pidController, float _P, float _I, float _D, float _ramp, float _limit, float _Ts);
float pidOperator(PidController *pidController, float error);
void reset(PidController *pidController);

#endif // PID_H