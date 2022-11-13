#include <ranges>
#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {

  fmt::print("result: {}",
    std::views::iota(10, 100)
    | std::views::transform([](int x){ return x * x; })
    | std::views::filter([](int x){ return x % 5 != 0; })
    | std::views::transform([](int x){ return std::to_string(x); })
  );

}