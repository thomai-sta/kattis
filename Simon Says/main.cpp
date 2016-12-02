#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  std::string line, command = "simon says ";
  int i = 0;
  while(std::cin)
  {
    std::getline(std::cin, line);
    if (i == 0)
    {
      // This is the number of commands, do nothing
      i++;
    }
    else
    {
      // Check if the command begins with "Simon says"
      if (line.size() > command.size())
      {
        if (!line.compare(0, command.size(), command))
        {
          std::cout << line.substr(11, line.size() - command.size());
        }
      }
      std::cout << "\n";
    }
  }
  return 0;
}