#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int num, nom, denom;
  std::vector<int> numbers;
  while (std::cin >> num)
  {
    numbers.push_back(num);
  }
  for (size_t i = 0; i < numbers.size() - 2; i += 2)
  {
    nom = numbers.at(i);
    denom = numbers.at(i + 1);
    std::cout << (int) nom / denom << " " << nom % denom << " / " << denom <<
     "\n";
  }
  return 0;
}
