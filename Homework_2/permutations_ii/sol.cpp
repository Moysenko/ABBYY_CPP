#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
