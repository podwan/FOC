################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ctrl/Utils/foc_utils.cpp \
../Ctrl/Utils/lowpass_filter.cpp \
../Ctrl/Utils/pid.cpp 

OBJS += \
./Ctrl/Utils/foc_utils.o \
./Ctrl/Utils/lowpass_filter.o \
./Ctrl/Utils/pid.o 

CPP_DEPS += \
./Ctrl/Utils/foc_utils.d \
./Ctrl/Utils/lowpass_filter.d \
./Ctrl/Utils/pid.d 


# Each subdirectory must supply rules for building sources it contributes
Ctrl/Utils/%.o Ctrl/Utils/%.su Ctrl/Utils/%.cyclo: ../Ctrl/Utils/%.cpp Ctrl/Utils/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Ctrl-2f-Utils

clean-Ctrl-2f-Utils:
	-$(RM) ./Ctrl/Utils/foc_utils.cyclo ./Ctrl/Utils/foc_utils.d ./Ctrl/Utils/foc_utils.o ./Ctrl/Utils/foc_utils.su ./Ctrl/Utils/lowpass_filter.cyclo ./Ctrl/Utils/lowpass_filter.d ./Ctrl/Utils/lowpass_filter.o ./Ctrl/Utils/lowpass_filter.su ./Ctrl/Utils/pid.cyclo ./Ctrl/Utils/pid.d ./Ctrl/Utils/pid.o ./Ctrl/Utils/pid.su

.PHONY: clean-Ctrl-2f-Utils

