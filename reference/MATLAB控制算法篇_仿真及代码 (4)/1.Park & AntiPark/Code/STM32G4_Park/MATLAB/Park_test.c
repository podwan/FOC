/*
 * File: Park_test.c
 *
 * Code generated for Simulink model 'Park_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Aug  6 13:51:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Park_test.h"

/* Exported block signals */
real32_T id;                           /* '<S5>/Add' */
real32_T iq;                           /* '<S5>/Add1' */
real32_T ic;                           /* '<S7>/Sin2' */
real32_T ia;                           /* '<S7>/Sin' */
real32_T ialpha;                       /* '<S6>/Add1' */
real32_T ibeta;                        /* '<S6>/Gain2' */

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1);
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1);
static void Clark_test(void);

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem1'
 *    '<S13>/If Action Subsystem1'
 */
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem3'
 *    '<S13>/If Action Subsystem3'
 */
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S12>/Sum' incorporates:
   *  Constant: '<S12>/Constant'
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

/* Output and update for atomic system: '<S1>/Clark_test' */
static void Clark_test(void)
{
  real32_T rtb_Merge;
  real32_T rtb_Sum;

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Inport: '<S11>/In1'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  RelationalOperator: '<S9>/Relational Operator1'
   *  Sum: '<S8>/Sum'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    rtb_Merge = rtDW.UnitDelay_DSTATE_j + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S9>/If Action Subsystem2' */
  }

  /* End of If: '<S9>/If' */

  /* Trigonometry: '<S7>/Sin1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Gain: '<S7>/Gain1'
   *  Math: '<S7>/Mod3'
   *  Sum: '<S7>/Add2'
   */
  rtb_Sum = arm_sin_f32(-rt_modf(rtb_Merge + -2.09439516F, 6.28318548F));

  /* Trigonometry: '<S7>/Sin2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant3'
   *  Gain: '<S7>/Gain2'
   *  Math: '<S7>/Mod4'
   *  Sum: '<S7>/Add3'
   */
  ic = arm_sin_f32(-rt_modf(rtb_Merge + 2.09439516F, 6.28318548F));

  /* Trigonometry: '<S7>/Sin' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain'
   *  Math: '<S7>/Mod'
   *  Sum: '<S7>/Add1'
   */
  ia = arm_sin_f32(-rt_modf(rtb_Merge, 6.28318548F));

  /* Sum: '<S6>/Add1' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Sum: '<S6>/Add'
   */
  ialpha = 0.666666687F * ia - (rtb_Sum + ic) * 0.333333343F;

  /* Gain: '<S6>/Gain2' incorporates:
   *  Sum: '<S6>/Add2'
   */
  ibeta = (rtb_Sum - ic) * 0.577350259F;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_j = rtb_Merge;
}

/* Model step function */
void Park_test_step(void)
{
  real32_T rtb_Merge;
  real32_T rtb_SinCos;
  real32_T rtb_Sum;

  /* Outputs for Atomic SubSystem: '<Root>/Park_test' */
  /* Outputs for Atomic SubSystem: '<S1>/Clark_test' */
  Clark_test();

  /* End of Outputs for SubSystem: '<S1>/Clark_test' */

  /* If: '<S13>/If' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   *  Inport: '<S15>/In1'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  Sum: '<S4>/Sum'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    rtb_Merge = rtDW.UnitDelay_DSTATE + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem2' */
  }

  /* End of If: '<S13>/If' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_Sum = arm_cos_f32(rtb_Merge);

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = arm_sin_f32(rtb_Merge);

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  id = ialpha * rtb_Sum + ibeta * rtb_SinCos;

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  iq = ibeta * rtb_Sum - ialpha * rtb_SinCos;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Merge;

  /* Outport: '<Root>/ualpha' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Add'
   */
  rtY.ualpha = id * rtb_Sum - iq * rtb_SinCos;

  /* Outport: '<Root>/ubeta' incorporates:
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add1'
   */
  rtY.ubeta = id * rtb_SinCos + iq * rtb_Sum;

  /* End of Outputs for SubSystem: '<Root>/Park_test' */
}

/* Model initialize function */
void Park_test_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
