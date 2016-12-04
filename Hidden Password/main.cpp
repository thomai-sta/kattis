#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
  std::string password, message;

  std::cin >> password;
  std::cin >> message;
  int *letter_positions = new int[password.size()];
  for (size_t i = 0; i < password.size(); i++)
  {
    letter_positions[i] = -1;
  }

  bool fail = false;
  size_t letter = 0;

  while (letter < password.size() && !fail)
  {
    size_t msg_idx = 0;
    if (letter > 0)
    {
      msg_idx = letter_positions[letter - 1] + 1;
    }
    while (msg_idx < message.size() && letter_positions[letter] == -1)
    {
      if (password[letter] == message[msg_idx])
      {
        letter_positions[letter] = msg_idx;
        /// Password letter found within the message
        /// Need to check that the following pass characters have not been
        /// present previously in the message
        int begin = 0, end = letter_positions[letter];
        if (letter > 0)
        {
          begin = letter_positions[letter - 1] + 1;
        }
        for (size_t i = letter + 1; i < password.size(); i++)
        {
          for (int j = begin; j < end; j++)
          {
            if (password[i] == message[j])
            {
              fail = true;
            }
          }
        }
      }
      msg_idx++;
    }
    if (letter_positions[letter] == -1)
    {
      /// Password letter not found within the message
      fail = true;
    }
    letter++;
  }

  if (!fail)
  {
    std::cout << "PASS" << std::endl;
  }
  else
  {
    std::cout << "FAIL" << std::endl;
  }

  return 0;
}
