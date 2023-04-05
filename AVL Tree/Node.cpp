#include "Node.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Node::Node() {          // default constructor for node
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    data = "";
    height = 0;
}

Node::Node(std::string newData) {        // constructor for new node with a set data passed in through parameter
    left = nullptr;
    right = nullptr;
    data = newData;
    parent = nullptr;
    height = 0;
}