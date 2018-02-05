#include "matrix.h"

row matrix::operator[](int row_)
{
  return row(*this, row_);
}

std::map<coord_t, value>& matrix::get_points()
{
  return m_points;
}

matrix::iterator matrix::begin()
{
  return m_points.begin();
}

matrix::iterator matrix::end()
{
  return m_points.end();
}

std::size_t matrix::size()
{
  return m_points.size();
}

std::tuple<int, int, int> matrix::make_tuple(std::pair<coord_t, value> it)
{
  int x = std::get<0>(it.first);
  int y = std::get<1>(it.first);
  int v =  it.second.get_value();

  return std::make_tuple(x, y, v);
}
