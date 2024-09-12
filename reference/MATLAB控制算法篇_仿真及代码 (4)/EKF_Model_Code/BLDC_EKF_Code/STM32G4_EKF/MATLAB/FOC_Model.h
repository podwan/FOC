/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 2.183
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Oct 22 20:56:15 2023
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
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S1>/Curr_loop' */
typedef struct {
  real32_T IdentityMatrix[16];         /* '<S16>/IdentityMatrix' */
  real32_T IdentityMatrix_k[16];       /* '<S19>/IdentityMatrix' */
  real32_T Delay1_DSTATE[16];          /* '<S6>/Delay1' */
  real32_T Delay_DSTATE[4];            /* '<S6>/Delay' */
  real32_T Divide_DWORK4[4];           /* '<S18>/Divide' */
  real32_T Merge;                      /* '<S2>/Merge' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T ZReset;                     /* '<S2>/Chart1' */
  real32_T Integrator_DSTATE;          /* '<S115>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S11>/Discrete-Time Integrator1' */
  real32_T UnitDelay_DSTATE;           /* '<S11>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S9>/Discrete-Time Integrator1' */
  real32_T Delay7_DSTATE;              /* '<S6>/Delay7' */
  real32_T Delay6_DSTATE;              /* '<S6>/Delay6' */
  real32_T Delay2_DSTATE;              /* '<S6>/Delay2' */
  real32_T Delay4_DSTATE;              /* '<S6>/Delay4' */
  real32_T Delay5_DSTATE;              /* '<S6>/Delay5' */
  real32_T Delay3_DSTATE;              /* '<S6>/Delay3' */
  real32_T Integrator_PREV_U;          /* '<S115>/Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV_U;/* '<S11>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV__h;/* '<S9>/Discrete-Time Integrator1' */
  real32_T cnt;                        /* '<S2>/Chart1' */
  uint32_T Curr_loop_PREV_T;           /* '<S1>/Curr_loop' */
  uint32_T IfActionSubsystem4_PREV_T;  /* '<S2>/If Action Subsystem4' */
  uint32_T IfActionSubsystem2_PREV_T;  /* '<S2>/If Action Subsystem2' */
  int16_T Integrator_DSTATE_f;         /* '<S65>/Integrator' */
  int16_T Integrator_PREV_U_l;         /* '<S65>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart1' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S2>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S9>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S9>/Discrete-Time Integrator1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S65>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE_e;  /* '<S115>/Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S11>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S9>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_f;/* '<S9>/Discrete-Time Integrator1' */
  uint8_T is_active_c7_FOC_Model;      /* '<S2>/Chart1' */
  uint8_T is_c7_FOC_Model;             /* '<S2>/Chart1' */
  boolean_T Curr_loop_RESET_ELAPS_T;   /* '<S1>/Curr_loop' */
  boolean_T IfActionSubsystem4_RESET_ELAPS_;/* '<S2>/If Action Subsystem4' */
  boolean_T IfActionSubsystem2_RESET_ELAPS_;/* '<S2>/If Action Subsystem2' */
} DW_Curr_loop;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Curr_loop Curr_loop_d;            /* '<S1>/Curr_loop' */
  real_T RestsSingal;                  /* '<S2>/Chart1' */
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T Integrator_DSTATE;          /* '<S166>/Integrator' */
  real32_T RateTransition3_Buffer0;    /* '<S1>/Rate Transition3' */
  real32_T Integrator_PREV_U;          /* '<S166>/Integrator' */
  uint32_T Speed_loop_PREV_T;          /* '<S1>/Speed_loop' */
  int8_T Integrator_PrevResetState;    /* '<S166>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S166>/Integrator' */
  boolean_T Speed_loop_RESET_ELAPS_T;  /* '<S1>/Speed_loop' */
} DW;

