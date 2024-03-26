################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../User/driver.cpp \
../User/encoder_base.cpp \
../User/lowpass_filter.cpp \
../User/math_utils.cpp \
../User/pid.cpp 

C_SRCS += \
../User/userMain.c 

C_DEPS += \
./User/userMain.d 

OBJS += \
./User/driver.o \
./User/encoder_base.o \
./User/lowpass_filter.o \
./User/math_utils.o \
./User/pid.o \
./User/userMain.o 

CPP_DEPS += \
./User/driver.d \
./User/encoder_base.d \
./User/lowpass_filter.d \
./User/math_utils.d \
./User/pid.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.cpp User/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/18575/Desktop/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6" -I"G:/workSpace/BLDCfirmware/g431cbu6/UserApp" -I"G:/workSpace/BLDCfirmware/g431cbu6/Platform/Utils" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/driver.cyclo ./User/driver.d ./User/driver.o ./User/driver.su ./User/encoder_base.cyclo ./User/encoder_base.d ./User/encoder_base.o ./User/encoder_base.su ./User/lowpass_filter.cyclo ./User/lowpass_filter.d ./User/lowpass_filter.o ./User/lowpass_filter.su ./User/math_utils.cyclo ./User/math_utils.d ./User/math_utils.o ./User/math_utils.su ./User/pid.cyclo ./User/pid.d ./User/pid.o ./User/pid.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su

.PHONY: clean-User

