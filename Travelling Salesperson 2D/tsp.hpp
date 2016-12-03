#ifndef _TSP_HPP_
#define _TSP_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <limits>

class tsp
{
public:
  int num_of_cities;
  std::vector<std::pair <float, float> > coordinates;
  std::vector<std::vector<int> > distances;

  tsp(int num_of_cities, std::vector <std::pair <float, float> > coordinates);
  void get_print_list();

};

#endif