/* Invariant block signals for system '<S1>/Curr_loop' */
typedef struct {
  const real32_T Transpose[8];         /* '<S18>/Transpose' */
} ConstB_Curr_loop;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_Curr_loop Curr_loop_d;        /* '<S1>/Curr_loop' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: B_Value
   * Referenced by: '<S6>/B'
   */
  real32_T B_Value[8];

  /* Computed Parameter: H_Value
   * Referenced by: '<S6>/H'
   */
  real32_T H_Value[8];

  /* Computed Parameter: Q_Value
   * Referenced by: '<S6>/Q'
   */
  real32_T Q_Value[16];

  /* Computed Parameter: R_Value
   * Referenced by: '<S6>/R'
   */
  real32_T R_Value[4];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/IdentityMatrix'
   *   '<S19>/IdentityMatrix'
   */
  real32_T pooled4[16];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T Speed_ref;                  /* '<Root>/Speed_ref' */
  real32_T MotorOnOff;                 /* '<Root>/MotorOnOff' */
  real32_T VDC;                        /* '<Root>/VDC' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Tcmp1;                      /* '<Root>/Tcmp1' */
  real32_T Tcmp2;                      /* '<Root>/Tcmp2' */
  real32_T Tcmp3;                      /* '<Root>/Tcmp3' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct curr_kpki_tag {
  real32_T curr_d_ki;                  /* Referenced by:
                                        * '<S15>/Constant2'
                                        * '<S15>/Constant4'
                                        */
  real32_T curr_d_kp;                  /* Referenced by:
                                        * '<S15>/Constant1'
                                        * '<S15>/Constant3'
                                        */
} curr_kpki_type;

