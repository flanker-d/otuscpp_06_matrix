#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

using coord_t = std::tuple<int, int>;

template<typename T>
class matrix;

template<typename T>
class value
{
  public:
    value(matrix<T>& matrix_, int val_)
      : m_matrix(matrix_)
      , m_value(val_)
    {
    }
    value(matrix<T>& matrix_)
      : m_matrix(matrix_)
      , m_value(-1)
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
      if(val == -1)
      {
        auto it = m_matrix.get_points().find(coord);
        if(it != m_matrix.get_points().end())
          m_matrix.get_points().erase(it);
      }
      else
        m_matrix.get_points().insert(std::make_pair(coord, value(m_matrix, val)));
    }

    friend std::ostream& operator<<(std::ostream& os, const value<T>& obj)
    {
      if(obj.m_value == -1)
        os << "0";
      else
        os << obj.m_value;
      return os;
    }

    int get_value()
    {
      return m_value;
    }

  private:
    matrix<T>& m_matrix;
    T m_value = -1;
    int m_row;
    int m_col;
};
