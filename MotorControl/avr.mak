#This file is generated by VisualGDB.
#It contains GCC settings automatically derived from the board support package (BSP).
#DO NOT EDIT MANUALLY. THE FILE WILL BE OVERWRITTEN. 
#Use VisualGDB Project Properties dialog or modify Makefile or per-configuration .mak files instead.

#In order to build this project manually (outside VisualGDB), please provide TOOLCHAIN_ROOT, BSP_ROOT, EFP_BASE and TESTFW_BASE variables via Environment or Make command line
#Embedded toolchain
CC := $(TOOLCHAIN_ROOT)/bin/avr-gcc.exe
CXX := $(TOOLCHAIN_ROOT)/bin/avr-g++.exe
LD := $(CXX)
AR := $(TOOLCHAIN_ROOT)/bin/avr-ar.exe
OBJCOPY := $(TOOLCHAIN_ROOT)/bin/avr-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS += 
INCLUDE_DIRS += 
LIBRARY_DIRS += 
LIBRARY_NAMES += 
ADDITIONAL_LINKER_INPUTS += 
MACOS_FRAMEWORKS += 
LINUX_PACKAGES += 

CFLAGS += 
CXXFLAGS += 
ASFLAGS += 
LDFLAGS += 
COMMONFLAGS += -mmcu=atmega328p
LINKER_SCRIPT := 

