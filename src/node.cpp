#include "node.hpp"

Node::Node() {
  this->label = 0;
  this->colour = 0;
  this->neighbours = nullptr;
}

void Node::setLabel(int newLabel) {
  label = newLabel;
}

Graph::Graph(int size) {
  this->size = size;
  this->members = new Node[size];
  
  for (int i = 0; i < size; i++) {
      this->members[i].neighbours = nullptr;
  }
}

Graph::~Graph() {
  delete[] members;
}

Node* Graph::getMembers() {
  return members;
}
