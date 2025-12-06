################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\SPI\subdir.mk
-include libraries\Gamebuino_META\src\utility\Sound-SD\subdir.mk
-include libraries\Gamebuino_META\src\utility\Sound\subdir.mk
-include libraries\Gamebuino_META\src\utility\SdFat\src\SpiDriver\subdir.mk
-include libraries\Gamebuino_META\src\utility\SdFat\src\SdCard\subdir.mk
-include libraries\Gamebuino_META\src\utility\SdFat\src\FatLib\subdir.mk
-include libraries\Gamebuino_META\src\utility\SdFat\src\subdir.mk
-include libraries\Gamebuino_META\src\utility\Save\subdir.mk
-include libraries\Gamebuino_META\src\utility\Misc\subdir.mk
-include libraries\Gamebuino_META\src\utility\MetaMode\subdir.mk
-include libraries\Gamebuino_META\src\utility\Language\subdir.mk
-include libraries\Gamebuino_META\src\utility\Gui\subdir.mk
-include libraries\Gamebuino_META\src\utility\Graphics-SD\subdir.mk
-include libraries\Gamebuino_META\src\utility\Graphics\subdir.mk
-include libraries\Gamebuino_META\src\utility\Display-ST7735\subdir.mk
-include libraries\Gamebuino_META\src\utility\Collide\subdir.mk
-include libraries\Gamebuino_META\src\utility\Buttons\subdir.mk
-include libraries\Gamebuino_META\src\utility\Bootloader\subdir.mk
-include libraries\Gamebuino_META\src\utility\Adafruit_ZeroDMA\subdir.mk
-include libraries\Gamebuino_META\src\utility\Adafruit_NeoPixel\subdir.mk
-include libraries\Gamebuino_META\src\subdir.mk
-include core\variant\subdir.mk
-include core\core\avr\subdir.mk
-include core\core\USB\subdir.mk
-include core\core\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release\arduino.ar \

ELF += \
TankBox.elf \

HEX += \
TankBox.hex \



#bootloaderTest
BurnBootLoader: 
	@echo trying to burn bootloader ${bootloader.tool}
	${tools.${bootloader.tool}.erase.pattern}
	${tools.${bootloader.tool}.bootloader.pattern}

uploadWithBuild: all
	@echo trying to build and upload with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}

uploadWithoutBuild: 
	@echo trying to upload without build with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}
    
uploadWithProgrammerWithBuild: all
	@echo trying to build and upload with programmer ${program.tool}
	${tools.${program.tool}.program.pattern}

uploadWithProgrammerWithoutBuild: 
	@echo trying to upload with programmer ${program.tool} without build
	${tools.${program.tool}.program.pattern}

# All Target
all: TankBox

# Tool invocations
TankBox: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-size" -A "C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release/TankBox.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-ar" rcs     C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

TankBox.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:\E\Sloeber\arduinoPlugin\packages\arduino\tools\arm-none-eabi-gcc\7-2017q4/bin/arm-none-eabi-gcc"  "-LC:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release" -Os -Wl,--gc-sections -save-temps  "-TC:\E\Sloeber\arduinoPlugin\packages\gamebuino\hardware\samd\1.2.2\variants\gamebuino_meta/linker_scripts/gcc/flash_with_bootloader.ld" "-Wl,-Map,C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release/TankBox.map" --specs=nano.specs --specs=nosys.specs -mcpu=cortex-m0plus -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -o "C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release/TankBox.elf"   $(LINK_OBJ)  -Wl,--start-group "-LC:\E\Sloeber\arduinoPlugin\packages\arduino\tools\CMSIS\4.5.0/CMSIS/Lib/GCC/" -larm_cortexM0l_math -lm  C:\Users\Dominik\Documents\Programmieren\Gamebuino\TankBox\Release/arduino.ar  -Wl,--end-group
	@echo 'Finished building: $@'
	@echo ' '

TankBox.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${recipe.objcopy.bin.pattern}
	${recipe.objcopy.hex.pattern}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ..\makefile.targets
