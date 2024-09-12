/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 2.171
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Aug 22 21:11:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"

/* Named constants for Chart: '<S2>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define IN_ThetaAlign                  ((uint8_T)5U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported block signals */
real32_T LunWm;                        /* '<S12>/Gain1' */
real32_T LunTheta;                     /* '<S23>/Unit Delay' */
real32_T ialpha;                       /* '<S2>/Clark' */
real32_T ibeta;                        /* '<S2>/Clark' */
real32_T ubeta;                        /* '<S2>/In_park' */
real32_T ualpha;                       /* '<S2>/In_park' */
real32_T state;                        /* '<S2>/Chart1' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
curr_kpki_type curr_kpki = {
  /* curr_d_ki */
  35.0F,

  /* curr_d_kp */
  0.17F
};

motor_type motor = {
  /* L */
  0.00535F,

  /* Pn */
  4.0F,

  /* Rs */
  6.97F
};

spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.0144F,

  /* spd_kp */
  0.3389F
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void Clark(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic, real32_T
                  *rty_ialpha, real32_T *rty_ibeta);
static void In_park(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta_sin,
                    real32_T rtu_theta_cos, real32_T *rty_ualpha, real32_T
                    *rty_ubeta);
static void Park(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_theta_sin,
                 real32_T rtu_theta_cos, real32_T *rty_id, real32_T *rty_iq);
static void SVPWM1(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                   real32_T rty_tABC[3]);
static void Curr_loop_Init(real_T *rty_RestsSingal, DW_Curr_loop *localDW);
static void Curr_loop_Enable(DW_Curr_loop *localDW);
static void Curr_loop(RT_MODEL * const rtM, real32_T rtu_ia, real32_T rtu_ib,
                      real32_T rtu_ic, real32_T rtu_MotorOnOff, real32_T
                      rtu_iq_ref, real32_T rtu_VDC, real32_T rty_Tcmp1[3],
                      real32_T *rty_Tcmp2, real32_T *rty_Tcmp3, real32_T
                      *rty_LunWm, real_T *rty_RestsSingal, DW_Curr_loop *localDW);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for atomic system: '<S2>/Clark' */
