CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE)
LIBS= -lsfml-window -lsfml-graphics -lsfml-system
DEP= CComponent.o Character.o CSprite.o CPosition.o CSpeed.o CharacterFactory.o main.o

all: $(EXEC)

$(EXEC): $(DEP)
	$(CC) -o $(EXEC) $(OBJECT)*.o $(LIBS)

%.o: $(SOURCE)%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

clear:
	rm -f  *~
	rm -f $(SOURCE)*~
	rm -f $(OBJECT)*.o
	rm -f $(EXEC)
