################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino\avr\dtostrf.c 

C_DEPS += \
.\core\core\avr\dtostrf.c.d 

AR_OBJ += \
.\core\core\avr\dtostrf.c.o 


# Each subdirectory must supply rules for building sources it contributes
core\core\avr\dtostrf.c.o: C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino\avr\dtostrf.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-gcc" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


