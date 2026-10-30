#include <sstream>
#include <cassert>

bool get_number(std::istream & input_stream, double & number)
{
  number = 1;
  return false;
}

void test_code()
{
  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value == 1);
}

int main()
{
  test_code();
}