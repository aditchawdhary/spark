#pragma once

#include <expected>
#include <istream>
#include <expected>
#include <string>

namespace stock_prices
{
    std::expected<double, std::string> get_number(std::istream & input_stream);
}