#include "sol.cpp"
#include <iostream>
#include <string>


int main() {
  std::string s1, s2, s3;
  std::cin >> s1 >> s2 >> s3;
  
  Solution sol;
  std::cout << sol.isInterleave(s1, s2, s3);
}