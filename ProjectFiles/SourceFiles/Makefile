#******************************************************************************************************
#*** .File        : Makefile **************************************************************************
#*** .Description : Use to build the project by write its command after accessing the cmd *************
#*** .Author      : Mohamed Ashour Hassan *************************************************************
# ***.Date        : 5/1/2024 **************************************************************************
#******************************************************************************************************
# All Variable used to setting configuration of project without change in Makfile code.
# Create object to indicate to ToolChain.
ToolChain := arm-none-eabi-
# Create object to indicate to usage target. 
Target := -mcpu=cortex-m4 -mthumb 
# Create object to indicate to Target's Linker Script File.
LinkerScriptFile := LinkerScriptForStm32f401xx.ld
# Create object to indicate to all source file in directory.
SourceFiles := $(wildcard *.c)
# Create object to indicate to all source file in directory after change its extension to .o (object file).
OBJFiles := $(SourceFiles:.c=.o)
# Create object to indicate to executable file .elf.
AppName_elf := app.elf
# Create object to indicate to executable file .hex.
AppName_hex := app.hex
 
#**********************************************************************************************************************
build:app.hex
	@echo "**************************** Hex file is Generated  ******************************************"
#******************************************************************************************************
# $@ indicate to target , $< indicate to dependency
# %.o -> $@ , %.c -> $< 
# So convert all source files to object files  
%.o : %.c
	$(ToolChain)gcc -c $(Target) $< -o $@
#******************************************************************************************************
$(AppName_elf) : $(OBJFiles)
	$(ToolChain)ld -Map app.map -T $(LinkerScriptFile) $(OBJFiles) -o $@
#******************************************************************************************************
$(AppName_hex) : $(AppName_elf)
	$(ToolChain)objcopy -O ihex $< $@
