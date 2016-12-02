#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int max = 0;
  int winner = 0;
  int points = 0, player = 1, grade = 0, temp;
  while (std::cin >> temp)
  {
    grade++;
    points += temp;
    if (grade == 4) {
      if (points > max) {
        max = points;
        winner = player;
      }
      points = 0;
      player++;
      grade = 0;
    }
  }
  std::cout << winner << " " << max << "\n";
  return 0;
}
