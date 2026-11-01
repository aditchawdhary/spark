#include <vector>
#include <limits>
#include <iostream>
#include <expected>

std::expected<double, std::string> get_number(std::istream & input_stream)
{
  double number{};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }
  input_stream.clear();
  input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return std::unexpected{"That's not a number"};
}

int main()
{
  // vector_insert();
  std::cout << "Please enter some numbers." << std::endl;
  std::vector<double> numbers{};
  auto number = get_number(std::cin);
  while (number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << "Got " << number.value() << " thanks!" << std::endl;
    number = get_number(std::cin);
  }
  std::cout << number.error() << std::endl;
  std::cout << "You entered" << std::endl;
  for (const auto& number : numbers)
  {
    std::cout << number << std::endl;
  }
}