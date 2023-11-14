#include "node.hpp"
#include "graph.hpp"
#include <stdexcept>


Graph::Graph(int size) {
  this->size = size;
  this->members = new Node[size];

  for (int i = 0; i < size; i++)
    this->members[i].neighbours = nullptr;
  
}

Graph::~Graph() {
  for (int i = 0; i < size; i++) {
    if (this->members[i].neighbours != nullptr)
      delete[] this->members[i].neighbours;   
  }

  delete[] this->members;
}

Node* Graph::getMembers() {
  return this->members;
}

int Graph::getSize(){
  return this->size;
}

Node Graph::getByLabel(int label) {
  int i = 0;
  while (this->getMembers()[i].getLabel() != label) {
    if (i >= size)
      throw std::out_of_range("Label not found");
 
        i++;
    }

  return this->getMembers()[i];
}

void Graph::bubbleSort() {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      int colour1 = this->members[j].getColour();
      int colour2 = this->members[j + 1].getColour();

      if (colour1 > colour2) std::swap(this->members[j], this->members[j + 1]);

      else if (colour1 == colour2) {
        if (this->members[j].getLabel() > this->members[j + 1].getLabel())
          std::swap(this->members[j], this->members[j + 1]);
      }
    }
  }
}

void Graph::selectionSort() {  
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (i < 0 || i >= size || j < 0 || j >= size) 
        throw std::out_of_range("Array index out of bounds");

      int colour1 = this->members[j].getColour();
      int colour2 = this->members[minIndex].getColour();

      if (colour1 < colour2) {
        minIndex = j;
      }
      else if (colour1 == colour2) {
        if (this->members[j].getLabel() < this->members[minIndex].getLabel()) {
          minIndex = j;
        }
      }
    }

    if (minIndex != i) {
      std::swap(this->members[i], this->members[minIndex]);
    }
  }
}

void Graph::insertionSort() {
  for (int i = 1; i < size; i++) {
    Node current = this->members[i];
    int j = i - 1;

    while (j >= 0 && (this->members[j].getColour() > current.getColour() || 
                     (this->members[j].getColour() == current.getColour() && this->members[j].getLabel() > current.getLabel()))) {
      this->members[j + 1] = this->members[j];
      j--;
    }

    this->members[j + 1] = current;
  }
}

int Graph::partition(int down, int up) {
  Node pivot = this->members[up];
  int i = down - 1;

  for (int j = down; j <= up - 1; j++) {
    int colour1 = this->members[j].getColour();
    int colour2 = pivot.getColour();

    if (colour1 < colour2 || (colour1 == colour2 && this->members[j].getLabel() < pivot.getLabel())) {
      i++;
      std::swap(this->members[i], this->members[j]);
    }
  }

  std::swap(this->members[i + 1], this->members[up]);
  return i + 1;
}

void Graph::quickSort(int down, int up) {
  if (down < up) {
    int pi = partition(down, up);

    quickSort(down, pi - 1);
    quickSort(pi + 1, up);
  }
}


void Graph::merge(int left, int mid, int right) {
  int nodeLSize = mid - left + 1;
  int nodeRSize = right - mid;

  Node* L = new Node[nodeLSize];
  Node* R = new Node[nodeRSize];

  for (int i = 0; i < nodeLSize; i++) {
    L[i] = this->members[left + i];
  }
  for (int j = 0; j < nodeRSize; j++) {
    R[j] = this->members[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < nodeLSize && j < nodeRSize) {
    int colour1 = L[i].getColour();
    int colour2 = R[j].getColour();

    if (colour1 < colour2 || (colour1 == colour2 && L[i].getLabel() < R[j].getLabel())) {
      this->members[k] = L[i];
      i++;
    } else {
      this->members[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < nodeLSize) {
    this->members[k] = L[i];
    i++;
    k++;
  }

  while (j < nodeRSize) {
    this->members[k] = R[j];
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

void Graph::heapify(int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n &&
    (this->members[left].getColour() < this->members[smallest].getColour() ||
      (this->members[left].getColour() == this->members[smallest].getColour() &&
      this->members[left].getLabel() < this->members[smallest].getLabel()))) {
    smallest = left;
  }

  if (right < n &&
    (this->members[right].getColour() < this->members[smallest].getColour() ||
      (this->members[right].getColour() == this->members[smallest].getColour() &&
      this->members[right].getLabel() < this->members[smallest].getLabel()))) {
    smallest = right;
  }

  if (smallest != i) {
    std::swap(this->members[i], this->members[smallest]);
    heapify(n, smallest);
  }
}

void Graph::heapSort() {
  int n = getSize();

  for (int i = n / 2 - 1; i >= 0; i--) 
    heapify(n, i);
  

  for (int i = n - 1; i > 0; i--) {
    std::swap(this->members[0], this->members[i]);
    heapify(i, 0);
  }

  int start = 0, end = this->getSize() -1;
  while (start < end) {
    std::swap(this->members[start], this->members[end]);
    start++;
    end--;
  }
  
}

void Graph::insertionSort(int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Node current = this->members[i];
        int j = i - 1;

        while (j >= left &&
               (this->members[j].getColour() > current.getColour() ||
                (this->members[j].getColour() == current.getColour() &&
                 this->members[j].getLabel() > current.getLabel()))) {

          this->members[j + 1] = this->members[j];
          j--;
        }

        this->members[j + 1] = current;
    }
}
void Graph::timSort() {
    int n = this->getSize();
    const int minRun = 32;

    for (int i = 0; i < n; i += minRun) {
        insertionSort(i, std::min((i + minRun - 1), (n - 1)));
    }

    for (int size = minRun; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            merge(left, mid, right);
        }
    }
}


bool Graph::greedy() {
  for (int i = 0; i < this->getSize(); i++) {
    Node* currentNode = &(this->getMembers()[i]);
    int currentColour = currentNode->getColour();
    int refColour = 1;

    while (refColour < currentColour) {
      bool colourFound = false;

      for (int j = 0; j < currentNode->getNumNeighbours(); j++) {
        if (i < 0 || i >= size || j < 0 || j >= size) 
         throw std::out_of_range("Array index out of bounds");

        int neighbourLabel = currentNode->getNeighbours()[j];
        Node vizinho = this->getByLabel(neighbourLabel);

        if (vizinho.getColour() == refColour) {
          colourFound = true;
          break;
        }
      }

      if (!colourFound) return false;

      refColour++;
    }
  }
  return true;
}
