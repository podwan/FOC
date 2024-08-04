goal:库与应用进行解耦，面向对象让不同的电机进行解耦
    使用时只需添加focLib.h
    移植只需修改focLib.h

其中：
    voltage模块
    是用于电压矢量输出,即根据PID输出的Uq,Ud及电角度生成SVPWM

    current模块
    用于三相电流输入，通过电角度和坐标转换后得到输入PID的Id,Iq

    bldcMotor模块
    1：用于给用户提供电机类型，用户可以根据该类型定义电机的对象，并进行初始化
    2：调用foc函数进行电机的控制

    math_utiles模块是FOC用到的数学运算方法

    其余的pid、lowPass_filter、encoder模块使用时需要进行初始化



需要用户实现的接口有:
1. void FOC_log(const char *format, ...):用于串口打印状态参数等信息
2. uint16_t、int32_t等类型的定义
3. void delay(uint32_t ms);毫秒延时



调试方法：
1. 首先使用controlType = VELOCITY_OEPN_LOOP  用于验证setTorque（SVPWM马鞍波)函数、编码器测 速（方向）及相电流采样（正弦波）的验证， 避免长时间运行（发热）
2. 使 torqueType = VOLTAGE; controlType = TORQUE; Uq = UqMax让电机最大转速运行（正反转），观察电流波形是否正确(Id基本保持不变，Iq符号在换向后发生翻转)
3. 使 torqueType = CURRENT; controlType = TORQUE;
a. 先单独调静态参数Id的PID，PID先设定P值，后加入I值消除稳态误差，确保Id是否能够根据设定的值进行响应后将目标值设为0
b. 加入Iq控制闭环，PID参数可以和Id一致
