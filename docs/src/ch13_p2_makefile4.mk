# NOT READY
CC=gcc
INCLUDE=-I.
CFLAGS=-Wall -Wextra -g3 -O -std=c99
LDLIBS=-lm
DEPS=ch13_p2_geom.h
SRC=ch13_p2_geom.c ch13_p2_main.c
OBJS=ch13_p2_geom.o ch13_p2_main.o
TARGET=ch13_p2_main

.PHONY:all clean
all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LDLIBS)

$(filter %.o,$(OBJS)): %.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
	rm -rf $(TARGET) $(OBJS)