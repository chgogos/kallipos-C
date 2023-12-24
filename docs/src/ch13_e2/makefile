CC=gcc
CFLAGS=-Wall -g

# Object files
OBJS=main.o math_functions.o utils.o

# Target executable
TARGET=calculator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c math_functions.h utils.h
	$(CC) $(CFLAGS) -c main.c

math_functions.o: math_functions.c math_functions.h
	$(CC) $(CFLAGS) -c math_functions.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
