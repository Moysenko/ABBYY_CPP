#include <ranges>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  auto input = std::ranges::istream_view<int>(std::cin)
    | std::views::take_while([](int x){ return x != -1; });

  std::vector<int> input_vec;
  std::ranges::copy(input, std::back_inserter(input_vec));
  std::ranges::copy(input_vec, std::ostream_iterator<int>(std::cout, " "));
}