################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Platform/Communication/ascii_processor.cpp \
../Platform/Communication/communication.cpp \
../Platform/Communication/interface_uart.cpp 

OBJS += \
./Platform/Communication/ascii_processor.o \
./Platform/Communication/communication.o \
./Platform/Communication/interface_uart.o 

CPP_DEPS += \
./Platform/Communication/ascii_processor.d \
./Platform/Communication/communication.d \
./Platform/Communication/interface_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Platform/Communication/%.o Platform/Communication/%.su Platform/Communication/%.cyclo: ../Platform/Communication/%.cpp Platform/Communication/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Platform-2f-Communication

clean-Platform-2f-Communication:
	-$(RM) ./Platform/Communication/ascii_processor.cyclo ./Platform/Communication/ascii_processor.d ./Platform/Communication/ascii_processor.o ./Platform/Communication/ascii_processor.su ./Platform/Communication/communication.cyclo ./Platform/Communication/communication.d ./Platform/Communication/communication.o ./Platform/Communication/communication.su ./Platform/Communication/interface_uart.cyclo ./Platform/Communication/interface_uart.d ./Platform/Communication/interface_uart.o ./Platform/Communication/interface_uart.su

.PHONY: clean-Platform-2f-Communication

