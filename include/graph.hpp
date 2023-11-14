#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"

/**
 * @class Graph
 * @brief Represents a graph with nodes and various sorting algorithms.
 */
class Graph {
public:
    /**
     * @brief Constructor for the Graph class.
     * @param size The size of the graph.
     */
    Graph(int size);

    /**
     * @brief Destructor for the Graph class.
     */
    ~Graph();

    /**
     * @brief Get the array of nodes representing the graph members.
     * @return A pointer to the array of nodes.
     */
    Node* getMembers();

    /**
     * @brief Get the size of the graph.
     * @return The size of the graph.
     */
    int getSize();

    /**
     * @brief Get a node by its label.
     * @param label The label of the node to retrieve.
     * @return The node with the specified label.
     */
    Node getByLabel(int label);

    /**
     * @brief Sort the graph using the bubble sort algorithm.
     */
    void bubbleSort();

    /**
     * @brief Sort the graph using the selection sort algorithm.
     */
    void selectionSort();

    /**
     * @brief Sort the graph using the insertion sort algorithm.
     */
    void insertionSort();

    /**
     * @brief Sort a portion of the graph using insertion sort.
     * @param left The starting index of the portion to be sorted.
     * @param right The ending index of the portion to be sorted.
     */
    void insertionSort(int left, int right);

    /**
     * @brief Sort the graph using the quicksort algorithm.
     * @param down The starting index of the portion to be sorted.
     * @param up The ending index of the portion to be sorted.
     */
    void quickSort(int down, int up);

    /**
     * @brief Partition the graph for quicksort.
     * @param down The starting index of the portion to be partitioned.
     * @param up The ending index of the portion to be partitioned.
     * @return The pivot index after partitioning.
     */
    int partition(int down, int up);

    /**
     * @brief Merge two sorted portions of the graph.
     * @param left The starting index of the first portion.
     * @param mid The ending index of the first portion and starting index of the second portion.
     * @param right The ending index of the second portion.
     */
    void merge(int left, int mid, int right);

    /**
     * @brief Sort the graph using the mergesort algorithm.
     * @param left The starting index of the portion to be sorted.
     * @param right The ending index of the portion to be sorted.
     */
    void mergeSort(int left, int right);

    /**
     * @brief Heapify a subtree rooted at the given index.
     * @param n The size of the heap.
     * @param i The index of the root of the subtree.
     */
    void heapify(int n, int i);

    /**
     * @brief Sort the graph using the heapsort algorithm.
     */
    void heapSort();

    /**
     * @brief Sort the graph using the timsort algorithm.
     */
    void timSort();

    /**
     * @brief Check if the graph is colored in a greedy manner.
     * @return True if the graph is colored greedily, false otherwise.
     */
    bool greedy();

private:
    int size;    ///< The size of the graph.
    Node* members; ///< Array of nodes representing the graph members.
};

#endif
