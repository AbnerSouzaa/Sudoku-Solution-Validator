#include "sudoku_validator.h"
#include <iostream>

int main() {
    std::cout << "=== Sudoku Solution Validator ===" << std::endl;

    std::string filename;
    std::cout << "Digite o nome do arquivo contendo o Sudoku (ex: sudoku.txt): ";
    std::cin >> filename;

    std::vector<std::vector<int>> board = readSudokuFromFile(filename);

    bool isValid = validateSudoku(board);

    if (isValid) {
        std::cout << "A solução do Sudoku é válida!" << std::endl;
    } else {
        std::cout << "A solução do Sudoku é inválida!" << std::endl;
    }

    return 0;
}
