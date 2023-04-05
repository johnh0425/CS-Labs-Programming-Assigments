#ifndef __NODE_H
#define __NODE_H
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct Node {
    Node* left;             // left pointer which points to left child
    Node* right;            // right pointer which points to right child
    string payload;         // data in node
    int count;              // the amount of data in binary tree
    Node();                 // defualt constructor
    Node(std::string newLoad);       // default constructor with a new payload to be set
};

#endif