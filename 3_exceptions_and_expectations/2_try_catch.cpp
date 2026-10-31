#include <iostream>
#include <exception>

double get_number(std::istream & input_stream)
{
  double number{};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }
  throw std::exception{};
}

int main()
{
  try
  {
    std::cout << "Please enter a number." << std::endl;
    double number = get_number(std::cin);
    std::cout << "Got " << number << " thanks!" << std::endl;
  }
  catch(const std::exception & ex)
  {
    std::cout << "Something went wrong" << std::endl;
  }
}