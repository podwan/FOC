

#ifndef __VOLTAGE_H
#define __VOLTAGE_H

#include "userMain.h"


void getDQVoltages(FocMotor *motor);
void getABVoltages(FocMotor *motor);
void setPhaseVoltage(FocMotor *motor, float Uq, float Ud, float angle_el);
void setSVPWM(FocMotor *motor);
extern const char sectorRemap[];
#endif