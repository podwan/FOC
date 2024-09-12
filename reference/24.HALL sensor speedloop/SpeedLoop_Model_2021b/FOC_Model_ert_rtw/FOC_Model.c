/*
 * File: FOC_Model.c
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

#include "FOC_Model.h"
#include "rtwtypes.h"
#include <math.h>
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
real32_T Torque;                       /* '<S11>/1_5_Pp' */
real32_T Power;                        /* '<S11>/Product' */
real32_T IqRef;                        /* '<S3>/Merge' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
curr_kpki_type curr_kpki = {
  /* CurrKi */
  35.0F,

  /* CurrKp */
  0.26F
};

spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.00144F,

  /* spd_kp */
  0.03389F
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
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3]);
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

/* Output and update for atomic system: '<S2>/SVPWM' */
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_a;
  real32_T rtb_Sum_o;

  /* Gain: '<S13>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S13>/Gain1' */
  rtb_Sum1_a = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S13>/Sum' */
  rtb_Sum_o = rtb_Min + rtb_Sum1_a;

  /* Sum: '<S13>/Sum1' */
  rtb_Sum1_a = rtb_Min - rtb_Sum1_a;

  /* Gain: '<S14>/Gain' incorporates:
   *  MinMax: '<S14>/Min'
   *  MinMax: '<S14>/Min1'
   *  Sum: '<S14>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_o), rtb_Sum1_a) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_o), rtb_Sum1_a)) * -0.5F;

  /* Sum: '<S8>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_o;
  rty_tABC[2] = rtb_Min + rtb_Sum1_a;

  /* Gain: '<S8>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S8>/Gain'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Sum1'
   */
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * 8500.0F;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * 8500.0F;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * 8500.0F;
}

