/*
 * File: Clark_test.h
 *
 * Code generated for Simulink model 'Clark_test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Sep 17 21:22:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Clark_test_h_
#define RTW_HEADER_Clark_test_h_
#include <float.h>
#include <math.h>
#ifndef Clark_test_COMMON_INCLUDES_
#define Clark_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Clark_test_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T ialpha;                     /* '<Root>/ialpha' */
  real32_T ibeta;                      /* '<Root>/ibeta' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T ib;                    /* '<S3>/Sin1' */
extern real32_T ic;                    /* '<S3>/Sin2' */
extern real32_T ia;                    /* '<S3>/Sin' */

/* Model entry point functions */
extern void Clark_test_initialize(void);
extern void Clark_test_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S3>/Mod1' : Unused code path elimination
 * Block '<S3>/Mod2' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('Clark/Clark_test')    - opens subsystem Clark/Clark_test
 * hilite_system('Clark/Clark_test/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Clark'
 * '<S1>'   : 'Clark/Clark_test'
 * '<S2>'   : 'Clark/Clark_test/Clark'
 * '<S3>'   : 'Clark/Clark_test/ThreeCurrGenerator'
 * '<S4>'   : 'Clark/Clark_test/ThreeCurrGenerator/FreqGenerator'
 * '<S5>'   : 'Clark/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit'
 * '<S6>'   : 'Clark/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S7>'   : 'Clark/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S8>'   : 'Clark/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Clark_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
