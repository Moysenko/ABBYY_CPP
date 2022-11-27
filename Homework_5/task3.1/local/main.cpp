#include <iostream>

#include "../sol.cpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> edges(m);
  for (auto& edge: edges) {
    for (int i = 0; i < 3; i++) {
      int x;
      std::cin >> x;
      edge.push_back(x);
    }
  }

  Solution sol;
  auto ans = sol.findCriticalAndPseudoCriticalEdges(n, edges);
  for (auto& arr: ans) {
    for (int& x: arr) {
      std::cout << x << ' ';
    }
    std::cout << std::endl;
  }
}