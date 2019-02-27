/*
 * Graph.h
 *
 *  Created on: Feb 2, 2018
 *      Author: plocci
 */

#include <vector>

using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph{
  struct Vertex{
    int dest_node;
    double weight;
    bool operator <(const Vertex& rhs) const {
      return dest_node < rhs.dest_node;
    }
    bool operator <(const int rhs) const {
      return dest_node < rhs;
    }
    bool operator >(const int rhs) const {
      return dest_node > rhs;
    }

    bool is_same_node(const int rhs) const {
      return dest_node == rhs;
    }
  };
  struct Node{
    int source_node;
    vector<Vertex> vertexes;
    bool operator <(const Node& rhs) const {
      return source_node < rhs.source_node;
    }
    bool operator <(const int rhs) const {
      return source_node < rhs;
    }
    bool operator >(const int rhs) const {
      return source_node > rhs;
    }
    bool is_same_node(const int rhs) const {
      return source_node == rhs;
    }

  };

  Graph();

  void add_unidirectional_sorted(int v1, int v2, double weight = 1,
      bool newline = 0);

  vector<Node> graph;

public:
  virtual ~Graph();
  Graph(vector<vector<double> >);

  unsigned int V() const;
  unsigned int E() const;
  bool adjacent(int v1, int v2) const;
  vector<int> neighbors(int v1) const;
  void add_unidirectional(int v1, int v2, double weight = 1);
  void add_bidirectional(int v1, int v2, double weight = 1);
  void remove_unidirectional(int v1, int v2);
  void remove_bidirectional(int v1, int v2);
  double get_node_value(int v1, int v2) const;
  double set_node_value(int v1, int v2);
  void print_graph() const;
};

#endif /* GRAPH_H_ */
