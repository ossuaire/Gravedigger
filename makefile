CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE) -I$(SOURCE)animations/ -I$(SOURCE)components/
LIBS= -lsfml-window -lsfml-graphics -lsfml-system
DEP= CComponent.o Character.o  CSprite.o CPosition.o CSpeed.o CAcceleration.o CharacterFactory.o AAnimation.o CState.o main.o

all: $(EXEC)

$(EXEC): $(DEP)
	$(CC) -o $(EXEC) $(OBJECT)*.o $(LIBS)

%.o: $(SOURCE)%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)animations/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

%.o: $(SOURCE)components/%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

clear:
	rm -f  *~
	rm -f $(SUBFLODERS)*~
	rm -f $(OBJECT)*.o
	rm -f $(EXEC)
