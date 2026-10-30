#include <cassert>
#include <istream>
#include <iostream>
#include <sstream>

[[nodiscard]] bool get_number(std::istream & input_stream, double & number)
{
  input_stream >> number;
  if (input_stream)
  {
    return true;
  }
  else
  {
    input_stream.clear();
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
}

void test_code()
{
  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value == 1);

  double unused{};
  std::stringstream bad_input{"q"};
  const bool not_ok = get_number(bad_input, unused);
  assert(!not_ok);

  std::stringstream mid_input{"qqq"};
  double mid_value{0.0};
  get_number(mid_input, mid_value);
}

int main()
{
  test_code();

  double number{};
  std::cout << "Please enter a number. \n";
  if(get_number(std::cin, number))
  {
    std::cout << "Got " << number << " thanks!" << std::endl;
  }
  else
  {
    std::cout << "Something went wrong" << std::endl;
    std::cout << "Please enter a number." << std::endl;
    number = {};
    const bool ok_now = get_number(std::cin, number);
    if (ok_now)
    {
      std::cout << "Got " << number << ", thanks!" << std::endl;
    }
    else
    {
      std::cout << "Something went wrong again!" << std::endl;
    }
  }
}


/**
 * 
 * achawdhary@macbookpro spark % g++ -Wall -std=c++23 \
 * ./2_variables_keyboard_input/9_input_streams_clear_ignore.cpp \
 * -o ./2_variables_keyboard_input/9_input_streams_clear_ignore
 *
 *   */ 


/**
 * achawdhary@macbookpro spark % ./2_variables_keyboard_input/9_input_streams_clear_ignore
 * Please enter a number. 
 * 12q
 * Got 12 thanks!
 * achawdhary@macbookpro spark % ./2_variables_keyboard_input/9_input_streams_clear_ignore
 * Please enter a number. 
 * 12a 
 * Something went wrong
 * Please enter a number.
 * 
 * 12
 * Got 12, thanks!
 * achawdhary@macbookpro spark % 
*/