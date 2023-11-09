#include "node.hpp"
#include "graph.hpp"

void Node::setColour(int newColour) {
  colour = newColour;
}

Graph::Graph(int size) {
  this->size = size;
  this->members = new Node[size];

  for (int i = 0; i < size; i++)
    this->members[i].neighbours = nullptr;
  
}

Graph::~Graph() {
  for (int i = 0; i < size; i++) {
    if (members[i].neighbours != nullptr)
      delete[] members[i].neighbours;   
  }

  delete[] members;
}

Node* Graph::getMembers() {
  return this->members;
}

void Graph::bubbleSort() {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      int color1 = members[j].getColour();
      int color2 = members[j + 1].getColour();

      if (color1 > color2) std::swap(members[j], members[j + 1]);

      else if (color1 == color2) {
        if (members[j].getLabel() > members[j + 1].getLabel())
          std::swap(members[j], members[j + 1]);
      }
    }
  }
}


void Graph::selectionSort() {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      int color1 = members[j].getColour();
      int color2 = members[minIndex].getColour();

      if (color1 < color2) {
        minIndex = j;
      }
      else if (color1 == color2) {
        if (members[j].getLabel() < members[minIndex].getLabel()) {
          minIndex = j;
        }
      }
    }

    if (minIndex != i) {
      std::swap(members[i], members[minIndex]);
    }
  }
}


