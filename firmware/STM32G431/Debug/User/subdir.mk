################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../User/app.cpp \
../User/comm.cpp \
../User/driver.cpp \
../User/encoder.cpp \
../User/foc.cpp \
../User/key.cpp \
../User/led.cpp \
../User/lowpass_filter.cpp \
../User/math_utils.cpp \
../User/motor.cpp \
../User/pid.cpp \
../User/time_utils.cpp \
../User/userMain.cpp \
../User/userTimer.cpp 

C_SRCS += \
../User/tle5012b.c 

C_DEPS += \
./User/tle5012b.d 

OBJS += \
./User/app.o \
./User/comm.o \
./User/driver.o \
./User/encoder.o \
./User/foc.o \
./User/key.o \
./User/led.o \
./User/lowpass_filter.o \
./User/math_utils.o \
./User/motor.o \
./User/pid.o \
./User/time_utils.o \
./User/tle5012b.o \
./User/userMain.o \
./User/userTimer.o 

CPP_DEPS += \
./User/app.d \
./User/comm.d \
./User/driver.d \
./User/encoder.d \
./User/foc.d \
./User/key.d \
./User/led.d \
./User/lowpass_filter.d \
./User/math_utils.d \
./User/motor.d \
./User/pid.d \
./User/time_utils.d \
./User/userMain.d \
./User/userTimer.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.cpp User/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/app.cyclo ./User/app.d ./User/app.o ./User/app.su ./User/comm.cyclo ./User/comm.d ./User/comm.o ./User/comm.su ./User/driver.cyclo ./User/driver.d ./User/driver.o ./User/driver.su ./User/encoder.cyclo ./User/encoder.d ./User/encoder.o ./User/encoder.su ./User/foc.cyclo ./User/foc.d ./User/foc.o ./User/foc.su ./User/key.cyclo ./User/key.d ./User/key.o ./User/key.su ./User/led.cyclo ./User/led.d ./User/led.o ./User/led.su ./User/lowpass_filter.cyclo ./User/lowpass_filter.d ./User/lowpass_filter.o ./User/lowpass_filter.su ./User/math_utils.cyclo ./User/math_utils.d ./User/math_utils.o ./User/math_utils.su ./User/motor.cyclo ./User/motor.d ./User/motor.o ./User/motor.su ./User/pid.cyclo ./User/pid.d ./User/pid.o ./User/pid.su ./User/time_utils.cyclo ./User/time_utils.d ./User/time_utils.o ./User/time_utils.su ./User/tle5012b.cyclo ./User/tle5012b.d ./User/tle5012b.o ./User/tle5012b.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su ./User/userTimer.cyclo ./User/userTimer.d ./User/userTimer.o ./User/userTimer.su

.PHONY: clean-User

