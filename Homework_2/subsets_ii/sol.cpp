#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end());
      std::vector<std::pair<int, int>> item_cnt;
      for (const auto& x: nums) {
        if (item_cnt.empty() || item_cnt.back().first != x) {
          item_cnt.emplace_back(x, 1);
        } else {
          item_cnt.back().second += 1;
        }
      }

      std::vector<std::vector<int>> result;
      result.emplace_back();

      for (auto& [x, cnt]: item_cnt) {
        size_t built_items_count = result.size();
        for (size_t built_item_i = 0; built_item_i < built_items_count; built_item_i++) {
          auto subset = result[built_item_i];
          for (size_t x_in_subset_cnt = 1; x_in_subset_cnt <= cnt; x_in_subset_cnt++) {
            subset.push_back(x);
            result.push_back(subset);
          }
        }
      }

      return result;
    }
};
