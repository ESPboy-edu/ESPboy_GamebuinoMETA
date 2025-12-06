################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiESP8266.cpp \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiGamebuino.cpp \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiParticle.cpp \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSAM3X.cpp \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSTM32.cpp \
C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiTeensy3.cpp 

LINK_OBJ += \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiESP8266.cpp.o \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiGamebuino.cpp.o \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiParticle.cpp.o \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSAM3X.cpp.o \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSTM32.cpp.o \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiTeensy3.cpp.o 

CPP_DEPS += \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiESP8266.cpp.d \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiGamebuino.cpp.d \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiParticle.cpp.d \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSAM3X.cpp.d \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSTM32.cpp.d \
.\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiTeensy3.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiESP8266.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiESP8266.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiGamebuino.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiGamebuino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiParticle.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiParticle.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSAM3X.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSAM3X.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSTM32.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiSTM32.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiTeensy3.cpp.o: C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\SdSpiTeensy3.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-g++" -mcpu=cortex-m0plus -mthumb -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-threadsafe-statics -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD -D__SKETCH_NAME__="""TankBox""" -DF_CPU=48000000L -DARDUINO=10812 -DARDUINO_SAMD_ZERO -DARDUINO_ARCH_SAMD  -D__SAMD21G18A__ -DUSB_VID=0x2341 -DUSB_PID=0x804d -DUSBCON "-DUSB_MANUFACTURER=\"Arduino LLC\"" "-DUSB_PRODUCT=\"Arduino Zero\"" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Include/" "-IC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS-Atmel\1.2.0/CMSIS/Device/ATMEL/" "-IC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release"   -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\cores\arduino" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta" -I"C:\Users\Dominik\Documents\Arduino\libraries\Gamebuino_META\src" -I"C:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


