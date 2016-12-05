#ifndef _MOVE_HPP_
#define _MOVE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ROWS 4
#define COLS 4

class move
{
public:
  void rotate(int ** matrix, int times);
  void make_move(int **matrix, int m);

};

#endif
