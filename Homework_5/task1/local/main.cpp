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

  int src1, src2, dest;
  std::cin >> src1 >> src2 >> dest;

  Solution sol;
  auto ans = sol.minimumWeight(n, edges, src1, src2, dest);
  std::cout << ans;
}