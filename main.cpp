#include <iostream>
#include <assert.h>
#include "matrix.h"

using namespace std;

int main()
{
  const int default_value = 0;
  using type_t = int;
  const int matrix_size = 10;

  matrix<type_t, default_value> matr;
  assert(matr.size() == 0);

  auto a = matr[0][0];
  assert(a == default_value);
  assert(matr.size() == 0);

  matr[100][100] = 314;
  assert(matr[100][100] == 314);
  assert(matr.size() == 1);

  matr[100][100] = default_value;
  assert(matr[100][100] == default_value);
  assert(matr.size() == 0);

  for(int i = 0; i < matrix_size; i++)
  {
    for(int j = 0; j < matrix_size; j++)
    {
      if(i == j)
        matr[i][j] = j;
    }
  }

  for(int i = 0; i < matrix_size; i++)
  {
    for(int j = 0; j < matrix_size; j++)
    {
      if((i + j) == (matrix_size - 1))
        matr[i][j] = j;
    }
  }

  for(int i = 1; i < matrix_size-1; i++)
  {
    for(int j = 1; j < matrix_size-1; j++)
    {
      std::cout << matr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << matr.size() << std::endl;

  for(auto c : matr)
  {
    int x;
    int y;
    type_t v;
    std::tie(x, y, v) = matrix<type_t, default_value>::make_tuple(c);
    std::cout << x << " " << y << " " << v << std::endl;
  }

  return 0;
}
