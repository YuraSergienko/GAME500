################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
game500.hex \

SECONDARY_LIST += \
game500.lst \

SECONDARY_SIZE += \
game500.siz \


# All Target
all: game500.elf secondary-outputs

# Tool invocations
game500.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "D:\GitHub\GAME500\src\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"game500.map" --specs=nano.specs --specs=nosys.specs -o "game500.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
game500.hex: game500.elf
	@	riscv-none-embed-objcopy -O ihex "game500.elf"  "game500.hex"
	@	@
game500.lst: game500.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "game500.elf" > "game500.lst"
	@	@
game500.siz: game500.elf
	@	riscv-none-embed-size --format=berkeley "game500.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) game500.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
