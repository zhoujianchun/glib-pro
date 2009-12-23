
CC     = gcc
CFLAGS = `pkg-config --cflags --libs gobject-2.0 glib-2.0` -Wall -g

all:test

test: main.c boy.c boy.h man.c man.h
	${CC} ${CFLAGS} main.c boy.c man.c -o test
clean:
	rm -f *.o test
