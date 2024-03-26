################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Platform/Utils/time_utils.cpp \
../Platform/Utils/timer.cpp 

C_SRCS += \
../Platform/Utils/st_hardware.c 

C_DEPS += \
./Platform/Utils/st_hardware.d 

OBJS += \
./Platform/Utils/st_hardware.o \
./Platform/Utils/time_utils.o \
./Platform/Utils/timer.o 

CPP_DEPS += \
./Platform/Utils/time_utils.d \
./Platform/Utils/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Platform/Utils/%.o Platform/Utils/%.su Platform/Utils/%.cyclo: ../Platform/Utils/%.c Platform/Utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Platform/Utils/%.o Platform/Utils/%.su Platform/Utils/%.cyclo: ../Platform/Utils/%.cpp Platform/Utils/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Platform-2f-Utils

clean-Platform-2f-Utils:
	-$(RM) ./Platform/Utils/st_hardware.cyclo ./Platform/Utils/st_hardware.d ./Platform/Utils/st_hardware.o ./Platform/Utils/st_hardware.su ./Platform/Utils/time_utils.cyclo ./Platform/Utils/time_utils.d ./Platform/Utils/time_utils.o ./Platform/Utils/time_utils.su ./Platform/Utils/timer.cyclo ./Platform/Utils/timer.d ./Platform/Utils/timer.o ./Platform/Utils/timer.su

.PHONY: clean-Platform-2f-Utils

