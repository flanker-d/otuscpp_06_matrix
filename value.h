#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

using coord_t = std::tuple<int, int>;

template<typename T, int default_value>
class matrix;

template<typename T, int default_value>
class value
{
  public:
    value(matrix<T, default_value>& matrix_, int val_)
      : m_matrix(matrix_)
      , m_value(val_)
    {
    }
    void set_row_col(int row_, int col_)
    {
      m_row = row_;
      m_col = col_;
    }
    void operator=(const int& val)
    {
      coord_t coord = std::make_tuple(m_row, m_col);
      if(val == default_value)
      {
        auto it = m_matrix.get_points().find(coord);
        if(it != m_matrix.get_points().end())
          m_matrix.get_points().erase(it);
      }
      else
        m_matrix.get_points().insert(std::make_pair(coord, value(m_matrix, val)));
    }
    friend bool operator==(value<T, default_value>& lhs, const T& rhs)
    {
      return lhs.get_value() == rhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const value<T, default_value>& obj)
    {
      if(obj.m_value == default_value)
        os << default_value;
      else
        os << obj.m_value;
      return os;
    }

    T get_value()
    {
      return m_value;
    }

  private:
    matrix<T, default_value>& m_matrix;
    T m_value = default_value;
    int m_row;
    int m_col;
};
