CC=gcc
CFLAGS=-c -Wall
LIBS=

all:a51_geffe

decifer:a51_geffe.o $(LIBS)

decifer.o:a51_geffe.c
	$(CC) $(CFLAGS) a51_geffe.c

clean:
	rm *.o
