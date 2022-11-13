#include "sol.cpp"
#include <iostream>
#include <vector>


int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> grid(n, std::vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> grid[i][j];
    }
  }

  Solution sol;
  std::cout << sol.numIslands(grid);

}