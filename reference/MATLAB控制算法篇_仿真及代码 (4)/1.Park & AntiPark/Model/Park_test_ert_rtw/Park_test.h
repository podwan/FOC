/*
 * File: Park_test.h
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

#ifndef RTW_HEADER_Park_test_h_
#define RTW_HEADER_Park_test_h_
#include <float.h>
#include <math.h>
#ifndef Park_test_COMMON_INCLUDES_
#define Park_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Park_test_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
  real32_T UnitDelay_DSTATE_j;         /* '<S8>/Unit Delay' */
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
extern real32_T id;                    /* '<S5>/Add' */
extern real32_T iq;                    /* '<S5>/Add1' */
extern real32_T ic;                    /* '<S7>/Sin2' */
extern real32_T ia;                    /* '<S7>/Sin' */
extern real32_T ialpha;                /* '<S6>/Add1' */
extern real32_T ibeta;                 /* '<S6>/Gain2' */

/* Model entry point functions */
extern void Park_test_initialize(void);
extern void Park_test_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
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
 * hilite_system('ParkAntiPark/Park_test')    - opens subsystem ParkAntiPark/Park_test
 * hilite_system('ParkAntiPark/Park_test/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ParkAntiPark'
 * '<S1>'   : 'ParkAntiPark/Park_test'
 * '<S2>'   : 'ParkAntiPark/Park_test/AntiPark'
 * '<S3>'   : 'ParkAntiPark/Park_test/Clark_test'
 * '<S4>'   : 'ParkAntiPark/Park_test/FreqGenerator'
 * '<S5>'   : 'ParkAntiPark/Park_test/Park'
 * '<S6>'   : 'ParkAntiPark/Park_test/Clark_test/Clark'
 * '<S7>'   : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator'
 * '<S8>'   : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator/FreqGenerator'
 * '<S9>'   : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit'
 * '<S10>'  : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S11>'  : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S12>'  : 'ParkAntiPark/Park_test/Clark_test/ThreeCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S13>'  : 'ParkAntiPark/Park_test/FreqGenerator/RangeLimit'
 * '<S14>'  : 'ParkAntiPark/Park_test/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S15>'  : 'ParkAntiPark/Park_test/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S16>'  : 'ParkAntiPark/Park_test/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Park_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
