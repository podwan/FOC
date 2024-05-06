################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app.c \
../User/as5407.c \
../User/comm.c \
../User/current.c \
../User/focMotor.c \
../User/key.c \
../User/led.c \
../User/lowpass_filter.c \
../User/math_utils.c \
../User/mt6701.c \
../User/pid.c \
../User/time_utils.c \
../User/userMain.c \
../User/userTimer.c \
../User/voltage.c 

OBJS += \
./User/app.o \
./User/as5407.o \
./User/comm.o \
./User/current.o \
./User/focMotor.o \
./User/key.o \
./User/led.o \
./User/lowpass_filter.o \
./User/math_utils.o \
./User/mt6701.o \
./User/pid.o \
./User/time_utils.o \
./User/userMain.o \
./User/userTimer.o \
./User/voltage.o 

C_DEPS += \
./User/app.d \
./User/as5407.d \
./User/comm.d \
./User/current.d \
./User/focMotor.d \
./User/key.d \
./User/led.d \
./User/lowpass_filter.d \
./User/math_utils.d \
./User/mt6701.d \
./User/pid.d \
./User/time_utils.d \
./User/userMain.d \
./User/userTimer.d \
./User/voltage.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/app.cyclo ./User/app.d ./User/app.o ./User/app.su ./User/as5407.cyclo ./User/as5407.d ./User/as5407.o ./User/as5407.su ./User/comm.cyclo ./User/comm.d ./User/comm.o ./User/comm.su ./User/current.cyclo ./User/current.d ./User/current.o ./User/current.su ./User/focMotor.cyclo ./User/focMotor.d ./User/focMotor.o ./User/focMotor.su ./User/key.cyclo ./User/key.d ./User/key.o ./User/key.su ./User/led.cyclo ./User/led.d ./User/led.o ./User/led.su ./User/lowpass_filter.cyclo ./User/lowpass_filter.d ./User/lowpass_filter.o ./User/lowpass_filter.su ./User/math_utils.cyclo ./User/math_utils.d ./User/math_utils.o ./User/math_utils.su ./User/mt6701.cyclo ./User/mt6701.d ./User/mt6701.o ./User/mt6701.su ./User/pid.cyclo ./User/pid.d ./User/pid.o ./User/pid.su ./User/time_utils.cyclo ./User/time_utils.d ./User/time_utils.o ./User/time_utils.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su ./User/userTimer.cyclo ./User/userTimer.d ./User/userTimer.o ./User/userTimer.su ./User/voltage.cyclo ./User/voltage.d ./User/voltage.o ./User/voltage.su

.PHONY: clean-User

