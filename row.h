#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

#include "matrix.h"
#include "value.h"

class matrix;

class row
{
  public:
    value& operator[](int col);
    row(matrix &matrix_, int row_);
  private:
    matrix& m_matrix;
    int m_row;
    value m_default_value = value(m_matrix);
};

