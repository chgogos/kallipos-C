CC=gcc
CFLAGS=-I.
LDLIBS=-lm
TARGET=ch13_p2_main

all:ch13_p2_geom.o ch13_p2_main.o
	$(CC) ch13_p2_geom.o ch13_p2_main.o -o $(TARGET) $(LDLIBS)

ch13_p2_geom.o:ch13_p2_geom.c ch13_p2_geom.h 
	$(CC) -c ch13_p2_geom.c -o ch13_p2_geom.o $(CFLAGS)

ch13_p2_main.o:ch13_p2_main.c ch13_p2_geom.h
	$(CC) -c ch13_p2_main.c -o ch13_p2_main.o $(CFLAGS)

clean:
	rm -rf $(TARGET) *.o