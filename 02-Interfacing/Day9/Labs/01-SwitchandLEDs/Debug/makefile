################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SwitchandLEDs.lss \

FLASH_IMAGE += \
SwitchandLEDs.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SwitchandLEDs.elf secondary-outputs

# Tool invocations
SwitchandLEDs.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SwitchandLEDs.map -mmcu=atmega32 -o "SwitchandLEDs.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SwitchandLEDs.lss: SwitchandLEDs.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SwitchandLEDs.elf  >"SwitchandLEDs.lss"
	@echo 'Finished building: $@'
	@echo ' '

SwitchandLEDs.hex: SwitchandLEDs.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SwitchandLEDs.elf  "SwitchandLEDs.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SwitchandLEDs.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SwitchandLEDs.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SwitchandLEDs.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
