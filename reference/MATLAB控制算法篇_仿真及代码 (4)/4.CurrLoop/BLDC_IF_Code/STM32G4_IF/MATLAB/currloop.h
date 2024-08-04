/*
 * File: currloop.h
 *
 * Code generated for Simulink model 'currloop'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Sep  2 20:53:54 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_currloop_h_
#define RTW_HEADER_currloop_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef currloop_COMMON_INCLUDES_
#define currloop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* currloop_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Motor_state;                  /* '<S1>/Chart' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S99>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_c;/* '<S7>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE_p;         /* '<S49>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_currloop;       /* '<S1>/Chart' */
  uint8_T is_c3_currloop;              /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct motor_tag {
  real32_T Pn;                         /* Referenced by:
                                        * '<S7>/Gain'
                                        * '<S8>/Gain'
                                        */
} motor_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

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
extern real32_T ThetaOpen;             /* '<S1>/Merge' */

/* Model entry point functions */
extern void currloop_initialize(void);
extern void currloop_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern motor_type motor;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
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
 * hilite_system('IF/currloop')    - opens subsystem IF/currloop
 * hilite_system('IF/currloop/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IF'
 * '<S1>'   : 'IF/currloop'
 * '<S2>'   : 'IF/currloop/AntiPark'
 * '<S3>'   : 'IF/currloop/Chart'
 * '<S4>'   : 'IF/currloop/Clark'
 * '<S5>'   : 'IF/currloop/If Action Subsystem'
 * '<S6>'   : 'IF/currloop/If Action Subsystem1'
 * '<S7>'   : 'IF/currloop/If Action Subsystem2'
 * '<S8>'   : 'IF/currloop/If Action Subsystem3'
 * '<S9>'   : 'IF/currloop/Park'
 * '<S10>'  : 'IF/currloop/SVPWM'
 * '<S11>'  : 'IF/currloop/idq_Controller'
 * '<S12>'  : 'IF/currloop/SVPWM/AntiClark'
 * '<S13>'  : 'IF/currloop/SVPWM/ei_t'
 * '<S14>'  : 'IF/currloop/idq_Controller/PID Controller1'
 * '<S15>'  : 'IF/currloop/idq_Controller/PID Controller2'
 * '<S16>'  : 'IF/currloop/idq_Controller/PID Controller1/Anti-windup'
 * '<S17>'  : 'IF/currloop/idq_Controller/PID Controller1/D Gain'
 * '<S18>'  : 'IF/currloop/idq_Controller/PID Controller1/Filter'
 * '<S19>'  : 'IF/currloop/idq_Controller/PID Controller1/Filter ICs'
 * '<S20>'  : 'IF/currloop/idq_Controller/PID Controller1/I Gain'
 * '<S21>'  : 'IF/currloop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S22>'  : 'IF/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S23>'  : 'IF/currloop/idq_Controller/PID Controller1/Integrator'
 * '<S24>'  : 'IF/currloop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S25>'  : 'IF/currloop/idq_Controller/PID Controller1/N Copy'
 * '<S26>'  : 'IF/currloop/idq_Controller/PID Controller1/N Gain'
 * '<S27>'  : 'IF/currloop/idq_Controller/PID Controller1/P Copy'
 * '<S28>'  : 'IF/currloop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S29>'  : 'IF/currloop/idq_Controller/PID Controller1/Reset Signal'
 * '<S30>'  : 'IF/currloop/idq_Controller/PID Controller1/Saturation'
 * '<S31>'  : 'IF/currloop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S32>'  : 'IF/currloop/idq_Controller/PID Controller1/Sum'
 * '<S33>'  : 'IF/currloop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S34>'  : 'IF/currloop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S35>'  : 'IF/currloop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S36>'  : 'IF/currloop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S37>'  : 'IF/currloop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S38>'  : 'IF/currloop/idq_Controller/PID Controller1/postSat Signal'
 * '<S39>'  : 'IF/currloop/idq_Controller/PID Controller1/preSat Signal'
 * '<S40>'  : 'IF/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S41>'  : 'IF/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S42>'  : 'IF/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S43>'  : 'IF/currloop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S44>'  : 'IF/currloop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S45>'  : 'IF/currloop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S46>'  : 'IF/currloop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S47>'  : 'IF/currloop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'IF/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'IF/currloop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'IF/currloop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'IF/currloop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S52>'  : 'IF/currloop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S53>'  : 'IF/currloop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'IF/currloop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S55>'  : 'IF/currloop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'IF/currloop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S57>'  : 'IF/currloop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'IF/currloop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S59>'  : 'IF/currloop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'IF/currloop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'IF/currloop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'IF/currloop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S63>'  : 'IF/currloop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'IF/currloop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'IF/currloop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S66>'  : 'IF/currloop/idq_Controller/PID Controller2/Anti-windup'
 * '<S67>'  : 'IF/currloop/idq_Controller/PID Controller2/D Gain'
 * '<S68>'  : 'IF/currloop/idq_Controller/PID Controller2/Filter'
 * '<S69>'  : 'IF/currloop/idq_Controller/PID Controller2/Filter ICs'
 * '<S70>'  : 'IF/currloop/idq_Controller/PID Controller2/I Gain'
 * '<S71>'  : 'IF/currloop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S72>'  : 'IF/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S73>'  : 'IF/currloop/idq_Controller/PID Controller2/Integrator'
 * '<S74>'  : 'IF/currloop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S75>'  : 'IF/currloop/idq_Controller/PID Controller2/N Copy'
 * '<S76>'  : 'IF/currloop/idq_Controller/PID Controller2/N Gain'
 * '<S77>'  : 'IF/currloop/idq_Controller/PID Controller2/P Copy'
 * '<S78>'  : 'IF/currloop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S79>'  : 'IF/currloop/idq_Controller/PID Controller2/Reset Signal'
 * '<S80>'  : 'IF/currloop/idq_Controller/PID Controller2/Saturation'
 * '<S81>'  : 'IF/currloop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S82>'  : 'IF/currloop/idq_Controller/PID Controller2/Sum'
 * '<S83>'  : 'IF/currloop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S84>'  : 'IF/currloop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S85>'  : 'IF/currloop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S86>'  : 'IF/currloop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S87>'  : 'IF/currloop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S88>'  : 'IF/currloop/idq_Controller/PID Controller2/postSat Signal'
 * '<S89>'  : 'IF/currloop/idq_Controller/PID Controller2/preSat Signal'
 * '<S90>'  : 'IF/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S91>'  : 'IF/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S92>'  : 'IF/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S93>'  : 'IF/currloop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S94>'  : 'IF/currloop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S95>'  : 'IF/currloop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S96>'  : 'IF/currloop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S97>'  : 'IF/currloop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S98>'  : 'IF/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'IF/currloop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S100>' : 'IF/currloop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S101>' : 'IF/currloop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'IF/currloop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S103>' : 'IF/currloop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S104>' : 'IF/currloop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S105>' : 'IF/currloop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S106>' : 'IF/currloop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S107>' : 'IF/currloop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S108>' : 'IF/currloop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S109>' : 'IF/currloop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S110>' : 'IF/currloop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S111>' : 'IF/currloop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'IF/currloop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S113>' : 'IF/currloop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'IF/currloop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S115>' : 'IF/currloop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_currloop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
