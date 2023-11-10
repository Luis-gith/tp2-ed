#include <iostream>
#include "node.hpp"
#include "graph.hpp"

int main() {
  char mode;
  int numVertices;
  std::cin >> mode >> numVertices;
  //std::cin >> numVertices;

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

  if(/*graph->greedy() == false*/0){
    std::cout << 0 << std::endl;
  } 
  else {
    std::cout << 1 << " ";
    switch (mode) {
      case 'b':
        graph->bubbleSort();
        break;

      case 's':
        graph->selectionSort();
        break;

      case 'i':
        graph->insertionSort();
        break;

      case 'q':
        graph->quickSort( 0, (numVertices - 1) );
        break;

      case 'm':
        graph->mergeSort( 0, (numVertices - 1) );
        break;

      /*case 'p':
        graph->heapSort();
        break;*/

      default:
        break;
    }

    for(int i = 0; i < numVertices; i++) 
    std::cout << graph->getMembers()[i].getLabel() << " ";
  }

  graph->getMembers()[1].getNeighbours()[1];
  // this->getMembers()[i].getNeighbours()[i];
    
  std::cout << std::endl;

  delete graph;

  return 0;
}


/*

TESTES 

b 6
3 1 2 3
3 0 2 4
3 0 1 5
1 0
1 1
1 2
1 2 3 2 1 1
r: 0 4 5 1 3 2


b 5
2 1 4
2 0 2
2 1 3
2 2 4
2 0 3
1 2 1 3 2
r: 0 2 1 4 3

p 6
3 1 2 3
3 0 2 4
3 0 1 5
1 0
1 1
1 2
1 2 3 2 1 1
r: 0 4 5 1 3 2

q 6
3 1 2 3
3 0 2 4
3 0 1 5
1 0
1 1
1 2
1 2 3 3 1 1
r: 0
*/

/*for(int i = 0; i < graph->getMembers()[1].getNumNeighbours(); i++)
  std::cout << graph->getMembers()[1].getNeighbours()[i] << " " << std::endl;*/