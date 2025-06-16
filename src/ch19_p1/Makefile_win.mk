CC = gcc
BIN = counter
SRC = main.c
CFLAGS = -std=c99 -pedantic -IC:\glew-2.1.0\include -IC:\glfw-3.3.8.bin.WIN64\include 
LIBS = -LC:\glfw-3.3.8.bin.WIN64\lib-mingw-w64 -LC:\glew-2.1.0\lib\Release\x64
LIBS += -lglfw3 -lopengl32 -lgdi32 -lm -lGLU32 -lGLEW32

$(BIN): $(SRC)
	del $(BIN).exe
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(BIN)

clean:
	del $(BIN).exe