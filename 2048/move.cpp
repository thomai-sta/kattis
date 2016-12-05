#include "move.hpp"

void move::rotate(int ** matrix, int times)
{
  for (int t = 0; t < times; t++)
  {
    for(int r = 0; r < ROWS; r++) {
      for(int c = r; c < COLS; c++) {
        std::swap(matrix[r][c], matrix[c][r]);
      }
    }
    /// Reverse Columns
    for(int c =0; c < COLS; c++) {
      for(int r = 0; r < ROWS / 2; r++) {
        std::swap(matrix[r][c], matrix[ROWS - r - 1][c]);
      }
    }
  }
  return;
}

void move::make_move(int **game_state, int m)
{
  /// Rotate game_state and perform left move, then rotate back
  rotate(game_state, m);

  int **new_num;
  new_num = new int *[ROWS];
  for (int i = 0; i < ROWS; i++)
  {
    new_num[i] = new int[COLS];
    for (int j = 0; j < COLS; j++)
    {
      new_num[i][j] = 0;
    }
  }

  for (int r = 0; r < ROWS; r++)
  {
    bool row_done = false;
    while(!row_done)
    {
      bool change = false;
      for (int c = 0; c < COLS - 1; c++)
      {
        if (game_state[r][c] == 0 && game_state[r][c + 1] != 0)
        {
          std::swap(game_state[r][c + 1], game_state[r][c]);
          std::swap(new_num[r][c + 1], new_num[r][c]);
          change = true;
        }
        else if (game_state[r][c + 1] == game_state[r][c] &&
         new_num[r][c + 1] == 0 &&
         new_num[r][c] == 0)
        {
          game_state[r][c] *= 2;
          game_state[r][c + 1] = 0;
          new_num[r][c] = 1;
          change = true;
        }
      }

      if (!change)
      {
        row_done = true;
      }
    }
  }

  /// Rotate game_state to its original state
  rotate(game_state, 4 - m);

  return;
}
