CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE) -I$(SOURCE)animations/ -I$(SOURCE)components/ -I$(SOURCE)actions/ -I$(SOURCE)collision/ -I$(SOURCE)factories/
LIBS= -lsfml-window -lsfml-graphics -lsfml-system
DEP= CComponent.o GameObject.o Item.o Character.o Environment.o CSprite.o CPosition.o CSpeed.o CAcceleration.o CBoundingBox.o ItemFactory.o CharacterFactory.o EnvironmentFactory.o AAnimation.o AThrow.o ALeft.o ARight.o AStand.o CState.o ICollisionStruct.o MockStruct.o ACAction.o ACThrow.o main.o

all: $(EXEC)

$(EXEC): $(DEP)
	$(CC) -o $(EXEC) $(OBJECT)*.o $(LIBS)

%.o: $(SOURCE)%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)animations/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)components/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)collision/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)actions/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)factories/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

clear:
	rm -f  *~
	rm -f $(SOURCE)*~
	rm -f $(SOURCE)components/*~
	rm -f $(SOURCE)animations/*~
	rm -f $(SOURCE)collision/*~
	rm -f $(SOURCE)actions/*~
	rm -f $(SOURCE)factories/*~
	rm -f $(OBJECT)*.o
	rm -f $(EXEC)
