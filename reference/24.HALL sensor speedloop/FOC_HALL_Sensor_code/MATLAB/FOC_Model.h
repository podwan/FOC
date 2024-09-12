/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue May  7 22:05:49 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_Model_h_
#define RTW_HEADER_FOC_Model_h_
#include <stddef.h>
#include <math.h>
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

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
  real32_T RateTransition2;            /* '<S1>/Rate Transition2' */
  real32_T Integrator_DSTATE;          /* '<S96>/Integrator' */
  real32_T Integrator_DSTATE_h;        /* '<S150>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  real32_T RateTransition2_Buffer0;    /* '<S1>/Rate Transition2' */
  real32_T Integrator_PREV_U;          /* '<S150>/Integrator' */
  uint32_T speedloop_PREV_T;           /* '<S1>/speedloop' */
  int16_T Integrator_DSTATE_p;         /* '<S46>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S150>/Integrator' */
  boolean_T speedloop_RESET_ELAPS_T;   /* '<S1>/speedloop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T Speed;                      /* '<Root>/Speed' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S147>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S155>/Proportional Gain' */
} spd_kpki_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
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
extern real32_T IqRef;                 /* '<S157>/Saturation' */
extern real32_T Wm;                    /* '<S3>/Gain2' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
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
 * hilite_system('speedloop/FOC_Model')    - opens subsystem speedloop/FOC_Model
 * hilite_system('speedloop/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'speedloop'
 * '<S1>'   : 'speedloop/FOC_Model'
 * '<S2>'   : 'speedloop/FOC_Model/currloop'
 * '<S3>'   : 'speedloop/FOC_Model/speedloop'
 * '<S4>'   : 'speedloop/FOC_Model/currloop/AntiPark'
 * '<S5>'   : 'speedloop/FOC_Model/currloop/Clark'
 * '<S6>'   : 'speedloop/FOC_Model/currloop/Park'
 * '<S7>'   : 'speedloop/FOC_Model/currloop/SVPWM'
 * '<S8>'   : 'speedloop/FOC_Model/currloop/idq_Controller'
 * '<S9>'   : 'speedloop/FOC_Model/currloop/SVPWM/AntiClark'
 * '<S10>'  : 'speedloop/FOC_Model/currloop/SVPWM/ei_t'
 * '<S11>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1'
 * '<S12>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2'
 * '<S13>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup'
 * '<S14>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain'
 * '<S15>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter'
 * '<S16>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs'
 * '<S17>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain'
 * '<S18>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S19>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S20>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator'
 * '<S21>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S22>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy'
 * '<S23>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain'
 * '<S24>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy'
 * '<S25>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S26>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal'
 * '<S27>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation'
 * '<S28>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S29>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum'
 * '<S30>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S31>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S32>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S33>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S34>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S35>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal'
 * '<S36>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal'
 * '<S37>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S38>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S39>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S40>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S41>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S42>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S43>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S44>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S45>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S47>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S48>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S49>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S50>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S51>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S52>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S53>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S54>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S55>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S56>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S57>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S58>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S59>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S60>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S61>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S62>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S63>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup'
 * '<S64>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain'
 * '<S65>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter'
 * '<S66>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs'
 * '<S67>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain'
 * '<S68>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S69>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S70>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator'
 * '<S71>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S72>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy'
 * '<S73>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain'
 * '<S74>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy'
 * '<S75>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S76>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal'
 * '<S77>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation'
 * '<S78>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S79>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum'
 * '<S80>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S81>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S82>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S83>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S84>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S85>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal'
 * '<S86>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal'
 * '<S87>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S88>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S89>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S90>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S91>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S92>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S93>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S94>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S95>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S97>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S98>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S100>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S101>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S102>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S103>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S104>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S105>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S106>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S107>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S108>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S110>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S112>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S113>' : 'speedloop/FOC_Model/speedloop/If Action Subsystem'
 * '<S114>' : 'speedloop/FOC_Model/speedloop/If Action Subsystem1'
 * '<S115>' : 'speedloop/FOC_Model/speedloop/If Action Subsystem2'
 * '<S116>' : 'speedloop/FOC_Model/speedloop/PID Controller3'
 * '<S117>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup'
 * '<S118>' : 'speedloop/FOC_Model/speedloop/PID Controller3/D Gain'
 * '<S119>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter'
 * '<S120>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter ICs'
 * '<S121>' : 'speedloop/FOC_Model/speedloop/PID Controller3/I Gain'
 * '<S122>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain'
 * '<S123>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain Fdbk'
 * '<S124>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator'
 * '<S125>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator ICs'
 * '<S126>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Copy'
 * '<S127>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Gain'
 * '<S128>' : 'speedloop/FOC_Model/speedloop/PID Controller3/P Copy'
 * '<S129>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Parallel P Gain'
 * '<S130>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Reset Signal'
 * '<S131>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation'
 * '<S132>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation Fdbk'
 * '<S133>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum'
 * '<S134>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum Fdbk'
 * '<S135>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode'
 * '<S136>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode Sum'
 * '<S137>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Integral'
 * '<S138>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Ngain'
 * '<S139>' : 'speedloop/FOC_Model/speedloop/PID Controller3/postSat Signal'
 * '<S140>' : 'speedloop/FOC_Model/speedloop/PID Controller3/preSat Signal'
 * '<S141>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S142>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S143>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S144>' : 'speedloop/FOC_Model/speedloop/PID Controller3/D Gain/Disabled'
 * '<S145>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter/Disabled'
 * '<S146>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter ICs/Disabled'
 * '<S147>' : 'speedloop/FOC_Model/speedloop/PID Controller3/I Gain/Internal Parameters'
 * '<S148>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S149>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S150>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator/Discrete'
 * '<S151>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator ICs/Internal IC'
 * '<S152>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S153>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Gain/Disabled'
 * '<S154>' : 'speedloop/FOC_Model/speedloop/PID Controller3/P Copy/Disabled'
 * '<S155>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S156>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Reset Signal/Disabled'
 * '<S157>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation/Enabled'
 * '<S158>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S159>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum/Sum_PI'
 * '<S160>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum Fdbk/Disabled'
 * '<S161>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode/Disabled'
 * '<S162>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S163>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S164>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S165>' : 'speedloop/FOC_Model/speedloop/PID Controller3/postSat Signal/Forward_Path'
 * '<S166>' : 'speedloop/FOC_Model/speedloop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
