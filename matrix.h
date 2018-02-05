#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "row.h"
#include "value.h"

using coord_t = std::tuple<int, int>;

template<typename T, int default_value>
class row;

template<typename T, int default_value>
class matrix
{
    using iterator = typename std::map<coord_t, value<T, default_value>>::iterator;

  public:
    row<T, default_value> operator[](int row_)
    {
      return row<T, default_value>(*this, row_);
    }
    std::map<coord_t, value<T, default_value>> &get_points()
    {
      return m_points;
    }
    iterator begin()
    {
      return m_points.begin();
    }
    iterator end()
    {
      return m_points.end();
    }
    std::size_t size()
    {
      return m_points.size();
    }
    static std::tuple<int, int, int> make_tuple(std::pair<coord_t, value<T, default_value>> it)
    {
      int x = std::get<0>(it.first);
      int y = std::get<1>(it.first);
      T v =  it.second.get_value();

      return std::make_tuple(x, y, v);
    }

  private:
    std::map<coord_t, value<T, default_value>> m_points;
    int m_default_value = default_value;
};
