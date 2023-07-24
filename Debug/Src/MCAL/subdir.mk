################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/Stm32_F103C6_EXTI.c \
../Src/MCAL/Stm32_F103C6_GPIO.c \
../Src/MCAL/Stm32_F103C6_RCC.c \
../Src/MCAL/Stm32_F103C6_USART.c 

OBJS += \
./Src/MCAL/Stm32_F103C6_EXTI.o \
./Src/MCAL/Stm32_F103C6_GPIO.o \
./Src/MCAL/Stm32_F103C6_RCC.o \
./Src/MCAL/Stm32_F103C6_USART.o 

C_DEPS += \
./Src/MCAL/Stm32_F103C6_EXTI.d \
./Src/MCAL/Stm32_F103C6_GPIO.d \
./Src/MCAL/Stm32_F103C6_RCC.d \
./Src/MCAL/Stm32_F103C6_USART.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/Stm32_F103C6_EXTI.o: ../Src/MCAL/Stm32_F103C6_EXTI.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-3 -fstack-usage -MMD -MP -MF"Src/MCAL/Stm32_F103C6_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MCAL/Stm32_F103C6_GPIO.o: ../Src/MCAL/Stm32_F103C6_GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-3 -fstack-usage -MMD -MP -MF"Src/MCAL/Stm32_F103C6_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MCAL/Stm32_F103C6_RCC.o: ../Src/MCAL/Stm32_F103C6_RCC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-3 -fstack-usage -MMD -MP -MF"Src/MCAL/Stm32_F103C6_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MCAL/Stm32_F103C6_USART.o: ../Src/MCAL/Stm32_F103C6_USART.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-3 -fstack-usage -MMD -MP -MF"Src/MCAL/Stm32_F103C6_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

