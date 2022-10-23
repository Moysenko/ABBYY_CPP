#include "sol.cpp"
#include <iostream>


int main() {
  int n;
  std::cin >> n;

  Solution sol;
  auto ans = sol.generateTrees(n);

  for (auto& ans_var: ans) {
    print_dfs(ans_var);
    std::cout << std::endl;
  }
}