#include <exception>
#include <iostream>

double get_number(std::istream & input_stream)
{
  double number{};
  input_stream >> number;
  if (input_stream)
  {
    return number;
  }
  throw std::exception{};
}

int main()
{
  std::cout << "Please enter a number." << std::endl << ">";
  double number = get_number(std::cin);
  std::cout << "Got " << number << " thanks! \n";
}