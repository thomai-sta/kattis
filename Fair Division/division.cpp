#include "division.hpp"

bool division::is_possible(int amount, std::vector<int> contributions)
{
  if (std::accumulate(contributions.begin(), contributions.end(), 0) < amount)
  {
    return false;
  }
  else
  {
    return true;
  }
}

std::vector<int> division::fair_division(int amount, std::vector<int> max_contr)
{
  if (std::accumulate(max_contr.begin(), max_contr.end(), 0) == amount)
  {
    return max_contr;
  }

  /// First sort max_contr in ascending order and keep initial indexing to put it back
  std::vector<int> init_idx;
  std::vector<int> contr;
  for (size_t i = 0; i < max_contr.size(); i++)
  {
    int temp = *std::max_element(max_contr.begin(), max_contr.end());
    int idx = std::distance(max_contr.begin(),
                            std::find(max_contr.begin(),
                                      max_contr.end(),
                                      temp));
    init_idx.push_back(idx);
    contr.push_back(temp);
    max_contr[idx] = 0;
  }
  std::reverse(contr.begin(), contr.end());

  /// Calculate contributions
  int current_max = contr.back(), idx;
  while(std::accumulate(contr.begin(), contr.end(), 0) > amount)
  {
    idx = std::distance(contr.begin(),
                        std::find(contr.begin(),
                                  contr.end(),
                                  current_max));
    contr[idx]--;
    current_max = contr.back();
  }

  /// Put contr order back
  // std::vector<int> final;
  for (int i = init_idx.size() - 1; i >= 0; i--)
  {
    // final.push_back(contr[init_idx[i]]);
    std::cout << contr[init_idx[i]] << " ";
  }
  std::cout << std::endl;
  // std::reverse(final.begin(), final.end());

  return contr;
}