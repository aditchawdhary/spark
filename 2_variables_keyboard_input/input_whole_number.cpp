#include <iostream>

int main()
{
  std::cout << "Please enter a number." << std::endl;
  int number{};
  std::cin >> number;
  std::cout << number << std::endl;
}


// achawdhary@macbookpro spark % g++ -Wall -std=c++23 ./2_variables_keyboard_input/input_whole_number.cpp -o input_whole_number