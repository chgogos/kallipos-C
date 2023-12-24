CC = gcc
CFLAGS = -Wall
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O3 -DNDEBUG

OBJ = main.o feature.o utils.o
DEVOBJ = main_dev.o feature_dev.o utils.o
PRODOBJ = main_prod.o feature_prod.o utils.o

.PHONY: all clean dev prod

all: dev prod

dev: CFLAGS += $(DEBUG_FLAGS)
dev: $(DEVOBJ)
	$(CC) $(CFLAGS) -o program_dev $(DEVOBJ)

prod: CFLAGS += $(RELEASE_FLAGS)
prod: $(PRODOBJ)
	$(CC) $(CFLAGS) -o program_prod $(PRODOBJ)

main_dev.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main_dev.o

feature_dev.o: feature.c
	$(CC) $(CFLAGS) -c feature.c -o feature_dev.o

main_prod.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main_prod.o

feature_prod.o: feature.c
	$(CC) $(CFLAGS) -c feature.c -o feature_prod.o

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o program_dev program_prod
