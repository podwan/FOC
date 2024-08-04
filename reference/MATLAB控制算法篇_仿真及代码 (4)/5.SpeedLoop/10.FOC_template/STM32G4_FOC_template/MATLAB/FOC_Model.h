/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Nov 25 13:32:26 2023
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
#include <float.h>
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
  real_T Motor_state;                  /* '<S2>/Chart' */
  real_T ZReset;                       /* '<S2>/Chart' */
  real_T cnt;                          /* '<S2>/Chart' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T Saturation;                 /* '<S159>/Saturation' */
  real32_T Integrator_DSTATE;          /* '<S101>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S9>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_h;        /* '<S152>/Integrator' */
  real32_T Integrator_PREV_U;          /* '<S152>/Integrator' */
  uint32_T speedloop_PREV_T;           /* '<S1>/speedloop' */
  int16_T Integrator_DSTATE_p;         /* '<S51>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S9>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S9>/Discrete-Time Integrator1' */
  uint8_T is_active_c3_FOC_Model;      /* '<S2>/Chart' */
  uint8_T is_c3_FOC_Model;             /* '<S2>/Chart' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S152>/Integrator' */
  boolean_T speedloop_RESET_ELAPS_T;   /* '<S1>/speedloop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real32_T SpeedFd;                    /* '<Root>/SpeedFd' */
  real32_T theta;                      /* '<Root>/theta' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct motor_tag {
  real32_T Pn;                         /* Referenced by: '<S9>/Gain' */
} motor_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S149>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S157>/Proportional Gain' */
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
extern real32_T ThetaOpen;             /* '<S2>/Merge' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern motor_type motor;
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
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
 * '<S5>'   : 'speedloop/FOC_Model/currloop/Chart'
 * '<S6>'   : 'speedloop/FOC_Model/currloop/Clark'
 * '<S7>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem'
 * '<S8>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem1'
 * '<S9>'   : 'speedloop/FOC_Model/currloop/If Action Subsystem2'
 * '<S10>'  : 'speedloop/FOC_Model/currloop/If Action Subsystem3'
 * '<S11>'  : 'speedloop/FOC_Model/currloop/Park'
 * '<S12>'  : 'speedloop/FOC_Model/currloop/SVPWM'
 * '<S13>'  : 'speedloop/FOC_Model/currloop/idq_Controller'
 * '<S14>'  : 'speedloop/FOC_Model/currloop/SVPWM/AntiClark'
 * '<S15>'  : 'speedloop/FOC_Model/currloop/SVPWM/ei_t'
 * '<S16>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1'
 * '<S17>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2'
 * '<S18>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup'
 * '<S19>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain'
 * '<S20>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter'
 * '<S21>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs'
 * '<S22>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain'
 * '<S23>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S24>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S25>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator'
 * '<S26>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S27>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy'
 * '<S28>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain'
 * '<S29>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy'
 * '<S30>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S31>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal'
 * '<S32>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation'
 * '<S33>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S34>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum'
 * '<S35>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S36>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S37>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S38>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S39>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S40>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal'
 * '<S41>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal'
 * '<S42>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S43>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S44>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S45>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S46>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S47>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S48>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S49>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S50>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S51>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S52>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S53>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S54>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S55>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S56>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S57>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S58>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S59>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S60>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S61>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S62>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S63>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S64>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S65>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S66>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S67>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S68>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup'
 * '<S69>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain'
 * '<S70>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter'
 * '<S71>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs'
 * '<S72>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain'
 * '<S73>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S74>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S75>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator'
 * '<S76>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S77>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy'
 * '<S78>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain'
 * '<S79>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy'
 * '<S80>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S81>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal'
 * '<S82>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation'
 * '<S83>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S84>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum'
 * '<S85>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S86>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S87>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S88>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S89>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S90>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal'
 * '<S91>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal'
 * '<S92>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S93>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S94>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S95>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S96>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S97>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S98>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S99>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S100>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S102>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S103>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S104>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S105>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S106>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S107>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S108>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S109>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S110>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S111>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S112>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S113>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S115>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S117>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S118>' : 'speedloop/FOC_Model/speedloop/PID Controller3'
 * '<S119>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup'
 * '<S120>' : 'speedloop/FOC_Model/speedloop/PID Controller3/D Gain'
 * '<S121>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter'
 * '<S122>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter ICs'
 * '<S123>' : 'speedloop/FOC_Model/speedloop/PID Controller3/I Gain'
 * '<S124>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain'
 * '<S125>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain Fdbk'
 * '<S126>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator'
 * '<S127>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator ICs'
 * '<S128>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Copy'
 * '<S129>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Gain'
 * '<S130>' : 'speedloop/FOC_Model/speedloop/PID Controller3/P Copy'
 * '<S131>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Parallel P Gain'
 * '<S132>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Reset Signal'
 * '<S133>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation'
 * '<S134>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation Fdbk'
 * '<S135>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum'
 * '<S136>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum Fdbk'
 * '<S137>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode'
 * '<S138>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode Sum'
 * '<S139>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Integral'
 * '<S140>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Ngain'
 * '<S141>' : 'speedloop/FOC_Model/speedloop/PID Controller3/postSat Signal'
 * '<S142>' : 'speedloop/FOC_Model/speedloop/PID Controller3/preSat Signal'
 * '<S143>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S144>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S145>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S146>' : 'speedloop/FOC_Model/speedloop/PID Controller3/D Gain/Disabled'
 * '<S147>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter/Disabled'
 * '<S148>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Filter ICs/Disabled'
 * '<S149>' : 'speedloop/FOC_Model/speedloop/PID Controller3/I Gain/Internal Parameters'
 * '<S150>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S151>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S152>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator/Discrete'
 * '<S153>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Integrator ICs/Internal IC'
 * '<S154>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S155>' : 'speedloop/FOC_Model/speedloop/PID Controller3/N Gain/Disabled'
 * '<S156>' : 'speedloop/FOC_Model/speedloop/PID Controller3/P Copy/Disabled'
 * '<S157>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S158>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Reset Signal/Disabled'
 * '<S159>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation/Enabled'
 * '<S160>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S161>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum/Sum_PI'
 * '<S162>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Sum Fdbk/Disabled'
 * '<S163>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode/Disabled'
 * '<S164>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S165>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S166>' : 'speedloop/FOC_Model/speedloop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S167>' : 'speedloop/FOC_Model/speedloop/PID Controller3/postSat Signal/Forward_Path'
 * '<S168>' : 'speedloop/FOC_Model/speedloop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
