#include <vector>
#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

void print_path(vector<string> path) {
  cout << path[0];
  for (int i = 1; i < path.size(); i++) {
    cout << " --> " << path[i];
  }
  cout << endl;
}

int main() {
  // init the data
  Graph city_map = Graph();
  city_map.add_node("Kansas City");
  city_map.add_node("Denver");
  city_map.add_node("San Francisco");
  city_map.add_node("Seattle");
  city_map.add_node("Chicago");
  city_map.add_node("New York");
  city_map.add_node("Miami");

  city_map.add_edge("Kansas City", "Denver", 605);
  city_map.add_edge("Kansas City", "San Francisco", 1802);
  city_map.add_edge("Kansas City", "Seattle", 1835);
  city_map.add_edge("Denver", "San Francisco", 1255);
  city_map.add_edge("Denver", "Miami", 2062);
  city_map.add_edge("San Francisco", "Chicago", 2128);
  city_map.add_edge("Chicago", "New York", 790);
  city_map.add_edge("Chicago", "Miami", 1380);
  city_map.add_edge("Miami", "New York", 1286);
  city_map.add_edge("New York", "Seattle", 2869);
  city_map.add_edge("Seattle", "San Francisco", 808);

  city_map.print_data();

  // get shortest paths
  vector<string> shortest_path = city_map.get_shortest_path("Seattle", "Denver");
  cout << "Shortest path from Seattle to Denver: ";
  print_path(shortest_path);
  shortest_path = city_map.get_shortest_path("San Francisco", "Kansas City");
  cout << "Shortest path from San Francisco to Kansas City: ";
  print_path(shortest_path);
}
