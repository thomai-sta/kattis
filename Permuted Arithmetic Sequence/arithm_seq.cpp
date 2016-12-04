#include "arithm_seq.hpp"

void arithm_seq::check_if_arithmetic(std::vector<std::vector<int> > sequences)
{
  for (size_t seq = 0; seq < sequences.size(); seq++)
  {
    std::vector<int> sequence = sequences[seq];

    /// First check for arithmetic as is
    bool arithmetic = true;
    size_t idx = 2;
    int diff = sequence[1] - sequence[0];

    while (arithmetic && idx < sequence.size())
    {
      if (sequence[idx] - sequence[idx - 1] != diff)
      {
        // Not arithmetic. Either permuted arithmetic or non-arithmetic
        arithmetic = false;
      }
      idx++;
    }

    /// Sort sequence to check for permuted
    std::sort (sequence.begin(), sequence.end());
    bool perm_arithmetic = true;
    idx = 2;
    diff = sequence[1] - sequence[0];

    while (perm_arithmetic && idx < sequence.size())
    {
      if (sequence[idx] - sequence[idx - 1] != diff)
      {
        perm_arithmetic = false;
      }
      idx++;
    }

    /// Print result
    if (arithmetic)
    {
      std::cout << "arithmetic" << std::endl;
    }
    else if (perm_arithmetic)
    {
      std::cout << "permuted arithmetic" << std::endl;
    }
    else
    {
      std::cout << "non-arithmetic" << std::endl;
    }

  }
}