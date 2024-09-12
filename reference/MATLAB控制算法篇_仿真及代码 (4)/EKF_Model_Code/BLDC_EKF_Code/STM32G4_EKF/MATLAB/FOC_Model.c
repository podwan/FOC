/*
 * File: FOC_Model.c
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
real32_T EKFWm;                        /* '<S2>/Gain1' */
real32_T EKFTheta;                     /* '<S2>/Mod' */
real32_T ualpha;                       /* '<S12>/Add' */
real32_T ubeta;                        /* '<S12>/Add1' */
real32_T ialpha;                       /* '<S5>/Add1' */
real32_T ibeta;                        /* '<S5>/Gain2' */
real32_T state;                        /* '<S2>/Chart1' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
curr_kpki_type curr_kpki = {
  /* curr_d_ki */
  35.0F,

  /* curr_d_kp */
  0.025F
};

motor_type motor = {
  /* L */
  0.00535F,

  /* Pn */
  4.0F,

  /* Rs */
  6.97F,

  /* flux */
  0.016884F
};

spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.000122904603F,

  /* spd_kp */
  0.0031514F
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
extern void rt_mrdivide_U1f4x2_U2f2x2_Yf4x2(const real32_T u0[8], const real32_T
  u1[4], real32_T y[8]);
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
                      *rty_EKFWm, real_T *rty_RestsSingal, const
                      ConstB_Curr_loop *localC, DW_Curr_loop *localDW);
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
  /* Sum: '<S12>/Add' incorporates:
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   */
  *rty_ualpha = rtu_ud * rtu_theta_cos - rtu_uq * rtu_theta_sin;

  /* Sum: '<S12>/Add1' incorporates:
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
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

  /* Gain: '<S28>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S28>/Gain1' */
  rtb_Sum1_j = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S28>/Sum' */
  rtb_Sum_b = rtb_Min + rtb_Sum1_j;

  /* Sum: '<S28>/Sum1' */
  rtb_Sum1_j = rtb_Min - rtb_Sum1_j;

  /* Gain: '<S29>/Gain' incorporates:
   *  MinMax: '<S29>/Min'
   *  MinMax: '<S29>/Min1'
   *  Sum: '<S29>/Sum'
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

void rt_mrdivide_U1f4x2_U2f2x2_Yf4x2(const real32_T u0[8], const real32_T u1[4],
  real32_T y[8])
{
  int32_T r1;
  int32_T r2;
  int32_T y_tmp;
  real32_T a21;
  real32_T a22;
  real32_T a22_tmp;
  if (fabsf(u1[1]) > fabsf(u1[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = u1[r2] / u1[r1];
  a22_tmp = u1[r1 + 2];
  a22 = u1[r2 + 2] - a22_tmp * a21;
  y_tmp = r1 << 2;
  y[y_tmp] = u0[0] / u1[r1];
  r2 <<= 2;
  y[r2] = (u0[4] - y[y_tmp] * a22_tmp) / a22;
  y[y_tmp] -= y[r2] * a21;
  y[y_tmp + 1] = u0[1] / u1[r1];
  y[r2 + 1] = (u0[5] - y[y_tmp + 1] * a22_tmp) / a22;
  y[y_tmp + 1] -= y[r2 + 1] * a21;
  y[y_tmp + 2] = u0[2] / u1[r1];
  y[r2 + 2] = (u0[6] - y[y_tmp + 2] * a22_tmp) / a22;
  y[y_tmp + 2] -= y[r2 + 2] * a21;
  y[y_tmp + 3] = u0[3] / u1[r1];
  y[r2 + 3] = (u0[7] - y[y_tmp + 3] * a22_tmp) / a22;
  y[y_tmp + 3] -= y[r2 + 3] * a21;
}

/* System initialize for function-call system: '<S1>/Curr_loop' */
static void Curr_loop_Init(real_T *rty_RestsSingal, DW_Curr_loop *localDW)
{
  /* Start for SwitchCase: '<S2>/Switch Case1' */
  localDW->SwitchCase1_ActiveSubsystem = -1;

  /* SystemInitialize for Chart: '<S2>/Chart1' */
  *rty_RestsSingal = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem2' */
  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem2' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/EKF' */
  /* Start for IdentityMatrix: '<S16>/IdentityMatrix' */
  memcpy(&localDW->IdentityMatrix[0], &rtConstP.pooled4[0], sizeof(real32_T) <<
         4U);

  /* Start for IdentityMatrix: '<S19>/IdentityMatrix' */
  memcpy(&localDW->IdentityMatrix_k[0], &rtConstP.pooled4[0], sizeof(real32_T) <<
         4U);

  /* End of SystemInitialize for SubSystem: '<S2>/EKF' */
}

/* Enable for function-call system: '<S1>/Curr_loop' */
static void Curr_loop_Enable(DW_Curr_loop *localDW)
{
  localDW->Curr_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S65>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S115>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_e = 1U;
}

