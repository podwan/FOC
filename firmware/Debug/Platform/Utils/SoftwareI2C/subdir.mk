################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform/Utils/SoftwareI2C/soft_i2c.c 

C_DEPS += \
./Platform/Utils/SoftwareI2C/soft_i2c.d 

OBJS += \
./Platform/Utils/SoftwareI2C/soft_i2c.o 


# Each subdirectory must supply rules for building sources it contributes
Platform/Utils/SoftwareI2C/%.o Platform/Utils/SoftwareI2C/%.su Platform/Utils/SoftwareI2C/%.cyclo: ../Platform/Utils/SoftwareI2C/%.c Platform/Utils/SoftwareI2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Platform-2f-Utils-2f-SoftwareI2C

clean-Platform-2f-Utils-2f-SoftwareI2C:
	-$(RM) ./Platform/Utils/SoftwareI2C/soft_i2c.cyclo ./Platform/Utils/SoftwareI2C/soft_i2c.d ./Platform/Utils/SoftwareI2C/soft_i2c.o ./Platform/Utils/SoftwareI2C/soft_i2c.su

.PHONY: clean-Platform-2f-Utils-2f-SoftwareI2C

