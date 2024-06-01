################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/MPU6050.c \
../User/app.c \
../User/comm.c \
../User/key.c \
../User/knob.c \
../User/led.c \
../User/mt6701.c \
../User/myI2C.c \
../User/time_utils.c \
../User/userMain.c \
../User/userTimer.c 

OBJS += \
./User/MPU6050.o \
./User/app.o \
./User/comm.o \
./User/key.o \
./User/knob.o \
./User/led.o \
./User/mt6701.o \
./User/myI2C.o \
./User/time_utils.o \
./User/userMain.o \
./User/userTimer.o 

C_DEPS += \
./User/MPU6050.d \
./User/app.d \
./User/comm.d \
./User/key.d \
./User/knob.d \
./User/led.d \
./User/mt6701.d \
./User/myI2C.d \
./User/time_utils.d \
./User/userMain.d \
./User/userTimer.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I"C:/Users/18575/Desktop/FOC/firmwareBak/User" -I"C:/Users/18575/Desktop/FOC/firmwareBak/FocLib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/MPU6050.cyclo ./User/MPU6050.d ./User/MPU6050.o ./User/MPU6050.su ./User/app.cyclo ./User/app.d ./User/app.o ./User/app.su ./User/comm.cyclo ./User/comm.d ./User/comm.o ./User/comm.su ./User/key.cyclo ./User/key.d ./User/key.o ./User/key.su ./User/knob.cyclo ./User/knob.d ./User/knob.o ./User/knob.su ./User/led.cyclo ./User/led.d ./User/led.o ./User/led.su ./User/mt6701.cyclo ./User/mt6701.d ./User/mt6701.o ./User/mt6701.su ./User/myI2C.cyclo ./User/myI2C.d ./User/myI2C.o ./User/myI2C.su ./User/time_utils.cyclo ./User/time_utils.d ./User/time_utils.o ./User/time_utils.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su ./User/userTimer.cyclo ./User/userTimer.d ./User/userTimer.o ./User/userTimer.su

.PHONY: clean-User

