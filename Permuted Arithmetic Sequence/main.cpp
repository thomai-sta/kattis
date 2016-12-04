#include "arithm_seq.hpp"

int main(int argc, char **argv)
{
  int num_of_seq;

  std::cin >> num_of_seq;
  std::vector<std::vector<int> > sequences;
  int seq_len, num;

  while (std::cin >> seq_len)
  {
    std::vector <int> temp;
    for (int i = 0; i < seq_len; i++)
    {
      std::cin >> num;
      temp.push_back(num);
    }
    sequences.push_back(temp);
  }
  arithm_seq object;
  object.check_if_arithmetic(sequences);


  return 0;
}
