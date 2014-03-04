################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../query/recvKRBERROR.c \
../query/recv_krb5_ap_rep.c \
../query/recv_krb5_kdc_rep.c \
../query/recv_krb5_safe.c \
../query/send_krb5_ap_req.c \
../query/send_krb5_authenticator.c \
../query/send_krb5_kdc_req.c \
../query/send_krb5_safe.c \
../query/send_recv_krb5_cred.c \
../query/send_recv_krb5_priv.c 

OBJS += \
./query/recvKRBERROR.o \
./query/recv_krb5_ap_rep.o \
./query/recv_krb5_kdc_rep.o \
./query/recv_krb5_safe.o \
./query/send_krb5_ap_req.o \
./query/send_krb5_authenticator.o \
./query/send_krb5_kdc_req.o \
./query/send_krb5_safe.o \
./query/send_recv_krb5_cred.o \
./query/send_recv_krb5_priv.o 

C_DEPS += \
./query/recvKRBERROR.d \
./query/recv_krb5_ap_rep.d \
./query/recv_krb5_kdc_rep.d \
./query/recv_krb5_safe.d \
./query/send_krb5_ap_req.d \
./query/send_krb5_authenticator.d \
./query/send_krb5_kdc_req.d \
./query/send_krb5_safe.d \
./query/send_recv_krb5_cred.d \
./query/send_recv_krb5_priv.d 


# Each subdirectory must supply rules for building sources it contributes
query/%.o: ../query/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


