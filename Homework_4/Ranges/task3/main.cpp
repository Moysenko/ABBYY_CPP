#include <iostream>
#include <ranges>
#include <vector>

struct Person {
  std::string name;
  std::string surname;

  friend std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << person.name << ' ' << person.surname;
    return out;
  }
};

template <typename InputIter, typename OutputIter>
void MyCopy(InputIter begin, InputIter end, OutputIter target) {
  for (auto iter{ begin }; iter != end; ++iter, ++target) {
    *target = *iter;
  }
}


int main() {

  std::vector<std::pair<Person, size_t>> person_age_vec = {
    {{"Misha", "Moysenko"}, 21},
    {{"Martin", "Eden"}, 24},
    {{"Old", "Namestin"}, 67},
    {{"Eric", "Cartman"}, 10},
    {{"Denzel", "Washington"}, 67},
    {{"Tom", "Cruise"}, 60},
    {{"Brad", "Pitt"}, 58}
  };

  auto person_mapper = [](const std::pair<Person, size_t>& person_info) {
    return person_info.first;
  };
  auto persons_prefix = person_age_vec
    | std::views::transform(person_mapper)
    | std::ranges::views::take(4);
  
  MyCopy(persons_prefix.begin(), persons_prefix.end(), 
         std::ostream_iterator<Person>(std::cout, "\n"));

   auto surname_mapper = [](const Person& person) {
     return person.surname;
   };
   auto surnames_prefix = persons_prefix
     | std::views::transform(surname_mapper);

   MyCopy(surnames_prefix.begin(), surnames_prefix.end(), 
          std::ostream_iterator<std::string>(std::cout, "\n"));

}