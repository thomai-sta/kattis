#include "dice.hpp"

int main(int argc, char **argv)
{
        std::vector<int> values;
        int num = 0;
        while (std::cin >> num)
        {
                values.push_back(num);
        }
        dice game(values);
        std::cout << game.get_winner() << "\n";
        return 0;
}
