#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

#include "Graph.h"

using namespace std;

Graph::Graph() {
  this->edges = vector<vector<pair<int,string> > >();
  this->node_names = vector<string>();
}

void Graph::print_data() {
  for (int i = 0; i < this->node_names.size(); i++) {
    cout << this->node_names[i] << ":" << endl;
    for (pair<int, string> edge : this->edges[i]) {
      cout << "\t" << edge.second << ": " << edge.first << endl;
    }
  }
}

void Graph::add_node(string name) {
  cout << "Adding node: " << name << endl;
  this->node_names.push_back(name);
  this->edges.push_back(vector<pair<int,string> >());
}

void Graph::add_edge(string node1, string node2, int distance) {
  cout << "Adding edge between " << node1 << " and " << node2 << " of distance " << distance << endl;
  // search for the nodes in the node_names list
  int idx_node1 = -1;
  int idx_node2 = -1;
  for (int idx = 0; idx < this->node_names.size(); idx++) {
    // check if either node found
    if (this->node_names[idx].compare(node1) == 0) {
      idx_node1 = idx;
    }
    if (this->node_names[idx].compare(node2) == 0) {
      idx_node2 = idx;
    }
    // if both are found, break
    if (idx_node1 != -1 && idx_node2 != -1) break;
  }

  // make sure nodes found
  if (idx_node1 == -1 || idx_node2 == -1) {
    cout << "Error adding edge: could not find specified nodes in graph" << endl;
    return;
  }
  
  // add pairs to each node's edge list
  pair<int,string> pair1(distance, node2);
  pair<int,string> pair2(distance, node1);
  this->edges[idx_node1].push_back(pair1);
  this->edges[idx_node2].push_back(pair2);
}

vector<string> Graph::get_shortest_path(string node1, string node2) {

}
