################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ctrl/Motor/knob.cpp \
../Ctrl/Motor/lowpass_filter.cpp \
../Ctrl/Motor/math_utils.cpp \
../Ctrl/Motor/motor.cpp \
../Ctrl/Motor/pid.cpp 

OBJS += \
./Ctrl/Motor/knob.o \
./Ctrl/Motor/lowpass_filter.o \
./Ctrl/Motor/math_utils.o \
./Ctrl/Motor/motor.o \
./Ctrl/Motor/pid.o 

CPP_DEPS += \
./Ctrl/Motor/knob.d \
./Ctrl/Motor/lowpass_filter.d \
./Ctrl/Motor/math_utils.d \
./Ctrl/Motor/motor.d \
./Ctrl/Motor/pid.d 


# Each subdirectory must supply rules for building sources it contributes
Ctrl/Motor/%.o Ctrl/Motor/%.su Ctrl/Motor/%.cyclo: ../Ctrl/Motor/%.cpp Ctrl/Motor/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Ctrl-2f-Motor

clean-Ctrl-2f-Motor:
	-$(RM) ./Ctrl/Motor/knob.cyclo ./Ctrl/Motor/knob.d ./Ctrl/Motor/knob.o ./Ctrl/Motor/knob.su ./Ctrl/Motor/lowpass_filter.cyclo ./Ctrl/Motor/lowpass_filter.d ./Ctrl/Motor/lowpass_filter.o ./Ctrl/Motor/lowpass_filter.su ./Ctrl/Motor/math_utils.cyclo ./Ctrl/Motor/math_utils.d ./Ctrl/Motor/math_utils.o ./Ctrl/Motor/math_utils.su ./Ctrl/Motor/motor.cyclo ./Ctrl/Motor/motor.d ./Ctrl/Motor/motor.o ./Ctrl/Motor/motor.su ./Ctrl/Motor/pid.cyclo ./Ctrl/Motor/pid.d ./Ctrl/Motor/pid.o ./Ctrl/Motor/pid.su

.PHONY: clean-Ctrl-2f-Motor

