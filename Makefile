CC = g++
CFLAGS = -g -Wall
LIBS = -lSDL -lSDL_image

headers = engine2d.h image.h debug.h
objects = engine2d.o image.o main.o

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

all: game

game: $(objects)
	$(CC) $(CFLAGS) -o a.out $(objects) $(LIBS)

$(objects) : $(headers)

clean:
	rm a.out *.o
