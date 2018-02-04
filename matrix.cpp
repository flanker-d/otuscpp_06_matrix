#include "matrix.h"

value&CRow::operator[](int col)
{
  coord_t coord = std::make_tuple(row, col);
  auto found = parent.m_points.find(coord);
  if(found != parent.m_points.end())
  {
    found->second.set_row_col(row, col);
    return found->second;
  }
  else
  {
    default_value.set_row_col(row, col);
    return default_value;
  }
}

CRow::CRow(CMatrix& parent_, int row_) :
  parent(parent_),
  row(row_)
{}

CRow CMatrix::operator[](int row)
{
  return CRow(*this, row);
}

std::map<coord_t, value>&CMatrix::points()
{
  return m_points;
}

value::value() : m_value(-1)
{
}

value::value(CMatrix* matrix, int val)
  : m_matrix(matrix)
  , m_value(val)
{
}

value::value(CMatrix* matrix)
  : m_matrix(matrix)
{
}

void value::set_row_col(int row, int col)
{
  m_row = row;
  m_col = col;
}

void value::operator=(const int& val)
{
  coord_t coord = std::make_tuple(m_row, m_col);
  if(val == -1)
  {
    auto it = m_matrix->points().find(coord);
    if(it != m_matrix->points().end())
      m_matrix->points().erase(it);
  }
  else
    m_matrix->points().insert(std::make_pair(coord, value(m_matrix, val)));
}
