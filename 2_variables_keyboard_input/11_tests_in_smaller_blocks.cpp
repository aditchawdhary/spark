#include <iostream>
#include <limits>
#include <sstream>
#include <istream>
#include <cassert>

bool get_number(std::istream & input_stream, double & number)
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

void test_code()
{
  {
    double value{};
    std::stringstream input{"1"};
    const bool ok = get_number(input, value);
    assert(ok);
    assert(value == 1);
  }
  
  {
    double value{};
    std::stringstream input{"q"};
    const bool not_ok = get_number(input, value);
    assert(!not_ok);
  }
}

int main()
{
  test_code();
}