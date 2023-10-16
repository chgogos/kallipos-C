CC = clang
BIN = counter
SRC = main.c
CFLAGS = -std=c99 -pedantic `pkg-config --cflags glew glfw3` 
LIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lm `pkg-config --libs glew glfw3` 

$(BIN): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(BIN)

clean:
	rm -f $(BIN)