/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jul 17 11:14:46 2024
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
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_struct_9tIy2hpXIgA1EOi7WWu7i_
#define DEFINED_TYPEDEF_FOR_struct_9tIy2hpXIgA1EOi7WWu7i_

typedef struct {
  real_T nonLinear;
} struct_9tIy2hpXIgA1EOi7WWu7i;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T RateTransition2;            /* '<S1>/Rate Transition2' */
  real32_T Saturation;                 /* '<S162>/Saturation' */
  real32_T Integrator_DSTATE;          /* '<S100>/Integrator' */
  real32_T Integrator_DSTATE_h;        /* '<S155>/Integrator' */
  real32_T RateTransition2_Buffer0;    /* '<S1>/Rate Transition2' */
  real32_T Integrator_PREV_U;          /* '<S155>/Integrator' */
  uint32_T Subsystem_PREV_T;           /* '<S3>/Subsystem' */
  int16_T Integrator_DSTATE_p;         /* '<S50>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S155>/Integrator' */
  boolean_T Subsystem_RESET_ELAPS_T;   /* '<S3>/Subsystem' */
  boolean_T Subsystem_MODE;            /* '<S3>/Subsystem' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T VBUS;                       /* '<Root>/VBUS' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T Speed;                      /* '<Root>/Speed' */
  real32_T Loop_Mode;                  /* '<Root>/Loop_Mode' */
  real32_T CurrMode_IqRef;             /* '<Root>/CurrMode_IqRef' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct curr_kpki_tag {
  real32_T CurrKi;                     /* Referenced by:
                                        * '<S9>/Constant2'
                                        * '<S9>/Constant4'
                                        */
  real32_T CurrKp;                     /* Referenced by:
                                        * '<S9>/Constant1'
                                        * '<S9>/Constant3'
                                        */
} curr_kpki_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S152>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S160>/Proportional Gain' */
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
extern real32_T Torque;                /* '<S11>/1_5_Pp' */
extern real32_T Power;                 /* '<S11>/Product' */
extern real32_T IqRef;                 /* '<S3>/Merge' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern curr_kpki_type curr_kpki;
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S12>/Gain' : Eliminated nontunable gain of 1
 * Block '<S12>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S12>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S11>/P_si2pu' : Eliminated nontunable gain of 1
 * Block '<S11>/T_si2pu' : Eliminated nontunable gain of 1
 * Block '<S11>/id_pu2si' : Eliminated nontunable gain of 1
 * Block '<S11>/iq_pu2si' : Eliminated nontunable gain of 1
 * Block '<S11>/wm_pu2si' : Eliminated nontunable gain of 1
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
 * '<S6>'   : 'speedloop/FOC_Model/currloop/PMSM Torque Estimator'
 * '<S7>'   : 'speedloop/FOC_Model/currloop/Park'
 * '<S8>'   : 'speedloop/FOC_Model/currloop/SVPWM'
 * '<S9>'   : 'speedloop/FOC_Model/currloop/idq_Controller'
 * '<S10>'  : 'speedloop/FOC_Model/currloop/PMSM Torque Estimator/Variant Subsystem'
 * '<S11>'  : 'speedloop/FOC_Model/currloop/PMSM Torque Estimator/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S12>'  : 'speedloop/FOC_Model/currloop/PMSM Torque Estimator/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S13>'  : 'speedloop/FOC_Model/currloop/SVPWM/AntiClark'
 * '<S14>'  : 'speedloop/FOC_Model/currloop/SVPWM/ei_t'
 * '<S15>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1'
 * '<S16>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2'
 * '<S17>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup'
 * '<S18>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain'
 * '<S19>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter'
 * '<S20>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs'
 * '<S21>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain'
 * '<S22>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S23>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator'
 * '<S25>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S26>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy'
 * '<S27>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain'
 * '<S28>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy'
 * '<S29>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S30>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal'
 * '<S31>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation'
 * '<S32>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum'
 * '<S34>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S35>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S36>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal'
 * '<S40>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal'
 * '<S41>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S43>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S44>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S45>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S46>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S47>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S48>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S49>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S50>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S51>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S52>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S53>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S54>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S55>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S56>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S57>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S58>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S59>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S60>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S61>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S62>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S63>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S64>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S66>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S67>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup'
 * '<S68>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain'
 * '<S69>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter'
 * '<S70>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs'
 * '<S71>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain'
 * '<S72>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S73>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S74>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator'
 * '<S75>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S76>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy'
 * '<S77>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain'
 * '<S78>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy'
 * '<S79>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S80>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal'
 * '<S81>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation'
 * '<S82>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S83>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum'
 * '<S84>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S85>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S86>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S87>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S88>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S89>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal'
 * '<S90>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal'
 * '<S91>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S92>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S93>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S94>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S95>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S96>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S97>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S98>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S99>'  : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S101>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S102>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S103>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S104>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S105>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S106>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S107>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S108>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S109>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S110>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S111>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S112>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S116>' : 'speedloop/FOC_Model/currloop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S117>' : 'speedloop/FOC_Model/speedloop/Compare To Constant'
 * '<S118>' : 'speedloop/FOC_Model/speedloop/If Action Subsystem'
 * '<S119>' : 'speedloop/FOC_Model/speedloop/If Action Subsystem1'
 * '<S120>' : 'speedloop/FOC_Model/speedloop/Subsystem'
 * '<S121>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3'
 * '<S122>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Anti-windup'
 * '<S123>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/D Gain'
 * '<S124>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Filter'
 * '<S125>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Filter ICs'
 * '<S126>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/I Gain'
 * '<S127>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Ideal P Gain'
 * '<S128>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Ideal P Gain Fdbk'
 * '<S129>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Integrator'
 * '<S130>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Integrator ICs'
 * '<S131>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/N Copy'
 * '<S132>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/N Gain'
 * '<S133>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/P Copy'
 * '<S134>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Parallel P Gain'
 * '<S135>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Reset Signal'
 * '<S136>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Saturation'
 * '<S137>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Saturation Fdbk'
 * '<S138>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Sum'
 * '<S139>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Sum Fdbk'
 * '<S140>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tracking Mode'
 * '<S141>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tracking Mode Sum'
 * '<S142>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tsamp - Integral'
 * '<S143>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tsamp - Ngain'
 * '<S144>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/postSat Signal'
 * '<S145>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/preSat Signal'
 * '<S146>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S147>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S148>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S149>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/D Gain/Disabled'
 * '<S150>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Filter/Disabled'
 * '<S151>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Filter ICs/Disabled'
 * '<S152>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/I Gain/Internal Parameters'
 * '<S153>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Ideal P Gain/Passthrough'
 * '<S154>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S155>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Integrator/Discrete'
 * '<S156>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Integrator ICs/Internal IC'
 * '<S157>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S158>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/N Gain/Disabled'
 * '<S159>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/P Copy/Disabled'
 * '<S160>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S161>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Reset Signal/Disabled'
 * '<S162>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Saturation/Enabled'
 * '<S163>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Saturation Fdbk/Disabled'
 * '<S164>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Sum/Sum_PI'
 * '<S165>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Sum Fdbk/Disabled'
 * '<S166>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tracking Mode/Disabled'
 * '<S167>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S168>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S169>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S170>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/postSat Signal/Forward_Path'
 * '<S171>' : 'speedloop/FOC_Model/speedloop/Subsystem/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */