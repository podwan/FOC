#include "encoder_base.h"
#include "../math_utils.h"
#include "../app.h"

inline float abs(float _v)
{
    return _v >= 0 ? _v : -_v;
}

void EncoderBase::VarInit()
{
    // Initialize all the internal variables of EncoderBase
    // to ensure a "smooth" startup (without a 'jump' from zero)
    getRawAngle();
    delayMicroSeconds(1);

    velocityLast = getRawAngle();
    // velocityTimestamp = micros();
    HAL_Delay(1);

    getRawAngle();
    delayMicroSeconds(1);

    angleLast = getRawAngle();
    // angleTimestamp = micros();
}

void EncoderBase::update()
{
    float angle = getRawAngle();

    float deltaAngle = angle - angleLast;

    // txA = deltaAngle;

    // If overflow happened track it as full rotation
    if (abs(deltaAngle) > (0.8f * _2PI))
        rotationCount += (deltaAngle > 0) ? -1 : 1;

    float time = (float)updatePeriod * 1e-6f;

    velocity = ((float)(rotationCount - rotationCountLast) * _2PI + deltaAngle) / time;
    // txB = time;
    // txC = velocity;
    angleLast = angle;
    rotationCountLast = rotationCount;
}

float EncoderBase::getFullAngle()
{
    return (float)rotationCount * _2PI + angleLast;
}
float EncoderBase::getLapAngle()
{
    return angleLast;
}
float EncoderBase::getVelocity()
{
    return velocity;
}