#include <vector>
#include <iostream>

void vector_insert()
{
  std::vector<int> numbers{0, 1};
  auto iterator = numbers.begin();
  numbers.insert(++iterator, -12345678);
  for (const auto number: numbers)
  {
    std::cout << number << std::endl;
  }
}

int main()
{
  vector_insert();
}