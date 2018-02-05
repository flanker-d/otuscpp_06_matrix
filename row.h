#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "matrix.h"
#include "value.h"

template<typename T, int default_value>
class matrix;

template<typename T, int default_value>
class row
{
  public:
    value<T, default_value>& operator[](int col)
    {
      coord_t coord = std::make_tuple(m_row, col);
      auto found = m_matrix.get_points().find(coord);
      if(found != m_matrix.get_points().end())
      {
        found->second.set_row_col(m_row, col);
        return found->second;
      }
      else
      {
        m_new_cell.set_row_col(m_row, col);
        return m_new_cell;
      }
    }
    row(matrix<T, default_value> &matrix_, int row_)
      : m_matrix(matrix_)
      , m_row(row_)
      , m_new_cell(value<T, default_value>(m_matrix, default_value))
    {
    }
  private:
    matrix<T, default_value>& m_matrix;
    int m_row;
    value<T, default_value> m_new_cell;// = value<T, default_value>(m_matrix, -1);
};

