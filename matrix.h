#pragma once
#include <map>
#include <tuple>
#include <algorithm>
#include <iostream>

using coord_t = std::tuple<int, int>;
class CMatrix;
class value
{
    friend class CMatrix;
  public:
    value();
    value(CMatrix* matrix, int val);
    value(CMatrix* matrix);
    void set_row_col(int row, int col);
    void operator=(const int& val);
    friend std::ostream& operator<<(std::ostream& os, const value& obj)
    {
      if(obj.m_value == -1)
        os << "*";
      else
        os << obj.m_value;
      return os;
    }
  private:
    CMatrix* m_matrix;
    int m_value = -1;
    int m_row;
    int m_col;
};

class CRow
{
    friend class CMatrix;
  public:
    value& operator[](int col);
  private:
    CRow(CMatrix &parent_, int row_);

    CMatrix& parent;
    int row;
    value default_value = value(&parent);
};


class CMatrix
{
    friend class CRow;
  public:
    CRow operator[](int row);
    std::map<coord_t, value> &points();
  private:
    int rows, cols;
    std::map<coord_t, value> m_points;
};
