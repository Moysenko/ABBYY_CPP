#include <iostream>
#include <ranges>
#include <vector>

struct Person {
  std::string name;
  std::string surname;
};

template <typename InputIter>
auto Sum(InputIter begin, InputIter end) {
  auto sum{ *begin };
  for (auto iter{ ++begin}; iter != end; ++iter) {
    sum += *iter;
  }
  return sum;
}

int main() {

  std::vector<std::pair<Person, size_t>> person_age_vec = {
    {{"Misha", "Moysenko"}, 21},
    {{"Martin", "Eden"}, 24},
    {{"Old", "Namestin"}, 67},
    {{"Eric", "Cartman"}, 10}
  };

  auto ages_mapper = [](const std::pair<Person, size_t>& person_info) {
    return person_info.second;
  };
  auto middle_ages_filter = [](size_t x) {
    return 12 <= x && x <= 65;
  };

  auto filtered_range = person_age_vec
    | std::views::transform(ages_mapper)
    | std::views::filter(middle_ages_filter);
  
  float ages_sum = Sum(filtered_range.begin(), filtered_range.end());
  size_t items_count = std::distance(filtered_range.begin(), filtered_range.end());
  std::cout << ages_sum / items_count;

}