#include "node.hpp"
#include <stdexcept>

Node::Node() {
  this->label = 0;
  this->colour = 0;
  this->neighbours = nullptr;
  this->numNeighbours = 0;
}

void Node::setLabel(int newLabel) {
  this->label = newLabel;
}

void Node::setColour(int newColour) {
  this->colour = newColour;
}

int Node::getColour() {
  return this->colour;
}

int Node::getLabel() {
  return this->label;
}

int* Node::getNeighbours() {
  if(this->neighbours == nullptr)
    throw::std::logic_error("Neighbours is null");

  return this->neighbours;
}

int Node::getNumNeighbours() {
  return this->numNeighbours;
}

void Node::addNeighbour(int auxLabel) {
  if (neighbours == nullptr) {
    neighbours = new int[1];
    if (!neighbours) {
        throw std::bad_alloc();  // Memory allocation failed
    }
  }
  else {
    int* temp = new int[numNeighbours + 1];
    for (int i = 0; i < numNeighbours; i++) 
      temp[i] = neighbours[i];

    delete[] neighbours;
    neighbours = temp;
  }
  
  neighbours[numNeighbours++] = auxLabel;
}
