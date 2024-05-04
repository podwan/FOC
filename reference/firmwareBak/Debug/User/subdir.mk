################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app.c \
../User/bldcMotor.c \
../User/comm.c \
../User/current.c \
../User/foc_utils.c \
../User/lowpass_filter.c \
../User/motor.c \
../User/mt6701.c \
../User/pid.c \
../User/userMain.c \
../User/userTimer.c \
../User/voltage.c 

OBJS += \
./User/app.o \
./User/bldcMotor.o \
./User/comm.o \
./User/current.o \
./User/foc_utils.o \
./User/lowpass_filter.o \
./User/motor.o \
./User/mt6701.o \
./User/pid.o \
./User/userMain.o \
./User/userTimer.o \
./User/voltage.o 

C_DEPS += \
./User/app.d \
./User/bldcMotor.d \
./User/comm.d \
./User/current.d \
./User/foc_utils.d \
./User/lowpass_filter.d \
./User/motor.d \
./User/mt6701.d \
./User/pid.d \
./User/userMain.d \
./User/userTimer.d \
./User/voltage.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/app.cyclo ./User/app.d ./User/app.o ./User/app.su ./User/bldcMotor.cyclo ./User/bldcMotor.d ./User/bldcMotor.o ./User/bldcMotor.su ./User/comm.cyclo ./User/comm.d ./User/comm.o ./User/comm.su ./User/current.cyclo ./User/current.d ./User/current.o ./User/current.su ./User/foc_utils.cyclo ./User/foc_utils.d ./User/foc_utils.o ./User/foc_utils.su ./User/lowpass_filter.cyclo ./User/lowpass_filter.d ./User/lowpass_filter.o ./User/lowpass_filter.su ./User/motor.cyclo ./User/motor.d ./User/motor.o ./User/motor.su ./User/mt6701.cyclo ./User/mt6701.d ./User/mt6701.o ./User/mt6701.su ./User/pid.cyclo ./User/pid.d ./User/pid.o ./User/pid.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su ./User/userTimer.cyclo ./User/userTimer.d ./User/userTimer.o ./User/userTimer.su ./User/voltage.cyclo ./User/voltage.d ./User/voltage.o ./User/voltage.su

.PHONY: clean-User

