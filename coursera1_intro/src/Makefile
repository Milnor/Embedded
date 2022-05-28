#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile supporting native x64 and ARM Cortex (MSP432) targets
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld 
	LDFLAGS = 
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGs = 
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld 
	LDFLAGS = 
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGs = 
endif

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: clean
clean:
	rm -f *.o *.out *.map 	
