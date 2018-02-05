#include "matrix.h"

row matrix::operator[](int row_)
{
  return row(*this, row_);
}

std::map<coord_t, value>& matrix::get_points()
{
  return m_points;
}
