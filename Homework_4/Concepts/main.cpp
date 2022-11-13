#include <type_traits>
#include <string>
#include <iostream>

struct Stringable {
  int x;
};

namespace std {

string to_string(const Stringable& s) {
  return to_string(s.x);
}

}  // std

template<class T>
concept IsStringable = 
    requires(T a) {
        std::to_string(a);
    };

template<typename T>
concept IsStringableNumber = 
  (std::integral<T> || std::floating_point<T>) && IsStringable<T>;

template <IsStringableNumber T1, IsStringableNumber T2>
std::string concat(const T1& a, const T2& b) {
  return std::to_string(a) + std::to_string(b);
}

int main() {
  std::cout << concat(1.3, -2);  // компилируется
  std::cout << concat(1.3, Stringable(1)); // не компилируется
}