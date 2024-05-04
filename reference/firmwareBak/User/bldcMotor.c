#include "bldcMotor.h"
#include "foc_utils.h"
#include "mt6701.h"
#include "voltage.h"
// FocParameters fp1;

// static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c);
// static float getElecAngle1(FocParameters *fp);

// void motorInit()
// {
//     fp1.pole_pairs = 7;
//     fp1.setPwm = setPwm1;
//     fp1.getElecAngle = getElecAngle1;
//     fp1.zeroElectricAngleOffSet = 0;
// }

// static void setPwm1(unsigned short int a, unsigned short int b, unsigned short int c)
// {
//     TIM1->CCR1 = a;
//     TIM1->CCR2 = b;
//     TIM1->CCR3 = c;
// }

// static float getElecAngle1(FocParameters *fp)
// {
//     fp->angle_el = _normalizeAngle(fp->pole_pairs * MT6701_GetRawAngle() - fp->zeroElectricAngleOffSet);
// }

// void getZeroElecAngle(FocParameters *fp)
// {
//     setPhaseVoltage(fp, 0.0f, 1.0f, 0.0f);
//     HAL_Delay(100);
//     fp->zeroElectricAngleOffSet = fp->getElecAngle(fp); // 测量电角度零位偏差
// }

// void foc(FocParameters *fp, uint32_t adc_a, uint32_t adc_b)
// {

//     static bool calibrateOffset;

//     if (calibrateOffset == 0)
//     {
//         getCurrentOffsets(fp, adc_a, adc_b);
//         getZeroElecAngle(fp);
//         calibrateOffset = 1;

//         float zero_elAngle = MT6701_GetElectricalAngle(); // 观察电角度是否为0

//         FOC_log("[zeroAngleOffset,zeroAngle]:%f,%f\r\n", fp->zeroElectricAngleOffSet, zero_elAngle);
//     }
//     else
//     {
//         switch (fp->controlType)
//         {
//         case ANGLE_OPEN_LOOP:

//             break;

//         case VELOCITY_OPEN_LOOP:

//             break;

//         case ANGLE:
//             break;

//         case VELOCITY:
//             break;

//         case TORQUE:

//             break;
//         }
//     }
// }
