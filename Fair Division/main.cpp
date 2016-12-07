#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <numeric>

int main(int argc, char **argv)
{
  int num;
  std::cin >> num;
  std::vector<int> max_contr;
  int amount, n, sum, max_idx, current_max;

  while(std::cin >> amount)
  {
    std::cin >> n;
    max_contr.clear();
    sum = 0;
    for (int i = 0; i < n; i++)
    {
      std::cin >> num;
      max_contr.push_back(num);
      sum += num;
    }

    for (int times = 0; times < 100000; times++)
    {

      if (sum < amount)
      {
        std::cout << "IMPOSSIBLE" << std::endl;
      }
      else if (sum == amount)
      {
        for (size_t i = 0; i < max_contr.size(); i++)
        {
          std::cout << max_contr[i] << " ";
        }
        std::cout << std::endl;
      }
      else
      {
        bool sorted = false;
        std::vector<int> init_idx;
        for (size_t i = 0; i < max_contr.size(); i++)
        {
          init_idx.push_back(i);
        }

        /// First sort max_contr in ascending order and keep initial indexing to put it back
        /// Bubblesort vector
        while(!sorted)
        {
          sorted = true;
          for(size_t j = 0; j < max_contr.size() - 1; j++)
          {
            if(max_contr[j] < max_contr[j + 1])
            {
              std::swap(max_contr[j + 1], max_contr[j]);
              std::swap(init_idx[j + 1], init_idx[j]);
              sorted = false;
            }
          }
        }
        std::reverse(max_contr.begin(), max_contr.end());

        /// Calculate contributions
        current_max = max_contr.back();
        while(sum > amount)
        {
          max_idx = std::distance(max_contr.begin(),
                                  std::find(max_contr.begin(),
                                            max_contr.end(),
                                            current_max));
          max_contr[max_idx]--;
          sum--;
          current_max = max_contr.back();
        }

        for (int i = init_idx.size() - 1; i >= 0; i--)
        {
          std::cout << max_contr[init_idx[i]] << " ";
        }
        std::cout << std::endl;
      }
    }
  }
  return 0;
}
