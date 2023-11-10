#include "node.hpp"
#include "graph.hpp"
#include <cstring>


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

int Graph::getSize(){
  return this->size;
}

bool Graph::greedy() {
    // Array to keep track of used colors for each vertex
    int* usedColors = new int[size];

    for (int i = 0; i < size; i++) {
        Node& current = members[i];

        // Initialize used colors for the current vertex
        memset(usedColors, 0, size * sizeof(int));

        // Iterate through neighbors and mark their colors as used
        for (int j = 0; j < current.getNumNeighbours(); j++) {
            int neighborId = current.getNeighbours()[j];
            int neighborColor = members[neighborId].getColour();
            usedColors[neighborColor] = 1;
        }

        // Find the first available color for the current node
        int availableColor = 0;
        while (usedColors[availableColor] == 1) {
            availableColor++;
        }

        // Set the color for the current node
        current.setColour(availableColor);
    }

    delete[] usedColors;

    // Check for conflicts after coloring
    for (int i = 0; i < size; i++) {
        Node& current = members[i];

        for (int j = 0; j < current.getNumNeighbours(); j++) {
            int neighborId = current.getNeighbours()[j];
            if (current.getColour() == members[neighborId].getColour()) {
                // Invalid coloring, as adjacent vertices have the same color
                return false;
            }
        }
    }

    // If no conflicts were found, the coloring is valid
    return true;
}




void Graph::bubbleSort() {
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

void Graph::insertionSort() {
  for (int i = 1; i < size; i++) {
    Node current = members[i];
    int j = i - 1;

    while (j >= 0 && (members[j].getColour() > current.getColour() || 
                     (members[j].getColour() == current.getColour() && members[j].getLabel() > current.getLabel()))) {
      members[j + 1] = members[j];
      j--;
    }

    members[j + 1] = current;
  }
}

//needed for quicksort
int Graph::partition(int down, int up) {
  Node pivot = members[up];
  int i = down - 1;

  for (int j = down; j <= up - 1; j++) {
    int color1 = members[j].getColour();
    int color2 = pivot.getColour();

    if (color1 < color2 || (color1 == color2 && members[j].getLabel() < pivot.getLabel())) {
      i++;
      std::swap(members[i], members[j]);
    }
  }

  std::swap(members[i + 1], members[up]);
  return i + 1;
}

void Graph::quickSort(int down, int up) {
  if (down < up) {
    int pi = partition(down, up);

    quickSort(down, pi - 1);
    quickSort(pi + 1, up);
  }
}

//needed for mergesort
void Graph::merge(int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Node* L = new Node[n1];
  Node* R = new Node[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = members[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = members[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    int color1 = L[i].getColour();
    int color2 = R[j].getColour();

    if (color1 < color2 || (color1 == color2 && L[i].getLabel() < R[j].getLabel())) {
      members[k] = L[i];
      i++;
    } else {
      members[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    members[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    members[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

void Graph::mergeSort(int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
  }
}