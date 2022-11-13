#include "sol.cpp"
#include <iostream>
#include <vector>


int main() {
  int m;
  std::cin >> m;

  std::vector<std::vector<int>> edges;
  while (m--) {
    int v, u;
    std::cin >> v >> u;
    edges.push_back({v, u});
  }

  Solution sol;
  auto ans = sol.findRedundantDirectedConnection(edges);
  std::cout << ans[0] << ' ' << ans[1];
}