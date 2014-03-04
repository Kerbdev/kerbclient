################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../parser/get_config_param.c \
../parser/ini.c 

OBJS += \
./parser/get_config_param.o \
./parser/ini.o 

C_DEPS += \
./parser/get_config_param.d \
./parser/ini.d 


# Each subdirectory must supply rules for building sources it contributes
parser/%.o: ../parser/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


