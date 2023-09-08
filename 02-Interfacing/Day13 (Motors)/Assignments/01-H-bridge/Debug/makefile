################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
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
H-bridge.lss \

FLASH_IMAGE += \
H-bridge.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: H-bridge.elf secondary-outputs

# Tool invocations
H-bridge.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,H-bridge.map -mmcu=atmega32 -o "H-bridge.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

H-bridge.lss: H-bridge.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S H-bridge.elf  >"H-bridge.lss"
	@echo 'Finished building: $@'
	@echo ' '

H-bridge.hex: H-bridge.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex H-bridge.elf  "H-bridge.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: H-bridge.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 H-bridge.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) H-bridge.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
