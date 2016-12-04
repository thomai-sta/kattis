#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{

  std::pair<unsigned long long int, unsigned long long int> numbers;
  unsigned long long int num;
  bool first = false;

  while(std::cin >> num)
  {
    if (!first)
    {
      numbers.first = num;
      first = true;
    }
    else
    {
      numbers.second = num;
      if (numbers.first >= numbers.second)
      {
        std::cout << numbers.first - numbers.second << std::endl;
      }
      else
      {
        std::cout << numbers.second - numbers.first << std::endl;
      }
      first = false;
    }
  }

  return 0;
}
