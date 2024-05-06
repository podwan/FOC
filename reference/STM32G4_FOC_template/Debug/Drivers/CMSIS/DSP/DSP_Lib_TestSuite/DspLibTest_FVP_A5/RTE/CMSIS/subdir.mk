################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-DspLibTest_FVP_A5-2f-RTE-2f-CMSIS

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-DspLibTest_FVP_A5-2f-RTE-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/RTX_Config.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/DspLibTest_FVP_A5/RTE/CMSIS/handlers.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-DspLibTest_FVP_A5-2f-RTE-2f-CMSIS

