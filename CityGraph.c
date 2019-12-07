#include <vector>
#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
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
  vector<string> shortest_path = city_map.get_shortest_path("Seattle", "Denver");
  for (string city : shortest_path) {
    cout << city << " ";
  }
  cout << endl;
}
