#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Graph {
  public:
    Graph();
    void print_data();
    void add_node(string name);
    void add_edge(string node1, string node2, int distance);
    vector<string> get_shortest_path(string node1, string node2);
  private:
    int find_idx(string node);
    // parallel vectors for edges and names
    vector<vector<pair<int, string> > > edges;
    vector<string> node_names;
};

#endif
