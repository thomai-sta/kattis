#include "tsp.hpp"

/**
 *  Solving the traveling salesman problem using nearest neighbors
 */


int main(int argc, char **argv)
{
  int num_of_cities;
  float coordinate;
  bool one = false;
  std::pair<float, float> temp;

  std::vector<std::pair<float, float> > coordinates;
  std::cin >> num_of_cities;

  while (std::cin >> coordinate)
  {
    if (!one)
    {
      temp.first = coordinate;
      one = true;
    }
    else
    {
      temp.second = coordinate;
      coordinates.push_back(temp);
      one = false;
    }
  }

  tsp salesman(num_of_cities, coordinates);
  salesman.get_print_list();

  return 0;
}
