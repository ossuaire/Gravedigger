CC=g++
EXEC=gravedigger
OBJECT=./object/
SOURCE=./src/

INCPATH= -I$(SOURCE)
LIBS= -lsfml-window
DEP= Main.o

all: $(EXEC)

$(EXEC): $(DEP)
	$(CC) -o $(EXEC) $(OBJECT)*.o $(LIBS)

%.o: $(SOURCE)%.cpp
	$(CC) -c $(INCPATH) -o $(OBJECT)$@ $^

clear:
	rm -f -r *~
	rm -f $(OBJECT)*.o
	rm -f $(EXEC)
