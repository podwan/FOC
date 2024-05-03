#ifndef __MOTOR_H
#define __MOTOR_H

// 函数声明
void OpenVelocity1(float target); // 开环运行测试，模拟电角度
void OpenVelocity2(float Uq);     // 开环转速测试，编码器反馈电角度，无转速控制

void velocity_PID_Config(void);    // 闭环速度PID控制,参数设置
void close_Velocity_Control(void); // 速度环PID控制
void close_Velocity_LOG(void);     // 串口输出目标转速，实际转速

#endif
