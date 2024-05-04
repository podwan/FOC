#include "lowpass_filter.h"

float lpfOperator(LowPassFilter *lfp, float x)
{

    float alpha = lfp->Tf / (lfp->Tf + lfp->dt);
    float y = alpha * lfp->y_prev + (1.0f - alpha) * x;
    lfp->y_prev = y;

    return y;
}
