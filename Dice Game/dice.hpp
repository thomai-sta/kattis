#ifndef _DICE_HPP_
#define _DICE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

class dice
{
public:
        int g1_low, g1_high, e1_low, e1_high, g2_low, g2_high, e2_low, e2_high;
        std::vector<int> g_sums, e_sums;

        dice(std::vector<int> values);
        std::vector<int> calc_sums(int low1, int high1, int low2, int high2);
        std::string get_winner();

};

#endif
