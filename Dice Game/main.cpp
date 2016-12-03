#include "dice.hpp"

int main(int argc, char **argv)
{
  std::cout << "Started" << std::endl;
  std::vector<int> values;
  int num = 0;
  while (std::cin >> num)
  {
    values.push_back(num);
  }
  std::cout << values.size() << std::endl;
  if (values.size() == 0)
  {
    std::cout << "No values given" << std::endl;
    return 1;
  }
  dice game(values);
  std::cout << game.get_winner() << std::endl;
  return 0;
}
