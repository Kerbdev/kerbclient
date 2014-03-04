################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usefull_func/usefull.c 

OBJS += \
./usefull_func/usefull.o 

C_DEPS += \
./usefull_func/usefull.d 


# Each subdirectory must supply rules for building sources it contributes
usefull_func/%.o: ../usefull_func/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


