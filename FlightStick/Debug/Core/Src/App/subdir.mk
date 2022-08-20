################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/app.c \
../Core/Src/App/backlight.c \
../Core/Src/App/buttons.c \
../Core/Src/App/interrupts.c \
../Core/Src/App/resistors.c \
../Core/Src/App/usb.c 

OBJS += \
./Core/Src/App/app.o \
./Core/Src/App/backlight.o \
./Core/Src/App/buttons.o \
./Core/Src/App/interrupts.o \
./Core/Src/App/resistors.o \
./Core/Src/App/usb.o 

C_DEPS += \
./Core/Src/App/app.d \
./Core/Src/App/backlight.d \
./Core/Src/App/buttons.d \
./Core/Src/App/interrupts.d \
./Core/Src/App/resistors.d \
./Core/Src/App/usb.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/%.o Core/Src/App/%.su: ../Core/Src/App/%.c Core/Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../USB_DEVICE/App -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App

clean-Core-2f-Src-2f-App:
	-$(RM) ./Core/Src/App/app.d ./Core/Src/App/app.o ./Core/Src/App/app.su ./Core/Src/App/backlight.d ./Core/Src/App/backlight.o ./Core/Src/App/backlight.su ./Core/Src/App/buttons.d ./Core/Src/App/buttons.o ./Core/Src/App/buttons.su ./Core/Src/App/interrupts.d ./Core/Src/App/interrupts.o ./Core/Src/App/interrupts.su ./Core/Src/App/resistors.d ./Core/Src/App/resistors.o ./Core/Src/App/resistors.su ./Core/Src/App/usb.d ./Core/Src/App/usb.o ./Core/Src/App/usb.su

.PHONY: clean-Core-2f-Src-2f-App

