CC = gcc
CFLAGS = -Wall
MV = mv

all: shared 

static:
	$(CC) -static ./mivip.c -o ./mivip $(CFLAGS)

shared:
	$(CC) -shared ./mivip.c -o ./mivip $(CFLAGS)

install: all
	$(MV) ./mivip /usr/bin/mivip