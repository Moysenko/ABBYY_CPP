#include <iostream>
#include <vector>

#include "sudoku_solver/sol.cpp"

int main() {
  int N = 9;
  std::vector<std::vector<char>> board(N);
  for (int y = 0; y < N; y++) {
    std::vector<char> row(N);
    for (int x = 0; x < N; x++) {
      std::cin >> row[x];
    }
    board[y] = std::move(row);
  }

  Solution solution;
  solution.solveSudoku(board);

  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      std::cout << board[x][y] << ' ';
    }
    std::cout << '\n';
  }
}