#include "sol.cpp"
#include <iostream>
#include <vector>


int main() {
  int n;
  std::cin >> n;
  std::vector<int> height(n);
  for (auto& h: height) {
    std::cin >> h;
  }

  Solution sol;
  std::cout << sol.trap(height);
}