################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIM0/subdir.mk
-include MCAL/INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
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
BuzzerTones.lss \

FLASH_IMAGE += \
BuzzerTones.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: BuzzerTones.elf secondary-outputs

# Tool invocations
BuzzerTones.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BuzzerTones.map -mmcu=atmega32 -o "BuzzerTones.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BuzzerTones.lss: BuzzerTones.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BuzzerTones.elf  >"BuzzerTones.lss"
	@echo 'Finished building: $@'
	@echo ' '

BuzzerTones.hex: BuzzerTones.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex BuzzerTones.elf  "BuzzerTones.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BuzzerTones.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 BuzzerTones.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) BuzzerTones.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
