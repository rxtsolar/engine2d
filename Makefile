CC          = g++
CFLAGS      = -g -Wall
LIBS        = -lSDL -lSDL_image -lSDL_mixer

INCLUDES    = include
BINS        = bin
OBJS        = obj
SRCS        = src
RESOURCES   = resource

headers     = ../$(INCLUDES)/engine2d.h \
              ../$(INCLUDES)/engimage.h \
              ../$(INCLUDES)/engcolor.h \
              ../$(INCLUDES)/shape.h    \
              ../$(INCLUDES)/sound.h    \
              ../$(INCLUDES)/timer.h    \
              ../$(INCLUDES)/object.h   \
              ../$(INCLUDES)/sprite.h   \
              ../$(INCLUDES)/debug.h    \
              ../$(INCLUDES)/vect2.h    \
              ../$(INCLUDES)/const.h

objects     = $(OBJS)/engine2d.o    \
              $(OBJS)/image.o       \
              $(OBJS)/color.o       \
              $(OBJS)/shape.o       \
              $(OBJS)/sound.o       \
              $(OBJS)/timer.o       \
              $(OBJS)/object.o      \
              $(OBJS)/sprite.o      \
              $(OBJS)/main.o

$(OBJS)/%.o : $(SRCS)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

all: game
	ln -s bin/a.out play

game: $(objects)
	$(CC) $(CFLAGS) -o $(BINS)/a.out $(objects) $(LIBS)

#$(objects) : $(headers)

clean:
	rm $(BINS)/* $(OBJS)/* play

.PHONY:
	clean
