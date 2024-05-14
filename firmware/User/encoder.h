
#ifndef __ENCODER_H
#define __ENCODER_H
#include "userMain.h"


void encoderInit(MagEncoder *encoder, float _Ts, float (*_getRawAngle)(void));
// void encoderUpdate(MagEncoder *encoder);
void getVelocity(MagEncoder *encoder);
void encoderUpdate(MagEncoder *encoder);
// float getMechanicalAngle();
// float getFullAngle();

#endif
