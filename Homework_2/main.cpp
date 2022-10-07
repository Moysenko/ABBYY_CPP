#include <iostream>
#include <vector>

#include "generate_parenthess/sol.cpp"

int main() {
  int n;
  std::cin >> n;

  Solution sol;
  auto ans = sol.generateParenthesis(n);
  for (auto& ans_i: ans) {
    std::cout << ans_i << ' ';
  }
}