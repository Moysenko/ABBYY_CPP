#include "sol.cpp"
#include <iostream>
#include <string>
#include <vector>


int main() {
  int n, amount;
  std::cin >> n >> amount;
  std::vector<int> coins(n);
  for (auto& coin: coins) {
    std::cin >> coin;
  }

  Solution sol;
  std::cout << sol.coinChange(coins, amount);
 
}