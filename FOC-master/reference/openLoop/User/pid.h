#ifndef __PID_H
#define __PID_H

typedef struct
{
    float setPoint;
    float iTerms;
    float lastInput;
    float kp;
    float ki;
    float kd;
    char positiveFeedback;
    float outputMax;
    float outputMin;
} PID;

void pidInit(PID *pid, float setPoint,
             float iTerms, float lastInput,
             float kp, float ki, float kd,
             char positiveFeedback, float outMax, float outMin);
unsigned int compute(PID *pid, float input);
void setTunings(PID *pid, float Kp, float Ki, float Kd);
#endif