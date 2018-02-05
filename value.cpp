#include "value.h"
#include "matrix.h"

value::value(matrix& matrix_, int val_)
  : m_matrix(matrix_)
  , m_value(val_)
{
}

value::value(matrix& matrix_)
  : m_matrix(matrix_)
  , m_value(-1)
{
}

void value::set_row_col(int row_, int col_)
{
  m_row = row_;
  m_col = col_;
}

void value::operator=(const int& val)
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

int value::get_value()
{
  return m_value;
}

std::ostream& operator<<(std::ostream& os, const value& obj)
{
  if(obj.m_value == -1)
    os << "0";
  else
    os << obj.m_value;
  return os;
}
