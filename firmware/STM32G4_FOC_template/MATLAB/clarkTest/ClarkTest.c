/*
 * File: ClarkTest.c
 *
 * Code generated for Simulink model 'ClarkTest'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug  4 13:51:42 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "ClarkTest.h"
#include "mw_cmsis.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>

/* Exported block signals */
real32_T ia;                           /* '<S3>/Sin' */
real32_T ib;                           /* '<S3>/Sin1' */
real32_T ic;                           /* '<S3>/Sin2' */

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void ClarkTest_step(void)
{
  real32_T rtb_Sum;

  /* Outputs for Atomic SubSystem: '<Root>/ClarkTest' */
  /* Sum: '<S5>/Sum' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_Sum = rtDW.UnitDelay_DSTATE + 0.000628318521F;

  /* If: '<S6>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   *  Sum: '<S5>/Sum'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Sum = (rtDW.UnitDelay_DSTATE + 0.000628318521F) - 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_Sum = (rtDW.UnitDelay_DSTATE + 0.000628318521F) + 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
  }

  /* End of If: '<S6>/If' */

  /* Trigonometry: '<S3>/Sin' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   *  Math: '<S3>/Mod'
   *  Sum: '<S3>/Add1'
   */
  ia = arm_sin_f32(-rt_modf(rtb_Sum, 6.28318548F));

  /* Trigonometry: '<S3>/Sin1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain1'
   *  Math: '<S3>/Mod3'
   *  Sum: '<S3>/Add2'
   */
  ib = arm_sin_f32(-rt_modf(rtb_Sum - 2.09439516F, 6.28318548F));

  /* Trigonometry: '<S3>/Sin2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant3'
   *  Gain: '<S3>/Gain2'
   *  Math: '<S3>/Mod4'
   *  Sum: '<S3>/Add3'
   */
  ic = arm_sin_f32(-rt_modf(rtb_Sum + 2.09439516F, 6.28318548F));

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum;

  /* Outport: '<Root>/ialpha' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Sum: '<S4>/Minus1'
   *  Sum: '<S4>/Plus'
   */
  rtY.ialpha = 0.666666687F * ia - (ib + ic) * 0.333333343F;

  /* Outport: '<Root>/ibeta' incorporates:
   *  Gain: '<S4>/Gain2'
   *  Sum: '<S4>/Minus'
   */
  rtY.ibeta = (ib - ic) * 0.577350259F;

  /* End of Outputs for SubSystem: '<Root>/ClarkTest' */
}

/* Model initialize function */
void ClarkTest_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
