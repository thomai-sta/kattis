#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  std::vector<std::string> values;
  std::string word, decoded_phrase;
  while (std::cin >> word)
  {
    int letters = word.size();
    for (int i = 0; i < letters; i++)
    {
      decoded_phrase.push_back(word.at(i));
      if ((word.at(i) == 'a') || (word.at(i) == 'e') || (word.at(i) == 'i') ||
        (word.at(i) == 'o') || (word.at(i) == 'u'))
      {
          i += 2;
      }
    }
    decoded_phrase.push_back(' ');
  }
  decoded_phrase.erase(decoded_phrase.end() - 1);
  std::cout << decoded_phrase << "\n";
  return 0;
}
