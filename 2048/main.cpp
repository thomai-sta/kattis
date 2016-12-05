#include "move.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
  int **game_state;
  game_state = new int*[ROWS];
  for (int r = 0; r < ROWS; r++)
  {
    game_state[r] = new int[COLS];
  }

  int num, idx = 0, move_direction;

  while(std::cin >> num)
  {
    if (idx == 16)
    {
      move_direction = num;
    }
    else
    {
      game_state[(int) idx / COLS][idx % COLS] = num;
    }
    idx++;
  }

  move obj;
  obj.make_move(game_state, move_direction);

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      std::cout << game_state[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
