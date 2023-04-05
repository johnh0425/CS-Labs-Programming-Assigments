#ifndef __BSTREE_H
#define __BSTREE_H
#include <iostream>
#include <stdexcept>
#include <string>
#include "Node.h"
using namespace std;

class BSTree {
 private:
    Node* root;      // pointer that sets a node as a the root of the tree
    void removeRec(BSTree* tree, std::string remove);      // recursion function for removing a string from tree  
    void preOrder(Node* node);                     // recursively prints the root first then the rest of tree from left subtree to right subtree
    void inOrder(Node* node);                      // recursively prints the tree in order from smallest to largest
    void postOrder(Node* node);                    // recursively prints the left subtree to right subtree, then the root
    bool searchRec(Node* node, std::string search) const;     // recursion function for searching a string
    int heightRec(Node* &) const;                // recursion function for returning the height of a string in tree
    void deleteTree(Node* node);                   // recursively called to delete BST
 public:
    BSTree();           // default constructor for tree
    ~BSTree();          // destructor for tree
    void insert(const std::string &);             // inserts a new string into the tree following the rule of BST
    bool search(const std::string &) const;       // searches for a string and return true or false if string is in tree
    std::string largest() const;                  // returns the largest data in tree
    std::string smallest() const;                 // returns smallest data in tree
    int height(const std::string &) const;        // returns the height string in tree
    void remove(const std::string &);             // removes the string of from search tree or counts down by 1 if more than 1 of the data exists in tree
    void preOrder();                         // calls the recursive function which prints the root first then the rest of tree from left subtree to right subtree
    void inOrder();                          // calls the recursive function which prints the tree in order from smallest to largest
    void postOrder();                     // calls the recursive function which prints the left subtree to right subtree, then the root
};

#endif