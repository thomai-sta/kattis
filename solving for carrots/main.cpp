#include <iostream>

int main(int argc, char **argv)
{
  int num = 0;
  int ind = 0;
  while (std::cin >> num)
  {
    ind++;
    if (ind == 2) break;
  }
  std::cout << num << std::endl;
  return 0;
}
