#include <array>
#include <iostream>

void array_experiment()
{
  std::array<double, 5> numbers{};
  std::cout << numbers[0] << std::endl;
  numbers[0] = 300.98789;
  std::cout << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << ", " << numbers[3] << ", " << numbers[4] << std::endl;
  numbers[1] = 300.1116;
  numbers[2] = 300.2227;
  numbers[3] = 300.3338;
  numbers[4] = 300.4449;
  for(auto &x: numbers) 
  {
    std::cout << x << ", " ;
  }
  std::cout << std::endl;
}


int main()
{
  array_experiment();
}