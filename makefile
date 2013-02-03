CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE) -I$(SOURCE)animations/ -I$(SOURCE)components/ -I$(SOURCE)rtree/
LIBS= -lsfml-window -lsfml-graphics -lsfml-system
DEP= CComponent.o GameObject.o Character.o Environment.o CSprite.o CPosition.o CSpeed.o CAcceleration.o CBoundingBox.o RTree.o CharacterFactory.o EnvironmentFactory.o AAnimation.o ALeft.o ARight.o AStand.o CState.o main.o

all: $(EXEC)

$(EXEC): $(DEP)
	$(CC) -o $(EXEC) $(OBJECT)*.o $(LIBS)

%.o: $(SOURCE)%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)animations/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)components/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)rtree/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

clear:
	rm -f  *~
	rm -f $(SOURCE)*~
	rm -f $(SOURCE)components/*~
	rm -f $(SOURCE)animations/*~
	rm -f $(SOURCE)rtree/*~
	rm -f $(OBJECT)*.o
	rm -f $(EXEC)
