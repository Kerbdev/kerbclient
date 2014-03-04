################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../library/aes.c \
../library/aesni.c \
../library/arc4.c \
../library/asn1parse.c \
../library/asn1write.c \
../library/base64.c \
../library/bignum.c \
../library/blowfish.c \
../library/camellia.c \
../library/certs.c \
../library/cipher.c \
../library/cipher_wrap.c \
../library/ctr_drbg.c \
../library/debug.c \
../library/des.c \
../library/dhm.c \
../library/ecdh.c \
../library/ecdsa.c \
../library/ecp.c \
../library/ecp_curves.c \
../library/entropy.c \
../library/entropy_poll.c \
../library/error.c \
../library/gcm.c \
../library/havege.c \
../library/md.c \
../library/md2.c \
../library/md4.c \
../library/md5.c \
../library/md_wrap.c \
../library/memory.c \
../library/memory_buffer_alloc.c \
../library/net.c \
../library/oid.c \
../library/padlock.c \
../library/pbkdf2.c \
../library/pem.c \
../library/pk.c \
../library/pk_wrap.c \
../library/pkcs11.c \
../library/pkcs12.c \
../library/pkcs5.c \
../library/pkparse.c \
../library/pkwrite.c \
../library/ripemd160.c \
../library/rsa.c \
../library/sha1.c \
../library/sha256.c \
../library/sha512.c \
../library/ssl_cache.c \
../library/ssl_ciphersuites.c \
../library/ssl_cli.c \
../library/ssl_srv.c \
../library/ssl_tls.c \
../library/threading.c \
../library/timing.c \
../library/version.c \
../library/x509.c \
../library/x509_create.c \
../library/x509_crl.c \
../library/x509_crt.c \
../library/x509_csr.c \
../library/x509write_crt.c \
../library/x509write_csr.c \
../library/xtea.c 

OBJS += \
./library/aes.o \
./library/aesni.o \
./library/arc4.o \
./library/asn1parse.o \
./library/asn1write.o \
./library/base64.o \
./library/bignum.o \
./library/blowfish.o \
./library/camellia.o \
./library/certs.o \
./library/cipher.o \
./library/cipher_wrap.o \
./library/ctr_drbg.o \
./library/debug.o \
./library/des.o \
./library/dhm.o \
./library/ecdh.o \
./library/ecdsa.o \
./library/ecp.o \
./library/ecp_curves.o \
./library/entropy.o \
./library/entropy_poll.o \
./library/error.o \
./library/gcm.o \
./library/havege.o \
./library/md.o \
./library/md2.o \
./library/md4.o \
./library/md5.o \
./library/md_wrap.o \
./library/memory.o \
./library/memory_buffer_alloc.o \
./library/net.o \
./library/oid.o \
./library/padlock.o \
./library/pbkdf2.o \
./library/pem.o \
./library/pk.o \
./library/pk_wrap.o \
./library/pkcs11.o \
./library/pkcs12.o \
./library/pkcs5.o \
./library/pkparse.o \
./library/pkwrite.o \
./library/ripemd160.o \
./library/rsa.o \
./library/sha1.o \
./library/sha256.o \
./library/sha512.o \
./library/ssl_cache.o \
./library/ssl_ciphersuites.o \
./library/ssl_cli.o \
./library/ssl_srv.o \
./library/ssl_tls.o \
./library/threading.o \
./library/timing.o \
./library/version.o \
./library/x509.o \
./library/x509_create.o \
./library/x509_crl.o \
./library/x509_crt.o \
./library/x509_csr.o \
./library/x509write_crt.o \
./library/x509write_csr.o \
./library/xtea.o 

C_DEPS += \
./library/aes.d \
./library/aesni.d \
./library/arc4.d \
./library/asn1parse.d \
./library/asn1write.d \
./library/base64.d \
./library/bignum.d \
./library/blowfish.d \
./library/camellia.d \
./library/certs.d \
./library/cipher.d \
./library/cipher_wrap.d \
./library/ctr_drbg.d \
./library/debug.d \
./library/des.d \
./library/dhm.d \
./library/ecdh.d \
./library/ecdsa.d \
./library/ecp.d \
./library/ecp_curves.d \
./library/entropy.d \
./library/entropy_poll.d \
./library/error.d \
./library/gcm.d \
./library/havege.d \
./library/md.d \
./library/md2.d \
./library/md4.d \
./library/md5.d \
./library/md_wrap.d \
./library/memory.d \
./library/memory_buffer_alloc.d \
./library/net.d \
./library/oid.d \
./library/padlock.d \
./library/pbkdf2.d \
./library/pem.d \
./library/pk.d \
./library/pk_wrap.d \
./library/pkcs11.d \
./library/pkcs12.d \
./library/pkcs5.d \
./library/pkparse.d \
./library/pkwrite.d \
./library/ripemd160.d \
./library/rsa.d \
./library/sha1.d \
./library/sha256.d \
./library/sha512.d \
./library/ssl_cache.d \
./library/ssl_ciphersuites.d \
./library/ssl_cli.d \
./library/ssl_srv.d \
./library/ssl_tls.d \
./library/threading.d \
./library/timing.d \
./library/version.d \
./library/x509.d \
./library/x509_create.d \
./library/x509_crl.d \
./library/x509_crt.d \
./library/x509_csr.d \
./library/x509write_crt.d \
./library/x509write_csr.d \
./library/xtea.d 


# Each subdirectory must supply rules for building sources it contributes
library/%.o: ../library/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


