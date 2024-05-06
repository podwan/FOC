#ifndef LOWPASS_FILTER_H
#define LOWPASS_FILTER_H
#include "userMain.h"

void lpfInit(LowPassFilter *filter, const float _Tf, const float _dt);
float lpfOperator(LowPassFilter *filter, float x);

#endif // LOWPASS_FILTER_H