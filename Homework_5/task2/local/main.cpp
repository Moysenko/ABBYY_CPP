#include <iostream>
#include <vector>

#include "../sol.cpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> points(n);
  for (auto& point: points) {
    for (int i = 0; i < 2; i++) {
      int x;
      std::cin >> x;
      point.push_back(x);
    }
  }

  Solution sol;
  std::cout << sol.minCostConnectPoints(points);
}