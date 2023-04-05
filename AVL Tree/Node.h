#ifndef __NODE_H
#define __NODE_H
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct Node {
    Node* left;             // left pointer which points to left child
    Node* right;            // right pointer which points to right child
    Node* parent;             // parent pointer of node
    int height;             // height of node in tree
    string data;         // data in node
    Node();                 // defualt constructor
    Node(std::string newData);       // default constructor with a new payload to be set
};

#endif