CC = g++
CFLAGS = -std=c++11 -Wall
SRC = src/main.cpp src/sudoku_validator.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = sudoku_validator

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC) *.o
