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
