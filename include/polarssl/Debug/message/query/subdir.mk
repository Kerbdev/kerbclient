################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../message/query/recvKRBERROR.c \
../message/query/recv_krb5_ap_rep.c \
../message/query/recv_krb5_kdc_rep.c \
../message/query/recv_krb5_safe.c \
../message/query/send_krb5_ap_req.c \
../message/query/send_krb5_authenticator.c \
../message/query/send_krb5_kdc_req.c \
../message/query/send_krb5_safe.c \
../message/query/send_recv_krb5_cred.c \
../message/query/send_recv_krb5_priv.c 

OBJS += \
./message/query/recvKRBERROR.o \
./message/query/recv_krb5_ap_rep.o \
./message/query/recv_krb5_kdc_rep.o \
./message/query/recv_krb5_safe.o \
./message/query/send_krb5_ap_req.o \
./message/query/send_krb5_authenticator.o \
./message/query/send_krb5_kdc_req.o \
./message/query/send_krb5_safe.o \
./message/query/send_recv_krb5_cred.o \
./message/query/send_recv_krb5_priv.o 

C_DEPS += \
./message/query/recvKRBERROR.d \
./message/query/recv_krb5_ap_rep.d \
./message/query/recv_krb5_kdc_rep.d \
./message/query/recv_krb5_safe.d \
./message/query/send_krb5_ap_req.d \
./message/query/send_krb5_authenticator.d \
./message/query/send_krb5_kdc_req.d \
./message/query/send_krb5_safe.d \
./message/query/send_recv_krb5_cred.d \
./message/query/send_recv_krb5_priv.d 


# Each subdirectory must supply rules for building sources it contributes
message/query/%.o: ../message/query/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


