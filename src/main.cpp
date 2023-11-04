#include <iostream>
#include "node.hpp"

int main() {
  int numVertices;
  std::cin >> numVertices;

  Graph* graph = new Graph(numVertices);

  for (int i = 0; i < numVertices; i++) {
    int numneighbours;
    std::cin >> numneighbours;

    for (int j = 0; j < numneighbours; j++) {
      int neighborId;
      std::cin >> neighborId;
      graph->getMembers()[i].addNeighbour(neighborId);
    }
}

for (int i = 0; i < numVertices; i++) {
  int colour;
  std::cin >> colour;
  graph->getMembers()[i].setColour(colour);
}

for (int i = 0; i < numVertices; i++) {
  std:: cout << graph->getMembers()[i].getColour() << std::endl;
}

delete graph;

return 0;
}
