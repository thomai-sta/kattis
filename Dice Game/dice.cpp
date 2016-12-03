#include "dice.hpp"

dice::dice(std::vector<int> values)
{
  g1_low = values.at(0);
  g1_high = values.at(1);
  g2_low = values.at(2);
  g2_high = values.at(3);
  e1_low = values.at(4);
  e1_high = values.at(5);
  e2_low = values.at(6);
  e2_high = values.at(7);

        // Calculate G's sums
  g_sums = calc_sums(g1_low, g1_high, g2_low, g2_high);
  sort(g_sums.begin(), g_sums.end());

        // Calculate E's sums
  e_sums = calc_sums(e1_low, e1_high, e2_low, e2_high);
  sort(e_sums.begin(), e_sums.end());
}

std::vector<int> dice::calc_sums(int low1, int high1, int low2, int high2)
{
  std::vector<int>  sums;
  for (int dice1 = low1; dice1 <= high1; dice1++)
  {
    for (int dice2 = low2; dice2 <= high2; dice2++)
    {
      sums.push_back(dice1 + dice2);
    }
  }
  return sums;
}


std::string dice::get_winner()
{
  // First Check if the winner is obvious
  if (e_sums.at(0) >= g_sums.back()) return "Emma";
  if (g_sums.at(0) >= e_sums.back()) return "Gunnar";

  int e_score = 0;
  int g_score = 0;
  for (size_t i = 0; i < e_sums.size(); i++)
  {
    for (size_t j = 0; j < g_sums.size(); j++)
    {
      if (e_sums.at(i) > g_sums.at(j))
      {
        e_score++;
      }
      else if (g_sums.at(j) > e_sums.at(i))
      {
        g_score++;
      }
    }
  }
  if (e_score == g_score)
  {
    return "Tie";
  }
  else if (e_score > g_score)
  {
    return "Emma";
  }
  else if (g_score > e_score)
  {
    return "Gunnar";
  }
  return "ERROR!";
}
