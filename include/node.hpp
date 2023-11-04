#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node {
  friend class Graph;
  public:
    Node();
    void setLabel(int newLabel);
  private:
    int label;
    int colour;
    Node* neighbours;
};

class Graph {
  public:
    Graph(int size);
    ~Graph();
    Node* getMembers();

  private:
    int size;
    Node* members;
};

#endif
