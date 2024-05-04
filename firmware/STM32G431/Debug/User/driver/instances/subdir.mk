################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../User/driver/instances/driver_fd6288q.cpp 

OBJS += \
./User/driver/instances/driver_fd6288q.o 

CPP_DEPS += \
./User/driver/instances/driver_fd6288q.d 


# Each subdirectory must supply rules for building sources it contributes
User/driver/instances/%.o User/driver/instances/%.su User/driver/instances/%.cyclo: ../User/driver/instances/%.cpp User/driver/instances/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-driver-2f-instances

clean-User-2f-driver-2f-instances:
	-$(RM) ./User/driver/instances/driver_fd6288q.cyclo ./User/driver/instances/driver_fd6288q.d ./User/driver/instances/driver_fd6288q.o ./User/driver/instances/driver_fd6288q.su

.PHONY: clean-User-2f-driver-2f-instances

