#include "motor.h"
#include "foc.h"

FocParameters fp1;

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c);

void motorInit()
{
    fp1.shaft_angle = 0;
    fp1.Uq = 2.0f;
    fp1.pole_pairs = 7;
    fp1.setPwm = setPwm1;
}

// param: velocity is radius per sec
void velocityOpenLoop(FocParameters *fp, float target_velocity, float Ts)
{
    fp->shaft_angle = _normalizeAngle(fp->shaft_angle + target_velocity * Ts);
    fp->angle_el = _electricalAngle(fp->shaft_angle, fp->pole_pairs);
    SVPWM(fp);
}

static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c)
{
    TIM1->CCR1 = a;
    TIM1->CCR2 = b;
    TIM1->CCR3 = c;
}