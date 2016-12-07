#ifndef _DIVISION_HPP_
#define _DIVISION_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


class division
{
public:
  bool is_possible(int amount, std::vector<int> contributions);
  std::vector<int> fair_division(int amount, std::vector<int> max_contr);
};

#endif