/* Model step function */
void FOC_Model_step(void)
{
  real32_T Integrator;
  real32_T rtb_Add_c;
  real32_T rtb_DeadZone;
  real32_T rtb_DeadZone_e;
  real32_T rtb_DeadZone_l;
  real32_T rtb_IntegralGain;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation_k;
  real32_T rtb_SinCos;
  uint32_T Subsystem_ELAPS_T;
  int16_T rtb_IProdOut_d;
  int8_T tmp;
  int8_T tmp_0;

  /* Outputs for Atomic SubSystem: '<Root>/FOC_Model' */
  /* RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/speedloop'
     */
    /* Outputs for Enabled SubSystem: '<S3>/Subsystem' incorporates:
     *  EnablePort: '<S120>/Enable'
     */
    /* If: '<S3>/If' incorporates:
     *  Constant: '<S117>/Constant'
     *  Inport: '<Root>/Loop_Mode'
     *  RelationalOperator: '<S117>/Compare'
     */
    if (rtU.Loop_Mode == 1.0F) {
      if (!rtDW.Subsystem_MODE) {
        rtDW.Subsystem_RESET_ELAPS_T = true;

        /* Enable for DiscreteIntegrator: '<S155>/Integrator' */
        rtDW.Integrator_SYSTEM_ENABLE = 1U;
        rtDW.Subsystem_MODE = true;
      }

      if (rtDW.Subsystem_RESET_ELAPS_T) {
        Subsystem_ELAPS_T = 0U;
      } else {
        Subsystem_ELAPS_T = rtM->Timing.clockTick1 - rtDW.Subsystem_PREV_T;
      }

      rtDW.Subsystem_PREV_T = rtM->Timing.clockTick1;
      rtDW.Subsystem_RESET_ELAPS_T = false;

      /* Sum: '<S120>/Sum2' incorporates:
       *  Inport: '<Root>/Speed'
       *  Inport: '<Root>/SpeedRef'
       */
      rtb_IntegralGain = (real32_T)rtU.SpeedRef - rtU.Speed;

      /* DiscreteIntegrator: '<S155>/Integrator' */
      if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
        /* DiscreteIntegrator: '<S155>/Integrator' */
        Integrator = rtDW.Integrator_DSTATE_h;
      } else {
        /* DiscreteIntegrator: '<S155>/Integrator' */
        Integrator = 0.001F * (real32_T)Subsystem_ELAPS_T
          * rtDW.Integrator_PREV_U + rtDW.Integrator_DSTATE_h;
      }

      /* End of DiscreteIntegrator: '<S155>/Integrator' */

      /* Sum: '<S164>/Sum' incorporates:
       *  Gain: '<S160>/Proportional Gain'
       */
      rtb_DeadZone_l = spd_kpki.spd_kp * rtb_IntegralGain + Integrator;

      /* Saturate: '<S162>/Saturation' incorporates:
       *  DeadZone: '<S148>/DeadZone'
       */
      if (rtb_DeadZone_l > 3.0F) {
        /* Saturate: '<S162>/Saturation' */
        rtDW.Saturation = 3.0F;
        rtb_DeadZone_l -= 3.0F;
      } else {
        if (rtb_DeadZone_l < -3.0F) {
          /* Saturate: '<S162>/Saturation' */
          rtDW.Saturation = -3.0F;
        } else {
          /* Saturate: '<S162>/Saturation' */
          rtDW.Saturation = rtb_DeadZone_l;
        }

        if (rtb_DeadZone_l >= -3.0F) {
          rtb_DeadZone_l = 0.0F;
        } else {
          rtb_DeadZone_l -= -3.0F;
        }
      }

      /* End of Saturate: '<S162>/Saturation' */

      /* Gain: '<S152>/Integral Gain' */
      rtb_IntegralGain *= spd_kpki.spd_ki;

      /* Update for DiscreteIntegrator: '<S155>/Integrator' */
      rtDW.Integrator_SYSTEM_ENABLE = 0U;
      rtDW.Integrator_DSTATE_h = Integrator;

      /* Switch: '<S146>/Switch1' incorporates:
       *  Constant: '<S146>/Clamping_zero'
       *  Constant: '<S146>/Constant'
       *  Constant: '<S146>/Constant2'
       *  RelationalOperator: '<S146>/fix for DT propagation issue'
       */
      if (rtb_DeadZone_l > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S146>/Switch2' incorporates:
       *  Constant: '<S146>/Clamping_zero'
       *  Constant: '<S146>/Constant3'
       *  Constant: '<S146>/Constant4'
       *  RelationalOperator: '<S146>/fix for DT propagation issue1'
       */
      if (rtb_IntegralGain > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S146>/Switch' incorporates:
       *  Constant: '<S146>/Clamping_zero'
       *  Logic: '<S146>/AND3'
       *  RelationalOperator: '<S146>/Equal1'
       *  RelationalOperator: '<S146>/Relational Operator'
       *  Switch: '<S146>/Switch1'
       *  Switch: '<S146>/Switch2'
       */
      if ((rtb_DeadZone_l != 0.0F) && (tmp == tmp_0)) {
        /* Update for DiscreteIntegrator: '<S155>/Integrator' incorporates:
         *  Constant: '<S146>/Constant1'
         */
        rtDW.Integrator_PREV_U = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S155>/Integrator' */
        rtDW.Integrator_PREV_U = rtb_IntegralGain;
      }

      /* End of Switch: '<S146>/Switch' */

      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S118>/Action Port'
       */
      /* Merge: '<S3>/Merge' incorporates:
       *  SignalConversion generated from: '<S118>/iqRef'
       */
      IqRef = rtDW.Saturation;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    } else {
      rtDW.Subsystem_MODE = false;

      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S119>/Action Port'
       */
      /* Merge: '<S3>/Merge' incorporates:
       *  Inport: '<Root>/CurrMode_IqRef'
       *  SignalConversion generated from: '<S119>/iqRef'
       */
      IqRef = rtU.CurrMode_IqRef;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    }

    /* End of If: '<S3>/If' */
    /* End of Outputs for SubSystem: '<S3>/Subsystem' */
    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* RateTransition: '<S1>/Rate Transition2' */
    rtDW.RateTransition2 = rtDW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* Outputs for Atomic SubSystem: '<S1>/currloop' */
  /* Trigonometry: '<S2>/SinCos1' incorporates:
   *  Inport: '<Root>/theta'
   */
  rtb_IntegralGain = cosf(rtU.theta);

  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S5>/Add'
   */
  Integrator = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

  /* Gain: '<S5>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S5>/Add2'
   */
  rtb_DeadZone_l = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S2>/SinCos' incorporates:
   *  Inport: '<Root>/theta'
   */
  rtb_SinCos = sinf(rtU.theta);

  /* Sum: '<S7>/Add' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   */
  rtb_Add_c = Integrator * rtb_IntegralGain + rtb_DeadZone_l * rtb_SinCos;

  /* Sum: '<S59>/Sum' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant3'
   *  DiscreteIntegrator: '<S50>/Integrator'
   *  Product: '<S55>/PProd Out'
   *  Sum: '<S9>/Sum1'
   */
  rtb_DeadZone = (0.0F - rtb_Add_c) * curr_kpki.CurrKp + (real32_T)
    rtDW.Integrator_DSTATE_p * 0.0001F;

  /* Saturate: '<S57>/Saturation' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_Saturation = 12.4707661F;
  } else if (rtb_DeadZone < -12.4707661F) {
    rtb_Saturation = -12.4707661F;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Sum: '<S7>/Add1' incorporates:
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   */
  rtb_DeadZone_l = rtb_DeadZone_l * rtb_IntegralGain - Integrator * rtb_SinCos;

  /* Sum: '<S9>/Sum7' */
  Integrator = rtDW.RateTransition2 - rtb_DeadZone_l;

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S9>/Constant1'
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Product: '<S105>/PProd Out'
   */
  rtb_DeadZone_e = Integrator * curr_kpki.CurrKp + rtDW.Integrator_DSTATE;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_DeadZone_e > 12.4707661F) {
    rtb_Saturation_k = 12.4707661F;
  } else if (rtb_DeadZone_e < -12.4707661F) {
    rtb_Saturation_k = -12.4707661F;
  } else {
    rtb_Saturation_k = rtb_DeadZone_e;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/SVPWM' */
  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/VBUS'
   *  Outport: '<Root>/tABC'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Sum: '<S4>/Add1'
   */
  SVPWM(rtb_Saturation * rtb_IntegralGain - rtb_Saturation_k * rtb_SinCos,
        rtb_Saturation * rtb_SinCos + rtb_Saturation_k * rtb_IntegralGain,
        rtU.VBUS, rtY.tABC);

  /* End of Outputs for SubSystem: '<S2>/SVPWM' */

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_DeadZone_e > 12.4707661F) {
    rtb_DeadZone_e -= 12.4707661F;
  } else if (rtb_DeadZone_e >= -12.4707661F) {
    rtb_DeadZone_e = 0.0F;
  } else {
    rtb_DeadZone_e -= -12.4707661F;
  }

  /* End of DeadZone: '<S93>/DeadZone' */

  /* Product: '<S97>/IProd Out' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  Integrator *= curr_kpki.CurrKi;

  /* Gain: '<S11>/1_5_Pp' incorporates:
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product3'
   *  Sum: '<S11>/Add'
   */
  Torque = (0.0F * rtb_Add_c + 0.016884F) * rtb_DeadZone_l * 3.0F;

  /* Product: '<S11>/Product' incorporates:
   *  Inport: '<Root>/Speed'
   */
  Power = Torque * rtU.Speed;

  /* DeadZone: '<S43>/DeadZone' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_DeadZone -= 12.4707661F;
  } else if (rtb_DeadZone >= -12.4707661F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -12.4707661F;
  }

  /* End of DeadZone: '<S43>/DeadZone' */

  /* Product: '<S47>/IProd Out' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant4'
   *  Sum: '<S9>/Sum1'
   */
  rtb_IProdOut_d = (int16_T)floorf((0.0F - rtb_Add_c) * curr_kpki.CurrKi);

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant2'
   *  RelationalOperator: '<S41>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/Clamping_zero'
   *  Constant: '<S41>/Constant3'
   *  Constant: '<S41>/Constant4'
   *  RelationalOperator: '<S41>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_d > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Logic: '<S41>/AND3'
   *  RelationalOperator: '<S41>/Equal1'
   *  RelationalOperator: '<S41>/Relational Operator'
   *  Switch: '<S41>/Switch1'
   *  Switch: '<S41>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut_d = 0;
  }

  /* Update for DiscreteIntegrator: '<S50>/Integrator' incorporates:
   *  Switch: '<S41>/Switch'
   */
  rtDW.Integrator_DSTATE_p += rtb_IProdOut_d;

  /* Switch: '<S91>/Switch1' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S91>/Constant2'
   *  RelationalOperator: '<S91>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_e > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant3'
   *  Constant: '<S91>/Constant4'
   *  RelationalOperator: '<S91>/fix for DT propagation issue1'
   */
  if (Integrator > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant1'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   *  RelationalOperator: '<S91>/Relational Operator'
   *  Switch: '<S91>/Switch1'
   *  Switch: '<S91>/Switch2'
   */
  if ((rtb_DeadZone_e != 0.0F) && (tmp == tmp_0)) {
    Integrator = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Switch: '<S91>/Switch'
   */
  rtDW.Integrator_DSTATE += 0.0001F * Integrator;

  /* End of Outputs for SubSystem: '<S1>/currloop' */

  /* Update for RateTransition: '<S1>/Rate Transition2' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition2_Buffer0 = IqRef;
  }

  /* End of Update for RateTransition: '<S1>/Rate Transition2' */
  /* End of Outputs for SubSystem: '<Root>/FOC_Model' */
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
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
