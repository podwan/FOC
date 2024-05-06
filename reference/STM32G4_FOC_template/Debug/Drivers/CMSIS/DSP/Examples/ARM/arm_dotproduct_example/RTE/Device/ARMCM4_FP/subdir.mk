################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/startup_ARMCM4.s 

C_SRCS += \
../Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.c 

OBJS += \
./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/startup_ARMCM4.o \
./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.o 

S_DEPS += \
./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/startup_ARMCM4.d 

C_DEPS += \
./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.o: ../Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.s Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.o Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.su Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.cyclo: ../Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/%.c Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_dotproduct_example-2f-RTE-2f-Device-2f-ARMCM4_FP

clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_dotproduct_example-2f-RTE-2f-Device-2f-ARMCM4_FP:
	-$(RM) ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/startup_ARMCM4.d ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/startup_ARMCM4.o ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.cyclo ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.d ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.o ./Drivers/CMSIS/DSP/Examples/ARM/arm_dotproduct_example/RTE/Device/ARMCM4_FP/system_ARMCM4.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_dotproduct_example-2f-RTE-2f-Device-2f-ARMCM4_FP

