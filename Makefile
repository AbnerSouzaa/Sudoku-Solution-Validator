# Simple Makefile to build the project
CC = g++
CFLAGS = -std=c++11 -Wall

all: sudoku_validator

sudoku_validator: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o sudoku_validator

clean:
	rm -f sudoku_validator
