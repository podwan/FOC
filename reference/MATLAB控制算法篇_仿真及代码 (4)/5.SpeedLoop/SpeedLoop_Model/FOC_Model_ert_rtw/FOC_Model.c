/*
 * File: FOC_Model.c
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

#include "FOC_Model.h"

/* Named constants for Chart: '<S2>/Chart' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define NumBitsPerChar                 8U
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
real32_T ThetaOpen;                    /* '<S2>/Merge' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
motor_type motor = {
  /* Pn */
  2.0F
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
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3]);
static void rate_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

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

  /* Gain: '<S14>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S14>/Gain1' */
  rtb_Sum1_a = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S14>/Sum' */
  rtb_Sum_o = rtb_Min + rtb_Sum1_a;

  /* Sum: '<S14>/Sum1' */
  rtb_Sum1_a = rtb_Min - rtb_Sum1_a;

  /* Gain: '<S15>/Gain' incorporates:
   *  MinMax: '<S15>/Min'
   *  MinMax: '<S15>/Min1'
   *  Sum: '<S15>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_o), rtb_Sum1_a) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_o), rtb_Sum1_a)) * -0.5F;

  /* Sum: '<S12>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_o;
  rty_tABC[2] = rtb_Min + rtb_Sum1_a;

  /* Gain: '<S12>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S12>/Constant'
   *  Gain: '<S12>/Gain'
   *  Product: '<S12>/Divide'
   *  Sum: '<S12>/Sum1'
   */
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * 8000.0F;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void FOC_Model_step(void)
{
  real32_T Integrator;
  real32_T rtb_IntegralGain;
  real32_T rtb_Saturation;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreIntegrator_l;
  real32_T rtb_SinCos;
  real32_T rtb_SinCos1;
  real32_T rtb_Sum;
  int16_T rtb_IProdOut_d;
  int16_T rtb_IProdOut_f;

  /* Outputs for Atomic SubSystem: '<Root>/FOC_Model' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    uint32_T speedloop_ELAPS_T;

    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/speedloop'
     */
    if (rtDW.speedloop_RESET_ELAPS_T) {
      speedloop_ELAPS_T = 0U;
    } else {
      speedloop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.speedloop_PREV_T;
    }

    rtDW.speedloop_PREV_T = rtM->Timing.clockTick1;
    rtDW.speedloop_RESET_ELAPS_T = false;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Inport: '<Root>/SpeedFd'
     *  Inport: '<Root>/SpeedRef'
     */
    rtb_IntegralGain = (real32_T)rtU.SpeedRef - rtU.SpeedFd;

    /* DiscreteIntegrator: '<S152>/Integrator' */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S152>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE_h;
    } else {
      /* DiscreteIntegrator: '<S152>/Integrator' */
      Integrator = 0.001F * (real32_T)speedloop_ELAPS_T * rtDW.Integrator_PREV_U
        + rtDW.Integrator_DSTATE_h;
    }

    /* End of DiscreteIntegrator: '<S152>/Integrator' */

    /* Sum: '<S161>/Sum' incorporates:
     *  Gain: '<S157>/Proportional Gain'
     */
    rtb_Sum = spd_kpki.spd_kp * rtb_IntegralGain + Integrator;

    /* DeadZone: '<S145>/DeadZone' incorporates:
     *  Saturate: '<S159>/Saturation'
     */
    if (rtb_Sum > 3.0F) {
      rtb_SignPreIntegrator_l = rtb_Sum - 3.0F;

      /* Saturate: '<S159>/Saturation' */
      rtDW.Saturation = 3.0F;
    } else {
      if (rtb_Sum >= -3.0F) {
        rtb_SignPreIntegrator_l = 0.0F;
      } else {
        rtb_SignPreIntegrator_l = rtb_Sum - -3.0F;
      }

      if (rtb_Sum < -3.0F) {
        /* Saturate: '<S159>/Saturation' */
        rtDW.Saturation = -3.0F;
      } else {
        /* Saturate: '<S159>/Saturation' */
        rtDW.Saturation = rtb_Sum;
      }
    }

    /* End of DeadZone: '<S145>/DeadZone' */

    /* Gain: '<S149>/Integral Gain' */
    rtb_IntegralGain *= spd_kpki.spd_ki;

    /* Update for DiscreteIntegrator: '<S152>/Integrator' */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE_h = Integrator;

    /* Signum: '<S143>/SignPreSat' */
    if (rtb_SignPreIntegrator_l < 0.0F) {
      Integrator = -1.0F;
    } else if (rtb_SignPreIntegrator_l > 0.0F) {
      Integrator = 1.0F;
    } else if (rtb_SignPreIntegrator_l == 0.0F) {
      Integrator = 0.0F;
    } else {
      Integrator = (rtNaNF);
    }

    /* End of Signum: '<S143>/SignPreSat' */

    /* Signum: '<S143>/SignPreIntegrator' */
    if (rtb_IntegralGain < 0.0F) {
      rtb_SinCos1 = -1.0F;
    } else if (rtb_IntegralGain > 0.0F) {
      rtb_SinCos1 = 1.0F;
    } else if (rtb_IntegralGain == 0.0F) {
      rtb_SinCos1 = 0.0F;
    } else {
      rtb_SinCos1 = (rtNaNF);
    }

    /* End of Signum: '<S143>/SignPreIntegrator' */

    /* Switch: '<S143>/Switch' incorporates:
     *  DataTypeConversion: '<S143>/DataTypeConv1'
     *  DataTypeConversion: '<S143>/DataTypeConv2'
     *  Gain: '<S143>/ZeroGain'
     *  Logic: '<S143>/AND3'
     *  RelationalOperator: '<S143>/Equal1'
     *  RelationalOperator: '<S143>/NotEqual'
     */
    if ((0.0F * rtb_Sum != rtb_SignPreIntegrator_l) && ((int8_T)Integrator ==
         (int8_T)rtb_SinCos1)) {
      /* Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
       *  Constant: '<S143>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S152>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_IntegralGain;
    }

    /* End of Switch: '<S143>/Switch' */
    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */
  }

  /* Outputs for Atomic SubSystem: '<S1>/currloop' */
  /* Sum: '<S6>/Add1' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S6>/Add'
   */
  rtb_SignPreIntegrator_l = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) *
    0.333333343F;

  /* Chart: '<S2>/Chart' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_FOC_Model == 0U) {
    rtDW.is_active_c3_FOC_Model = 1U;
    rtDW.is_c3_FOC_Model = IN_IDLE;
  } else {
    switch (rtDW.is_c3_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 2000) {
        rtDW.is_c3_FOC_Model = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.ZReset = 0.0;
        rtDW.cnt = 0.0;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Model = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0F) {
        rtDW.is_c3_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_state = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Model = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 20000) {
        rtDW.is_c3_FOC_Model = IN_RunStage;
      } else {
        if (rtDW.cnt == 1.0) {
          rtDW.ZReset = 1.0;
        }

        rtDW.cnt = 1.0;
        rtDW.Motor_state = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Model = IN_IDLE;
      } else {
        rtDW.Motor_state = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* SwitchCase: '<S2>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 0.5F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    if ((rtDW.ZReset > 0.0) && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      rtDW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }

    rtb_IntegralGain = rtDW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    if ((rtDW.ZReset > 0.0) && (rtDW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
      rtDW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }

    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant1'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
     *  Math: '<S9>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S2>/Constant5'
     *  Inport: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S9>/Gain'
     *  Product: '<S9>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += motor.Pn * 83.7758F * 0.5F * 0.0001F;
    if (rtDW.ZReset > 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (rtDW.ZReset < 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = -1;
    } else if (rtDW.ZReset == 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 0;
    } else {
      rtDW.DiscreteTimeIntegrator_PrevRese = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F * rtb_IntegralGain;
    if (rtDW.ZReset > 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 1;
    } else if (rtDW.ZReset < 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = -1;
    } else if (rtDW.ZReset == 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 0;
    } else {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Inport: '<Root>/theta'
     *  Inport: '<S10>/theta'
     */
    ThetaOpen = rtU.theta;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Inport: '<S10>/iq_ref'
     */
    rtDW.Merge1 = rtDW.Saturation;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Trigonometry: '<S2>/SinCos1' */
  rtb_SinCos1 = cosf(ThetaOpen);

  /* Gain: '<S6>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S6>/Add2'
   */
  rtb_IntegralGain = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S2>/SinCos' */
  rtb_SinCos = sinf(ThetaOpen);

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Add'
   */
  rtb_Sum = 0.0F - (rtb_SignPreIntegrator_l * rtb_SinCos1 + rtb_IntegralGain *
                    rtb_SinCos);

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S13>/Constant3'
   *  DiscreteIntegrator: '<S51>/Integrator'
   *  Product: '<S56>/PProd Out'
   */
  Integrator = rtb_Sum * 0.26F + (real32_T)rtDW.Integrator_DSTATE_p * 0.0001F;

  /* Saturate: '<S58>/Saturation' */
  if (Integrator > 12.4707661F) {
    rtb_Saturation = 12.4707661F;
  } else if (Integrator < -12.4707661F) {
    rtb_Saturation = -12.4707661F;
  } else {
    rtb_Saturation = Integrator;
  }

  /* End of Saturate: '<S58>/Saturation' */

  /* Sum: '<S13>/Sum7' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Sum: '<S11>/Add1'
   */
  rtb_IntegralGain = rtDW.Merge1 - (rtb_IntegralGain * rtb_SinCos1 -
    rtb_SignPreIntegrator_l * rtb_SinCos);

  /* Sum: '<S110>/Sum' incorporates:
   *  Constant: '<S13>/Constant1'
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Product: '<S106>/PProd Out'
   */
  rtb_SignPreIntegrator_l = rtb_IntegralGain * 0.26F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S108>/Saturation' */
  if (rtb_SignPreIntegrator_l > 12.4707661F) {
    rtb_SignPreIntegrator = 12.4707661F;
  } else if (rtb_SignPreIntegrator_l < -12.4707661F) {
    rtb_SignPreIntegrator = -12.4707661F;
  } else {
    rtb_SignPreIntegrator = rtb_SignPreIntegrator_l;
  }

  /* End of Saturate: '<S108>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/SVPWM' */
  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/v_bus'
   *  Outport: '<Root>/tABC'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Sum: '<S4>/Add1'
   */
  SVPWM(rtb_Saturation * rtb_SinCos1 - rtb_SignPreIntegrator * rtb_SinCos,
        rtb_Saturation * rtb_SinCos + rtb_SignPreIntegrator * rtb_SinCos1,
        rtU.v_bus, rtY.tABC);

  /* End of Outputs for SubSystem: '<S2>/SVPWM' */

  /* Gain: '<S42>/ZeroGain' */
  rtb_SinCos1 = 0.0F * Integrator;

  /* DeadZone: '<S44>/DeadZone' */
  if (Integrator > 12.4707661F) {
    Integrator -= 12.4707661F;
  } else if (Integrator >= -12.4707661F) {
    Integrator = 0.0F;
  } else {
    Integrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S44>/DeadZone' */

  /* Product: '<S48>/IProd Out' incorporates:
   *  Constant: '<S13>/Constant4'
   */
  rtb_IProdOut_d = (int16_T)floorf(rtb_Sum * 35.0F);

  /* Gain: '<S92>/ZeroGain' */
  rtb_Sum = 0.0F * rtb_SignPreIntegrator_l;

  /* DeadZone: '<S94>/DeadZone' */
  if (rtb_SignPreIntegrator_l > 12.4707661F) {
    rtb_SignPreIntegrator_l -= 12.4707661F;
  } else if (rtb_SignPreIntegrator_l >= -12.4707661F) {
    rtb_SignPreIntegrator_l = 0.0F;
  } else {
    rtb_SignPreIntegrator_l -= -12.4707661F;
  }

  /* End of DeadZone: '<S94>/DeadZone' */

  /* Product: '<S98>/IProd Out' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  rtb_IntegralGain *= 35.0F;

  /* Signum: '<S42>/SignPreSat' */
  if (Integrator < 0.0F) {
    rtb_SinCos = -1.0F;
  } else if (Integrator > 0.0F) {
    rtb_SinCos = 1.0F;
  } else if (Integrator == 0.0F) {
    rtb_SinCos = 0.0F;
  } else {
    rtb_SinCos = (rtNaNF);
  }

  /* End of Signum: '<S42>/SignPreSat' */

  /* Signum: '<S42>/SignPreIntegrator' */
  if (rtb_IProdOut_d < 0) {
    rtb_IProdOut_f = -1;
  } else {
    rtb_IProdOut_f = (int16_T)(rtb_IProdOut_d > 0);
  }

  /* End of Signum: '<S42>/SignPreIntegrator' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant1'
   *  DataTypeConversion: '<S42>/DataTypeConv1'
   *  DataTypeConversion: '<S42>/DataTypeConv2'
   *  Logic: '<S42>/AND3'
   *  RelationalOperator: '<S42>/Equal1'
   *  RelationalOperator: '<S42>/NotEqual'
   */
  if ((rtb_SinCos1 != Integrator) && ((int8_T)rtb_SinCos == rtb_IProdOut_f)) {
    rtb_IProdOut_d = 0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Update for DiscreteIntegrator: '<S51>/Integrator' */
  rtDW.Integrator_DSTATE_p += rtb_IProdOut_d;

  /* Signum: '<S92>/SignPreSat' */
  if (rtb_SignPreIntegrator_l < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_SignPreIntegrator_l > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_SignPreIntegrator_l == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S92>/SignPreSat' */

  /* Signum: '<S92>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0F) {
    rtb_SinCos1 = -1.0F;
  } else if (rtb_IntegralGain > 0.0F) {
    rtb_SinCos1 = 1.0F;
  } else if (rtb_IntegralGain == 0.0F) {
    rtb_SinCos1 = 0.0F;
  } else {
    rtb_SinCos1 = (rtNaNF);
  }

  /* End of Signum: '<S92>/SignPreIntegrator' */

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S92>/Constant1'
   *  DataTypeConversion: '<S92>/DataTypeConv1'
   *  DataTypeConversion: '<S92>/DataTypeConv2'
   *  Logic: '<S92>/AND3'
   *  RelationalOperator: '<S92>/Equal1'
   *  RelationalOperator: '<S92>/NotEqual'
   */
  if ((rtb_Sum != rtb_SignPreIntegrator_l) && ((int8_T)Integrator == (int8_T)
       rtb_SinCos1)) {
    rtb_IntegralGain = 0.0F;
  }

  /* End of Switch: '<S92>/Switch' */

  /* Update for DiscreteIntegrator: '<S101>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IntegralGain;

  /* End of Outputs for SubSystem: '<S1>/currloop' */
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
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/FOC_Model' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/currloop' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem2' */
  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem2' */
  /* End of SystemInitialize for SubSystem: '<S1>/currloop' */
  /* End of SystemInitialize for SubSystem: '<Root>/FOC_Model' */

  /* Enable for Atomic SubSystem: '<Root>/FOC_Model' */
  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/speedloop'
   */
  rtDW.speedloop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S152>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
  /* End of Enable for SubSystem: '<Root>/FOC_Model' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
