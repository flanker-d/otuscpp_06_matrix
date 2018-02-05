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
    using iterator = std::map<coord_t, value>::iterator;
  public:
    row operator[](int row_);
    std::map<coord_t, value> &get_points();
    iterator begin();
    iterator end();
    std::size_t size();
    static std::tuple<int, int, int> make_tuple(std::pair<coord_t, value> it);

  private:
    std::map<coord_t, value> m_points;
};
