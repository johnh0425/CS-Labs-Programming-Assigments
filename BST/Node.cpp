#include "Node.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Node::Node() {          // default constructor for node
    left = nullptr;
    right = nullptr;
    payload = "";
    count = 1;
}

Node::Node(std::string newLoad) {        // constructor for new node with a set payload passed in through parameter
    left = nullptr;
    right = nullptr;
    payload = newLoad;
    count = 1;
}