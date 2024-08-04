/*
 * File: ClarkTest.h
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

#ifndef RTW_HEADER_ClarkTest_h_
#define RTW_HEADER_ClarkTest_h_
#ifndef ClarkTest_COMMON_INCLUDES_
#define ClarkTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ClarkTest_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
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
extern real32_T ia;                    /* '<S3>/Sin' */
extern real32_T ib;                    /* '<S3>/Sin1' */
extern real32_T ic;                    /* '<S3>/Sin2' */

/* Model entry point functions */
extern void ClarkTest_initialize(void);
extern void ClarkTest_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
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
 * hilite_system('FOC/ClarkTest')    - opens subsystem FOC/ClarkTest
 * hilite_system('FOC/ClarkTest/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC'
 * '<S1>'   : 'FOC/ClarkTest'
 * '<S2>'   : 'FOC/ClarkTest/Subsystem'
 * '<S3>'   : 'FOC/ClarkTest/ThreeCurrGenerator'
 * '<S4>'   : 'FOC/ClarkTest/Subsystem/Clark'
 * '<S5>'   : 'FOC/ClarkTest/ThreeCurrGenerator/FreqGenerator'
 * '<S6>'   : 'FOC/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit'
 * '<S7>'   : 'FOC/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S8>'   : 'FOC/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S9>'   : 'FOC/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_ClarkTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
