#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"


class Graph {
  public:
    Graph(int size);
    ~Graph();
    Node* getMembers();
    int getSize();
    Node getByLabel(int label);
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    
    void quickSort(int down, int up);
    int partition(int down, int up);

    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

    bool greedy();

  private:
    int size;
    Node* members;
};


#endif

