#ifndef __ENCODER_BASE_H
#define __ENCODER_BASE_H
#include "../userMain.h"
#include "../math_utils.h"
#include "../time_utils.h"
// declare general interfaces encoder need to implement
class EncoderBase
{
public:
    float getFullAngle();
    void update();
    float getLapAngle();
    float getVelocity();

protected:
    virtual float getRawAngle() = 0;
    void VarInit();
    uint32_t updatePeriod;
    float angleLast = 0;
    int32_t rotationCount = 0;
    float velocityLast = 0;
    int32_t rotationCountLast = 0;
    float velocity;
};

#endif
