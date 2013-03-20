##### Makefile #################################################################

PROJECT = GraveDigger
VERSION = 0.1

SOURCE_DIR = src/
SOURCE_DIRS = $(SOURCE_DIR) $(sort $(dir $(wildcard $(SOURCE_DIR)*/**)))
RESOURCE_DIR = material/
BUILD_DIR = build/
OBJECT_DIR = $(BUILD_DIR).obj/

EXEC = $(BUILD_DIR)$(shell echo $(PROJECT) | tr '[:upper:]' '[:lower:]')
SOURCES = $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)*.cpp))
HEADERS = $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)*.hpp))
OBJECTS = $(addprefix $(OBJECT_DIR), $(patsubst %.cpp, %.o, $(SOURCES)))

CC = g++
LD = $(CC)
CFLAGS = $(addprefix -I, $(SOURCE_DIRS))
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

################################################################################

.PHONY: clean clean-all init

default: init $(EXEC)

init:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(addprefix $(OBJECT_DIR), $(SOURCE_DIRS))

$(EXEC): $(OBJECTS)
	@echo ">> Compiling $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(OBJECT_DIR)%.o: %.cpp $(HEADERS)
	@echo ">> $<\n   |-> $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECT_DIR)

clean-all:
	rm -rf $(BUILD_DIR)

