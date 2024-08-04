/*
 * File: ParkTest.c
 *
 * Code generated for Simulink model 'ParkTest'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug  4 14:57:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "ParkTest.h"
#include "rtwtypes.h"
#include "mw_cmsis.h"
#include <math.h>
#include <float.h>

/* Exported block signals */
real32_T ia;                           /* '<S7>/Sin' */
real32_T ib;                           /* '<S7>/Sin1' */
real32_T ic;                           /* '<S7>/Sin2' */
real32_T ialpha;                       /* '<S8>/Minus1' */
real32_T ibeta;                        /* '<S8>/Gain2' */
real32_T id;                           /* '<S5>/Add' */
real32_T iq;                           /* '<S5>/Minus' */

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1);
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1);

/*
 * Output and update for action system:
 *    '<S10>/If Action Subsystem1'
 *    '<S14>/If Action Subsystem1'
 */
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S11>/Constant'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * Output and update for action system:
 *    '<S10>/If Action Subsystem3'
 *    '<S14>/If Action Subsystem3'
 */
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_Out1 = rtu_In1 + 6.28318548F;
}

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
void ParkTest_step(void)
{
  real32_T rtb_Merge;
  real32_T rtb_SinCos;
  real32_T rtb_Sum;
  real32_T rtb_Sum_n;

  /* Outputs for Atomic SubSystem: '<Root>/ParkTest' */
  /* Sum: '<S9>/Sum' incorporates:
   *  UnitDelay: '<S9>/Unit Delay'
   */
  rtb_Sum = rtDW.UnitDelay_DSTATE + 0.000628318521F;

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  RelationalOperator: '<S10>/Relational Operator'
   *  RelationalOperator: '<S10>/Relational Operator1'
   *  Sum: '<S9>/Sum'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/In1' */
    rtb_Merge = rtDW.UnitDelay_DSTATE + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem2' */
  }

  /* End of If: '<S10>/If' */

  /* Trigonometry: '<S7>/Sin' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain'
   *  Math: '<S7>/Mod'
   *  Sum: '<S7>/Add1'
   */
  ia = arm_sin_f32(-rt_modf(rtb_Merge, 6.28318548F));

  /* Trigonometry: '<S7>/Sin1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain1'
   *  Math: '<S7>/Mod3'
   *  Sum: '<S7>/Add2'
   */
  ib = arm_sin_f32(-rt_modf(rtb_Merge - 2.09439516F, 6.28318548F));

  /* Trigonometry: '<S7>/Sin2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant3'
   *  Gain: '<S7>/Gain2'
   *  Math: '<S7>/Mod4'
   *  Sum: '<S7>/Add3'
   */
  ic = arm_sin_f32(-rt_modf(rtb_Merge + 2.09439516F, 6.28318548F));

  /* Sum: '<S8>/Minus1' incorporates:
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Sum: '<S8>/Plus'
   */
  ialpha = 0.666666687F * ia - (ib + ic) * 0.333333343F;

  /* If: '<S14>/If' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  Sum: '<S4>/Sum'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Sum);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Sum);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* SignalConversion generated from: '<S16>/In1' */
    rtb_Sum = rtDW.UnitDelay_DSTATE_j + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem2' */
  }

  /* End of If: '<S14>/If' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_Sum_n = arm_cos_f32(rtb_Sum);

  /* Gain: '<S8>/Gain2' incorporates:
   *  Sum: '<S8>/Minus'
   */
  ibeta = (ib - ic) * 0.577350259F;

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = arm_sin_f32(rtb_Sum);

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  id = ialpha * rtb_Sum_n + ibeta * rtb_SinCos;

  /* Sum: '<S5>/Minus' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  iq = ibeta * rtb_Sum_n - ialpha * rtb_SinCos;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Merge;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_j = rtb_Sum;

  /* Outport: '<Root>/ualpha' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Minus'
   */
  rtY.ualpha = id * rtb_Sum_n - iq * rtb_SinCos;

  /* Outport: '<Root>/ubeta' incorporates:
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Plus'
   */
  rtY.ubeta = id * rtb_SinCos + iq * rtb_Sum_n;

  /* End of Outputs for SubSystem: '<Root>/ParkTest' */
}

/* Model initialize function */
void ParkTest_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
