################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-Intrinsics

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-Intrinsics:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/Intrinsics_.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/Intrinsics/intrinsics.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-Intrinsics

