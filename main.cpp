#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
  CMatrix matr;
  const int SIZE = 10;
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      if(i == j)
        matr[i][j] = j;
    }
  }

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      if((i + j) == (SIZE - 1))
        matr[i][j] = j;
    }
  }

  matr[4][4] = -1;
  matr[4][4] = 4;

  for(int i = 1; i < SIZE-1; i++)
  {
    for(int j = 1; j < SIZE-1; j++)
    {
      std::cout << matr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
