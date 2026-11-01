#include <vector>
#include <iostream>

void vector_experiment()
{
  std::vector numbers{07, 14};
  for(const auto number: numbers)
  {
    std::cout << number << std::endl;
  }
}

int main()
{
  vector_experiment();
}