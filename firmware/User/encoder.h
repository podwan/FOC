
#ifndef __ENCODER_H
#define __ENCODER_H
#include "userMain.h"
/**
 *  Direction structure
 */
typedef enum
{
    CW = 1,     // clockwise
    CCW = -1,   // counter clockwise
    UNKNOWN = 0 // not yet known or invalid state
} Direction;

void encoderInit(MagEncoder *encoder, float _Ts, float (*_getRawAngle)(void));
// void encoderUpdate(MagEncoder *encoder);
void getVelocity(MagEncoder *encoder);
void encoderUpdate(MagEncoder *encoder);
// float getMechanicalAngle();
// float getFullAngle();

#endif
