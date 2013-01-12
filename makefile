CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE)
LIBS= -lsfml-window -lsfml-graphics
DEP= CharacterFactory.o Character.o CPosition.o CComponent.o main.o

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
