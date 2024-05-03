#ifndef PID_H
#define PID_H

#include "userMain.h"
#include "math_utils.h"
#include "foc.h"

class PidController
{
public:
    PidController() = default;

    explicit PidController(float _p, float _i, float _d, float _ramp, float _limit) : p(_p), i(_i), d(_d), outputRamp(_ramp), limit(_limit)
    {
    }

    float operator()(float error);

    float p = 0;
    float i = 0;
    float d = 0;
    float outputRamp = 0;
    float limit = 0;

protected:
    float errorLast = 0;
    float outputLast = 0;
    float integralLast = 0;
};

#endif
