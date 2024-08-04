/*
 * File: VF.c
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug  4 16:38:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "VF.h"
#include "mw_cmsis.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void VF_step(void)
{
  real_T rtb_Min;
  real_T rtb_Minus;
  real_T rtb_Sum1_b;
  real_T rtb_Sum_i;
  real32_T rtb_SinCos;
  real32_T rtb_SinCos1;
  real32_T rtb_Sum_n;

  /* Outputs for Atomic SubSystem: '<Root>/VF mode' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Sum_n = (real32_T)(0.00062831853071795862 * rtU.Freq) +
    rtDW.UnitDelay_DSTATE;

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   */
  if (rtb_Sum_n > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Sum_n -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  } else if (rtb_Sum_n < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum_n += 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
  }

  /* End of If: '<S5>/If' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_SinCos1 = arm_cos_f32(rtb_Sum_n);

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = arm_sin_f32(rtb_Sum_n);

  /* Sum: '<S2>/Minus' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_Minus = rtU.ud * rtb_SinCos1 - rtU.uq * rtb_SinCos;

  /* Gain: '<S9>/Gain' */
  rtb_Min = -0.5 * rtb_Minus;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Plus'
   */
  rtb_Sum1_b = (rtU.ud * rtb_SinCos + rtU.uq * rtb_SinCos1) * 0.8660254037844386;

  /* Sum: '<S9>/Sum' */
  rtb_Sum_i = rtb_Min + rtb_Sum1_b;

  /* Sum: '<S9>/Sum1' */
  rtb_Sum1_b = rtb_Min - rtb_Sum1_b;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Inport: '<Root>/v_bus'
   *  MinMax: '<S10>/Max'
   *  MinMax: '<S10>/Min'
   *  Sum: '<S10>/Sum'
   */
  rtb_Min = (fmin(fmin(rtb_Minus, rtb_Sum_i), rtb_Sum1_b) + fmax(fmax(rtb_Minus,
    rtb_Sum_i), rtb_Sum1_b)) * -0.5 + 0.5F * rtU.v_bus;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum_n;

  /* Outport: '<Root>/tABC' incorporates:
   *  Gain: '<S4>/PWM_halfPeriod'
   *  Inport: '<Root>/v_bus'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Sum'
   */
  rtY.tABC[0] = (rtb_Min + rtb_Minus) / rtU.v_bus * 8000.0;
  rtY.tABC[1] = (rtb_Min + rtb_Sum_i) / rtU.v_bus * 8000.0;
  rtY.tABC[2] = (rtb_Min + rtb_Sum1_b) / rtU.v_bus * 8000.0;

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
