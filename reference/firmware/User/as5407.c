#include "as5407.h"
#include "math_utils.h"
static unsigned int rotationCount, rotationCount_Last;

// https://blog.csdn.net/weixin_42416680/article/details/132197502
//  计算奇偶函数
uint16_t Parity_bit_Calculate(uint16_t data_2_cal)
{
    uint16_t parity_bit_value = 0;
    while (data_2_cal != 0)
    {
        parity_bit_value ^= data_2_cal;
        data_2_cal >>= 1;
    }
    return (parity_bit_value & 0x1);
}
// SPI发送读取函数
uint16_t SPI_ReadWrite_OneByte(uint16_t _txdata)
{
    CS_GPIO_Port->BSRR = (uint32_t)CS_Pin << 16U; // Chip select
                                                  // AS5407P_CS_L // cs拉低
    uint16_t rxdata;

    if (HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)&_txdata, (uint8_t *)&rxdata, 1, 1000) != HAL_OK)
        rxdata = 0;
    //   AS5407P_CS_H // cs拉高 return rxdata;

    CS_GPIO_Port->BSRR = CS_Pin;
    return rxdata;
}

uint16_t as5047readRawData(uint16_t add)
{
    uint16_t data;
    add |= 0x4000;
    // 读指令 bit14 置1
    if (Parity_bit_Calculate(add) == 1)
        add = add | 0x8000;
    // 如果前15位 1的个数位偶数，则Bit15 置1
    SPI_ReadWrite_OneByte(add);
    // 发送一条指令，不管读回的数据
    data = SPI_ReadWrite_OneByte(NOP | 0x4000);
    // 发送一条空指令，读取上一次指令返回的数据。
    data &= 0x3fff;
    return data;
}

// 将传感器原始数据转化为弧度
float as5047GetRawAngle(void)
{
    uint16_t rawData = as5047readRawData(ANGLECOM);
    return (float)rawData / 16384.0f * _2PI;
}

// 获得转过的总角度，有圈数累加
float as5047GetFullAngle(void)
{
    static float angle_Last = 0.0f;    // 上次的轴角度，范围0~6.28
    float angle = as5047GetRawAngle(); // 当前角度，范围0~6.28
    float deltaAngle = angle - angle_Last;

    // 计算旋转的总圈数
    // 通过判断角度变化是否大于80%的一圈(0.8f*6.28318530718f)来判断是否发生了溢出，如果发生了，则将full_rotations增加1（如果d_angle小于0）或减少1（如果d_angle大于0）。

    if (fabsf(deltaAngle) > (0.8f * 6.28318530718f))
    {
        rotationCount += (deltaAngle > 0) ? -1 : 1; // 圈数计算
        rotationCount_Last = rotationCount;
    }

    angle_Last = angle;
    return rotationCount * 6.28318530718f + angle_Last; // 转过的圈数 * 2pi + 未转满一圈的角度值
}

// 计算转速  Ts is call period in microsecond
float as5047GetVelocity(float Ts)
{
    static float full_Angle_Last = 0.0f; // 记录上次转过的总角度
    float full_Angle = as5047GetFullAngle();
    float delta_Angle = (rotationCount - rotationCount_Last) * _2PI + (full_Angle - full_Angle_Last);
    float vel = delta_Angle * Ts; // Ts = 1ms

    // 更新变量值
    full_Angle_Last = full_Angle;
    return vel;
}