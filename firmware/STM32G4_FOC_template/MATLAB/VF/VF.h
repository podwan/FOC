/*
 * File: VF.h
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

#ifndef RTW_HEADER_VF_h_
#define RTW_HEADER_VF_h_
#ifndef VF_COMMON_INCLUDES_
#define VF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* VF_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ud;                           /* '<Root>/ud' */
  real_T uq;                           /* '<Root>/uq' */
  real_T Freq;                         /* '<Root>/Freq' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T tABC[3];                      /* '<Root>/tABC' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void VF_initialize(void);
extern void VF_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion4' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FOC/VF mode')    - opens subsystem FOC/VF mode
 * hilite_system('FOC/VF mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC'
 * '<S1>'   : 'FOC/VF mode'
 * '<S2>'   : 'FOC/VF mode/AntiPark'
 * '<S3>'   : 'FOC/VF mode/FreqGenerator'
 * '<S4>'   : 'FOC/VF mode/SVPWM'
 * '<S5>'   : 'FOC/VF mode/FreqGenerator/RangeLimit'
 * '<S6>'   : 'FOC/VF mode/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S7>'   : 'FOC/VF mode/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S8>'   : 'FOC/VF mode/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S9>'   : 'FOC/VF mode/SVPWM/AntiClark'
 * '<S10>'  : 'FOC/VF mode/SVPWM/center'
 */
#endif                                 /* RTW_HEADER_VF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
