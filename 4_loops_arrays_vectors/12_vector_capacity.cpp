#include <vector>
#include <iostream>

int main()
{
  std::vector<int> numbers(40, 5);

  for(int &x : numbers){
    std::cout << x << ", ";
  }
  std::cout << std::endl;

  
  std::cout << "Space for " << numbers.capacity() << std::endl;
  numbers.push_back(2);
  std::cout << "Space for " << numbers.capacity() << std::endl;

  for(int &x : numbers){
    std::cout << x << ", ";
  }
  std::cout << std::endl;

  std::vector<int> numbers_curly{40, 5};
  std::cout << "Space for " << numbers_curly.capacity() << std::endl;
  numbers_curly.push_back(2);
  std::cout << "Space for " << numbers_curly.capacity() << std::endl;

  for(int &x : numbers_curly){
    std::cout << x << ", ";
  }
  std::cout << std::endl;

}