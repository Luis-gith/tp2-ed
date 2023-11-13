#include "node.hpp"
#include "graph.hpp"

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

Node Graph::getByLabel(int label) {
  int i = 0;
  while(this->getMembers()[i].getLabel() != label) i++;

  return this->getMembers()[i];
}

//working
void Graph::bubbleSort() {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      int colour1 = members[j].getColour();
      int colour2 = members[j + 1].getColour();

      if (colour1 > colour2) std::swap(members[j], members[j + 1]);

      else if (colour1 == colour2) {
        if (members[j].getLabel() > members[j + 1].getLabel())
          std::swap(members[j], members[j + 1]);
      }
    }
  }
}

//working
void Graph::selectionSort() {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      int colour1 = members[j].getColour();
      int colour2 = members[minIndex].getColour();

      if (colour1 < colour2) {
        minIndex = j;
      }
      else if (colour1 == colour2) {
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

//working
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

//working
//needed for quicksort
int Graph::partition(int down, int up) {
  Node pivot = members[up];
  int i = down - 1;

  for (int j = down; j <= up - 1; j++) {
    int colour1 = members[j].getColour();
    int colour2 = pivot.getColour();

    if (colour1 < colour2 || (colour1 == colour2 && members[j].getLabel() < pivot.getLabel())) {
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

//working
//needed for mergesort
void Graph::merge(int left, int mid, int right) {
  int nodeLSize = mid - left + 1;
  int nodeRSize = right - mid;

  Node* L = new Node[nodeLSize];
  Node* R = new Node[nodeRSize];

  for (int i = 0; i < nodeLSize; i++) {
    L[i] = members[left + i];
  }
  for (int j = 0; j < nodeRSize; j++) {
    R[j] = members[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < nodeLSize && j < nodeRSize) {
    int colour1 = L[i].getColour();
    int colour2 = R[j].getColour();

    if (colour1 < colour2 || (colour1 == colour2 && L[i].getLabel() < R[j].getLabel())) {
      members[k] = L[i];
      i++;
    } else {
      members[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < nodeLSize) {
    members[k] = L[i];
    i++;
    k++;
  }

  while (j < nodeRSize) {
    members[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

//working
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
    (members[left].getColour() < members[smallest].getColour() ||
      (members[left].getColour() == members[smallest].getColour() &&
      members[left].getLabel() < members[smallest].getLabel()))) {
    smallest = left;
  }

  if (right < n &&
    (members[right].getColour() < members[smallest].getColour() ||
      (members[right].getColour() == members[smallest].getColour() &&
      members[right].getLabel() < members[smallest].getLabel()))) {
    smallest = right;
  }

  if (smallest != i) {
    std::swap(members[i], members[smallest]);
    heapify(n, smallest);
  }
}

void Graph::heapSort() {
  int n = getSize();

  for (int i = n / 2 - 1; i >= 0; i--) 
    heapify(n, i);
  

  for (int i = n - 1; i > 0; i--) {
    std::swap(members[0], members[i]);
    heapify(i, 0);
  }

  int start = 0, end = this->getSize() -1;
  while (start < end) {
    std::swap(members[start], members[end]);
    start++;
    end--;
  }
  
}

//needed for timsort
void Graph::insertionSort(int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Node current = members[i];
        int j = i - 1;

        // Compare based on color and label
        while (j >= left &&
               (members[j].getColour() > current.getColour() ||
                (members[j].getColour() == current.getColour() &&
                 members[j].getLabel() > current.getLabel()))) {
            members[j + 1] = members[j];
            j--;
        }

        members[j + 1] = current;
    }
}
void Graph::timSort() {
    int n = this->getSize();
    const int minRun = 32;

    // Sort individual subarrays of size minRun using Insertion Sort
    for (int i = 0; i < n; i += minRun) {
        insertionSort(i, std::min((i + minRun - 1), (n - 1)));
    }

    // Merge the sorted runs
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
