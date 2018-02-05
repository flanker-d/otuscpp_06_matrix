#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

using coord_t = std::tuple<int, int>;
class matrix;

class value
{
  public:
    value(matrix* matrix_, int val_);
    value(matrix* matrix_);
    void set_row_col(int row_, int col_);
    void operator=(const int& val);
    friend std::ostream& operator<<(std::ostream& os, const value& obj);
  private:
    matrix* m_matrix;
    int m_value = -1;
    int m_row;
    int m_col;
};
