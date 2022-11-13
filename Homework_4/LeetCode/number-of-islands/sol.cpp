#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    std::vector<int> dx = {-1, 0, 1, 0};
    std::vector<int> dy = {0, -1, 0, 1};

    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (grid[x][y] == '0') continue;

        for (int i = 0; i < 4; i++) {
          if (0 <= x + dx[i] && x + dx[i] < n && 
              0 <= y + dy[i] && y + dy[i] < m &&
              grid[x + dx[i]][y + dy[i]] == '1') {
            graph[x * m + y].push_back((x + dx[i]) * m + y + dy[i]);
          }
        }
      }
    }

    size_t components = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1' && !visited[i * m + j]) {
          ++components;
          dfs(i * m + j);
        }
      }
    }

    return components;
  }

  void dfs(int vertex) {
    visited[vertex] = true;
    for (int to : graph[vertex]) {
      if (!visited[to]) dfs(to);
    }  
  }

  static const size_t MAX_N = 300, MAX_M = 300;
  std::vector<int> graph[MAX_N * MAX_M];
  bool visited[MAX_N * MAX_M];
};