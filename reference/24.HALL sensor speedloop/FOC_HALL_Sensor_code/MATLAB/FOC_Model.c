/*
 * File: FOC_Model.c
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

#include "FOC_Model.h"
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
real32_T IqRef;                        /* '<S157>/Saturation' */
real32_T Wm;                           /* '<S3>/Gain2' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.00144F,

  /* spd_kp */
  0.003389F
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

  /* Gain: '<S9>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S9>/Gain1' */
  rtb_Sum1_a = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S9>/Sum' */
  rtb_Sum_o = rtb_Min + rtb_Sum1_a;

  /* Sum: '<S9>/Sum1' */
  rtb_Sum1_a = rtb_Min - rtb_Sum1_a;

  /* Gain: '<S10>/Gain' incorporates:
   *  MinMax: '<S10>/Min'
   *  MinMax: '<S10>/Min1'
   *  Sum: '<S10>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_o), rtb_Sum1_a) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_o), rtb_Sum1_a)) * -0.5F;

  /* Sum: '<S7>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_o;
  rty_tABC[2] = rtb_Min + rtb_Sum1_a;

  /* Gain: '<S7>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain'
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Sum1'
   */
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * 8000.0F;
}

/* Model step function */
void FOC_Model_step(void)
{
  real32_T Integrator;
  real32_T rtb_Add_c;
  real32_T rtb_IntegralGain;
  real32_T rtb_Merge;
  real32_T rtb_Saturation;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SinCos;
  real32_T rtb_Sum;
  int16_T rtb_IProdOut_d;
  int16_T rtb_IProdOut_f;

  /* Outputs for Atomic SubSystem: '<Root>/FOC_Model' */
  /* RateTransition: '<S1>/Rate Transition1' */
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
     *  Inport: '<Root>/Speed'
     *  Inport: '<Root>/SpeedRef'
     */
    rtb_IntegralGain = (real32_T)rtU.SpeedRef - rtU.Speed;

    /* DiscreteIntegrator: '<S150>/Integrator' */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S150>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE_h;
    } else {
      /* DiscreteIntegrator: '<S150>/Integrator' */
      Integrator = 0.001F * (real32_T)speedloop_ELAPS_T * rtDW.Integrator_PREV_U
        + rtDW.Integrator_DSTATE_h;
    }

    /* End of DiscreteIntegrator: '<S150>/Integrator' */

    /* Sum: '<S159>/Sum' incorporates:
     *  Gain: '<S155>/Proportional Gain'
     */
    rtb_Sum = spd_kpki.spd_kp * rtb_IntegralGain + Integrator;

    /* DeadZone: '<S143>/DeadZone' incorporates:
     *  Saturate: '<S157>/Saturation'
     */
    if (rtb_Sum > 5.0F) {
      rtb_Merge = rtb_Sum - 5.0F;

      /* Saturate: '<S157>/Saturation' */
      IqRef = 5.0F;
    } else {
      if (rtb_Sum >= -5.0F) {
        rtb_Merge = 0.0F;
      } else {
        rtb_Merge = rtb_Sum - -5.0F;
      }

      if (rtb_Sum < -5.0F) {
        /* Saturate: '<S157>/Saturation' */
        IqRef = -5.0F;
      } else {
        /* Saturate: '<S157>/Saturation' */
        IqRef = rtb_Sum;
      }
    }

    /* End of DeadZone: '<S143>/DeadZone' */

    /* Gain: '<S147>/Integral Gain' */
    rtb_IntegralGain *= spd_kpki.spd_ki;

    /* Sum: '<S3>/Add' incorporates:
     *  Inport: '<Root>/theta'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    rtb_Add_c = rtU.theta - rtDW.UnitDelay_DSTATE;

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S113>/Constant2'
     *  Constant: '<S115>/Constant2'
     *  Sum: '<S113>/Add'
     *  Sum: '<S115>/Add'
     */
    if (rtb_Add_c < -5.0F) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S113>/Action Port'
       */
      rtb_Add_c += 6.28318548F;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    } else if (rtb_Add_c > 5.0F) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S115>/Action Port'
       */
      rtb_Add_c -= 6.28318548F;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    }

    /* End of If: '<S3>/If' */

    /* Gain: '<S3>/Gain2' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain3'
     */
    Wm = 1000.0F * rtb_Add_c * 0.5F * 9.54929638F;

    /* Update for DiscreteIntegrator: '<S150>/Integrator' */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE_h = Integrator;

    /* Signum: '<S141>/SignPreSat' */
    if (rtb_Merge < 0.0F) {
      rtb_SinCos = -1.0F;
    } else if (rtb_Merge > 0.0F) {
      rtb_SinCos = 1.0F;
    } else if (rtb_Merge == 0.0F) {
      rtb_SinCos = 0.0F;
    } else {
      rtb_SinCos = (rtNaNF);
    }

    /* End of Signum: '<S141>/SignPreSat' */

    /* Signum: '<S141>/SignPreIntegrator' */
    if (rtb_IntegralGain < 0.0F) {
      Integrator = -1.0F;
    } else if (rtb_IntegralGain > 0.0F) {
      Integrator = 1.0F;
    } else if (rtb_IntegralGain == 0.0F) {
      Integrator = 0.0F;
    } else {
      Integrator = (rtNaNF);
    }

    /* End of Signum: '<S141>/SignPreIntegrator' */

    /* Switch: '<S141>/Switch' incorporates:
     *  DataTypeConversion: '<S141>/DataTypeConv1'
     *  DataTypeConversion: '<S141>/DataTypeConv2'
     *  Gain: '<S141>/ZeroGain'
     *  Logic: '<S141>/AND3'
     *  RelationalOperator: '<S141>/Equal1'
     *  RelationalOperator: '<S141>/NotEqual'
     */
    if ((0.0F * rtb_Sum != rtb_Merge) && ((int8_T)rtb_SinCos == (int8_T)
         Integrator)) {
      /* Update for DiscreteIntegrator: '<S150>/Integrator' incorporates:
       *  Constant: '<S141>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S150>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_IntegralGain;
    }

    /* End of Switch: '<S141>/Switch' */

    /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
     *  Inport: '<Root>/theta'
     */
    rtDW.UnitDelay_DSTATE = rtU.theta;

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* RateTransition: '<S1>/Rate Transition2' */
    rtDW.RateTransition2 = rtDW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Outputs for Atomic SubSystem: '<S1>/currloop' */
  /* Trigonometry: '<S2>/SinCos1' incorporates:
   *  Inport: '<Root>/theta'
   */
  rtb_Add_c = cosf(rtU.theta);

  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S5>/Add'
   */
  rtb_Merge = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

  /* Gain: '<S5>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S5>/Add2'
   */
  rtb_IntegralGain = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S2>/SinCos' incorporates:
   *  Inport: '<Root>/theta'
   */
  rtb_SinCos = sinf(rtU.theta);

  /* Sum: '<S8>/Sum1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product1'
   *  Sum: '<S6>/Add'
   */
  Integrator = 0.0F - (rtb_Merge * rtb_Add_c + rtb_IntegralGain * rtb_SinCos);

  /* Sum: '<S55>/Sum' incorporates:
   *  Constant: '<S8>/Constant3'
   *  DiscreteIntegrator: '<S46>/Integrator'
   *  Product: '<S51>/PProd Out'
   */
  rtb_Sum = Integrator * 0.26F + (real32_T)rtDW.Integrator_DSTATE_p * 0.0001F;

  /* Saturate: '<S53>/Saturation' */
  if (rtb_Sum > 12.4707661F) {
    rtb_Saturation = 12.4707661F;
  } else if (rtb_Sum < -12.4707661F) {
    rtb_Saturation = -12.4707661F;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S53>/Saturation' */

  /* Sum: '<S8>/Sum7' incorporates:
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Sum: '<S6>/Add1'
   */
  rtb_IntegralGain = rtDW.RateTransition2 - (rtb_IntegralGain * rtb_Add_c -
    rtb_Merge * rtb_SinCos);

  /* Sum: '<S105>/Sum' incorporates:
   *  Constant: '<S8>/Constant1'
   *  DiscreteIntegrator: '<S96>/Integrator'
   *  Product: '<S101>/PProd Out'
   */
  rtb_Merge = rtb_IntegralGain * 0.26F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S103>/Saturation' */
  if (rtb_Merge > 12.4707661F) {
    rtb_SignPreIntegrator = 12.4707661F;
  } else if (rtb_Merge < -12.4707661F) {
    rtb_SignPreIntegrator = -12.4707661F;
  } else {
    rtb_SignPreIntegrator = rtb_Merge;
  }

  /* End of Saturate: '<S103>/Saturation' */

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
  SVPWM(rtb_Saturation * rtb_Add_c - rtb_SignPreIntegrator * rtb_SinCos,
        rtb_Saturation * rtb_SinCos + rtb_SignPreIntegrator * rtb_Add_c,
        rtU.v_bus, rtY.tABC);

  /* End of Outputs for SubSystem: '<S2>/SVPWM' */

  /* Gain: '<S87>/ZeroGain' */
  rtb_Add_c = 0.0F * rtb_Merge;

  /* DeadZone: '<S89>/DeadZone' */
  if (rtb_Merge > 12.4707661F) {
    rtb_Merge -= 12.4707661F;
  } else if (rtb_Merge >= -12.4707661F) {
    rtb_Merge = 0.0F;
  } else {
    rtb_Merge -= -12.4707661F;
  }

  /* End of DeadZone: '<S89>/DeadZone' */

  /* Product: '<S93>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  rtb_IntegralGain *= 35.0F;

  /* Gain: '<S37>/ZeroGain' */
  rtb_SinCos = 0.0F * rtb_Sum;

  /* DeadZone: '<S39>/DeadZone' */
  if (rtb_Sum > 12.4707661F) {
    rtb_Sum -= 12.4707661F;
  } else if (rtb_Sum >= -12.4707661F) {
    rtb_Sum = 0.0F;
  } else {
    rtb_Sum -= -12.4707661F;
  }

  /* End of DeadZone: '<S39>/DeadZone' */

  /* Product: '<S43>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  rtb_IProdOut_d = (int16_T)floorf(Integrator * 35.0F);

  /* Signum: '<S37>/SignPreSat' */
  if (rtb_Sum < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_Sum > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_Sum == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S37>/SignPreSat' */

  /* Signum: '<S37>/SignPreIntegrator' */
  if (rtb_IProdOut_d < 0) {
    rtb_IProdOut_f = -1;
  } else {
    rtb_IProdOut_f = (int16_T)(rtb_IProdOut_d > 0);
  }

  /* End of Signum: '<S37>/SignPreIntegrator' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant1'
   *  DataTypeConversion: '<S37>/DataTypeConv1'
   *  DataTypeConversion: '<S37>/DataTypeConv2'
   *  Logic: '<S37>/AND3'
   *  RelationalOperator: '<S37>/Equal1'
   *  RelationalOperator: '<S37>/NotEqual'
   */
  if ((rtb_SinCos != rtb_Sum) && ((int8_T)Integrator == rtb_IProdOut_f)) {
    rtb_IProdOut_d = 0;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Update for DiscreteIntegrator: '<S46>/Integrator' */
  rtDW.Integrator_DSTATE_p += rtb_IProdOut_d;

  /* Signum: '<S87>/SignPreSat' */
  if (rtb_Merge < 0.0F) {
    rtb_SinCos = -1.0F;
  } else if (rtb_Merge > 0.0F) {
    rtb_SinCos = 1.0F;
  } else if (rtb_Merge == 0.0F) {
    rtb_SinCos = 0.0F;
  } else {
    rtb_SinCos = (rtNaNF);
  }

  /* End of Signum: '<S87>/SignPreSat' */

  /* Signum: '<S87>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_IntegralGain > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_IntegralGain == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S87>/SignPreIntegrator' */

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S87>/Constant1'
   *  DataTypeConversion: '<S87>/DataTypeConv1'
   *  DataTypeConversion: '<S87>/DataTypeConv2'
   *  Logic: '<S87>/AND3'
   *  RelationalOperator: '<S87>/Equal1'
   *  RelationalOperator: '<S87>/NotEqual'
   */
  if ((rtb_Add_c != rtb_Merge) && ((int8_T)rtb_SinCos == (int8_T)Integrator)) {
    rtb_IntegralGain = 0.0F;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Update for DiscreteIntegrator: '<S96>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IntegralGain;

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
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Enable for Atomic SubSystem: '<Root>/FOC_Model' */
  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/speedloop'
   */
  rtDW.speedloop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S150>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
  /* End of Enable for SubSystem: '<Root>/FOC_Model' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
