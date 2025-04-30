#ifndef SUDOKU_VALIDATOR_H
#define SUDOKU_VALIDATOR_H

#include <vector>
#include <string>

bool validateSudoku(const std::vector<std::vector<int>>& board);
std::vector<std::vector<int>> readSudokuFromFile(const std::string& filename);

#endif 
