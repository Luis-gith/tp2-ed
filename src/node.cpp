#include "node.hpp"

Node::Node() {
  this->label = 0;
  this->colour = 0;
  this->neighbours = nullptr;
  this->numNeighbours = 0;
}

void Node::setLabel(int newLabel) {
  this->label = newLabel;
}

void Node::addNeighbour(int auxLabel) {
  if (neighbours == nullptr) neighbours = new int[1];
   
  else {
    int* temp = new int[numNeighbours + 1];
    for (int i = 0; i < numNeighbours; i++) 
      temp[i] = neighbours[i];

    delete[] neighbours;
    neighbours = temp;
  }

  neighbours[numNeighbours++] = auxLabel;
}

int Node::getColour() {
  return this->colour;
}

int Node::getLabel() {
  return this->label;
}

int* Node::getNeighbours() {
  return this->neighbours;
}

int Node::getNumNeighbours() {
  return this->numNeighbours;
}