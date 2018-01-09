################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/Dma.c \
../Src/Flash.c \
../Src/Gpio.c \
../Src/I2C.c \
../Src/IWDG.c \
../Src/Rcc.c \
../Src/Rng.c \
../Src/Timer.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/usart.c 

OBJS += \
./Src/ADC.o \
./Src/Dma.o \
./Src/Flash.o \
./Src/Gpio.o \
./Src/I2C.o \
./Src/IWDG.o \
./Src/Rcc.o \
./Src/Rng.o \
./Src/Timer.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/usart.o 

C_DEPS += \
./Src/ADC.d \
./Src/Dma.d \
./Src/Flash.d \
./Src/Gpio.d \
./Src/I2C.d \
./Src/IWDG.d \
./Src/Rcc.d \
./Src/Rng.d \
./Src/Timer.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/ZheHao/STM32/Gpio/Inc" -I"C:/ZheHao/STM32/Gpio/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/ZheHao/STM32/Gpio/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/ZheHao/STM32/Gpio/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/ZheHao/STM32/Gpio/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


