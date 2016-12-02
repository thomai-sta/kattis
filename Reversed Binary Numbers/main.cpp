#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h> 
#include <algorithm>

int main(int argc, char **argv)
{
  // int num = atoi(argv[1]);
  int num = 0;
  std::cin >> num;

  // Convert number to binary
  std::vector<int> binary;

  while (num / 2 != 0)
  {
    binary.push_back(num % 2);
    num = num / 2;
  }
  if (num) 
  {
    binary.push_back(1);
  }
  // Now vector binary contains th reversed binary number from binary.start() 
  // -> binary.end()
  int reversed_num = 0;
  std::reverse(binary.begin(), binary.end()); 
  for (int i = 0; i < binary.size(); i++)
  {
    reversed_num += pow(2, i) * binary.at(i);
  }
  std::cout << reversed_num << "\n";
  
  return 0;
}
