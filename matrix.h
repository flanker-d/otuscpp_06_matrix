#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "row.h"
#include "value.h"

using coord_t = std::tuple<int, int>;

class row;
class matrix
{
  public:
    row operator[](int row_);
    std::map<coord_t, value> &get_points();
  private:
    std::map<coord_t, value> m_points;
};
