################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UserApp/protocols/ascii_protocol.cpp 

OBJS += \
./UserApp/protocols/ascii_protocol.o 

CPP_DEPS += \
./UserApp/protocols/ascii_protocol.d 


# Each subdirectory must supply rules for building sources it contributes
UserApp/protocols/%.o UserApp/protocols/%.su UserApp/protocols/%.cyclo: ../UserApp/protocols/%.cpp UserApp/protocols/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-UserApp-2f-protocols

clean-UserApp-2f-protocols:
	-$(RM) ./UserApp/protocols/ascii_protocol.cyclo ./UserApp/protocols/ascii_protocol.d ./UserApp/protocols/ascii_protocol.o ./UserApp/protocols/ascii_protocol.su

.PHONY: clean-UserApp-2f-protocols

