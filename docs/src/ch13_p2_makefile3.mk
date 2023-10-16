CC=gcc
INCLUDE=-I.
CFLAGS=-Wall -Wextra -g3 -O -std=c99
LDLIBS=-lm
TARGET=ch13_p2_main

.PHONY:all clean
all:$(TARGET)

$(TARGET):ch13_p2_geom.o ch13_p2_main.o
	$(CC) $^ -o $@ $(LDLIBS)

ch13_p2_geom.o:ch13_p2_geom.c ch13_p2_geom.h 
	$(CC) -c ch13_p2_geom.c -o $@ $(CFLAGS) $(INCLUDE)

ch13_p2_main.o:ch13_p2_main.c ch13_p2_geom.h
	$(CC) -c ch13_p2_main.c -o $@ $(CFLAGS) $(INCLUDE)

clean:
	rm -rf $(TARGET) *.o