/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 2.173
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Oct  3 11:49:31 2023
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

/* Block signals and states (default storage) for system '<S1>/Curr_loop' */
typedef struct {
  real32_T Merge;                      /* '<S2>/Merge' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T ZReset;                     /* '<S2>/Chart1' */
  real32_T UnitDelay_DSTATE;           /* '<S23>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S165>/Integrator' */
  real32_T Delay_DSTATE;               /* '<S12>/Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S21>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S21>/Unit Delay3' */
  real32_T Integrator_DSTATE_d;        /* '<S57>/Integrator' */
  real32_T UnitDelay2_DSTATE;          /* '<S21>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_h;         /* '<S21>/Unit Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S10>/Discrete-Time Integrator1' */
  real32_T UnitDelay_DSTATE_b;         /* '<S10>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S8>/Discrete-Time Integrator1' */
  real32_T Integrator_PREV_U;          /* '<S165>/Integrator' */
  real32_T Integrator_PREV_U_c;        /* '<S57>/Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV_U;/* '<S10>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S8>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV__h;/* '<S8>/Discrete-Time Integrator1' */
  real32_T cnt;                        /* '<S2>/Chart1' */
  uint32_T Curr_loop_PREV_T;           /* '<S1>/Curr_loop' */
  uint32_T IfActionSubsystem4_PREV_T;  /* '<S2>/If Action Subsystem4' */
  uint32_T IfActionSubsystem2_PREV_T;  /* '<S2>/If Action Subsystem2' */
  int16_T Integrator_DSTATE_f;         /* '<S115>/Integrator' */
  int16_T Integrator_PREV_U_l;         /* '<S115>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart1' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S2>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S8>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S8>/Discrete-Time Integrator1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S115>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE_e;  /* '<S165>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE_k;  /* '<S57>/Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S10>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S8>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTE_f;/* '<S8>/Discrete-Time Integrator1' */
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
  real32_T Integrator_DSTATE;          /* '<S216>/Integrator' */
  real32_T RateTransition3_Buffer0;    /* '<S1>/Rate Transition3' */
  real32_T Integrator_PREV_U;          /* '<S216>/Integrator' */
  uint32_T Speed_loop_PREV_T;          /* '<S1>/Speed_loop' */
  int8_T Integrator_PrevResetState;    /* '<S216>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S216>/Integrator' */
  boolean_T Speed_loop_RESET_ELAPS_T;  /* '<S1>/Speed_loop' */
} DW;

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
                                        * '<S21>/Gain15'
                                        * '<S21>/Gain16'
                                        * '<S21>/Gain17'
                                        * '<S21>/Gain20'
                                        * '<S21>/Gain21'
                                        * '<S21>/Gain22'
                                        */
  real32_T Pn;                         /* Referenced by:
                                        * '<S8>/Gain'
                                        * '<S10>/Gain'
                                        * '<S12>/Gain'
                                        */
  real32_T Rs;                         /* Referenced by:
                                        * '<S21>/Gain15'
                                        * '<S21>/Gain20'
                                        */
} motor_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S213>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S221>/Proportional Gain' */
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

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T LunWm;                 /* '<S12>/Gain1' */
extern real32_T LunTheta;              /* '<S23>/Unit Delay' */
extern real32_T ialpha;                /* '<S2>/Clark' */
extern real32_T ibeta;                 /* '<S2>/Clark' */
extern real32_T ubeta;                 /* '<S2>/In_park' */
extern real32_T ualpha;                /* '<S2>/In_park' */
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
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S10>/Add1' : Unused code path elimination
 * Block '<S10>/Add2' : Unused code path elimination
 * Block '<S10>/Constant3' : Unused code path elimination
 * Block '<S10>/Mod1' : Unused code path elimination
 * Block '<S10>/Product' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S10>/Scope2' : Unused code path elimination
 * Block '<S10>/Scope3' : Unused code path elimination
 * Block '<S10>/Scope4' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope3' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
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
 * hilite_system('BLDC_Lun/FOC_Model')    - opens subsystem BLDC_Lun/FOC_Model
 * hilite_system('BLDC_Lun/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BLDC_Lun'
 * '<S1>'   : 'BLDC_Lun/FOC_Model'
 * '<S2>'   : 'BLDC_Lun/FOC_Model/Curr_loop'
 * '<S3>'   : 'BLDC_Lun/FOC_Model/Speed_loop'
 * '<S4>'   : 'BLDC_Lun/FOC_Model/Curr_loop/Chart1'
 * '<S5>'   : 'BLDC_Lun/FOC_Model/Curr_loop/Clark'
 * '<S6>'   : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem'
 * '<S7>'   : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem1'
 * '<S8>'   : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem2'
 * '<S9>'   : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem3'
 * '<S10>'  : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem4'
 * '<S11>'  : 'BLDC_Lun/FOC_Model/Curr_loop/In_park'
 * '<S12>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer'
 * '<S13>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Park'
 * '<S14>'  : 'BLDC_Lun/FOC_Model/Curr_loop/SVPWM1'
 * '<S15>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller'
 * '<S16>'  : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem'
 * '<S17>'  : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem1'
 * '<S18>'  : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem2'
 * '<S19>'  : 'BLDC_Lun/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem3'
 * '<S20>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2'
 * '<S21>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/discrete luenberger observer1'
 * '<S22>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller'
 * '<S23>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/SpeedToTheta'
 * '<S24>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Anti-windup'
 * '<S25>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/D Gain'
 * '<S26>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Filter'
 * '<S27>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Filter ICs'
 * '<S28>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/I Gain'
 * '<S29>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Ideal P Gain'
 * '<S30>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Ideal P Gain Fdbk'
 * '<S31>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Integrator'
 * '<S32>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Integrator ICs'
 * '<S33>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/N Copy'
 * '<S34>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/N Gain'
 * '<S35>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/P Copy'
 * '<S36>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Parallel P Gain'
 * '<S37>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Reset Signal'
 * '<S38>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Saturation'
 * '<S39>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Saturation Fdbk'
 * '<S40>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Sum'
 * '<S41>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Sum Fdbk'
 * '<S42>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tracking Mode'
 * '<S43>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tracking Mode Sum'
 * '<S44>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tsamp - Integral'
 * '<S45>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tsamp - Ngain'
 * '<S46>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/postSat Signal'
 * '<S47>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/preSat Signal'
 * '<S48>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S49>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S50>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S51>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/D Gain/Disabled'
 * '<S52>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Filter/Disabled'
 * '<S53>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Filter ICs/Disabled'
 * '<S54>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/I Gain/Internal Parameters'
 * '<S55>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Ideal P Gain/Passthrough'
 * '<S56>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S57>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Integrator/Discrete'
 * '<S58>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Integrator ICs/Internal IC'
 * '<S59>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S60>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/N Gain/Disabled'
 * '<S61>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/P Copy/Disabled'
 * '<S62>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S63>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Reset Signal/Disabled'
 * '<S64>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Saturation/Enabled'
 * '<S65>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Saturation Fdbk/Disabled'
 * '<S66>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Sum/Sum_PI'
 * '<S67>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Sum Fdbk/Disabled'
 * '<S68>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tracking Mode/Disabled'
 * '<S69>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S70>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tsamp - Integral/Passthrough'
 * '<S71>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S72>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/postSat Signal/Forward_Path'
 * '<S73>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/PID Controller/preSat Signal/Forward_Path'
 * '<S74>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/SpeedToTheta/Angle_Limit'
 * '<S75>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/SpeedToTheta/Angle_Limit/If Action Subsystem1'
 * '<S76>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/SpeedToTheta/Angle_Limit/If Action Subsystem2'
 * '<S77>'  : 'BLDC_Lun/FOC_Model/Curr_loop/Lunberger Observer/PLL2/SpeedToTheta/Angle_Limit/If Action Subsystem3'
 * '<S78>'  : 'BLDC_Lun/FOC_Model/Curr_loop/SVPWM1/InvClark'
 * '<S79>'  : 'BLDC_Lun/FOC_Model/Curr_loop/SVPWM1/ei_t'
 * '<S80>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1'
 * '<S81>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2'
 * '<S82>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup'
 * '<S83>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain'
 * '<S84>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter'
 * '<S85>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs'
 * '<S86>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain'
 * '<S87>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S88>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S89>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator'
 * '<S90>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S91>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy'
 * '<S92>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain'
 * '<S93>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy'
 * '<S94>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S95>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal'
 * '<S96>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation'
 * '<S97>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S98>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum'
 * '<S99>'  : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S100>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S101>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S102>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S103>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S104>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal'
 * '<S105>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal'
 * '<S106>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S107>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S108>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S109>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S110>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S111>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S112>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S113>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S114>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S116>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S117>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S118>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S119>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S120>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S121>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S122>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S123>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S124>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S125>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S126>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S127>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S129>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S130>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S131>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S132>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup'
 * '<S133>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain'
 * '<S134>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter'
 * '<S135>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs'
 * '<S136>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain'
 * '<S137>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S138>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S139>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator'
 * '<S140>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S141>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy'
 * '<S142>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain'
 * '<S143>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy'
 * '<S144>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S145>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal'
 * '<S146>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation'
 * '<S147>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S148>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum'
 * '<S149>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S150>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S151>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S152>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S153>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S154>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal'
 * '<S155>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal'
 * '<S156>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S157>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S158>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S159>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S160>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S161>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S162>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S163>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S164>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S165>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S166>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S167>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S168>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S169>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S170>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S171>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S172>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S173>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S174>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S175>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S176>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S177>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S178>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S179>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S180>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S181>' : 'BLDC_Lun/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S182>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3'
 * '<S183>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Anti-windup'
 * '<S184>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/D Gain'
 * '<S185>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Filter'
 * '<S186>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Filter ICs'
 * '<S187>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/I Gain'
 * '<S188>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain'
 * '<S189>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S190>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Integrator'
 * '<S191>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Integrator ICs'
 * '<S192>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/N Copy'
 * '<S193>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/N Gain'
 * '<S194>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/P Copy'
 * '<S195>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain'
 * '<S196>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Reset Signal'
 * '<S197>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Saturation'
 * '<S198>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk'
 * '<S199>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Sum'
 * '<S200>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk'
 * '<S201>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tracking Mode'
 * '<S202>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S203>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral'
 * '<S204>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S205>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/postSat Signal'
 * '<S206>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/preSat Signal'
 * '<S207>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S208>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S209>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S210>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/D Gain/Disabled'
 * '<S211>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Filter/Disabled'
 * '<S212>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S213>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/I Gain/Internal Parameters'
 * '<S214>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S215>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S216>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Integrator/Discrete'
 * '<S217>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S218>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S219>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/N Gain/Disabled'
 * '<S220>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/P Copy/Disabled'
 * '<S221>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S222>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S223>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Saturation/Enabled'
 * '<S224>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S225>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S226>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S227>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S228>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S229>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S230>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S231>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S232>' : 'BLDC_Lun/FOC_Model/Speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
