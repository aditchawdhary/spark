#include <expected>
#include <iostream>
#include <limits>

std::expected<double, std::string> get_number(std::istream & input_stream)
{
  double number{};
  input_stream >> number;
  if (input_stream)
  {
    return number;
  }
  input_stream.clear();
  input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void show_numbers(const std::array<double, 5u> & numbers)
{
  for (const auto number: numbers)
  {
    std::cout << number << std::endl;
  }
}

int main()
{
  std::cout << "Please enter some numbers" << std::endl;
  std::array<double, 5u> numbers{};
  size_t count{0u};
  while(count < numbers.size())
  {
    std::cout << '>';
    auto number = get_number(std::cin);
    if(number.has_value())
    {
      numbers[count] = number.value();
      std::cout << "Got " << number.value() << " thanks!" << std::endl;
    }
    else
    {
      std::cout << number.error() << std::endl;
    }
    ++count;
  }
  show_numbers(numbers);
}