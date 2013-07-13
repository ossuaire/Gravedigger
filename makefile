##### Configuration ############################################################

PROJECT = GraveDigger
VERSION = 0.1
ICON		= material/img/icon/gravedigger.icns

SOURCE_DIR 		= src/
SOURCE_DIRS 	= $(SOURCE_DIR) $(sort $(dir $(wildcard $(SOURCE_DIR)*/**)))
RESOURCE_DIR	= material/
BUILD_DIR 		= build/
OBJECT_DIR 		= $(BUILD_DIR).obj/

EXEC 		= $(shell echo $(PROJECT) | tr '[:upper:]' '[:lower:]')
SOURCES	= $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)*.cpp))
HEADERS = $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)*.hpp))
OBJECTS = $(addprefix $(OBJECT_DIR), $(patsubst %.cpp, %.o, $(SOURCES)))

CC 			= g++
LD 			= $(CC)
CFLAGS	= $(addprefix -I, $(SOURCE_DIRS))
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system
ifeq ($(shell uname), Darwin)
LDFLAGS += -framework CoreFoundation
endif

##### Main targets #############################################################

.PHONY: 	init osx clean clean-all
default:	init $(BUILD_DIR)$(EXEC)
all: 			init osx

##### Executable ###############################################################

init:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(addprefix $(OBJECT_DIR), $(SOURCE_DIRS))

$(BUILD_DIR)$(EXEC): $(OBJECTS)
	@echo ">> Compiling $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(OBJECT_DIR)%.o: %.cpp $(HEADERS)
	@echo ">> $<\n   |-> $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

##### OS-X #####################################################################

APP 			= $(PROJECT).app
PLIST			= info.plist
PLIST_SED	= -e "s/__EXEC__/$(EXEC)/g"				\
						-e "s/__PROJECT__/$(PROJECT)/g"	\
						-e "s/__VERSION__/$(VERSION)/g" \
						-e "s/__ICON__/$(EXEC)/g"
DMG				= $(PROJECT)-$(VERSION).dmg

osx: init $(BUILD_DIR)$(DMG)

$(BUILD_DIR)$(DMG): $(BUILD_DIR)$(APP)
	@echo ">> Creating $@"
	@hdiutil create -fs HFS+ -srcfolder $< -volname $(basename $(DMG)) $@ \
	 > /dev/null

$(BUILD_DIR)$(APP): $(BUILD_DIR)$(EXEC) $(PLIST)
	@echo ">> Creating $@"
	@mkdir -p $@/Contents/MacOS
	@mkdir -p $@/Contents/Resources
	@cp -R $(RESOURCE_DIR) $@/Contents/Resources/$(RESOURCE_DIR)
	@cp $(ICON) $@/Contents/Resources/$(EXEC)$(suffix $(ICON))
	@sed $(PLIST_SED) $(PLIST) > $@/Contents/Info.plist
	@echo "APPL????" > $@/Contents/PkgInfo
	@cp $< $@/Contents/MacOS

##### Cleaning #################################################################

clean:
	rm -rf $(OBJECT_DIR)

clean-all:
	rm -rf $(BUILD_DIR)

