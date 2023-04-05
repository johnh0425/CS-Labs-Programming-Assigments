#include "Node.h"
#include <string>
using namespace std;

Node::Node() {      // Node default constructor
    numKeys = 0;       
    small = "";        
    large = "";         
    left = nullptr;        
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(std::string sm, Node *lef, Node *mid) {       // Node constructor with small, left pointer, and middle pointer as parameter
    numKeys = 1;
    small = sm;
    large = "";
    left = lef;
    middle = mid;
    right = nullptr;
    parent = nullptr;
}

Node::Node(std::string sm, std::string lg) {          // Node constructor with small and large values
    numKeys = 2;    
    small = sm;
    large = lg;
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(std::string sm) {         // Node constructor with only small value
    numKeys = 1;
    small = sm;
    large = "";
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}