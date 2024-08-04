/*
 * File: VF.h
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

#ifndef RTW_HEADER_VF_h_
#define RTW_HEADER_VF_h_
#include <math.h>
#ifndef VF_COMMON_INCLUDES_
#define VF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* VF_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ud;                         /* '<Root>/ud' */
  real32_T uq;                         /* '<Root>/uq' */
  real32_T Freq;                       /* '<Root>/Freq' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
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
 * hilite_system('SVPWM/VF mode')    - opens subsystem SVPWM/VF mode
 * hilite_system('SVPWM/VF mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SVPWM'
 * '<S1>'   : 'SVPWM/VF mode'
 * '<S2>'   : 'SVPWM/VF mode/AntiPark'
 * '<S3>'   : 'SVPWM/VF mode/FreqGenerator'
 * '<S4>'   : 'SVPWM/VF mode/SVPWM'
 * '<S5>'   : 'SVPWM/VF mode/FreqGenerator/RangeLimit'
 * '<S6>'   : 'SVPWM/VF mode/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S7>'   : 'SVPWM/VF mode/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S8>'   : 'SVPWM/VF mode/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S9>'   : 'SVPWM/VF mode/SVPWM/AntiClark'
 * '<S10>'  : 'SVPWM/VF mode/SVPWM/ei_t'
 */
#endif                                 /* RTW_HEADER_VF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
