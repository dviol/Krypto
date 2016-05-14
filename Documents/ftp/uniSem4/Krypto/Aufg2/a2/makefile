CC=gcc
CFLAGS=-c -Wall
LIBS=

all:decifer

decifer:decifer.o $(LIBS)

decifer.o:decifer.c
	$(CC) $(CFLAGS) decifer.c

clean:
	rm *.o
