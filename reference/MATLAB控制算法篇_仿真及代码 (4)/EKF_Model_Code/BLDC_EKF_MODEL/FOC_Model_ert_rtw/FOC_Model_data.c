/*
 * File: FOC_Model_data.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 2.183
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Oct 22 20:56:15 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  /* Start of '<S1>/Curr_loop' */
  {
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F }/* '<S18>/Transpose' */
  }
  /* End of '<S1>/Curr_loop' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Computed Parameter: B_Value
   * Referenced by: '<S6>/B'
   */
  { 186.915894F, 0.0F, 0.0F, 0.0F, 0.0F, 186.915894F, 0.0F, 0.0F },

  /* Computed Parameter: H_Value
   * Referenced by: '<S6>/H'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Q_Value
   * Referenced by: '<S6>/Q'
   */
  { 0.001F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.0F, 0.0F, 0.0F, 0.0F, 10.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.01F },

  /* Computed Parameter: R_Value
   * Referenced by: '<S6>/R'
   */
  { 0.1F, 0.0F, 0.0F, 0.1F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/IdentityMatrix'
   *   '<S19>/IdentityMatrix'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
