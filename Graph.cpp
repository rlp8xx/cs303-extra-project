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
    #ifndef NDEBUG
    cout << i << ": " << this->node_names[i] << ":" << endl;
    #else
    cout << this->node_names[i] << ":" << endl;
    #endif
    for (pair<int, string> edge : this->edges[i]) {
      cout << "\t" << edge.second << ": " << edge.first << endl;
    }
  }
}

void Graph::add_node(string name) {
  #ifndef NDEBUG
  cout << "Adding node: " << name << endl;
  #endif
  this->node_names.push_back(name);
  this->edges.push_back(vector<pair<int,string> >());
}

void Graph::add_edge(string node1, string node2, int distance) {
  #ifndef NDEBUG
  cout << "Adding edge between " << node1 << " and " << node2 << " of distance " << distance << endl;
  #endif
  // search for the nodes in the node_names list
  int idx_node1 = this->find_idx(node1);
  int idx_node2 = this->find_idx(node2);

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

// Returns the index of a node if it's in the graph
// returns -1 if not found
int Graph::find_idx(string node) {
  for (int i = 0; i < this->node_names.size(); i++) {
    if (this->node_names[i].compare(node) == 0) {
      return i;
    }
  }
  return -1;
}

vector<string> Graph::get_shortest_path(string node1, string node2) {
  #ifndef NDEBUG
  cout << "Getting shortest path between " << node1 << " and " << node2 << endl;
  #endif

  // init empty set of vertices included in shortest path
  vector<string> shortest_path = vector<string>();
  // init set of distances to 'infinite'
  // this is parallel to the edges and node_names vectors
  vector<int> distances(this->node_names.size(), INT_MAX);
  // set distance of start node to 0
  int idx_node1 = this->find_idx(node1);
  int idx_node2 = this->find_idx(node2);
  distances[idx_node1] = 0;
   
  int min_elem_idx;
  do {
    #ifndef NDEBUG
    cout << "Finding min distance elem not in shortest_path" << endl;
    #endif
    // get the minimum distance elem
    min_elem_idx = -1;
    int min = INT_MAX;
    for (int i = 0; i < distances.size(); i++) {
      // if shortest_path set is empty, don't check it with find
      if (shortest_path.empty()) {
        #ifndef NDEBUG
        cout << "shortest_path set empty, finding min elem" << endl;
        #endif
        if (distances[i] < min) {
          #ifndef NDEBUG
          cout << "Found new min at index: " << i << ", " << node_names[i] << endl;
          #endif
          min = distances[i];
          min_elem_idx = i;
        }
      } else {
        #ifndef NDEBUG
        cout << "Shortest_path not empty, finding min elem" << endl;
        #endif
        if (distances[i] < min && find(shortest_path.begin(), shortest_path.end(), node_names[i]) != shortest_path.end()) {
          #ifndef NDEBUG
          cout << "Found new min at index: " << i << ", " << node_names[i] << endl; 
          #endif
          min = distances[i];
          min_elem_idx = i;
        }
      }
    }
    if (min_elem_idx == -1) {
      cout << "Error while finding minimum distance element" << endl;
      return vector<string>();
    }

    #ifndef NDEBUG
    cout << "Minimum element idx: " << min_elem_idx << " Min elem: " << this->node_names[min_elem_idx] << endl;
    #endif 
    shortest_path.push_back(this->node_names[min_elem_idx]);
    // update distances for all connected nodes
    int other_idx;
    for (pair<int,string> edge : this->edges[min_elem_idx]) {
      other_idx = this->find_idx(edge.second);
      if (distances[min_elem_idx] + edge.first < distances[other_idx]) {
        #ifndef NDEBUG
        cout << "Updating distance for: " << edge.second << " Distance: " << distances[min_elem_idx] + edge.first << endl;
        #endif
        distances[other_idx] = edge.first + distances[min_elem_idx];
      }
    }
    // set distance to inf after selection so it wont get picked again
    distances[min_elem_idx] = INT_MAX;
  } while (min_elem_idx != idx_node2);
  return shortest_path;
}
