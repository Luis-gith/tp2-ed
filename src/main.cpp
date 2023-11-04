#include <iostream>
#include "node.hpp"

int main(int argc, char const *argv[]) {
  int size = atoi(argv[1]);
  Graph* graph = new Graph(size);
  Node* graphMembers = graph->getMembers();

  for (int i = 0; i < size; i++) {
    graphMembers[i].setLabel(1);
  }

  delete graph;

  return 0;
}
