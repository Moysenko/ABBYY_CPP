#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
      int n = height.size();
      int max_left[n];
      int max_right[n];

      max_left[0] = height[0];
      max_right[n - 1] = height[n - 1];
      for (int i = 1; i < n; i++) {
        max_left[i] = std::max(max_left[i - 1], height[i]);
      }
      for (int i = n - 2; i >= 0; i--) {
        max_right[i] = std::max(max_right[i + 1], height[i]);
      }

      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans += std::min(max_left[i], max_right[i]) - height[i];
      }

      return ans;
    }
};