typedef struct motor_tag {
  real32_T L;                          /* Referenced by:
                                        * '<S17>/Constant6'
                                        * '<S17>/Constant7'
                                        * '<S17>/Gain1'
                                        * '<S17>/Gain2'
                                        * '<S17>/Gain3'
                                        * '<S17>/Gain4'
                                        * '<S23>/Gain1'
                                        * '<S23>/Gain2'
                                        * '<S23>/Gain4'
                                        * '<S23>/Gain5'
                                        */
  real32_T Pn;                         /* Referenced by:
                                        * '<S2>/Gain2'
                                        * '<S9>/Gain'
                                        * '<S11>/Gain'
                                        */
  real32_T Rs;                         /* Referenced by:
                                        * '<S17>/Constant6'
                                        * '<S17>/Constant7'
                                        * '<S23>/Gain4'
                                        * '<S23>/Gain5'
                                        */
  real32_T flux;                       /* Referenced by:
                                        * '<S17>/Gain1'
                                        * '<S17>/Gain2'
                                        * '<S17>/Gain3'
                                        * '<S17>/Gain4'
                                        * '<S23>/Gain1'
                                        * '<S23>/Gain2'
                                        */
} motor_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S163>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S171>/Proportional Gain' */
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
    uint32_T clockTick0;
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
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T EKFWm;                 /* '<S2>/Gain1' */
extern real32_T EKFTheta;              /* '<S2>/Mod' */
extern real32_T ualpha;                /* '<S12>/Add' */
extern real32_T ubeta;                 /* '<S12>/Add1' */
extern real32_T ialpha;                /* '<S5>/Add1' */
extern real32_T ibeta;                 /* '<S5>/Gain2' */
extern real32_T state;                 /* '<S2>/Chart1' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern curr_kpki_type curr_kpki;
extern motor_type motor;
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S18>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S11>/Add1' : Unused code path elimination
 * Block '<S11>/Add2' : Unused code path elimination
 * Block '<S11>/Constant3' : Unused code path elimination
 * Block '<S11>/Mod1' : Unused code path elimination
 * Block '<S11>/Product' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope2' : Unused code path elimination
 * Block '<S11>/Scope3' : Unused code path elimination
 * Block '<S11>/Scope4' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope3' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S17>/Reshape1' : Reshape block reduction
 * Block '<S17>/Reshape2' : Reshape block reduction
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * hilite_system('BLDC_EKF/FOC_Model')    - opens subsystem BLDC_EKF/FOC_Model
 * hilite_system('BLDC_EKF/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BLDC_EKF'
 * '<S1>'   : 'BLDC_EKF/FOC_Model'
 * '<S2>'   : 'BLDC_EKF/FOC_Model/Curr_loop'
 * '<S3>'   : 'BLDC_EKF/FOC_Model/Speed_loop'
 * '<S4>'   : 'BLDC_EKF/FOC_Model/Curr_loop/Chart1'
 * '<S5>'   : 'BLDC_EKF/FOC_Model/Curr_loop/Clark'
 * '<S6>'   : 'BLDC_EKF/FOC_Model/Curr_loop/EKF'
 * '<S7>'   : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem'
 * '<S8>'   : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem1'
 * '<S9>'   : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem2'
 * '<S10>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem3'
 * '<S11>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem4'
 * '<S12>'  : 'BLDC_EKF/FOC_Model/Curr_loop/In_park'
 * '<S13>'  : 'BLDC_EKF/FOC_Model/Curr_loop/Park'
 * '<S14>'  : 'BLDC_EKF/FOC_Model/Curr_loop/SVPWM1'
 * '<S15>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller'
 * '<S16>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/A'
 * '<S17>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/F'
 * '<S18>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/K'
 * '<S19>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/P'
 * '<S20>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/P_pre'
 * '<S21>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/X_hat'
 * '<S22>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/X_pre'
 * '<S23>'  : 'BLDC_EKF/FOC_Model/Curr_loop/EKF/f'
 * '<S24>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem'
 * '<S25>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem1'
 * '<S26>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem2'
 * '<S27>'  : 'BLDC_EKF/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem3'
 * '<S28>'  : 'BLDC_EKF/FOC_Model/Curr_loop/SVPWM1/InvClark'
 * '<S29>'  : 'BLDC_EKF/FOC_Model/Curr_loop/SVPWM1/ei_t'
 * '<S30>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1'
 * '<S31>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2'
 * '<S32>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup'
 * '<S33>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain'
 * '<S34>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter'
 * '<S35>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs'
 * '<S36>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain'
 * '<S37>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S38>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S39>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator'
 * '<S40>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S41>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy'
 * '<S42>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain'
 * '<S43>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy'
 * '<S44>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S45>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal'
 * '<S46>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation'
 * '<S47>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S48>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum'
 * '<S49>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S50>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S51>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S52>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S53>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S54>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal'
 * '<S55>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal'
 * '<S56>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S57>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S58>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S59>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S60>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S61>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S62>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S63>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S64>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S65>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S66>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S67>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S68>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S69>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S70>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S71>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S72>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S73>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S74>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S75>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S76>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S77>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S78>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S79>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S80>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S81>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S82>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup'
 * '<S83>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain'
 * '<S84>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter'
 * '<S85>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs'
 * '<S86>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain'
 * '<S87>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S88>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S89>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator'
 * '<S90>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S91>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy'
 * '<S92>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain'
 * '<S93>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy'
 * '<S94>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S95>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal'
 * '<S96>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation'
 * '<S97>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S98>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum'
 * '<S99>'  : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S100>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S101>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S102>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S103>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S104>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal'
 * '<S105>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal'
 * '<S106>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S107>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S108>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S109>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S110>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S111>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S112>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S113>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S114>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S116>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S117>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S118>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S119>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S120>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S121>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S122>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S123>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S124>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S125>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S126>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S127>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S129>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S130>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S131>' : 'BLDC_EKF/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S132>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3'
 * '<S133>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Anti-windup'
 * '<S134>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/D Gain'
 * '<S135>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Filter'
 * '<S136>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Filter ICs'
 * '<S137>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/I Gain'
 * '<S138>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain'
 * '<S139>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S140>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Integrator'
 * '<S141>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Integrator ICs'
 * '<S142>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/N Copy'
 * '<S143>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/N Gain'
 * '<S144>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/P Copy'
 * '<S145>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain'
 * '<S146>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Reset Signal'
 * '<S147>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Saturation'
 * '<S148>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk'
 * '<S149>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Sum'
 * '<S150>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk'
 * '<S151>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tracking Mode'
 * '<S152>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S153>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral'
 * '<S154>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S155>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/postSat Signal'
 * '<S156>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/preSat Signal'
 * '<S157>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S158>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S159>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S160>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/D Gain/Disabled'
 * '<S161>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Filter/Disabled'
 * '<S162>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S163>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/I Gain/Internal Parameters'
 * '<S164>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S165>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S166>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Integrator/Discrete'
 * '<S167>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S168>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S169>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/N Gain/Disabled'
 * '<S170>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/P Copy/Disabled'
 * '<S171>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S172>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S173>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Saturation/Enabled'
 * '<S174>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S175>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S176>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S177>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S178>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S179>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S180>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S181>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S182>' : 'BLDC_EKF/FOC_Model/Speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
