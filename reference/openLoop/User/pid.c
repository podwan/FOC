#include "pid.h"

void pidInit(PID *pid, float setPoint,
             float iTerms, float lastInput,
             float kp, float ki, float kd,
             char positiveFeedback, float outputMax, float outputMin)
{
    
   pid->iTerms = iTerms;
   pid->lastInput = lastInput;
   pid->kp = kp;
   pid->kd = kd;
   pid->ki = ki;
   pid->positiveFeedback = positiveFeedback;
   pid->outputMax = outputMax;
   pid->outputMin = outputMin;
}

unsigned int compute(PID *pid, float input)
{

   /*Compute all the working error variables*/

   float output;
   float error = pid->setPoint - input;   // P
   float dInput = input - pid->lastInput; // D
   pid->iTerms += (pid->ki * error);      // I
   if (pid->iTerms > pid->outputMax)
      pid->iTerms = pid->outputMax;
   else if (pid->iTerms < pid->outputMin)
      pid->iTerms = pid->outputMin;

   /*Compute PID output*/
   output = pid->kp * error + pid->iTerms - pid->kd * dInput;
   if (output > pid->outputMax)
      output = pid->outputMax;
   else if (output < pid->outputMin)
      output = pid->outputMin;

   /*Remember some variables for next time*/
   pid->lastInput = input;

   return (unsigned int)output;
}

void setTunings(PID *pid, float Kp, float Ki, float Kd)
{
   if (Kp < 0 || Ki < 0 || Kd < 0)
      return;
   else
   {
      if (pid->positiveFeedback == 1)
      {
         pid->kp = Kp;
         pid->ki = Ki;
         pid->kd = Kd;
      }
      else
      {
         pid->kp = (0 - pid->kp);
         pid->ki = (0 - pid->ki);
         pid->kd = (0 - pid->kd);
      }
   }
}
