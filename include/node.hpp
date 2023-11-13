#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

/**
 * @class Node
 * @brief Represents a node in a graph.
 */
class Node {
  friend class Graph;
public:
  /**
   * @brief Default constructor for the Node class.
   */
  Node();

  /**
   * @brief Gets the label of the node.
   * @return The label of the node.
   */
  int getLabel();

  /**
   * @brief Sets the label of the node.
   * @param newLabel The new label for the node.
   */
  void setLabel(int newLabel);

  /**
   * @brief Adds a neighbour to the node.
   * @param neighbourId The label of the new neighbour.
   */
  void addNeighbour(int neighbourId);

  /**
   * @brief Gets the colour of the node.
   * @return The colour of the node.
   */
  int getColour();

  /**
   * @brief Sets the colour of the node.
   * @param newColour The new colour for the node.
   */
  void setColour(int newColour);

  /**
   * @brief Gets an array of neighbour labels.
   * @return A pointer to the array of neighbour labels.
   */
  int *getNeighbours();

  /**
   * @brief Gets the number of neighbors.
   * @return The number of neighbors.
   */
  int getNumNeighbours();

private:
  int label;           ///< The label of the node.
  int colour;          ///< The colour of the node.
  int *neighbours;     ///< Array of neighbour labels.
  int numNeighbours;   ///< Number of neighbors.
};

#endif
