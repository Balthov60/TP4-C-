### CONFIGURATION

# PROJECT CONFIGURATION

BUILD_FOLDER        = bin
SRC_FOLDER          = src
EXEC                = Analog

MAIN_TEST_MODULE    = main
MODULES_NAME        = Analyse ArgumentParser Datetime GraphVizWriter Hit LogReader Request

# COMPILATION CONFIGURATION

CC                  =g++
CC_FLAGS            =-Wall -pedantic -std=c++11 
CC_DEBUG_FLAGS      =-g -DMAP


### INITIALISATION

# GET FILES

object_files    := $(addprefix $(BUILD_FOLDER)/,$(MODULES_NAME))

ifneq (,$(findstring test,$(MAKECMDGOALS)))
	test_file       := $(lastword $(MAKECMDGOALS))
endif

object_files    := $(BUILD_FOLDER)/$(MAIN_TEST_MODULE).o $(foreach object,$(object_files),$(object).o)
modules_folders := $(foreach folder,$(MODULES_NAME),$(SRC_FOLDER)/$(folder))


### RULES

# MAIN RULES

all: clean
all: $(BUILD_FOLDER)/$(EXEC)

.SILENT:

# BUILD MAIN EXEC

vpath %.cpp $(modules_folders) $(SRC_FOLDER) $(ADDITIONAL_FOLDER)

$(BUILD_FOLDER)/$(EXEC): $(object_files)
	@echo "building executable : $@ with [$^]\n"
	$(CC) $(CC_FLAGS) -o $@ $^ -lm
	@echo "building done."

# BUILD OBJECTS

$(BUILD_FOLDER)/%.o: %.cpp
	@echo "building : [$@ $<]"
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "builded  : [$@ $<]\n"


### OTHER

clear : clean
clean :
	@echo "Clean all objects file"
	rm -f $(BUILD_FOLDER)/*.o

clean-all :
	@echo "Clean all"
	rm -f $(BUILD_FOLDER)/*

init :
	mkdir $(BUILD_FOLDER)/
