#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

int main(int argc, char **argv)
{
  int num_of_obs, num;
  int sum_sl_min = 0, sum_seconds = 0;
  bool sl = false;

  std::cin >> num_of_obs;

  while (std::cin >> num)
  {
    if (!sl)
    {
      sum_sl_min += num;
      sl = true;
    }
    else
    {
      sum_seconds += num;
      sl = false;
    }
  }

  double avg_min = sum_seconds / 60.0 / sum_sl_min;
  if (avg_min <= 1.0)
  {
    std::cout << "measurement error" << std::endl;
  }
  else
  {
    std::cout << std::fixed << std::setprecision(12);
    std::cout << avg_min << std::endl;
  }


  return 0;
}
