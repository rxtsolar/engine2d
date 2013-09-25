CC = g++
CFLAGS = -g -Wall
LIBS = -lSDL -lSDL_image -lSDL_mixer

headers = engine2d.h image.h color.h shape.h sound.h timer.h \
          object.h debug.h vect2.h
objects = engine2d.o image.o color.o shape.o sound.o timer.o \
          object.o main.o

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

all: game

game: $(objects)
	$(CC) $(CFLAGS) -o a.out $(objects) $(LIBS)

$(objects) : $(headers)

clean:
	rm a.out *.o
