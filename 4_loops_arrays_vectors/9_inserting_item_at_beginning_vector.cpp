#include <vector>
#include <iostream>

void vector_insert()
{
  std::vector<int> numbers{0,1};
  numbers.insert(numbers.begin(), -1234567);
  for(const auto &number: numbers)
  {
    std::cout << number << std::endl;
  }
}

int main() 
{
  vector_insert();
}