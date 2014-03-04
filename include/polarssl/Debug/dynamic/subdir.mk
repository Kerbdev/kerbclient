################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dynamic/create.c \
../dynamic/free.c 

OBJS += \
./dynamic/create.o \
./dynamic/free.o 

C_DEPS += \
./dynamic/create.d \
./dynamic/free.d 


# Each subdirectory must supply rules for building sources it contributes
dynamic/%.o: ../dynamic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


