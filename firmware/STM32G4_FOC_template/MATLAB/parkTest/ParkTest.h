/*
 * File: ParkTest.h
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

#ifndef RTW_HEADER_ParkTest_h_
#define RTW_HEADER_ParkTest_h_
#ifndef ParkTest_COMMON_INCLUDES_
#define ParkTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ParkTest_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S9>/Unit Delay' */
  real32_T UnitDelay_DSTATE_j;         /* '<S4>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T ualpha;                     /* '<Root>/ualpha' */
  real32_T ubeta;                      /* '<Root>/ubeta' */
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
extern real32_T ia;                    /* '<S7>/Sin' */
extern real32_T ib;                    /* '<S7>/Sin1' */
extern real32_T ic;                    /* '<S7>/Sin2' */
extern real32_T ialpha;                /* '<S8>/Minus1' */
extern real32_T ibeta;                 /* '<S8>/Gain2' */
extern real32_T id;                    /* '<S5>/Add' */
extern real32_T iq;                    /* '<S5>/Minus' */

/* Model entry point functions */
extern void ParkTest_initialize(void);
extern void ParkTest_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('FOC/ParkTest')    - opens subsystem FOC/ParkTest
 * hilite_system('FOC/ParkTest/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC'
 * '<S1>'   : 'FOC/ParkTest'
 * '<S2>'   : 'FOC/ParkTest/AntiPark'
 * '<S3>'   : 'FOC/ParkTest/ClarkTest'
 * '<S4>'   : 'FOC/ParkTest/FreqGenerator'
 * '<S5>'   : 'FOC/ParkTest/Park'
 * '<S6>'   : 'FOC/ParkTest/ClarkTest/Clark'
 * '<S7>'   : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator'
 * '<S8>'   : 'FOC/ParkTest/ClarkTest/Clark/Clark'
 * '<S9>'   : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator/FreqGenerator'
 * '<S10>'  : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit'
 * '<S11>'  : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S12>'  : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S13>'  : 'FOC/ParkTest/ClarkTest/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S14>'  : 'FOC/ParkTest/FreqGenerator/RangeLimit'
 * '<S15>'  : 'FOC/ParkTest/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S16>'  : 'FOC/ParkTest/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S17>'  : 'FOC/ParkTest/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_ParkTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
