#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "row.h"
#include "value.h"

using coord_t = std::tuple<int, int>;

template<typename T>
class row;

template<typename T>
class matrix
{
    using iterator = typename std::map<coord_t, value<T>>::iterator;

  public:
    row<T> operator[](int row_)
    {
      return row<T>(*this, row_);
    }
    std::map<coord_t, value<T>> &get_points()
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
    static std::tuple<int, int, int> make_tuple(std::pair<coord_t, value<T>> it)
    {
      int x = std::get<0>(it.first);
      int y = std::get<1>(it.first);
      T v =  it.second.get_value();

      return std::make_tuple(x, y, v);
    }

  private:
    std::map<coord_t, value<T>> m_points;
};
