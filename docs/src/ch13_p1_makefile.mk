CC=gcc
CFLAGS=-Wall -Wextra
CFILES=ch13_p1_utility.c ch13_p1_io.c ch13_p1_main.c 
OBJECTS=ch13_p1_utility.o ch13_p1_io.o ch13_p1_main.o
FILENAME=geolocations.txt
BINARY=ch13_p1_main

all:$(BINARY)

$(BINARY):$(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

run:$(BINARY)
	./$(BINARY) $(FILENAME)

clean:
	rm -rf *.o $(BINARY)