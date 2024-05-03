

#ifndef __FOC_H
#define __FOC_H

#include "userMain.h"

#define SHUNT_RESISTOR 0.1f // 100mR
#define GAIN 100.0f         // opAmp
#define VLOTS_AMPS_RATIO 1.0f / SHUNT_RESISTOR / GAIN

#define CARRIER_FREQUENCY 10000                          // PWM载波频率
#define PWM_PERIOD_VALUE (160000000 / CARRIER_FREQUENCY) // 6400
#define DEAD_TIME (160000000 / CARRIER_FREQUENCY / 25)   // DT/1.6 = 6400 / 40	DT = 256
#define HALP_PWM_PERIOD (PWM_PERIOD_VALUE / 2.0f)        // PWM period * 2
#define U_DC 12.0f

void calibrateOffsets(FocParameters *fp, uint32_t adc_a, uint32_t adc_b);
extern const char sectorRemap[];
#endif