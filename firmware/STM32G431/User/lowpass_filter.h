#ifndef LOWPASS_FILTER_H
#define LOWPASS_FILTER_H

#include "userMain.h"
#include "math_utils.h"
#include "foc.h"

class LowPassFilter
{
public:
    LowPassFilter() = default;

    explicit LowPassFilter(float _timeConstant)
        : outputLast(0.0f)
    {
    }

    float operator()(float _input);
    float timeConstant;

protected:
    float outputLast;
};

#endif