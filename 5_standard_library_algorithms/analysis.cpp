#include <algorithm>
#include <iostream>
#include <cassert>
#include <numeric>
#include <stdexcept>

#include "analysis.h"
#include "input.h"

namespace stock_prices
{
    std::vector<double> get_prices(std::istream & input_stream)
    {
        std::cout << "Please enter some numbers. " << std::endl;
        std::vector<double> numbers{};
        std::cout << '>';
        auto number = stock_prices::get_number(input_stream);
        while(number.has_value())
        {
            numbers.push_back(number.value());
            std::cout << '>';
            number = stock_prices::get_number(input_stream);
        }
        return numbers;
    }

    std::vector<double> remove_invalid(std::vector<double> prices)
    {
        auto new_end = std::remove_if(prices.begin(), prices.end(), negative);
        prices.erase(new_end, prices.end());
        return prices;
    }

    double average(const std::vector<double> & prices)
    {
        if(prices.empty())
        {
            throw std::invalid_argument("Prices cannot be empty");
        }
        // double sum{0.0};
        // for(const double & price: prices)
        // {
        //     sum += price;
        // }
        // return sum/prices.size();
        return std::accumulate(prices.begin(), prices.end(), double{})/prices.size();
    }

    void test_analysis()
    {
        auto got = remove_invalid({-1.2, 3.5});
        assert(got.size() == 1);
        assert(got[0] == 3.5);

        try
        {
            average({});
            assert(false);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        assert(average({1.0})==1.0);

    }

    std::vector<double> remove_invalid_iter(std::vector<double> prices)
    {
        for(auto iterator = prices.begin(); iterator != prices.end();)
        {
            if(negative(*iterator))
            {
                iterator = prices.erase(iterator);
            }
            else
            {
                ++iterator;
            }
        }
        return prices; 
    }
}

int main()
{
    auto prices = stock_prices::get_prices(std::cin);
    if (!prices.empty())
    {
        auto result = std::ranges::minmax(prices);
        std::cout  << "min " << result.min << std::endl;
        std::cout << "max " << result.max << std::endl;
    }
    auto invalid = std::ranges::count_if(prices, stock_prices::negative);
    std::cout << invalid << " prices below zero" << std::endl;
    auto erased = std::erase_if(prices, stock_prices::negative);
    std::cout << erased << " prices below zero" << std::endl;


    std::cout << "Average " << stock_prices::average(prices) << std::endl;


    std::sort(prices.begin(), prices.end());
    for(auto p: prices)
    {
        std::cout << p << ", ";
    }
    std::cout << std::endl;

}