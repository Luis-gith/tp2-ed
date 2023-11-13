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
  while(this->getMembers()[i].getLabel() != label)  
    i++;
  return this->getMembers()[i];
}

//working
void Graph::bubbleSort() {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      int color1 = members[j].getColour();
      int color2 = members[j + 1].getColour();

      if (color1 > color2) std::swap(members[j], members[j + 1]);

      else if (color1 == color2) {
        if (members[j].getLabel() > members[j + 1].getLabel())
          std::swap(members[j], members[j + 1]);
      }
    }
  }
    //percorre membros do grafo
  /*for (int i = 0; i < this->getSize(); i++) {
    //impressão de membro
      std::cout << std::endl;
    std::cout << "membro " << i << " tem cor: " << this->getMembers()[i].getColour() << std::endl;

    //percorre vizinhos de cada membro
    for(int j = 0; j < this->getMembers()[i].getNumNeighbours(); j++)  {
      //impressão de vizinhos
      int vizinho = this->getMembers()[i].getNeighbours()[j];
      std::cout << "o vizinho: "<< vizinho << " possui cor: " << this->getMembers()[vizinho].getColour() << ", ";
    }
  }*/
}

//working
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

//working
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

//working
void Graph::mergeSort(int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
  }
}


/*bool Graph::greedy() {

  for(int i = 0; i < this->getSize(); i++)  {
    Node noAtual = this->getMembers()[i];
    int corAtual = noAtual.getColour();
    //int corVizinhos[noAtual.getNumNeighbours()];
    std::cout <<  "cor de " << noAtual.getLabel() << ": " << corAtual << std::endl <<" vizinhos: ";
    for (int j = 0; j < noAtual.getNumNeighbours(); j++) {
      Node vizinho = this->getMembers()[noAtual.getNeighbours()[j]];
      ///int corVizinho = vizinho.getColour();
      //std::cout << corVizinho << " ";
      std::cout << vizinho.getLabel();
    }
    std::cout << std::endl;
  }
  return true;
  
}*/

/*bool Graph::greedy() {
  //std::cout << this->getMembers()[3].getNeighbours()[0] << " " << this->getMembers()[3].getNeighbours()[1];
  for(int i = 0; i < this->getSize(); i++)  {
    Node noAtual = this->getMembers()[i];
    int corAtual = noAtual.getColour();
    //std::cout <<  "cor de " << noAtual.getLabel() << ": " << corAtual 
    //  << std::endl <<" vizinhos: " << noAtual.getNeighbours()[i];

    //std::cout << std::endl;
  }
  return true;
  
}*/



bool Graph::greedy() {
    for (int i = 0; i < this->getSize(); i++) {
        Node* verticeAtual = &(this->getMembers()[i]);
        int corAtual = verticeAtual->getColour();
        int corEsperada = 1;

        while (corEsperada < corAtual) {
            bool encontrouCor = false;

            for (int j = 0; j < verticeAtual->getNumNeighbours(); j++) {
                int vizinhoLabel = verticeAtual->getNeighbours()[j];
                Node vizinho = this->getByLabel(vizinhoLabel);

                if (vizinho.getColour() == corEsperada) {
                    encontrouCor = true;
                    break;
                }
            }

            if (!encontrouCor) {
                return false;
            }

            corEsperada++;
        }
    }
    return true;
}
