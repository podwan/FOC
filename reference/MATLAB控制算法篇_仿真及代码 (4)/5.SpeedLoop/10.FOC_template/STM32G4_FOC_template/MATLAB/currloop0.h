/*
 * File: currloop0.h
 *
 * Code generated for Simulink model 'currloop0'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Nov 25 13:15:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_currloop0_h_
#define RTW_HEADER_currloop0_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef currloop0_COMMON_INCLUDES_
#define currloop0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* currloop0_COMMON_INCLUDES_ */

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
  real_T ZReset;                       /* '<S1>/Chart' */
  real_T cnt;                          /* '<S1>/Chart' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S99>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S7>/Discrete-Time Integrator1' */
  int16_T Integrator_DSTATE_p;         /* '<S49>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S7>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S7>/Discrete-Time Integrator1' */
  uint8_T is_active_c3_currloop0;      /* '<S1>/Chart' */
  uint8_T is_c3_currloop0;             /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
  real32_T iq_ref;                     /* '<Root>/iq_ref' */
  real32_T theta;                      /* '<Root>/theta' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct motor_tag {
  real32_T Pn;                         /* Referenced by: '<S7>/Gain' */
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
extern void currloop0_initialize(void);
extern void currloop0_step(void);

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
 * hilite_system('speedloop/FOC_Model/currloop')    - opens subsystem speedloop/FOC_Model/currloop
 * hilite_system('speedloop/FOC_Model/currloop/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'speedloop/FOC_Model'
 * '<S1>'   : 'speedloop/FOC_Model/currloop'
 * '<S2>'   : 'speedloop/FOC_Model/currloop/AntiPark'
 * '<S3>'   : 'speedloop/FOC_Model/currloop/Chart'
 * '<S4>'   : 'speedloop/FOC_Model/currloop/Clark'
 * '<S5>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem'
 * '<S6>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem1'
 * '<S7>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem2'
 * '<S8>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem3'
 * '<S9>'   : 'speedloop/FOC_Model/currloop/Park'
 * '<S10>'  : 'speedloop/FOC_Model/currloop/SVPWM'
 * '<S11>'  : 'speedloop/FOC_Model/currloop/idq_Controller'
 * '<S12>'  : 'speedloop/FOC_Model/currloop/SVPWM/AntiClark'
 * '<S13>'  : 'speedloop/FOC_Model/currloop/SVPWM/ei_t'
 * '<S14>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1'
 * '<S15>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2'
 * '<S16>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup'
 * '<S17>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain'
 * '<S18>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter'
 * '<S19>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs'
 * '<S20>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain'
 * '<S21>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S22>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S23>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator'
 * '<S24>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S25>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy'
 * '<S26>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain'
 * '<S27>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy'
 * '<S28>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S29>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal'
 * '<S30>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation'
 * '<S31>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S32>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum'
 * '<S33>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S34>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S35>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S36>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S37>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S38>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal'
 * '<S39>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal'
 * '<S40>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S41>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S42>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S43>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S44>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S45>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S46>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S47>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S52>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S53>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S55>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S57>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S59>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S63>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S66>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup'
 * '<S67>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain'
 * '<S68>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter'
 * '<S69>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs'
 * '<S70>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain'
 * '<S71>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S72>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S73>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator'
 * '<S74>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S75>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy'
 * '<S76>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain'
 * '<S77>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy'
 * '<S78>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S79>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal'
 * '<S80>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation'
 * '<S81>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S82>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum'
 * '<S83>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S84>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S85>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S86>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S87>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S88>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal'
 * '<S89>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal'
 * '<S90>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S91>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S92>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S93>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S94>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S95>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S96>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S97>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S98>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S100>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S101>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S103>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S104>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S105>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S106>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S107>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S108>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S109>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S110>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S111>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S113>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S115>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_currloop0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
