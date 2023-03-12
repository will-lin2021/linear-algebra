############################################################
# Will's Custom Makefile for C/C++ Projects
#
# File Hierarchy
# 	assets			Assets Files (.png, .ico, etc)
#	bin 			Binary Files (.out, .exe, etc)
#	build			Build Files (.obj, etc)
#	doc				Documentation
#	include 		External Library Headers
#	lib 			External Library Files
#	src 			Source Files (.c, .cpp, .h, etc)
#	test			Test code
############################################################


################### MODIFIABLE VARIABLES ###################
# PROJECT TYPE
SRCEXT := c

# FILE HIERARCHY
SRCDIR := src
BUILDDIR := build
TARGET := bin/linalg_main

# PROJECT BUILDING
CFLAGS := -g -Wall
LIB :=
INC := -I include
############################################################


################# NON-MODIFIABLE VARIABLES #################
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%.$(SRCEXT),$(BUILDDIR)/%.o,$(SOURCES))

ifeq ($(SRCEXT), c)
CC=gcc
else ifeq ($(SRCEXT), cpp)
CC=g++
endif
############################################################


########### CHECK IF NECESSARY VARIABLES ARE SET ###########
# Logic to check if everything needed is defined
ifndef SRCEXT
$(error Source extension not defined)
endif
ifeq ($(TARGET),bin/)
$(error Target not set correctly)
endif
############################################################


############## MAIN COMPILE AND BUILD TARGETS ##############
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $^ -o $(TARGET) $(INC)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Building..."
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
############################################################


##################### CLEAN EVERYTHING #####################
.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -f $(BUILDDIR)/* $(TARGET)
############################################################

######################### TESTING ##########################