# Sudoku Solution Validator

This project implements a **Sudoku Solution Validator** to check if a given Sudoku puzzle solution is valid using **C++11** and **threads** for concurrent validation.

---

## Project Setup

### Requirements:
- Linux-based system
- C++ compiler (e.g., GCC) with C++11 support
- `make` utility

If you don't have the required packages, install them using:

```bash
sudo apt update
sudo apt install build-essential
```

#### How to compile and run

1. Clone the repository

```bash
git clone <repository-url>
cd sudoku-validator
```

2. Build the project using Makefile

```bash
make
```


3. Create the input file sudoku.txt

Create a file named sudoku.txt in the project root. It must contain:

- 9 lines

- 9 numbers per line, separated by spaces

- Each number between 1 and 9

Example:

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9


4. Run the validator

```bash
./sudoku_validator
```

5. When prompted:

=== Sudoku Solution Validator ===
Digite o nome do arquivo contendo o Sudoku (ex: sudoku.txt):


6. Type:

```bash
sudoku.txt
```

7. Expected outputs:

Valid solution:

A solução do Sudoku é válida!


Invalid solution:

A solução do Sudoku é inválida!


8. Cleaning up build files

```bash
make clean
```