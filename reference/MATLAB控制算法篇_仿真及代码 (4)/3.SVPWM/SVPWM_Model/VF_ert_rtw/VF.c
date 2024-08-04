/*
 * File: VF.c
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Aug 27 12:37:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "VF.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3]);
static void VFmode(void);

/* Output and update for atomic system: '<S1>/SVPWM' */
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_j;
  real32_T rtb_Sum_p;

  /* Gain: '<S9>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S9>/Gain1' */
  rtb_Sum1_j = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S9>/Sum' */
  rtb_Sum_p = rtb_Min + rtb_Sum1_j;

  /* Sum: '<S9>/Sum1' */
  rtb_Sum1_j = rtb_Min - rtb_Sum1_j;

  /* Gain: '<S10>/Gain' incorporates:
   *  MinMax: '<S10>/Min'
   *  MinMax: '<S10>/Min1'
   *  Sum: '<S10>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_p), rtb_Sum1_j) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_p), rtb_Sum1_j)) * -0.5F;

  /* Sum: '<S4>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_p;
  rty_tABC[2] = rtb_Min + rtb_Sum1_j;

  /* Gain: '<S4>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Sum1'
   */
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * 8000.0F;
}

/* Output and update for atomic system: '<Root>/VF mode' */
static void VFmode(void)
{
  real32_T rtb_SinCos;
  real32_T rtb_SinCos1;
  real32_T rtb_Sum;

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Sum = 0.000628318521F * rtU.Freq + rtDW.UnitDelay_DSTATE;

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   */
  if (rtb_Sum > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Sum -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  } else if (rtb_Sum < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum += 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
  }

  /* End of If: '<S5>/If' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_SinCos1 = arm_cos_f32(rtb_Sum);

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = arm_sin_f32(rtb_Sum);

  /* Outputs for Atomic SubSystem: '<S1>/SVPWM' */
  /* Sum: '<S2>/Add' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Inport: '<Root>/v_bus'
   *  Outport: '<Root>/tABC'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add1'
   */
  SVPWM(rtU.ud * rtb_SinCos1 - rtU.uq * rtb_SinCos, rtU.ud * rtb_SinCos + rtU.uq
        * rtb_SinCos1, rtU.v_bus, rtY.tABC);

  /* End of Outputs for SubSystem: '<S1>/SVPWM' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum;
}

/* Model step function */
void VF_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/VF mode' */
  VFmode();

  /* End of Outputs for SubSystem: '<Root>/VF mode' */
}

/* Model initialize function */
void VF_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
