#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node *root;   // root of tree

public:
  Tree( );    // default tree constructor
  ~Tree( );     // tree destrcutor
  void insert(const std::string &);    // insert movie name to tree  (calls the recursive function)
  void preOrder( ) const;       // prints tree in pre order   (calls the recursive function)
  void inOrder( ) const;        // prints tree in order   (calls the recursive function)
  void postOrder( ) const;      // prints tree in post order    (calls the recursive function)
  void remove(const std::string &);    // removes movie name in tree     (calls the recursive function)
  bool search (const std::string &) const;   // searches if movie name is in tree    (calls the recursive function)

private:
  // Add additional functions/variables here
  void deleteTree(Node* node);      // called by destructor to remove all node in tree
  void insertRec(Node *node, std::string movieName);     // inserts movie name to tree
  bool searchRec(Node *node, std::string movieName) const;     // searches for is movie name is in tree
  void preOrderRec(Node *node) const;     // prints tree in pre order
  void inOrderRec(Node *node) const;      // prints tree in order
  void postOrderRec(Node *node) const;    // prints tree in post order
  void removeRec(Tree *tree, std::string movieName);     // removes a movie name in tree
  Node* split(Tree *tree, Node* node, Node* nodeParent, std::string movieName);    // splits node when inserting a movie name into a full node
  // Node* BTMerge(Node *node);
  // Node* BTreeFuse(Node *leftNode, Node *rightNode);
    
};

#endif