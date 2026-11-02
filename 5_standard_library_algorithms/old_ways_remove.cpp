#include <algorithm>
#include <cassert>

#include "analysis.h"

namespace stock_prices
{
    std::vector<double> remove_invalid(std::vector<double> prices)
    {
        return prices
    }

    void test_analysis()
    {
        auto got = remove_invalid({-1.2, 3.5});
        assert(got.size() == 1);
        assert(got[0] == 3.5);
    }

}