static void Clark(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic, real32_T
                  *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S5>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S5>/Gain2' incorporates:
   *  Sum: '<S5>/Add2'
   */
  *rty_ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/* Output and update for atomic system: '<S2>/In_park' */
static void In_park(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta_sin,
                    real32_T rtu_theta_cos, real32_T *rty_ualpha, real32_T
                    *rty_ubeta)
{
  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  *rty_ualpha = rtu_ud * rtu_theta_cos - rtu_uq * rtu_theta_sin;

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  *rty_ubeta = rtu_ud * rtu_theta_sin + rtu_uq * rtu_theta_cos;
}

/* Output and update for atomic system: '<S2>/Park' */
static void Park(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_theta_sin,
                 real32_T rtu_theta_cos, real32_T *rty_id, real32_T *rty_iq)
{
  /* Sum: '<S13>/Add' incorporates:
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   */
  *rty_id = rtu_ialpha * rtu_theta_cos + rtu_ibeta * rtu_theta_sin;

  /* Sum: '<S13>/Add1' incorporates:
   *  Product: '<S13>/Product2'
   *  Product: '<S13>/Product3'
   */
  *rty_iq = rtu_ibeta * rtu_theta_cos - rtu_ialpha * rtu_theta_sin;
}

/* Output and update for atomic system: '<S2>/SVPWM1' */
static void SVPWM1(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                   real32_T rty_tABC[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_j;
  real32_T rtb_Sum_b;

  /* Gain: '<S78>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S78>/Gain1' */
  rtb_Sum1_j = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S78>/Sum' */
  rtb_Sum_b = rtb_Min + rtb_Sum1_j;

  /* Sum: '<S78>/Sum1' */
  rtb_Sum1_j = rtb_Min - rtb_Sum1_j;

  /* Gain: '<S79>/Gain' incorporates:
   *  MinMax: '<S79>/Min'
   *  MinMax: '<S79>/Min1'
   *  Sum: '<S79>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_b), rtb_Sum1_j) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_b), rtb_Sum1_j)) * -0.5F;

  /* Gain: '<S14>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S14>/Constant'
   *  Gain: '<S14>/Gain'
   *  Product: '<S14>/Divide'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S14>/Sum1'
   */
  rty_tABC[0] = (-(rtb_Min + rtu_Valpha) / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[1] = (-(rtb_Min + rtb_Sum_b) / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[2] = (-(rtb_Min + rtb_Sum1_j) / rtu_v_bus + 0.5F) * 8000.0F;
}

real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* System initialize for function-call system: '<S1>/Curr_loop' */
static void Curr_loop_Init(real_T *rty_RestsSingal, DW_Curr_loop *localDW)
{
  /* Start for SwitchCase: '<S2>/Switch Case1' */
  localDW->SwitchCase1_ActiveSubsystem = -1;

  /* SystemInitialize for Chart: '<S2>/Chart1' */
  *rty_RestsSingal = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem2' */
  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem2' */
}

/* Enable for function-call system: '<S1>/Curr_loop' */
static void Curr_loop_Enable(DW_Curr_loop *localDW)
{
  localDW->Curr_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S115>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S165>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_e = 1U;

  /* Enable for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_k = 1U;
}

/* Output and update for function-call system: '<S1>/Curr_loop' */
static void Curr_loop(RT_MODEL * const rtM, real32_T rtu_ia, real32_T rtu_ib,
                      real32_T rtu_ic, real32_T rtu_MotorOnOff, real32_T
                      rtu_iq_ref, real32_T rtu_VDC, real32_T rty_Tcmp1[3],
                      real32_T *rty_Tcmp2, real32_T *rty_Tcmp3, real32_T
                      *rty_LunWm, real_T *rty_RestsSingal, DW_Curr_loop *localDW)
{
  real32_T DiscreteTimeIntegrator;
  real32_T DiscreteTimeIntegrator1_n;
  real32_T Integrator;
  real32_T rtb_Cos;
  real32_T rtb_Gain16;
  real32_T rtb_Gain21;
  real32_T rtb_Gain23;
  real32_T rtb_Gain24;
  real32_T rtb_IProdOut;
  real32_T rtb_Product3;
  real32_T rtb_SignPreSat;
  real32_T rtb_SignPreSat_1;
  real32_T rtb_SignPreSat_g;
  real32_T rtb_Sin;
  real32_T rtb_Sum1_j;
  real32_T rtb_ZeroGain_m;
  uint32_T Curr_loop_ELAPS_T;
  uint32_T Curr_loop_PREV_T_tmp;
  int16_T Integrator_g;
  int16_T rtb_IProdOut_p;
  int8_T rtAction;
  int8_T rtPrevAction;
  if (localDW->Curr_loop_RESET_ELAPS_T) {
    Curr_loop_ELAPS_T = 0U;
  } else {
    Curr_loop_ELAPS_T = rtM->Timing.clockTick0 - localDW->Curr_loop_PREV_T;
  }

  /* Update for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
   *  ActionPort: '<S10>/Action Port'
   */
  /* Update for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S8>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
   *  ActionPort: '<S10>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S8>/Action Port'
   */
  /* SwitchCase: '<S2>/Switch Case1' */
  Curr_loop_PREV_T_tmp = rtM->Timing.clockTick0;

  /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
  /* End of Update for SubSystem: '<S2>/If Action Subsystem2' */
  /* End of Update for SubSystem: '<S2>/If Action Subsystem4' */
  localDW->Curr_loop_PREV_T = Curr_loop_PREV_T_tmp;
  localDW->Curr_loop_RESET_ELAPS_T = false;

  /* Chart: '<S2>/Chart1' */
  if (localDW->temporalCounter_i1 < 32767U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c7_FOC_Model == 0U) {
    localDW->is_active_c7_FOC_Model = 1U;
    localDW->is_c7_FOC_Model = IN_IDLE;
  } else {
    switch (localDW->is_c7_FOC_Model) {
     case IN_AlignStage:
      if (localDW->temporalCounter_i1 >= 1000) {
        localDW->is_c7_FOC_Model = IN_OpenStage;
        localDW->temporalCounter_i1 = 0U;
        localDW->ZReset = 0.0F;
        localDW->cnt = 0.0F;
      } else if (rtu_MotorOnOff == 0.0F) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else {
        state = 2.0F;
        *rty_RestsSingal = 0.0;
      }
      break;

     case IN_IDLE:
      if (rtu_MotorOnOff == 1.0F) {
        localDW->is_c7_FOC_Model = IN_AlignStage;
        localDW->temporalCounter_i1 = 0U;
      } else {
        state = 1.0F;
        *rty_RestsSingal = 0.0;
      }
      break;

     case IN_OpenStage:
      if (rtu_MotorOnOff == 0.0F) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else if (localDW->temporalCounter_i1 >= 30000) {
        localDW->is_c7_FOC_Model = IN_ThetaAlign;
        localDW->temporalCounter_i1 = 0U;
      } else {
        if (localDW->cnt == 1.0F) {
          localDW->ZReset = 1.0F;
        }

        localDW->cnt = 1.0F;
        state = 3.0F;
        *rty_RestsSingal = 0.0;
      }
      break;

     case IN_RunStage:
      if (rtu_MotorOnOff == 0.0F) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else {
        state = 5.0F;
        *rty_RestsSingal = 1.0;
      }
      break;

     default:
      /* case IN_ThetaAlign: */
      if (localDW->temporalCounter_i1 >= 5000) {
        localDW->is_c7_FOC_Model = IN_RunStage;
      } else {
        state = 4.0F;
        *rty_RestsSingal = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* Outputs for Atomic SubSystem: '<S2>/Clark' */
  /* SignalConversion generated from: '<S2>/Clark' */
  Clark(rtu_ia, rtu_ib, rtu_ic, &ialpha, &ibeta);

  /* End of Outputs for SubSystem: '<S2>/Clark' */

  /* UnitDelay: '<S23>/Unit Delay' */
  LunTheta = localDW->UnitDelay_DSTATE;

  /* SwitchCase: '<S2>/Switch Case1' */
  rtPrevAction = localDW->SwitchCase1_ActiveSubsystem;
  rtAction = -1;
  switch ((int32_T)state) {
   case 1:
    rtAction = 0;
    break;

   case 2:
    rtAction = 1;
    break;

   case 3:
    rtAction = 2;
    break;

   case 4:
    rtAction = 3;
    break;

   case 5:
    rtAction = 4;
    break;
  }

  localDW->SwitchCase1_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/theta_fd'
     */
    localDW->Merge = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/iq_ref'
     */
    localDW->Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/theta_fd'
     */
    localDW->Merge = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    localDW->Merge1 = 1.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 2:
    {
      uint32_T IfActionSubsystem2_ELAPS_T;
      if (rtAction != rtPrevAction) {
        localDW->IfActionSubsystem2_RESET_ELAPS_ = true;

        /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S8>/Action Port'
         */
        /* Enable for SwitchCase: '<S2>/Switch Case1' incorporates:
         *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
         *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
         */
        localDW->DiscreteTimeIntegrator_SYSTEM_E = 1U;
        localDW->DiscreteTimeIntegrator1_SYSTE_f = 1U;

        /* End of Enable for SubSystem: '<S2>/If Action Subsystem2' */
      }

      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      if (localDW->IfActionSubsystem2_RESET_ELAPS_) {
        IfActionSubsystem2_ELAPS_T = 0U;
      } else {
        IfActionSubsystem2_ELAPS_T = Curr_loop_PREV_T_tmp -
          localDW->IfActionSubsystem2_PREV_T;
      }

      localDW->IfActionSubsystem2_PREV_T = Curr_loop_PREV_T_tmp;
      localDW->IfActionSubsystem2_RESET_ELAPS_ = false;

      /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
      if (localDW->DiscreteTimeIntegrator_SYSTEM_E != 0) {
        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
      } else if ((localDW->ZReset > 0.0F) &&
                 (localDW->DiscreteTimeIntegrator_PrevRese <= 0)) {
        localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
      } else {
        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = 0.0001F * (real32_T)IfActionSubsystem2_ELAPS_T *
          localDW->DiscreteTimeIntegrator_PREV_U +
          localDW->DiscreteTimeIntegrator_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

      /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
      if (localDW->DiscreteTimeIntegrator1_SYSTE_f != 0) {
        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = localDW->DiscreteTimeIntegrator1_DSTAT_j;
      } else if ((localDW->ZReset > 0.0F) &&
                 (localDW->DiscreteTimeIntegrator1_PrevRes <= 0)) {
        localDW->DiscreteTimeIntegrator1_DSTAT_j = 0.0F;

        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = localDW->DiscreteTimeIntegrator1_DSTAT_j;
      } else {
        /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = 0.0001F * (real32_T)
          IfActionSubsystem2_ELAPS_T * localDW->DiscreteTimeIntegrator1_PREV__h
          + localDW->DiscreteTimeIntegrator1_DSTAT_j;
      }

      /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S8>/Constant'
       *  Math: '<S8>/Mod'
       */
      localDW->Merge = rt_modf(DiscreteTimeIntegrator1_n, 6.28318548F);

      /* Merge: '<S2>/Merge1' incorporates:
       *  Constant: '<S8>/Constant2'
       *  SignalConversion generated from: '<S8>/iq_ref'
       */
      localDW->Merge1 = 1.0F;

      /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
       *  Gain: '<S8>/Gain'
       *  Product: '<S8>/Product'
       */
      localDW->DiscreteTimeIntegrator_SYSTEM_E = 0U;
      localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator;
      if (localDW->ZReset > 0.0F) {
        localDW->DiscreteTimeIntegrator_PrevRese = 1;
      } else if (localDW->ZReset < 0.0F) {
        localDW->DiscreteTimeIntegrator_PrevRese = -1;
      } else if (localDW->ZReset == 0.0F) {
        localDW->DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        localDW->DiscreteTimeIntegrator_PrevRese = 2;
      }

      localDW->DiscreteTimeIntegrator_PREV_U = motor.Pn * 62.8318558F *
        0.333333343F;

      /* End of Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
      localDW->DiscreteTimeIntegrator1_SYSTE_f = 0U;
      localDW->DiscreteTimeIntegrator1_DSTAT_j = DiscreteTimeIntegrator1_n;
      if (localDW->ZReset > 0.0F) {
        localDW->DiscreteTimeIntegrator1_PrevRes = 1;
      } else if (localDW->ZReset < 0.0F) {
        localDW->DiscreteTimeIntegrator1_PrevRes = -1;
      } else if (localDW->ZReset == 0.0F) {
        localDW->DiscreteTimeIntegrator1_PrevRes = 0;
      } else {
        localDW->DiscreteTimeIntegrator1_PrevRes = 2;
      }

      localDW->DiscreteTimeIntegrator1_PREV__h = DiscreteTimeIntegrator;

      /* End of Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    }
    break;

   case 3:
    {
      uint32_T IfActionSubsystem2_ELAPS_T;
      if (rtAction != rtPrevAction) {
        localDW->IfActionSubsystem4_RESET_ELAPS_ = true;

        /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
         *  ActionPort: '<S10>/Action Port'
         */
        /* Enable for SwitchCase: '<S2>/Switch Case1' incorporates:
         *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
         */
        localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;

        /* End of Enable for SubSystem: '<S2>/If Action Subsystem4' */
      }

      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      if (localDW->IfActionSubsystem4_RESET_ELAPS_) {
        IfActionSubsystem2_ELAPS_T = 0U;
      } else {
        IfActionSubsystem2_ELAPS_T = Curr_loop_PREV_T_tmp -
          localDW->IfActionSubsystem4_PREV_T;
      }

      localDW->IfActionSubsystem4_PREV_T = Curr_loop_PREV_T_tmp;
      localDW->IfActionSubsystem4_RESET_ELAPS_ = false;

      /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
      if (localDW->DiscreteTimeIntegrator1_SYSTEM_ != 0) {
        /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator1_DSTATE;
      } else {
        /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator = 0.0001F * (real32_T)IfActionSubsystem2_ELAPS_T *
          localDW->DiscreteTimeIntegrator1_PREV_U +
          localDW->DiscreteTimeIntegrator1_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S10>/Constant'
       *  Math: '<S10>/Mod'
       *  SignalConversion generated from: '<S10>/Theta_fd'
       */
      localDW->Merge = rt_modf(DiscreteTimeIntegrator, 6.28318548F);

      /* If: '<S10>/If' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Constant: '<S16>/Constant'
       *  SignalConversion generated from: '<S16>/Out1'
       *  Sum: '<S10>/Add'
       *  UnitDelay: '<S10>/Unit Delay'
       */
      if (localDW->UnitDelay_DSTATE_b + 0.01F >= 1.0F) {
        /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        DiscreteTimeIntegrator1_n = 1.0F;

        /* End of Outputs for SubSystem: '<S10>/If Action Subsystem' */
      } else {
        DiscreteTimeIntegrator1_n = localDW->UnitDelay_DSTATE_b + 0.01F;
      }

      /* End of If: '<S10>/If' */

      /* Merge: '<S2>/Merge1' incorporates:
       *  Constant: '<S10>/Constant2'
       *  Constant: '<S10>/Constant4'
       *  Product: '<S10>/Product1'
       *  Sum: '<S10>/Add4'
       */
      localDW->Merge1 = 1.0F - DiscreteTimeIntegrator1_n * 0.7F;

      /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
       *  Gain: '<S10>/Gain'
       */
      localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
      localDW->DiscreteTimeIntegrator1_DSTATE = DiscreteTimeIntegrator;
      localDW->DiscreteTimeIntegrator1_PREV_U = motor.Pn * 62.8318558F;

      /* Update for UnitDelay: '<S10>/Unit Delay' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Sum: '<S10>/Add'
       */
      localDW->UnitDelay_DSTATE_b += 0.01F;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
    }
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Inport: '<S9>/theta_Close'
     */
    localDW->Merge = LunTheta;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Inport: '<S9>/iq_CloseRef'
     */
    localDW->Merge1 = rtu_iq_ref;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* Trigonometry: '<S2>/Cos' */
  rtb_Cos = cosf(localDW->Merge);

  /* Trigonometry: '<S2>/Sin' */
  rtb_Sin = sinf(localDW->Merge);

  /* Outputs for Atomic SubSystem: '<S2>/Park' */
  Park(ialpha, ibeta, rtb_Sin, rtb_Cos, &DiscreteTimeIntegrator,
       &DiscreteTimeIntegrator1_n);

  /* End of Outputs for SubSystem: '<S2>/Park' */

  /* Sum: '<S15>/Sum1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Sum1_j = 0.0F - DiscreteTimeIntegrator;

  /* DiscreteIntegrator: '<S115>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S115>/Integrator' */
    Integrator_g = localDW->Integrator_DSTATE_f;
  } else {
    /* DiscreteIntegrator: '<S115>/Integrator' */
    Integrator_g = (int16_T)((int16_T)((int32_T)Curr_loop_ELAPS_T
      * localDW->Integrator_PREV_U_l) + localDW->Integrator_DSTATE_f);
  }

  /* End of DiscreteIntegrator: '<S115>/Integrator' */

  /* Sum: '<S124>/Sum' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant3'
   *  DiscreteIntegrator: '<S115>/Integrator'
   *  Product: '<S120>/PProd Out'
   *  Sum: '<S15>/Sum1'
   */
  rtb_SignPreSat = (0.0F - DiscreteTimeIntegrator) * curr_kpki.curr_d_kp +
    (real32_T)Integrator_g * 0.0001F;

  /* Sum: '<S15>/Sum7' */
  rtb_IProdOut = localDW->Merge1 - DiscreteTimeIntegrator1_n;

  /* DiscreteIntegrator: '<S165>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE_e != 0) {
    /* DiscreteIntegrator: '<S165>/Integrator' */
    Integrator = localDW->Integrator_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S165>/Integrator' */
    Integrator = 0.0001F * (real32_T)Curr_loop_ELAPS_T
      * localDW->Integrator_PREV_U + localDW->Integrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S165>/Integrator' */

  /* Sum: '<S174>/Sum' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Product: '<S170>/PProd Out'
   */
  rtb_SignPreSat_g = rtb_IProdOut * curr_kpki.curr_d_kp + Integrator;

  /* Saturate: '<S122>/Saturation' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_SignPreSat_1 = 12.4707661F;
  } else if (rtb_SignPreSat < -12.4707661F) {
    rtb_SignPreSat_1 = -12.4707661F;
  } else {
    rtb_SignPreSat_1 = rtb_SignPreSat;
  }

  /* End of Saturate: '<S122>/Saturation' */

  /* Saturate: '<S172>/Saturation' */
  if (rtb_SignPreSat_g > 12.4707661F) {
    rtb_ZeroGain_m = 12.4707661F;
  } else if (rtb_SignPreSat_g < -12.4707661F) {
    rtb_ZeroGain_m = -12.4707661F;
  } else {
    rtb_ZeroGain_m = rtb_SignPreSat_g;
  }

  /* End of Saturate: '<S172>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/In_park' */
  /* SignalConversion generated from: '<S2>/In_park' */
  In_park(rtb_SignPreSat_1, rtb_ZeroGain_m, rtb_Sin, rtb_Cos, &ualpha, &ubeta);

  /* End of Outputs for SubSystem: '<S2>/In_park' */

  /* Sum: '<S20>/Add8' incorporates:
   *  Product: '<S20>/Product4'
   *  Product: '<S20>/Product5'
   *  Trigonometry: '<S20>/Cos'
   *  Trigonometry: '<S20>/Sin'
   *  UnitDelay: '<S21>/Unit Delay1'
   *  UnitDelay: '<S21>/Unit Delay3'
   */
  DiscreteTimeIntegrator1_n = (0.0F - localDW->UnitDelay1_DSTATE * cosf(LunTheta))
    - localDW->UnitDelay3_DSTATE * sinf(LunTheta);

  /* DiscreteIntegrator: '<S57>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE_k != 0) {
    /* DiscreteIntegrator: '<S57>/Integrator' */
    rtb_Cos = localDW->Integrator_DSTATE_d;
  } else {
    /* DiscreteIntegrator: '<S57>/Integrator' */
    rtb_Cos = 0.0001F * (real32_T)Curr_loop_ELAPS_T
      * localDW->Integrator_PREV_U_c + localDW->Integrator_DSTATE_d;
  }

  /* End of DiscreteIntegrator: '<S57>/Integrator' */

  /* Sum: '<S66>/Sum' incorporates:
   *  Gain: '<S62>/Proportional Gain'
   */
  DiscreteTimeIntegrator = 212.1F * DiscreteTimeIntegrator1_n + rtb_Cos;

  /* Saturate: '<S64>/Saturation' incorporates:
   *  DeadZone: '<S50>/DeadZone'
   */
  if (DiscreteTimeIntegrator > 6283.18555F) {
    rtb_Sin = 6283.18555F;
    DiscreteTimeIntegrator -= 6283.18555F;
  } else {
    if (DiscreteTimeIntegrator < -6283.18555F) {
      rtb_Sin = -6283.18555F;
    } else {
      rtb_Sin = DiscreteTimeIntegrator;
    }

    if (DiscreteTimeIntegrator >= -6283.18555F) {
      DiscreteTimeIntegrator = 0.0F;
    } else {
      DiscreteTimeIntegrator -= -6283.18555F;
    }
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Gain: '<S12>/Gain1' incorporates:
   *  Gain: '<S12>/Gain'
   */
  *rty_LunWm = 1.0F / motor.Pn * rtb_Sin * 9.54929638F;

  /* Gain: '<S54>/Integral Gain' */
  DiscreteTimeIntegrator1_n *= 2500.0F;

  /* Signum: '<S48>/SignPreSat' */
  if (DiscreteTimeIntegrator < 0.0F) {
    rtb_Gain21 = -1.0F;
  } else if (DiscreteTimeIntegrator > 0.0F) {
    rtb_Gain21 = 1.0F;
  } else {
    rtb_Gain21 = DiscreteTimeIntegrator;
  }

  /* End of Signum: '<S48>/SignPreSat' */

  /* Signum: '<S48>/SignPreIntegrator' */
  if (DiscreteTimeIntegrator1_n < 0.0F) {
    rtb_Gain23 = -1.0F;
  } else if (DiscreteTimeIntegrator1_n > 0.0F) {
    rtb_Gain23 = 1.0F;
  } else {
    rtb_Gain23 = DiscreteTimeIntegrator1_n;
  }

  /* End of Signum: '<S48>/SignPreIntegrator' */

  /* Switch: '<S48>/Switch' incorporates:
   *  DataTypeConversion: '<S48>/DataTypeConv1'
   *  DataTypeConversion: '<S48>/DataTypeConv2'
   *  Logic: '<S48>/AND3'
   *  RelationalOperator: '<S48>/Equal1'
   *  RelationalOperator: '<S48>/NotEqual'
   */
  if ((0.0F != DiscreteTimeIntegrator) && ((int8_T)rtb_Gain21 == (int8_T)
       rtb_Gain23)) {
    /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
     *  Constant: '<S48>/Constant1'
     */
    localDW->Integrator_PREV_U_c = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S57>/Integrator' */
    localDW->Integrator_PREV_U_c = DiscreteTimeIntegrator1_n;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Sum: '<S23>/Sum1' incorporates:
   *  Gain: '<S23>/Ts'
   */
  rtb_ZeroGain_m = 0.0001F * rtb_Sin + LunTheta;

  /* Gain: '<S21>/Gain21' incorporates:
   *  UnitDelay: '<S21>/Unit Delay3'
   */
  rtb_Gain21 = 0.0001F / motor.L * localDW->UnitDelay3_DSTATE;

  /* Sum: '<S21>/Add11' incorporates:
   *  UnitDelay: '<S21>/Unit Delay2'
   */
  DiscreteTimeIntegrator = localDW->UnitDelay2_DSTATE - ibeta;

  /* Gain: '<S21>/Gain23' */
  rtb_Gain23 = -0.399999976F * DiscreteTimeIntegrator;

  /* Gain: '<S21>/Gain' incorporates:
   *  Delay: '<S12>/Delay'
   */
  DiscreteTimeIntegrator1_n = 0.0001F * localDW->Delay_DSTATE;

  /* Product: '<S21>/Product3' incorporates:
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  rtb_Product3 = DiscreteTimeIntegrator1_n * localDW->UnitDelay1_DSTATE;

  /* Gain: '<S21>/Gain24' */
  rtb_Gain24 = 1.4F * DiscreteTimeIntegrator;

  /* Gain: '<S21>/Gain16' incorporates:
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  rtb_Gain16 = 0.0001F / motor.L * localDW->UnitDelay1_DSTATE;

  /* Sum: '<S21>/Add8' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  DiscreteTimeIntegrator = localDW->UnitDelay_DSTATE_h - ialpha;

  /* Outputs for Atomic SubSystem: '<S2>/SVPWM1' */
  SVPWM1(ualpha, ubeta, rtu_VDC, rty_Tcmp1);

  /* End of Outputs for SubSystem: '<S2>/SVPWM1' */

  /* SignalConversion generated from: '<S2>/Tcmp2' */
  *rty_Tcmp2 = rty_Tcmp1[1];

  /* SignalConversion generated from: '<S2>/Tcmp3' */
  *rty_Tcmp3 = rty_Tcmp1[2];

  /* DeadZone: '<S108>/DeadZone' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_SignPreSat -= 12.4707661F;
  } else if (rtb_SignPreSat >= -12.4707661F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat -= -12.4707661F;
  }

  /* End of DeadZone: '<S108>/DeadZone' */

  /* Product: '<S112>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_IProdOut_p = (int16_T)floorf(rtb_Sum1_j * curr_kpki.curr_d_ki);

  /* DeadZone: '<S158>/DeadZone' */
  if (rtb_SignPreSat_g > 12.4707661F) {
    rtb_SignPreSat_g -= 12.4707661F;
  } else if (rtb_SignPreSat_g >= -12.4707661F) {
    rtb_SignPreSat_g = 0.0F;
  } else {
    rtb_SignPreSat_g -= -12.4707661F;
  }

  /* End of DeadZone: '<S158>/DeadZone' */

  /* Product: '<S162>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  rtb_IProdOut *= curr_kpki.curr_d_ki;

  /* If: '<S74>/If1' */
  if (rtb_ZeroGain_m > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  Constant: '<S76>/2pi'
     *  Sum: '<S76>/Subtract1'
     */
    localDW->UnitDelay_DSTATE = rtb_ZeroGain_m - 6.28318548F;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem2' */
  } else if (rtb_ZeroGain_m < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  Constant: '<S77>/Angle_offset'
     *  Sum: '<S77>/Subtract1'
     */
    localDW->UnitDelay_DSTATE = rtb_ZeroGain_m + 6.28318548F;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  Inport: '<S75>/In1'
     */
    localDW->UnitDelay_DSTATE = rtb_ZeroGain_m;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
  }

  /* End of If: '<S74>/If1' */

  /* Update for SwitchCase: '<S2>/Switch Case1' */
  switch (localDW->SwitchCase1_ActiveSubsystem) {
   case 0:
   case 1:
   case 4:
    break;

   case 2:
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    localDW->IfActionSubsystem2_PREV_T = Curr_loop_PREV_T_tmp;
    localDW->IfActionSubsystem2_RESET_ELAPS_ = false;

    /* End of Update for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   case 3:
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    localDW->IfActionSubsystem4_PREV_T = Curr_loop_PREV_T_tmp;
    localDW->IfActionSubsystem4_RESET_ELAPS_ = false;

    /* End of Update for SubSystem: '<S2>/If Action Subsystem4' */
    break;
  }

  /* Update for DiscreteIntegrator: '<S115>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 0U;
  localDW->Integrator_DSTATE_f = Integrator_g;

  /* Signum: '<S106>/SignPreSat' */
  if (rtb_SignPreSat < 0.0F) {
    rtb_SignPreSat_1 = -1.0F;
  } else if (rtb_SignPreSat > 0.0F) {
    rtb_SignPreSat_1 = 1.0F;
  } else {
    rtb_SignPreSat_1 = rtb_SignPreSat;
  }

  /* End of Signum: '<S106>/SignPreSat' */

  /* Signum: '<S106>/SignPreIntegrator' */
  if (rtb_IProdOut_p < 0) {
    Integrator_g = -1;
  } else {
    Integrator_g = (int16_T)(rtb_IProdOut_p > 0);
  }

  /* End of Signum: '<S106>/SignPreIntegrator' */

  /* Switch: '<S106>/Switch' incorporates:
   *  DataTypeConversion: '<S106>/DataTypeConv1'
   *  DataTypeConversion: '<S106>/DataTypeConv2'
   *  Logic: '<S106>/AND3'
   *  RelationalOperator: '<S106>/Equal1'
   *  RelationalOperator: '<S106>/NotEqual'
   */
  if ((0.0F != rtb_SignPreSat) && ((int8_T)rtb_SignPreSat_1 == Integrator_g)) {
    /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
     *  Constant: '<S106>/Constant1'
     */
    localDW->Integrator_PREV_U_l = 0;
  } else {
    /* Update for DiscreteIntegrator: '<S115>/Integrator' */
    localDW->Integrator_PREV_U_l = rtb_IProdOut_p;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Update for DiscreteIntegrator: '<S165>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_e = 0U;
  localDW->Integrator_DSTATE = Integrator;

  /* Signum: '<S156>/SignPreSat' */
  if (rtb_SignPreSat_g < 0.0F) {
    rtb_ZeroGain_m = -1.0F;
  } else if (rtb_SignPreSat_g > 0.0F) {
    rtb_ZeroGain_m = 1.0F;
  } else {
    rtb_ZeroGain_m = rtb_SignPreSat_g;
  }

  /* End of Signum: '<S156>/SignPreSat' */

  /* Signum: '<S156>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_Sum1_j = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_Sum1_j = 1.0F;
  } else {
    rtb_Sum1_j = rtb_IProdOut;
  }

  /* End of Signum: '<S156>/SignPreIntegrator' */

  /* Switch: '<S156>/Switch' incorporates:
   *  DataTypeConversion: '<S156>/DataTypeConv1'
   *  DataTypeConversion: '<S156>/DataTypeConv2'
   *  Logic: '<S156>/AND3'
   *  RelationalOperator: '<S156>/Equal1'
   *  RelationalOperator: '<S156>/NotEqual'
   */
  if ((0.0F != rtb_SignPreSat_g) && ((int8_T)rtb_ZeroGain_m == (int8_T)
       rtb_Sum1_j)) {
    /* Update for DiscreteIntegrator: '<S165>/Integrator' incorporates:
     *  Constant: '<S156>/Constant1'
     */
    localDW->Integrator_PREV_U = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S165>/Integrator' */
    localDW->Integrator_PREV_U = rtb_IProdOut;
  }

  /* End of Switch: '<S156>/Switch' */

  /* Update for Delay: '<S12>/Delay' */
  localDW->Delay_DSTATE = rtb_Sin;

  /* Update for UnitDelay: '<S21>/Unit Delay1' incorporates:
   *  Gain: '<S21>/Gain19'
   *  Product: '<S21>/Product2'
   *  Sum: '<S21>/Add9'
   *  UnitDelay: '<S21>/Unit Delay3'
   */
  localDW->UnitDelay1_DSTATE = (localDW->UnitDelay1_DSTATE -
    localDW->UnitDelay3_DSTATE * DiscreteTimeIntegrator1_n) + 1.4F *
    DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S21>/Unit Delay3' incorporates:
   *  Sum: '<S21>/Add12'
   */
  localDW->UnitDelay3_DSTATE = (localDW->UnitDelay3_DSTATE + rtb_Product3) +
    rtb_Gain24;

  /* Update for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_k = 0U;
  localDW->Integrator_DSTATE_d = rtb_Cos;

  /* Gain: '<S21>/Gain20' incorporates:
   *  Gain: '<S21>/Gain15'
   */
  DiscreteTimeIntegrator1_n = 1.0F - motor.Rs * 0.0001F / motor.L;

  /* Update for UnitDelay: '<S21>/Unit Delay2' incorporates:
   *  Gain: '<S21>/Gain20'
   *  Gain: '<S21>/Gain22'
   *  Sum: '<S21>/Add10'
   */
  localDW->UnitDelay2_DSTATE = ((DiscreteTimeIntegrator1_n *
    localDW->UnitDelay2_DSTATE - rtb_Gain21) + 0.0001F / motor.L * ubeta) +
    rtb_Gain23;

  /* Update for UnitDelay: '<S21>/Unit Delay' incorporates:
   *  Gain: '<S21>/Gain15'
   *  Gain: '<S21>/Gain17'
   *  Gain: '<S21>/Gain18'
   *  Sum: '<S21>/Add5'
   */
  localDW->UnitDelay_DSTATE_h = ((DiscreteTimeIntegrator1_n *
    localDW->UnitDelay_DSTATE_h - rtb_Gain16) + 0.0001F / motor.L * ualpha) +
    -0.399999976F * DiscreteTimeIntegrator;
}

/* Model step function */
void FOC_Model_step(void)
{
  real32_T PWM_HalfPeriod[3];

  /* RateTransition: '<S1>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/Curr_loop'
   */
  /* Inport: '<Root>/ia' incorporates:
   *  Inport: '<Root>/MotorOnOff'
   *  Inport: '<Root>/VDC'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Outport: '<Root>/Tcmp2'
   *  Outport: '<Root>/Tcmp3'
   */
  Curr_loop(rtM, rtU.ia, rtU.ib, rtU.ic, rtU.MotorOnOff, rtDW.RateTransition3,
            rtU.VDC, PWM_HalfPeriod, &rtY.Tcmp2, &rtY.Tcmp3, &LunWm,
            &rtDW.RestsSingal, &rtDW.Curr_loop_d);

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator1' */

  /* Outport: '<Root>/Tcmp1' */
  rtY.Tcmp1 = PWM_HalfPeriod[0];

  /* RateTransition: '<S1>/Rate Transition' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    real32_T Integrator;
    real32_T rtb_IntegralGain;
    real32_T rtb_IntegralGain_0;
    real32_T rtb_SignPreIntegrator;
    real32_T rtb_Sum;
    uint32_T Speed_loop_ELAPS_T;

    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/Speed_loop'
     */
    if (rtDW.Speed_loop_RESET_ELAPS_T) {
      Speed_loop_ELAPS_T = 0U;
    } else {
      Speed_loop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.Speed_loop_PREV_T;
    }

    rtDW.Speed_loop_PREV_T = rtM->Timing.clockTick1;
    rtDW.Speed_loop_RESET_ELAPS_T = false;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Inport: '<Root>/Speed_ref'
     */
    rtb_IntegralGain = rtU.Speed_ref - LunWm;

    /* DiscreteIntegrator: '<S216>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S216>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else if ((rtDW.RestsSingal > 0.0) && (rtDW.Integrator_PrevResetState <= 0))
    {
      rtDW.Integrator_DSTATE = 0.0F;

      /* DiscreteIntegrator: '<S216>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else {
      /* DiscreteIntegrator: '<S216>/Integrator' */
      Integrator = 0.001F * (real32_T)Speed_loop_ELAPS_T
        * rtDW.Integrator_PREV_U + rtDW.Integrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S216>/Integrator' */

    /* Sum: '<S225>/Sum' incorporates:
     *  Gain: '<S221>/Proportional Gain'
     */
    rtb_Sum = spd_kpki.spd_kp * rtb_IntegralGain + Integrator;

    /* DeadZone: '<S209>/DeadZone' */
    if (rtb_Sum > 3.0F) {
      rtb_SignPreIntegrator = rtb_Sum - 3.0F;
    } else if (rtb_Sum >= -3.0F) {
      rtb_SignPreIntegrator = 0.0F;
    } else {
      rtb_SignPreIntegrator = rtb_Sum - -3.0F;
    }

    /* End of DeadZone: '<S209>/DeadZone' */

    /* Gain: '<S213>/Integral Gain' */
    rtb_IntegralGain *= spd_kpki.spd_ki;

    /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE = Integrator;
    if (rtDW.RestsSingal > 0.0) {
      rtDW.Integrator_PrevResetState = 1;
    } else if (rtDW.RestsSingal < 0.0) {
      rtDW.Integrator_PrevResetState = -1;
    } else if (rtDW.RestsSingal == 0.0) {
      rtDW.Integrator_PrevResetState = 0;
    } else {
      rtDW.Integrator_PrevResetState = 2;
    }

    /* Signum: '<S207>/SignPreSat' */
    if (rtb_SignPreIntegrator < 0.0F) {
      Integrator = -1.0F;
    } else if (rtb_SignPreIntegrator > 0.0F) {
      Integrator = 1.0F;
    } else {
      Integrator = rtb_SignPreIntegrator;
    }

    /* End of Signum: '<S207>/SignPreSat' */

    /* Signum: '<S207>/SignPreIntegrator' */
    if (rtb_IntegralGain < 0.0F) {
      rtb_IntegralGain_0 = -1.0F;
    } else if (rtb_IntegralGain > 0.0F) {
      rtb_IntegralGain_0 = 1.0F;
    } else {
      rtb_IntegralGain_0 = rtb_IntegralGain;
    }

    /* End of Signum: '<S207>/SignPreIntegrator' */

    /* Switch: '<S207>/Switch' incorporates:
     *  DataTypeConversion: '<S207>/DataTypeConv1'
     *  DataTypeConversion: '<S207>/DataTypeConv2'
     *  Gain: '<S207>/ZeroGain'
     *  Logic: '<S207>/AND3'
     *  RelationalOperator: '<S207>/Equal1'
     *  RelationalOperator: '<S207>/NotEqual'
     */
    if ((0.0F != rtb_SignPreIntegrator) && ((int8_T)Integrator == (int8_T)
         rtb_IntegralGain_0)) {
      /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
       *  Constant: '<S207>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S216>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_IntegralGain;
    }

    /* End of Switch: '<S207>/Switch' */

    /* Saturate: '<S223>/Saturation' */
    if (rtb_Sum > 3.0F) {
      /* Update for RateTransition: '<S1>/Rate Transition3' */
      rtDW.RateTransition3_Buffer0 = 3.0F;
    } else if (rtb_Sum < -3.0F) {
      /* Update for RateTransition: '<S1>/Rate Transition3' */
      rtDW.RateTransition3_Buffer0 = -3.0F;
    } else {
      /* Update for RateTransition: '<S1>/Rate Transition3' */
      rtDW.RateTransition3_Buffer0 = rtb_Sum;
    }

    /* End of Saturate: '<S223>/Saturation' */
    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void FOC_Model_initialize(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/Curr_loop'
   */
  Curr_loop_Init(&rtDW.RestsSingal, &rtDW.Curr_loop_d);

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator1' */

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/Curr_loop'
   */
  Curr_loop_Enable(&rtDW.Curr_loop_d);

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator1' */

  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  rtDW.Speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S216>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
