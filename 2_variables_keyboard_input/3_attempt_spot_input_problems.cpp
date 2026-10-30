#include <iostream>

int main()
{
  int largest_int = std::numeric_limits<int>::max();
  int smallest_int = std::numeric_limits<int>::min();
  double largest_double = std::numeric_limits<double>::max();
  double smallest_double = std::numeric_limits<double>::min();
  double largest_int_double = (double) largest_int + 1.0;
  std::cout << largest_int << std::endl << smallest_int << std::endl << largest_double << std::endl << smallest_double << std::endl;

  std::cout << std::log2((double) largest_int + 1.0) << std::endl;
  std::cout << std::log2((double) largest_double) << std::endl;

  
  std::cout << "Please enter number upto " << largest_double << std::endl;
  double number{};
  std::cin >> number;
  std::cout << number << std::endl;
  if (!std::cin.eof() && std::cin.peek() != '\n')
  {
    std::cout << "Unused input \n";
  }

}