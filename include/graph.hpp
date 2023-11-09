#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"


class Graph {
  public:
    Graph(int size);
    ~Graph();
    Node* getMembers();
    void bubbleSort();

  private:
    int size;
    Node* members;
};


#endif

