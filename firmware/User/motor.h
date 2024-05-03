#ifndef __MOTOR_H
#define __MOTOR_H
#include "userMain.h"

void motorInit();
void velocityOpenLoop(FocParameters *fp, float target_velocity, float Ts);
#endif