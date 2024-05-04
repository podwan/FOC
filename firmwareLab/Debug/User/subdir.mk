################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/comm.c \
../User/foc_utils.c \
../User/userMain.c \
../User/voltage.c 

OBJS += \
./User/comm.o \
./User/foc_utils.o \
./User/userMain.o \
./User/voltage.o 

C_DEPS += \
./User/comm.d \
./User/foc_utils.d \
./User/userMain.d \
./User/voltage.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/comm.cyclo ./User/comm.d ./User/comm.o ./User/comm.su ./User/foc_utils.cyclo ./User/foc_utils.d ./User/foc_utils.o ./User/foc_utils.su ./User/userMain.cyclo ./User/userMain.d ./User/userMain.o ./User/userMain.su ./User/voltage.cyclo ./User/voltage.d ./User/voltage.o ./User/voltage.su

.PHONY: clean-User

