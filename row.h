#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "matrix.h"
#include "value.h"

template<typename T>
class matrix;

template<typename T>
class row
{
  public:
    value<T>& operator[](int col)
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
    row(matrix<T> &matrix_, int row_) :
      m_matrix(matrix_),
      m_row(row_)
    {
    }
  private:
    matrix<T>& m_matrix;
    int m_row;
    value<T> m_new_cell = value<T>(m_matrix);
};

