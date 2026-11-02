#include <iostream>
#include <array>

#include "input.h"

std::array<double, 5u> get_prices(std::istream & input_stream)
{
    std::cout << "Please enter some numbers. Type anything else to finish." << std::endl;
    std::array<double, 5u> numbers{};
    size_t count{0u};
    while(count < numbers.size())
    {
        std::cout << '>';
        auto number = stock_prices::get_number(input_stream);
        if (number.has_value())
        {
            numbers[count] = number.value();
            std::cout << "Got " << number.value() << " thanks!" << std::endl;
        }
        else
        {
            std::cout << number.error() << std::endl;
        }
        count++;
    }
    return numbers;
}

int main()
{
    auto prices = get_prices(std::cin);
    std::cout << "The prices entered are:" << std::endl;
    for (auto &x : prices)
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}