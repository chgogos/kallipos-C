CC=clang
CFLAGS=-Wall -Werror
LDLIBS=-lgmp

all:main

run: main
	./main

main:main.o
	$(CC) main.o -o main $(LDLIBS)

main.o:main.c
	$(CC) -c main.c $(CFLAGS) 

clean:
	rm -f *.o main