#include <iostream>

int main()
{
  double number1{};
  double number2{};
  std::cout << "Please enter a number." << std::endl;
  std::cin >> number1;
  std::cout << "You entered: " << number1 << std::endl;
  std::cout << "Please enter another number." << std::endl;
  std::cin >> number2;
  std::cout << "You entered: " << number2 << std::endl;
}


// g++ -Wall -std=c++23 ./4_loops_arrays_vectors/1_attempt_input_several_number.cpp \
// -o ./4_loops_arrays_vectors/output/1_attempt_input_several_number