#include <iostream>
#include "node.hpp"
#include "graph.hpp"

int main() {
  int numVertices;
  std::cin >> numVertices;

  Graph* graph = new Graph(numVertices);

  for(int i = 0; i < numVertices; i++){
    graph->getMembers()[i].setLabel(i);
  }
    
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
  std:: cout << "Label: "<< graph->getMembers()[i].getLabel() << 
  " colour: " <<
  graph->getMembers()[i].getColour() << std::endl;
}

std::cout << std::endl;

graph->bubbleSort();

/*for(int i = 0; i < graph->getMembers()[1].getNumNeighbours(); i++)
  std::cout << graph->getMembers()[1].getNeighbours()[i] << " " << std::endl;*/
for(int i = 0; i < numVertices; i++) 
  std::cout << graph->getMembers()[i].getColour() << " ";
std::cout << std::endl;
delete graph;

return 0;
}
/*6
3 1 2 3
3 0 2 4
3 0 1 5
1 0
1 1
1 2
1 2 3 2 1 1
*/

