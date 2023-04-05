#ifndef __AVLTREE_H
#define __AVLTREE_H

#include "Node.h"

class AVLTree {
 public:
    AVLTree();    // tree default constructor
    ~AVLTree();    // destructor
    void deleteTree(Node* node);     // recursively calls itself to destruct tree called by destructor
    void insert(const std::string &);        // insert string to avl tree
    int balanceFactor(Node*);          // returns the balance factor at node
    void printBalanceFactors();        // prints the avl tree in order
    void visualizeTree(const std::string &);       // visualizes the tree
 private:
    Node* root;         // root of tree
    void Rebalance(Node *);         // rebalances the tree when unbalanced
    void rotateLeft(Node *);           // rotates left at node
    void rotateRight(Node *);          // rotates right at node
    void printBalanceFactors(Node *);        // recursively calls print in order
    void visualizeTree(ofstream &, Node *);        // visualizes the tree
    void AVLTreeSetChild(Node* parent, std::string whichChild, Node *child);     // sets the child during the rotation
    void AVLTreeUpdateHeight(Node *node);          // updates the height after rotation
    void AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild);        // replaces the child during the rotation
};

#endif