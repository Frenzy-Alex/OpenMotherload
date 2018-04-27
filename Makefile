# Suppress display of executed commands.
$(VERBOSE).SILENT:

#=============================================================================
#		Project settings

# Project name
PROJECT = OpenMotherload

# Build Type: Debug or Release
BUILD_TYPE = Release

# 
BINARY_DIR = Binary
OUTPUT_DIR = $(BINARY_DIR)/$(BUILD_TYPE)
BUILD_DIR = Build
INCLUDE_DIR = Include
SOURCE_DIR = Source

# Architecture
ARCH = x86_64

#=============================================================================
#		Compiler & Linker flags

# Source files
SOURCES = $(shell find Source/ -type f -name *.cpp | sed 's|^\./||')

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

PCH_HEADER = $(INCLUDE_DIR)/ACE/PrecompiledHeader.h
PCH_OUTPUT = $(INCLUDE_DIR)/ACE/PrecompiledHeader.h.gch

# C++ compiler
CXX = ccache g++

# C++ compiler flags
CXXFLAGS = -fpch-preprocess -Wall -std=gnu++17 -Ofast
CXXFLAGS_INCLUDES = -I$(INCLUDE_DIR) -I$(SOURCE_DIR)
CXXFLAGS_DEBUG = -D DEBUG
CXXFLAGS_RELEASE = -D NDEBUG

# Linker flags
LDFLAGS = -Wl,-rpath,'$$ORIGIN/.'
LDFLAGS_DEBUG = 
LDFLAGS_RELEASE = 

LIBRARIES = -L./Library/$(BUILD_TYPE)/ -lACE

ifeq ($(BUILD_TYPE), Debug)
	CXXFLAGS += $(CXXFLAGS_DEBUG)
	LDFLAGS += $(LDFLAGS_DEBUG)
else ifeq ($(BUILD_TYPE), Release)
	CXXFLAGS += $(CXXFLAGS_RELEASE)
	LDFLAGS += $(LDFLAGS_RELEASE)
else
	$(error Wrong BUILD_TYPE $(BUILD_TYPE), must be one of: DEBUG, RELEASE)
endif

#=============================================================================
#		Targets

.PHONY : all prebuild build postbuild $(PCH_OUTPUT) $(OBJECTS) clean

# All
all : prebuild build postbuild

# Pre build
prebuild :
	echo "\t Prebuild"
	
	echo "Create" $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	
	echo "Create" $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)

# Build
build : prebuild $(PCH_OUTPUT) $(OBJECTS)
	echo "\tCompile" $(PROJECT)
	$(CXX) $(LDFLAGS) $(addprefix $(BUILD_DIR)/, $(OBJECTS)) $(LIBRARIES) -o $(OUTPUT_DIR)/$(PROJECT)

# Post build
postbuild : prebuild build
	echo "\t Postbuild"
	cp -r Data $(OUTPUT_DIR)
	cp -r Library/$(BUILD_TYPE)/* Binary/$(BUILD_TYPE)

# Generate PCH
$(PCH_OUTPUT) : $(PCH_HEADER) prebuild
	echo "\t Generate precompiled header"
	$(CXX) $(CXXFLAGS_INCLUDES) $(CXXFLAGS) -o $(PCH_OUTPUT) $(PCH_HEADER)

# Objects
OBJECTS_COUNTER = 1
$(OBJECTS) : %.o : %.cpp prebuild $(PCH_OUTPUT)
	mkdir -p $(dir Build/$@)
	echo "[" $(OBJECTS_COUNTER)/$(words $(OBJECTS)) "] Building" $<
	$(CXX) $(CXXFLAGS_INCLUDES) $(CXXFLAGS) -include $(PCH_HEADER) -c -o Build/$@ $<
	$(eval OBJECTS_COUNTER=$(shell echo $$(($(OBJECTS_COUNTER)+1))))

# Clean
clean :
	echo "\t Clean"

	echo "Remove Binary ... "
	rm -rf $(BINARY_DIR)

	echo "Remove Build ... "
	rm -rf $(BUILD_DIR)
