#include "sudoku_validator.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <set>

bool valid = true;

// Função para validar uma linha específica
void validateRow(const std::vector<std::vector<int>>& board, int row) {
    std::set<int> seen;
    for (int num : board[row]) {
        if (num < 1 || num > 9 || seen.find(num) != seen.end()) {
            valid = false;
            return;
        }
        seen.insert(num);
    }
}


// Função para ler o Sudoku de um arquivo
std::vector<std::vector<int>> readSudokuFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> board(9, std::vector<int>(9));
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            file >> board[i][j];
        }
    }

    return board;
}
