

#ifndef __VOLTAGE_H
#define __VOLTAGE_H

#include "userMain.h"

void getDQVoltages(FocMotor *motor);
void getABVoltages(FocMotor *motor);
void setTorque(FocMotor *motor, float Uq, float Ud, float angle_el);
void setSVPWM(FocMotor *motor);
void svpwm_test(FocMotor *motor, float Uq, float acc);
extern const char sectorRemap[];
#endif