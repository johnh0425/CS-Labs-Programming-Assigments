#ifndef __NODE_H
#define __NODE_H

#include <string>

using namespace std;

class Node {

  friend class Tree;

private:
  std::string small;       // small value of node
  std::string large;       // large value of node

  Node *left;         // pointer to the left child
  Node *middle;       // pointer to the middle child
  Node *right;         // pointer to right child
  Node *parent;       // pointer to parent of node

  // Add additional functions/variables here. Remember, you may not add any
  // Node * or string variables.
  int numKeys;            // num of values in node
  Node();                 // default constructor
  Node(std::string sm, Node *lef, Node *mid);      // constructor of node with small, left and middle values
  Node(std::string sm, std::string lg);             // constructor of node with only small and large values
  Node(std::string sm);              // constructor of node with only small value

};

#endif