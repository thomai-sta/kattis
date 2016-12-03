#include "tsp.hpp"


tsp::tsp(int num_of_cities, std::vector <std::pair <float, float> > coordinates)
{
  this->num_of_cities = num_of_cities;
  this->coordinates = coordinates;
  // Calculate all distances
  for (int city = 0; city < num_of_cities; city++)
  {
    std::pair<float, float> city_coord = coordinates[city];
    std::vector<int> temp_vec;
    for (int destination = 0; destination < num_of_cities; destination++)
    {
      std::pair<float, float> dest_coord = coordinates[destination];
      int dist = sqrt(pow(city_coord.first - dest_coord.first, 2) +
        pow(city_coord.second - dest_coord.second, 2));
      temp_vec.push_back(dist);
    }
    distances.push_back(temp_vec);
  }
}

/**
 * Randomly start from a city. Then calculate next city using nearest neighbors
 */

void tsp::get_print_list()
{
  std::vector <int> unvisited_cities;
  for (int i = 0; i < num_of_cities; i++)
  {
    unvisited_cities.push_back(i);
  }

  srand (time(NULL));

  std::vector <int> route;
  int last_visit = rand() % num_of_cities;
  route.push_back(last_visit);
  unvisited_cities.erase(std::remove(unvisited_cities.begin(),
                                     unvisited_cities.end(), last_visit),
                                     unvisited_cities.end());

  /// Nearest neighbor for last_visit, to find next:
  int nearest = -1, shortest_dist = std::numeric_limits<int>::max();

  while (unvisited_cities.size() > 0)
  {
    for (size_t i = 0; i < unvisited_cities.size(); i++)
    {
      if (distances[last_visit][unvisited_cities[i]] < shortest_dist)
      {
        shortest_dist = distances[last_visit][unvisited_cities[i]];
        nearest = unvisited_cities[i];
      }
    }
    last_visit = nearest;
    route.push_back(last_visit);
    unvisited_cities.erase(std::remove(unvisited_cities.begin(),
                                       unvisited_cities.end(), last_visit),
                                       unvisited_cities.end());
    nearest = -1;
    shortest_dist = std::numeric_limits<int>::max();
  }

  /// Print route
  for (size_t i = 0; i < route.size(); i++)
  {
    std::cout << route[i] << std::endl;
  }
}