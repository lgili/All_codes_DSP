################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Source/0_Main.obj" \
"./Source/1_GPIO.obj" \
"./Source/2_ADC.obj" \
"./Source/3_PWM.obj" \
"./Source/4_TIMER.obj" \
"./Source/5_ISR.obj" \
"./Source/6_SPI.obj" \
"./Source/F2837xS_CodeStartBranch.obj" \
"./Source/F2837xS_DefaultISR.obj" \
"./Source/F2837xS_GlobalVariableDefs.obj" \
"./Source/F2837xS_Gpio.obj" \
"./Source/F2837xS_PieCtrl.obj" \
"./Source/F2837xS_PieVect.obj" \
"./Source/F2837xS_SysCtrl.obj" \
"./Source/F2837xS_usDelay.obj" \
"./Source/LCD_SPI.obj" \
"../cmd/2837xS_Generic_FLASH_lnk.cmd" \
"../cmd/2837xS_RAM_lnk_cpu1.cmd" \
"../cmd/F2837xS_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-lrts2800_fpu32.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/subdir_vars.mk
-include cmd/subdir_vars.mk
-include Source/subdir_rules.mk
-include cmd/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
28377_LIMPO.out \

EXE_OUTPUTS__QUOTED += \
"28377_LIMPO.out" \

BIN_OUTPUTS += \
28377_LIMPO.hex \

BIN_OUTPUTS__QUOTED += \
"28377_LIMPO.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "28377_LIMPO.out"

# Tool invocations
28377_LIMPO.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --fp_mode=relaxed --advice:performance=all --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"28377_LIMPO.map" --stack_size=0x200 --warn_sections -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="28377_LIMPO_linkInfo.xml" --rom_model -o "28377_LIMPO.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

28377_LIMPO.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/hex2000"  -o "28377_LIMPO.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Source\0_Main.obj" "Source\1_GPIO.obj" "Source\2_ADC.obj" "Source\3_PWM.obj" "Source\4_TIMER.obj" "Source\5_ISR.obj" "Source\6_SPI.obj" "Source\F2837xS_CodeStartBranch.obj" "Source\F2837xS_DefaultISR.obj" "Source\F2837xS_GlobalVariableDefs.obj" "Source\F2837xS_Gpio.obj" "Source\F2837xS_PieCtrl.obj" "Source\F2837xS_PieVect.obj" "Source\F2837xS_SysCtrl.obj" "Source\F2837xS_usDelay.obj" "Source\LCD_SPI.obj" 
	-$(RM) "Source\0_Main.d" "Source\1_GPIO.d" "Source\2_ADC.d" "Source\3_PWM.d" "Source\4_TIMER.d" "Source\5_ISR.d" "Source\6_SPI.d" "Source\F2837xS_DefaultISR.d" "Source\F2837xS_GlobalVariableDefs.d" "Source\F2837xS_Gpio.d" "Source\F2837xS_PieCtrl.d" "Source\F2837xS_PieVect.d" "Source\F2837xS_SysCtrl.d" "Source\LCD_SPI.d" 
	-$(RM) "Source\F2837xS_CodeStartBranch.d" "Source\F2837xS_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

