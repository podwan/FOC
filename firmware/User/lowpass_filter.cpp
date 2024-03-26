#include "lowpass_filter.h"

float LowPassFilter::operator()(float _input)
{

    float dt = FOC_PERIOD * 1e-6f;
    float alpha = timeConstant / (timeConstant + dt);
    float output = alpha * outputLast + (1.0f - alpha) * _input;
    outputLast = output;

    return output;
}
