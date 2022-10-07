#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        Generate(n, n, "");
        return answer_;
    }

private:
    void Generate(int par_to_open, int par_to_close, std::string current_seq) {
        if (par_to_open == 0 && par_to_close == 0) {
            answer_.push_back(std::move(current_seq));
            return;
        }

        if (par_to_open > 0) {
            Generate(par_to_open - 1, par_to_close, current_seq + "(");
        }
        if (par_to_close > par_to_open) {
            Generate(par_to_open, par_to_close - 1, current_seq + ")");
        }
    }

private:
    std::vector<std::string> answer_;
};
