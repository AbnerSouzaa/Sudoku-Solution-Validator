#include "sudoku_validator.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <set>
#include <mutex>  

bool valid = true;
std::mutex logMutex;  

// Função para validar uma linha específica do Sudoku
void validateRow(const std::vector<std::vector<int>>& board, int row) {
    {
        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "Thread [" << std::this_thread::get_id() << "] validando linha " << row << std::endl;
    }

    std::set<int> seen;
    for (int num : board[row]) {
        if (num < 1 || num > 9 || seen.find(num) != seen.end()) {
            valid = false;
            {
                std::lock_guard<std::mutex> lock(logMutex);
                std::cout << "Erro: linha " << row << " inválida." << std::endl;
            }
            return;
        }
        seen.insert(num);
    }
}

// Função para validar uma coluna específica
void validateColumn(const std::vector<std::vector<int>>& board, int col) {
    {
        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "Thread [" << std::this_thread::get_id() << "] validando coluna " << col << std::endl;
    }

    std::set<int> seen;
    for (int row = 0; row < 9; ++row) {
        int num = board[row][col];
        if (num < 1 || num > 9 || seen.find(num) != seen.end()) {
            valid = false;
            {
                std::lock_guard<std::mutex> lock(logMutex);
                std::cout << "Erro: coluna " << col << " inválida." << std::endl;
            }
            return;
        }
        seen.insert(num);
    }
}

// Função para validar uma subgrade 3x3 específica
void validateSubgrid(const std::vector<std::vector<int>>& board, int startRow, int startCol) {
    {
        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "Thread [" << std::this_thread::get_id() << "] validando subgrade iniciando em (" << startRow << ", " << startCol << ")" << std::endl;
    }

    std::set<int> seen;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int num = board[startRow + row][startCol + col];
            if (num < 1 || num > 9 || seen.find(num) != seen.end()) {
                valid = false;
                {
                    std::lock_guard<std::mutex> lock(logMutex);
                    std::cout << "Erro: subgrade (" << startRow << ", " << startCol << ") inválida." << std::endl;
                }
                return;
            }
            seen.insert(num);
        }
    }
}

// Função principal para validar o Sudoku usando múltiplas threads
bool validateSudoku(const std::vector<std::vector<int>>& board) {
    valid = true;

    std::vector<std::thread> threads;

    // Validar linhas e colunas
    for (int i = 0; i < 9; ++i) {
        threads.push_back(std::thread(validateRow, std::ref(board), i));
        threads.push_back(std::thread(validateColumn, std::ref(board), i));
    }
    // Validar subgrades 3x3
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            threads.push_back(std::thread(validateSubgrid, std::ref(board), row, col));
        }
    }
    // Esperar todas as threads terminarem
    for (auto& t : threads) {
        t.join();
    }

    return valid;
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
