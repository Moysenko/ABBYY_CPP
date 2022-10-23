#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
      int min_steps[amount + 1];
      int inf = INT_MAX - 1;
      std::fill(min_steps, min_steps + amount + 1, inf);
      min_steps[0] = 0;

      for (int coin: coins) {
        for (int amount_before_coin = 0; amount_before_coin + coin <= amount; amount_before_coin++) {
          int current_amount = amount_before_coin + coin;
          min_steps[current_amount] = std::min(min_steps[current_amount], min_steps[amount_before_coin] + 1);
        }
      }

      return min_steps[amount] == inf ? -1 : min_steps[amount];
    }
};