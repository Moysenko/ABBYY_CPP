#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    if (s2.size() > s1.size()) {
      swap(s1, s2);
    }

    int N = s1.size(), M = s2.size();
    bool is_presented[M + 1];
    std::fill(is_presented, is_presented + M + 1, false);
    is_presented[0] = true;

    for (int n = 0; n <= N; n++) {
      for (int m = 0; m <= M; m++) {
        if (n == 0 && m == 0) continue;

        if (m > 0 && s3[n + m - 1] == s2[m - 1] && is_presented[m - 1]) {
          is_presented[m] = true;
        } else if (n > 0 && s3[n + m - 1] == s1[n - 1] && is_presented[m]) {
          is_presented[m] = true;
        } else {
          is_presented[m] = false;
        }
      }
    }

    return is_presented[M];
  }
};