/* Output and update for function-call system: '<S1>/Curr_loop' */
static void Curr_loop(RT_MODEL * const rtM, real32_T rtu_ia, real32_T rtu_ib,
                      real32_T rtu_ic, real32_T rtu_MotorOnOff, real32_T
                      rtu_iq_ref, real32_T rtu_VDC, real32_T rty_Tcmp1[3],
                      real32_T *rty_Tcmp2, real32_T *rty_Tcmp3, real32_T
                      *rty_EKFWm, real_T *rty_RestsSingal, const
                      ConstB_Curr_loop *localC, DW_Curr_loop *localDW)
{
  int32_T i;
  int32_T i_0;
  int32_T rtb_Transpose_tmp;
  int32_T rtb_Transpose_tmp_tmp;
  real32_T rtb_Add_i[16];
  real32_T rtb_Transpose[16];
  real32_T rtb_Transpose_0[16];
  real32_T rtb_Divide[8];
  real32_T rtb_Add1[4];
  real32_T rtb_Add_n[4];
  real32_T rtb_MatrixMultiply_d[4];
  real32_T rtb_VectorConcatenate1[4];
  real32_T rtb_VectorConcatenate4[4];
  real32_T rtb_VectorConcatenate[2];
  real32_T tmp[2];
  real32_T tmp_0[2];
  real32_T DiscreteTimeIntegrator;
  real32_T DiscreteTimeIntegrator1_n;
  real32_T DiscreteTimeIntegrator1_n_0;
  real32_T Integrator;
  real32_T rtb_Add_l_tmp;
  real32_T rtb_Add_l_tmp_0;
  real32_T rtb_Cos;
  real32_T rtb_IProdOut;
  real32_T rtb_SignPreIntegrator_bb;
  real32_T rtb_Sin;
  real32_T rtb_Sum1;
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
   *  ActionPort: '<S11>/Action Port'
   */
  /* Update for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S9>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
   *  ActionPort: '<S11>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S9>/Action Port'
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
  Clark(rtu_ia, rtu_ib, rtu_ic, &ialpha, &ibeta);

  /* End of Outputs for SubSystem: '<S2>/Clark' */

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
    localDW->Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/theta_fd'
     */
    localDW->Merge = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    localDW->Merge1 = 0.3F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 2:
    {
      uint32_T IfActionSubsystem2_ELAPS_T;
      if (rtAction != rtPrevAction) {
        localDW->IfActionSubsystem2_RESET_ELAPS_ = true;

        /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        /* Enable for SwitchCase: '<S2>/Switch Case1' incorporates:
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
         */
        localDW->DiscreteTimeIntegrator_SYSTEM_E = 1U;
        localDW->DiscreteTimeIntegrator1_SYSTE_f = 1U;

        /* End of Enable for SubSystem: '<S2>/If Action Subsystem2' */
      }

      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      if (localDW->IfActionSubsystem2_RESET_ELAPS_) {
        IfActionSubsystem2_ELAPS_T = 0U;
      } else {
        IfActionSubsystem2_ELAPS_T = Curr_loop_PREV_T_tmp -
          localDW->IfActionSubsystem2_PREV_T;
      }

      localDW->IfActionSubsystem2_PREV_T = Curr_loop_PREV_T_tmp;
      localDW->IfActionSubsystem2_RESET_ELAPS_ = false;

      /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
      if (localDW->DiscreteTimeIntegrator_SYSTEM_E != 0) {
        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
      } else if ((localDW->ZReset > 0.0F) &&
                 (localDW->DiscreteTimeIntegrator_PrevRese <= 0)) {
        localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
      } else {
        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = 0.0001F * (real32_T)IfActionSubsystem2_ELAPS_T *
          localDW->DiscreteTimeIntegrator_PREV_U +
          localDW->DiscreteTimeIntegrator_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

      /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
      if (localDW->DiscreteTimeIntegrator1_SYSTE_f != 0) {
        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = localDW->DiscreteTimeIntegrator1_DSTAT_j;
      } else if ((localDW->ZReset > 0.0F) &&
                 (localDW->DiscreteTimeIntegrator1_PrevRes <= 0)) {
        localDW->DiscreteTimeIntegrator1_DSTAT_j = 0.0F;

        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = localDW->DiscreteTimeIntegrator1_DSTAT_j;
      } else {
        /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator1_n = 0.0001F * (real32_T)
          IfActionSubsystem2_ELAPS_T * localDW->DiscreteTimeIntegrator1_PREV__h
          + localDW->DiscreteTimeIntegrator1_DSTAT_j;
      }

      /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S9>/Constant'
       *  Math: '<S9>/Mod'
       */
      localDW->Merge = rt_modf(DiscreteTimeIntegrator1_n, 6.28318548F);

      /* Merge: '<S2>/Merge1' incorporates:
       *  Constant: '<S9>/Constant2'
       *  SignalConversion generated from: '<S9>/iq_ref'
       */
      localDW->Merge1 = 0.3F;

      /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
       *  Gain: '<S9>/Gain'
       *  Product: '<S9>/Product'
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

      localDW->DiscreteTimeIntegrator_PREV_U = motor.Pn * 31.4159279F *
        0.333333343F;

      /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
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

      /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    }
    break;

   case 3:
    {
      uint32_T IfActionSubsystem2_ELAPS_T;
      if (rtAction != rtPrevAction) {
        localDW->IfActionSubsystem4_RESET_ELAPS_ = true;

        /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* Enable for SwitchCase: '<S2>/Switch Case1' incorporates:
         *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
         */
        localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;

        /* End of Enable for SubSystem: '<S2>/If Action Subsystem4' */
      }

      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      if (localDW->IfActionSubsystem4_RESET_ELAPS_) {
        IfActionSubsystem2_ELAPS_T = 0U;
      } else {
        IfActionSubsystem2_ELAPS_T = Curr_loop_PREV_T_tmp -
          localDW->IfActionSubsystem4_PREV_T;
      }

      localDW->IfActionSubsystem4_PREV_T = Curr_loop_PREV_T_tmp;
      localDW->IfActionSubsystem4_RESET_ELAPS_ = false;

      /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
      if (localDW->DiscreteTimeIntegrator1_SYSTEM_ != 0) {
        /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator1_DSTATE;
      } else {
        /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
        DiscreteTimeIntegrator = 0.0001F * (real32_T)IfActionSubsystem2_ELAPS_T *
          localDW->DiscreteTimeIntegrator1_PREV_U +
          localDW->DiscreteTimeIntegrator1_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S11>/Constant'
       *  Math: '<S11>/Mod'
       *  SignalConversion generated from: '<S11>/Theta_fd'
       */
      localDW->Merge = rt_modf(DiscreteTimeIntegrator, 6.28318548F);

      /* If: '<S11>/If' incorporates:
       *  Constant: '<S11>/Constant1'
       *  Constant: '<S24>/Constant'
       *  SignalConversion generated from: '<S24>/Out1'
       *  Sum: '<S11>/Add'
       *  UnitDelay: '<S11>/Unit Delay'
       */
      if (localDW->UnitDelay_DSTATE + 0.01F >= 1.0F) {
        /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        rtb_IProdOut = 1.0F;

        /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */
      } else {
        rtb_IProdOut = localDW->UnitDelay_DSTATE + 0.01F;
      }

      /* End of If: '<S11>/If' */

      /* Merge: '<S2>/Merge1' incorporates:
       *  Constant: '<S11>/Constant2'
       *  Constant: '<S11>/Constant4'
       *  Product: '<S11>/Product1'
       *  Sum: '<S11>/Add4'
       */
      localDW->Merge1 = 0.3F - rtb_IProdOut * 0.05F;

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
       *  Gain: '<S11>/Gain'
       */
      localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
      localDW->DiscreteTimeIntegrator1_DSTATE = DiscreteTimeIntegrator;
      localDW->DiscreteTimeIntegrator1_PREV_U = motor.Pn * 31.4159279F;

      /* Update for UnitDelay: '<S11>/Unit Delay' incorporates:
       *  Constant: '<S11>/Constant1'
       *  Sum: '<S11>/Add'
       */
      localDW->UnitDelay_DSTATE += 0.01F;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
    }
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Inport: '<S10>/theta_Close'
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    localDW->Merge = EKFTheta;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Inport: '<S10>/iq_CloseRef'
     */
    localDW->Merge1 = rtu_iq_ref;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* Trigonometry: '<S2>/Cos' */
  rtb_Cos = arm_cos_f32(localDW->Merge);

  /* Trigonometry: '<S2>/Sin' */
  rtb_Sin = arm_sin_f32(localDW->Merge);

  /* Outputs for Atomic SubSystem: '<S2>/Park' */
  Park(ialpha, ibeta, rtb_Sin, rtb_Cos, &rtb_SignPreIntegrator_bb,
       &DiscreteTimeIntegrator);

  /* End of Outputs for SubSystem: '<S2>/Park' */

  /* Sum: '<S15>/Sum1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Sum1 = 0.0F - rtb_SignPreIntegrator_bb;

  /* DiscreteIntegrator: '<S65>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S65>/Integrator' */
    Integrator_g = localDW->Integrator_DSTATE_f;
  } else {
    /* DiscreteIntegrator: '<S65>/Integrator' */
    Integrator_g = (int16_T)((int16_T)((int32_T)Curr_loop_ELAPS_T
      * localDW->Integrator_PREV_U_l) + localDW->Integrator_DSTATE_f);
  }

  /* End of DiscreteIntegrator: '<S65>/Integrator' */

  /* Sum: '<S74>/Sum' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant3'
   *  DiscreteIntegrator: '<S65>/Integrator'
   *  Product: '<S70>/PProd Out'
   *  Sum: '<S15>/Sum1'
   */
  DiscreteTimeIntegrator1_n = (0.0F - rtb_SignPreIntegrator_bb) *
    curr_kpki.curr_d_kp + (real32_T)Integrator_g * 0.0001F;

  /* Sum: '<S15>/Sum7' */
  rtb_IProdOut = localDW->Merge1 - DiscreteTimeIntegrator;

  /* DiscreteIntegrator: '<S115>/Integrator' */
  if (localDW->Integrator_SYSTEM_ENABLE_e != 0) {
    /* DiscreteIntegrator: '<S115>/Integrator' */
    Integrator = localDW->Integrator_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S115>/Integrator' */
    Integrator = 0.0001F * (real32_T)Curr_loop_ELAPS_T
      * localDW->Integrator_PREV_U + localDW->Integrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S115>/Integrator' */

  /* Sum: '<S124>/Sum' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Product: '<S120>/PProd Out'
   */
  DiscreteTimeIntegrator = rtb_IProdOut * curr_kpki.curr_d_kp + Integrator;

  /* Saturate: '<S72>/Saturation' */
  if (DiscreteTimeIntegrator1_n > 12.4707661F) {
    DiscreteTimeIntegrator1_n_0 = 12.4707661F;
  } else if (DiscreteTimeIntegrator1_n < -12.4707661F) {
    DiscreteTimeIntegrator1_n_0 = -12.4707661F;
  } else {
    DiscreteTimeIntegrator1_n_0 = DiscreteTimeIntegrator1_n;
  }

  /* End of Saturate: '<S72>/Saturation' */

  /* Saturate: '<S122>/Saturation' */
  if (DiscreteTimeIntegrator > 12.4707661F) {
    rtb_SignPreIntegrator_bb = 12.4707661F;
  } else if (DiscreteTimeIntegrator < -12.4707661F) {
    rtb_SignPreIntegrator_bb = -12.4707661F;
  } else {
    rtb_SignPreIntegrator_bb = DiscreteTimeIntegrator;
  }

  /* End of Saturate: '<S122>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/In_park' */
  In_park(DiscreteTimeIntegrator1_n_0, rtb_SignPreIntegrator_bb, rtb_Sin,
          rtb_Cos, &ualpha, &ubeta);

  /* End of Outputs for SubSystem: '<S2>/In_park' */

  /* Outputs for Atomic SubSystem: '<S2>/EKF' */
  /* Trigonometry: '<S17>/Cos1' incorporates:
   *  Delay: '<S6>/Delay7'
   */
  rtb_Cos = sinf(localDW->Delay7_DSTATE);

  /* Trigonometry: '<S17>/Cos' incorporates:
   *  Delay: '<S6>/Delay7'
   */
  rtb_SignPreIntegrator_bb = cosf(localDW->Delay7_DSTATE);

  /* Gain: '<S23>/Gain4' incorporates:
   *  Constant: '<S17>/Constant6'
   *  Gain: '<S23>/Gain5'
   */
  DiscreteTimeIntegrator1_n_0 = -motor.Rs / motor.L;

  /* Product: '<S16>/Matrix Multiply' incorporates:
   *  Constant: '<S17>/Constant6'
   */
  rtb_Sin = DiscreteTimeIntegrator1_n_0 * 0.0001F;

  /* Sum: '<S16>/Add1' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenate'
   *  Constant: '<S17>/Constant4'
   *  Constant: '<S17>/Constant5'
   *  Product: '<S16>/Matrix Multiply'
   */
  rtb_Add_i[0] = rtb_Sin;
  rtb_Add_i[1] = 0.0F;
  rtb_Add_i[2] = 0.0F;
  rtb_Add_i[3] = 0.0F;
  rtb_Add_i[4] = 0.0F;
  rtb_Add_i[5] = rtb_Sin;
  rtb_Add_i[6] = 0.0F;
  rtb_Add_i[7] = 0.0F;

  /* Gain: '<S17>/Gain4' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S23>/Gain2'
   */
  rtb_Sin = motor.flux / motor.L;

  /* Sum: '<S16>/Add1' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenate'
   *  Gain: '<S17>/Gain4'
   *  Product: '<S16>/Matrix Multiply'
   */
  rtb_Add_i[8] = rtb_Sin * rtb_Cos * 0.0001F;

  /* Gain: '<S17>/Gain3' incorporates:
   *  Gain: '<S23>/Gain1'
   */
  rtb_Add_l_tmp_0 = -motor.flux / motor.L;

  /* Sum: '<S16>/Add1' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenate'
   *  Constant: '<S17>/Constant4'
   *  Constant: '<S17>/Constant5'
   *  Gain: '<S17>/Gain3'
   *  Product: '<S16>/Matrix Multiply'
   */
  rtb_Add_i[9] = rtb_Add_l_tmp_0 * rtb_SignPreIntegrator_bb * 0.0001F;
  rtb_Add_i[10] = 0.0F;
  rtb_Add_i[11] = 0.0001F;

  /* Gain: '<S17>/Gain1' incorporates:
   *  Delay: '<S6>/Delay6'
   *  Gain: '<S17>/Gain2'
   */
  rtb_Add_l_tmp = rtb_Sin * localDW->Delay6_DSTATE;

  /* Sum: '<S16>/Add1' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenate'
   *  Constant: '<S17>/Constant4'
   *  Constant: '<S17>/Constant5'
   *  Gain: '<S17>/Gain1'
   *  IdentityMatrix: '<S16>/IdentityMatrix'
   *  Math: '<S20>/Transpose'
   *  Product: '<S16>/Matrix Multiply'
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   */
  rtb_Add_i[12] = rtb_Add_l_tmp * rtb_SignPreIntegrator_bb * 0.0001F;
  rtb_Add_i[13] = rtb_Add_l_tmp * rtb_Cos * 0.0001F;
  rtb_Add_i[14] = 0.0F;
  rtb_Add_i[15] = 0.0F;
  mw_arm_add_f32(&localDW->IdentityMatrix[0], &rtb_Add_i[0], &rtb_Transpose[0],
                 16U);
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* Product: '<S20>/Matrix Multiply' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Math: '<S20>/Transpose'
     */
    for (i = 0; i < 4; i++) {
      rtb_Transpose_tmp_tmp = i << 2;
      rtb_Transpose_tmp = i_0 + rtb_Transpose_tmp_tmp;
      rtb_Transpose_0[rtb_Transpose_tmp] = 0.0F;
      rtb_Transpose_0[rtb_Transpose_tmp] += localDW->
        Delay1_DSTATE[rtb_Transpose_tmp_tmp] * rtb_Transpose[i_0];
      rtb_Transpose_0[rtb_Transpose_tmp] += localDW->
        Delay1_DSTATE[rtb_Transpose_tmp_tmp + 1] * rtb_Transpose[i_0 + 4];
      rtb_Transpose_0[rtb_Transpose_tmp] += localDW->
        Delay1_DSTATE[rtb_Transpose_tmp_tmp + 2] * rtb_Transpose[i_0 + 8];
      rtb_Transpose_0[rtb_Transpose_tmp] += localDW->
        Delay1_DSTATE[rtb_Transpose_tmp_tmp + 3] * rtb_Transpose[i_0 + 12];
    }

    /* End of Product: '<S20>/Matrix Multiply' */
    for (i = 0; i < 4; i++) {
      /* Sum: '<S20>/Add' incorporates:
       *  Math: '<S20>/Transpose'
       *  Product: '<S20>/Matrix Multiply1'
       */
      rtb_Transpose_tmp_tmp = (i << 2) + i_0;
      rtb_Add_i[rtb_Transpose_tmp_tmp] = 0.0F;
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtb_Transpose_0[i_0] * rtb_Transpose[i];
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtb_Transpose_0[i_0 + 4] *
        rtb_Transpose[i + 4];
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtb_Transpose_0[i_0 + 8] *
        rtb_Transpose[i + 8];
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtb_Transpose_0[i_0 + 12] *
        rtb_Transpose[i + 12];
    }
  }

  /* Sum: '<S20>/Add' incorporates:
   *  Constant: '<S6>/Q'
   *  Product: '<S20>/Matrix Multiply1'
   */
  mw_arm_add_f32(&rtb_Add_i[0], &rtConstP.Q_Value[0], &rtb_Transpose[0], 16U);

  /* Product: '<S18>/Matrix Multiply' incorporates:
   *  Math: '<S18>/Transpose'
   *  Sum: '<S20>/Add'
   */
  for (i_0 = 0; i_0 < 2; i_0++) {
    for (i = 0; i < 4; i++) {
      rtb_Transpose_tmp_tmp = i_0 << 2;
      rtb_Transpose_tmp = i + rtb_Transpose_tmp_tmp;
      rtb_Divide[rtb_Transpose_tmp] = 0.0F;
      rtb_Divide[rtb_Transpose_tmp] += localC->Transpose[rtb_Transpose_tmp_tmp] *
        rtb_Transpose[i];
      rtb_Divide[rtb_Transpose_tmp] += localC->Transpose[rtb_Transpose_tmp_tmp +
        1] * rtb_Transpose[i + 4];
      rtb_Divide[rtb_Transpose_tmp] += localC->Transpose[rtb_Transpose_tmp_tmp +
        2] * rtb_Transpose[i + 8];
      rtb_Divide[rtb_Transpose_tmp] += localC->Transpose[rtb_Transpose_tmp_tmp +
        3] * rtb_Transpose[i + 12];
    }
  }

  for (i = 0; i < 8; i++) {
    rtb_Add_i[i] = rtb_Divide[i];
  }

  /* End of Product: '<S18>/Matrix Multiply' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    for (i = 0; i < 2; i++) {
      /* Sum: '<S18>/Add' incorporates:
       *  Constant: '<S6>/H'
       *  Product: '<S18>/Matrix Multiply1'
       */
      rtb_Transpose_tmp_tmp = (i_0 << 1) + i;
      rtb_VectorConcatenate4[rtb_Transpose_tmp_tmp] = 0.0F;

      /* Product: '<S18>/Matrix Multiply1' */
      rtb_Transpose_tmp = i_0 << 2;

      /* Sum: '<S18>/Add' incorporates:
       *  Constant: '<S6>/H'
       *  Product: '<S18>/Matrix Multiply1'
       */
      rtb_VectorConcatenate4[rtb_Transpose_tmp_tmp] +=
        rtb_Divide[rtb_Transpose_tmp] * rtConstP.H_Value[i];
      rtb_VectorConcatenate4[rtb_Transpose_tmp_tmp] +=
        rtb_Divide[rtb_Transpose_tmp + 1] * rtConstP.H_Value[i + 2];
      rtb_VectorConcatenate4[rtb_Transpose_tmp_tmp] +=
        rtb_Divide[rtb_Transpose_tmp + 2] * rtConstP.H_Value[i + 4];
      rtb_VectorConcatenate4[rtb_Transpose_tmp_tmp] +=
        rtb_Divide[rtb_Transpose_tmp + 3] * rtConstP.H_Value[i + 6];
    }
  }

  /* Sum: '<S18>/Add' incorporates:
   *  Constant: '<S6>/R'
   *  Product: '<S18>/Matrix Multiply1'
   */
  mw_arm_add_f32(&rtb_VectorConcatenate4[0], &rtConstP.R_Value[0],
                 &rtb_VectorConcatenate1[0], 4U);

  /* Product: '<S18>/Divide' incorporates:
   *  Sum: '<S18>/Add'
   */
  rt_mrdivide_U1f4x2_U2f2x2_Yf4x2(&rtb_Add_i[0], rtb_VectorConcatenate1,
    rtb_Divide);

  /* Sum: '<S23>/Add' incorporates:
   *  Delay: '<S6>/Delay2'
   *  Delay: '<S6>/Delay4'
   *  Delay: '<S6>/Delay5'
   *  Gain: '<S23>/Gain2'
   *  Gain: '<S23>/Gain4'
   *  Product: '<S23>/Product1'
   *  Trigonometry: '<S23>/Cos1'
   */
  rtb_MatrixMultiply_d[0] = rtb_Sin * localDW->Delay4_DSTATE * sinf
    (localDW->Delay5_DSTATE) + DiscreteTimeIntegrator1_n_0 *
    localDW->Delay2_DSTATE;

  /* Sum: '<S23>/Add1' incorporates:
   *  Delay: '<S6>/Delay3'
   *  Delay: '<S6>/Delay4'
   *  Delay: '<S6>/Delay5'
   *  Gain: '<S23>/Gain1'
   *  Gain: '<S23>/Gain5'
   *  Product: '<S23>/Product2'
   *  Trigonometry: '<S23>/Cos'
   */
  rtb_MatrixMultiply_d[1] = rtb_Add_l_tmp_0 * localDW->Delay4_DSTATE * cosf
    (localDW->Delay5_DSTATE) + DiscreteTimeIntegrator1_n_0 *
    localDW->Delay3_DSTATE;

  /* SignalConversion generated from: '<S23>/Vector Concatenate4' incorporates:
   *  Constant: '<S23>/Constant'
   */
  rtb_MatrixMultiply_d[2] = 0.0F;

  /* SignalConversion generated from: '<S23>/Vector Concatenate4' incorporates:
   *  Delay: '<S6>/Delay4'
   */
  rtb_MatrixMultiply_d[3] = localDW->Delay4_DSTATE;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* Sum: '<S22>/Add2' incorporates:
     *  Constant: '<S6>/B'
     *  Product: '<S22>/Matrix Multiply1'
     *  SignalConversion generated from: '<S6>/Vector Concatenate'
     * */
    rtb_VectorConcatenate4[i_0] = rtConstP.B_Value[i_0 + 4] * ubeta +
      rtConstP.B_Value[i_0] * ualpha;
  }

  /* Sum: '<S22>/Add2' incorporates:
   *  Product: '<S21>/Matrix Multiply'
   *  Product: '<S22>/Matrix Multiply1'
   */
  mw_arm_add_f32(&rtb_MatrixMultiply_d[0], &rtb_VectorConcatenate4[0],
                 &rtb_VectorConcatenate1[0], 4U);

  /* Sum: '<S22>/Add1' incorporates:
   *  Delay: '<S6>/Delay'
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add2'
   */
  rtb_VectorConcatenate1[0] *= 0.0001F;
  rtb_VectorConcatenate1[1] *= 0.0001F;
  rtb_VectorConcatenate1[2] *= 0.0001F;
  rtb_VectorConcatenate1[3] *= 0.0001F;
  mw_arm_add_f32(&localDW->Delay_DSTATE[0], &rtb_VectorConcatenate1[0],
                 &rtb_Add1[0], 4U);

  /* SignalConversion generated from: '<S6>/Vector Concatenate2' */
  rtb_VectorConcatenate[0] = ialpha;

  /* SignalConversion generated from: '<S6>/Vector Concatenate2' */
  rtb_VectorConcatenate[1] = ibeta;

  /* Outputs for Atomic SubSystem: '<S6>/X_hat' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    /* Sum: '<S21>/Add1' incorporates:
     *  Constant: '<S6>/H'
     *  Product: '<S21>/Matrix Multiply1'
     *  Sum: '<S22>/Add1'
     */
    tmp[i_0] = ((rtConstP.H_Value[i_0 + 2] * rtb_Add1[1] + rtConstP.H_Value[i_0]
                 * rtb_Add1[0]) + rtConstP.H_Value[i_0 + 4] * rtb_Add1[2]) +
      rtConstP.H_Value[i_0 + 6] * rtb_Add1[3];
  }

  /* Sum: '<S21>/Add1' incorporates:
   *  Concatenate: '<S6>/Vector Concatenate2'
   *  Product: '<S21>/Matrix Multiply1'
   */
  mw_arm_sub_f32(&rtb_VectorConcatenate[0], &tmp[0], &tmp_0[0], 2U);
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* Sum: '<S21>/Add' incorporates:
     *  Product: '<S18>/Divide'
     *  Product: '<S21>/Matrix Multiply'
     *  Sum: '<S21>/Add1'
     */
    rtb_VectorConcatenate4[i_0] = rtb_Divide[i_0 + 4] * tmp_0[1] +
      rtb_Divide[i_0] * tmp_0[0];
  }

  /* Sum: '<S21>/Add' incorporates:
   *  Product: '<S21>/Matrix Multiply'
   *  Sum: '<S22>/Add1'
   */
  mw_arm_add_f32(&rtb_Add1[0], &rtb_VectorConcatenate4[0], &rtb_Add_n[0], 4U);

  /* End of Outputs for SubSystem: '<S6>/X_hat' */

  /* Update for Delay: '<S6>/Delay7' */
  localDW->Delay7_DSTATE = rtb_Add_n[3];

  /* Update for Delay: '<S6>/Delay6' */
  localDW->Delay6_DSTATE = rtb_Add_n[2];
  for (i_0 = 0; i_0 < 4; i_0++) {
    for (i = 0; i < 4; i++) {
      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S6>/H'
       *  Product: '<S19>/Matrix Multiply1'
       */
      rtb_Transpose_tmp_tmp = (i_0 << 2) + i;
      rtb_Add_i[rtb_Transpose_tmp_tmp] = 0.0F;

      /* Product: '<S19>/Matrix Multiply1' incorporates:
       *  Constant: '<S6>/H'
       */
      rtb_Transpose_tmp = i_0 << 1;

      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S6>/H'
       *  Product: '<S18>/Divide'
       *  Product: '<S19>/Matrix Multiply1'
       */
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtConstP.H_Value[rtb_Transpose_tmp] *
        rtb_Divide[i];
      rtb_Add_i[rtb_Transpose_tmp_tmp] += rtConstP.H_Value[rtb_Transpose_tmp + 1]
        * rtb_Divide[i + 4];
    }
  }

  /* Sum: '<S19>/Add' incorporates:
   *  IdentityMatrix: '<S19>/IdentityMatrix'
   *  Product: '<S19>/Matrix Multiply1'
   */
  mw_arm_sub_f32(&localDW->IdentityMatrix_k[0], &rtb_Add_i[0], &rtb_Transpose_0
                 [0], 16U);

  /* Update for Delay: '<S6>/Delay2' */
  localDW->Delay2_DSTATE = rtb_Add_n[0];

  /* Update for Delay: '<S6>/Delay4' */
  localDW->Delay4_DSTATE = rtb_Add_n[2];

  /* Update for Delay: '<S6>/Delay5' */
  localDW->Delay5_DSTATE = rtb_Add_n[3];

  /* Update for Delay: '<S6>/Delay3' */
  localDW->Delay3_DSTATE = rtb_Add_n[1];
  for (i = 0; i < 4; i++) {
    /* Update for Delay: '<S6>/Delay1' incorporates:
     *  Product: '<S19>/Matrix Multiply'
     *  Sum: '<S19>/Add'
     *  Sum: '<S20>/Add'
     */
    for (i_0 = 0; i_0 < 4; i_0++) {
      /* Product: '<S19>/Matrix Multiply' incorporates:
       *  Sum: '<S19>/Add'
       */
      rtb_Transpose_tmp_tmp = i_0 << 2;
      rtb_Transpose_tmp = i + rtb_Transpose_tmp_tmp;
      localDW->Delay1_DSTATE[rtb_Transpose_tmp] = 0.0F;
      localDW->Delay1_DSTATE[rtb_Transpose_tmp] +=
        rtb_Transpose[rtb_Transpose_tmp_tmp] * rtb_Transpose_0[i];
      localDW->Delay1_DSTATE[rtb_Transpose_tmp] +=
        rtb_Transpose[rtb_Transpose_tmp_tmp + 1] * rtb_Transpose_0[i + 4];
      localDW->Delay1_DSTATE[rtb_Transpose_tmp] +=
        rtb_Transpose[rtb_Transpose_tmp_tmp + 2] * rtb_Transpose_0[i + 8];
      localDW->Delay1_DSTATE[rtb_Transpose_tmp] +=
        rtb_Transpose[rtb_Transpose_tmp_tmp + 3] * rtb_Transpose_0[i + 12];
    }

    /* End of Update for Delay: '<S6>/Delay1' */

    /* Update for Delay: '<S6>/Delay' incorporates:
     *  Sum: '<S21>/Add'
     */
    localDW->Delay_DSTATE[i] = rtb_Add_n[i];
  }

  /* End of Outputs for SubSystem: '<S2>/EKF' */

  /* Gain: '<S2>/Gain1' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  *rty_EKFWm = 1.0F / motor.Pn * rtb_Add_n[2] * 9.54929638F;

  /* Math: '<S2>/Mod' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  EKFTheta = rt_modf(rtb_Add_n[3], 6.28318548F);

  /* Outputs for Atomic SubSystem: '<S2>/SVPWM1' */
  SVPWM1(ualpha, ubeta, rtu_VDC, rty_Tcmp1);

  /* End of Outputs for SubSystem: '<S2>/SVPWM1' */

  /* SignalConversion generated from: '<S2>/Tcmp2' */
  *rty_Tcmp2 = rty_Tcmp1[1];

  /* SignalConversion generated from: '<S2>/Tcmp3' */
  *rty_Tcmp3 = rty_Tcmp1[2];

  /* DeadZone: '<S58>/DeadZone' */
  if (DiscreteTimeIntegrator1_n > 12.4707661F) {
    DiscreteTimeIntegrator1_n -= 12.4707661F;
  } else if (DiscreteTimeIntegrator1_n >= -12.4707661F) {
    DiscreteTimeIntegrator1_n = 0.0F;
  } else {
    DiscreteTimeIntegrator1_n -= -12.4707661F;
  }

  /* End of DeadZone: '<S58>/DeadZone' */

  /* Product: '<S62>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  rtb_IProdOut_p = (int16_T)floorf(rtb_Sum1 * curr_kpki.curr_d_ki);

  /* DeadZone: '<S108>/DeadZone' */
  if (DiscreteTimeIntegrator > 12.4707661F) {
    DiscreteTimeIntegrator -= 12.4707661F;
  } else if (DiscreteTimeIntegrator >= -12.4707661F) {
    DiscreteTimeIntegrator = 0.0F;
  } else {
    DiscreteTimeIntegrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S108>/DeadZone' */

  /* Product: '<S112>/IProd Out' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  rtb_IProdOut *= curr_kpki.curr_d_ki;

  /* Update for SwitchCase: '<S2>/Switch Case1' */
  switch (localDW->SwitchCase1_ActiveSubsystem) {
   case 0:
   case 1:
   case 4:
    break;

   case 2:
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    localDW->IfActionSubsystem2_PREV_T = Curr_loop_PREV_T_tmp;
    localDW->IfActionSubsystem2_RESET_ELAPS_ = false;

    /* End of Update for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   case 3:
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    localDW->IfActionSubsystem4_PREV_T = Curr_loop_PREV_T_tmp;
    localDW->IfActionSubsystem4_RESET_ELAPS_ = false;

    /* End of Update for SubSystem: '<S2>/If Action Subsystem4' */
    break;
  }

  /* Update for DiscreteIntegrator: '<S65>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE = 0U;
  localDW->Integrator_DSTATE_f = Integrator_g;

  /* Signum: '<S56>/SignPreSat' */
  if (DiscreteTimeIntegrator1_n < 0.0F) {
    DiscreteTimeIntegrator1_n_0 = -1.0F;
  } else if (DiscreteTimeIntegrator1_n > 0.0F) {
    DiscreteTimeIntegrator1_n_0 = 1.0F;
  } else {
    DiscreteTimeIntegrator1_n_0 = DiscreteTimeIntegrator1_n;
  }

  /* End of Signum: '<S56>/SignPreSat' */

  /* Signum: '<S56>/SignPreIntegrator' */
  if (rtb_IProdOut_p < 0) {
    Integrator_g = -1;
  } else {
    Integrator_g = (int16_T)(rtb_IProdOut_p > 0);
  }

  /* End of Signum: '<S56>/SignPreIntegrator' */

  /* Switch: '<S56>/Switch' incorporates:
   *  DataTypeConversion: '<S56>/DataTypeConv1'
   *  DataTypeConversion: '<S56>/DataTypeConv2'
   *  Logic: '<S56>/AND3'
   *  RelationalOperator: '<S56>/Equal1'
   *  RelationalOperator: '<S56>/NotEqual'
   */
  if ((0.0F != DiscreteTimeIntegrator1_n) && ((int8_T)
       DiscreteTimeIntegrator1_n_0 == Integrator_g)) {
    /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
     *  Constant: '<S56>/Constant1'
     */
    localDW->Integrator_PREV_U_l = 0;
  } else {
    /* Update for DiscreteIntegrator: '<S65>/Integrator' */
    localDW->Integrator_PREV_U_l = rtb_IProdOut_p;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Update for DiscreteIntegrator: '<S115>/Integrator' */
  localDW->Integrator_SYSTEM_ENABLE_e = 0U;
  localDW->Integrator_DSTATE = Integrator;

  /* Signum: '<S106>/SignPreSat' */
  if (DiscreteTimeIntegrator < 0.0F) {
    rtb_SignPreIntegrator_bb = -1.0F;
  } else if (DiscreteTimeIntegrator > 0.0F) {
    rtb_SignPreIntegrator_bb = 1.0F;
  } else {
    rtb_SignPreIntegrator_bb = DiscreteTimeIntegrator;
  }

  /* End of Signum: '<S106>/SignPreSat' */

  /* Signum: '<S106>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    DiscreteTimeIntegrator1_n = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    DiscreteTimeIntegrator1_n = 1.0F;
  } else {
    DiscreteTimeIntegrator1_n = rtb_IProdOut;
  }

  /* End of Signum: '<S106>/SignPreIntegrator' */

  /* Switch: '<S106>/Switch' incorporates:
   *  DataTypeConversion: '<S106>/DataTypeConv1'
   *  DataTypeConversion: '<S106>/DataTypeConv2'
   *  Logic: '<S106>/AND3'
   *  RelationalOperator: '<S106>/Equal1'
   *  RelationalOperator: '<S106>/NotEqual'
   */
  if ((0.0F != DiscreteTimeIntegrator) && ((int8_T)rtb_SignPreIntegrator_bb ==
       (int8_T)DiscreteTimeIntegrator1_n)) {
    /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
     *  Constant: '<S106>/Constant1'
     */
    localDW->Integrator_PREV_U = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S115>/Integrator' */
    localDW->Integrator_PREV_U = rtb_IProdOut;
  }

  /* End of Switch: '<S106>/Switch' */
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
            rtU.VDC, PWM_HalfPeriod, &rtY.Tcmp2, &rtY.Tcmp3, &EKFWm,
            &rtDW.RestsSingal, &rtConstB.Curr_loop_d, &rtDW.Curr_loop_d);

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
    rtb_IntegralGain = rtU.Speed_ref - EKFWm;

    /* DiscreteIntegrator: '<S166>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S166>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else if ((rtDW.RestsSingal > 0.0) && (rtDW.Integrator_PrevResetState <= 0))
    {
      rtDW.Integrator_DSTATE = 0.0F;

      /* DiscreteIntegrator: '<S166>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else {
      /* DiscreteIntegrator: '<S166>/Integrator' */
      Integrator = 0.001F * (real32_T)Speed_loop_ELAPS_T
        * rtDW.Integrator_PREV_U + rtDW.Integrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S166>/Integrator' */

    /* Sum: '<S175>/Sum' incorporates:
     *  Gain: '<S171>/Proportional Gain'
     */
    rtb_Sum = spd_kpki.spd_kp * rtb_IntegralGain + Integrator;

    /* DeadZone: '<S159>/DeadZone' */
    if (rtb_Sum > 3.0F) {
      rtb_SignPreIntegrator = rtb_Sum - 3.0F;
    } else if (rtb_Sum >= -3.0F) {
      rtb_SignPreIntegrator = 0.0F;
    } else {
      rtb_SignPreIntegrator = rtb_Sum - -3.0F;
    }

    /* End of DeadZone: '<S159>/DeadZone' */

    /* Gain: '<S163>/Integral Gain' */
    rtb_IntegralGain *= spd_kpki.spd_ki;

    /* Update for DiscreteIntegrator: '<S166>/Integrator' incorporates:
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

    /* Signum: '<S157>/SignPreSat' */
    if (rtb_SignPreIntegrator < 0.0F) {
      Integrator = -1.0F;
    } else if (rtb_SignPreIntegrator > 0.0F) {
      Integrator = 1.0F;
    } else {
      Integrator = rtb_SignPreIntegrator;
    }

    /* End of Signum: '<S157>/SignPreSat' */

    /* Signum: '<S157>/SignPreIntegrator' */
    if (rtb_IntegralGain < 0.0F) {
      rtb_IntegralGain_0 = -1.0F;
    } else if (rtb_IntegralGain > 0.0F) {
      rtb_IntegralGain_0 = 1.0F;
    } else {
      rtb_IntegralGain_0 = rtb_IntegralGain;
    }

    /* End of Signum: '<S157>/SignPreIntegrator' */

    /* Switch: '<S157>/Switch' incorporates:
     *  DataTypeConversion: '<S157>/DataTypeConv1'
     *  DataTypeConversion: '<S157>/DataTypeConv2'
     *  Gain: '<S157>/ZeroGain'
     *  Logic: '<S157>/AND3'
     *  RelationalOperator: '<S157>/Equal1'
     *  RelationalOperator: '<S157>/NotEqual'
     */
    if ((0.0F != rtb_SignPreIntegrator) && ((int8_T)Integrator == (int8_T)
         rtb_IntegralGain_0)) {
      /* Update for DiscreteIntegrator: '<S166>/Integrator' incorporates:
       *  Constant: '<S157>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S166>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_IntegralGain;
    }

    /* End of Switch: '<S157>/Switch' */

    /* Saturate: '<S173>/Saturation' */
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

    /* End of Saturate: '<S173>/Saturation' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S166>/Integrator' */
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

  /* Enable for DiscreteIntegrator: '<S166>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
