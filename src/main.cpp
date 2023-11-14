#include <iostream>
#include <stdexcept>
#include <chrono>
#include "node.hpp"
#include "graph.hpp"

using namespace std::chrono;

int main() {
  char mode;
  int numVertices;
  try {
    std::cin >> mode >> numVertices;

    if (std::cin.fail() || numVertices <= 0)
        throw std::invalid_argument("Invalid input for mode or number of vertices"); 
  } 
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1; 
  }

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

  auto start = high_resolution_clock::now();

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

    case 'p':
        graph->heapSort();
        break;
      
    case 'y':
      graph->timSort();
      break;
      

    default:
      std::cerr << "Invalid sorting mode" << std::endl;
      return 1; 
  }
    if(graph->greedy()){
      std::cout << 1 << " ";
      for(int i = 0; i < numVertices; i++) 
      std::cout << graph->getMembers()[i].getLabel() << " ";
    }
    else std::cout << 0;


  std::cout << std::endl;

  delete graph;
  auto stop = std::chrono::high_resolution_clock::now();


  auto duration = duration_cast<microseconds>(stop - start);

  std::cout << std::endl << "tempo:" << duration.count() << std::endl;

  return 0;
}