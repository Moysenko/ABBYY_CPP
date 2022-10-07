#include <iostream>
#include <vector>

#include "permutations_ii/sol.cpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> inp(n);
  for (auto& x: inp) {
    std::cin >> x;
  }

  Solution sol;
  auto ans = sol.permuteUnique(inp);
  for (auto& ans_i: ans) {
    for (auto& x: ans_i) {
      std::cout << x << ' ';
    }
    std::cout << '\n';
  }
}