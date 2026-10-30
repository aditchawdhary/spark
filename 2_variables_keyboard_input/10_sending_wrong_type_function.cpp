#include <limits>
#include <sstream>
#include <iostream>
#include <istream>
#include <cassert>

[[nodiscard]] bool get_number(std::istream & input_stream, double & number)
{
  input_stream >> number;
  if (input_stream)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void some_experiments()
{
  // int number{}; ----- sending wrong type to a function, does not compile
  double number{};
  bool OK = get_number(std::cin, number);
  std::cout << OK << std::endl;
}

int main()
{
  some_experiments();
}