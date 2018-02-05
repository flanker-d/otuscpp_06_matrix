#include "row.h"

value&row::operator[](int col)
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
    m_default_value.set_row_col(m_row, col);
    return m_default_value;
  }
}

row::row(matrix& matrix_, int row_) :
  m_matrix(matrix_),
  m_row(row_)
{}
