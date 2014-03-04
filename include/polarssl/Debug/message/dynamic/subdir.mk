################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../message/dynamic/create.c \
../message/dynamic/free.c 

OBJS += \
./message/dynamic/create.o \
./message/dynamic/free.o 

C_DEPS += \
./message/dynamic/create.d \
./message/dynamic/free.d 


# Each subdirectory must supply rules for building sources it contributes
message/dynamic/%.o: ../message/dynamic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


