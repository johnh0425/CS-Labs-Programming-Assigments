#include "BSTree.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

BSTree::BSTree() {          // default constructor for BST
    root = nullptr;         // set root to nullptr meaning empty tree
}   

BSTree::~BSTree() {
    deleteTree(root);           // deletes tree starting from the leaf up to the root
}

void BSTree::deleteTree(Node* node) {
    if (node == nullptr) {              // returns when tree is deleted at the end
        return;
    }
    deleteTree(node->left);             // deletes left subtree
    deleteTree(node->right);            // deletes right subtree
    delete node;                        // deletes root
}

void BSTree::insert(const std::string &insert) {         // inserts string into list
    Node* newNode = new Node(insert);           // constructs a new node to be placed into BST
    if (root == nullptr) {                      // checks if tree is empty, if it is set newNode as root
        root = newNode;
    }
    else {
        Node* currNode = root;
        while (currNode != nullptr) {           // stop when a node is nullptr meaning when you get to the bottom of tree to insert new node
            if (newNode->payload == currNode->payload) {        // if the string is already in tree, just increment count
                currNode->count = currNode->count + 1;
                currNode = nullptr;
            }
            else if (newNode->payload < currNode->payload) {        // if string is less than a node, then go to left child
                if (currNode->left == nullptr) {                // if child is not occupied insert
                    currNode->left = newNode;
                    currNode = nullptr;
                }
                else {
                    currNode = currNode->left;
                }
            }
            else {
                if (currNode->right == nullptr) {           // if string is more than a node, then go to right child
                    currNode->right = newNode;              //  if child is not occupied insert
                    currNode = nullptr;
                }
                else {
                    currNode = currNode->right;
                }
            }
        }
    }
}

bool BSTree::search(const std::string &search) const {       // searches and returns true or false for if string exists in tree
    return this->searchRec(this->root, search);         // calls recursive search function
}

bool BSTree::searchRec(Node* node, std::string search) const{        // searches for string in tree
    if (node == nullptr) {                          // returns false if tree is empty
        return false;
    }
    else if (node->payload == search) {         // returns true when string is found in tree
        return true;
    }
    else if (node->payload < search) {                  // calls the recursive search function starting from right child if string is more than a node
        return searchRec(node->right, search);
    }
    else {                                             // calls the recursive search function starting from left child if string is less than node
        return searchRec(node->left, search);
    }
}

std::string BSTree::largest() const {            // returns the largest value in tree
    if (root == nullptr) {              // returns empty string if tree is emtpy
        return "";
    }
    else {  
        Node* currNode = root;          
        while(currNode->right != nullptr) {         // goes all the way right until a leaf is reached
            currNode = currNode->right;
        }
        return currNode->payload;           // return far right leaf node
    }
}

std::string BSTree::smallest() const {           // returns smallest value in tree
    if (root != nullptr) {                  // checks if tree is empty
        Node* currNode = root;
        while(currNode->left != nullptr) {          // goes all the way left until a leaf is reached
            currNode = currNode->left;
        }
        return currNode->payload;
    }
    return "";
}

int BSTree::height(const std::string &searchHeight) const {      // returns the height of string in BST
    if (root == nullptr) {              // returns -1 if tree is empty
        return -1;
    }
    else {
        Node* currNode = root;
        while (currNode != nullptr) {           // stops when bottom of tree is reached
            if (currNode->payload == searchHeight) {        // returns the height of string when string is found
                return heightRec(currNode);             // calls recursive height function
            }
            else if (currNode->payload < searchHeight) {            // goes to the right child when string height is greater than node
                currNode = currNode->right;
            }
            else {                      // goes to left child when string is not greater or equal to node
                currNode = currNode->left;
            }
        }
        return -1;          // return -1 when string is not found in tree
    }
}

int BSTree::heightRec(Node* &node) const{       // recursive height function
    if (node == nullptr) {          // returns -1 when node is not found
        return -1;
    }
    int leftHeight = heightRec(node->left);
    int rightHeight = heightRec(node->right);
    return 1 + max(leftHeight, rightHeight);        // counts and returns every time it goes down the tree
}

void BSTree::remove(const std::string &remove) {         // calls the recursive function for removing a string from tree
    removeRec(this, remove);            // calling recursive function
}

void BSTree::preOrder() {       // calls recursive function for printing tree in preorder
    preOrder(root);    
}

void BSTree::inOrder() {            // calls recursive function for printing tree in inorder
    inOrder(root);
}

void BSTree::postOrder() {          // calls recursive function for printing tree in postorder
    postOrder(root);
}

void BSTree::preOrder(Node* node) {
    if (node == nullptr) {      // returns when end of tree is reached
        return;
    }
    std::cout << node->payload << "(" << node->count << "), ";       // prints out root first
    preOrder(node->left);           // print out left subtree
    preOrder(node->right);          // print out right subtree
}
void BSTree::inOrder(Node* node) {
    if (node == nullptr) {          // returns when end of tree is reached
        return;
    }
    inOrder(node->left);            // prints out left subtree
    std::cout << node->payload << "(" << node->count << "), ";       // print out root
    inOrder(node->right);           // prints out right subtree
}
void BSTree::postOrder(Node* node) {
    if (node == nullptr) {          // returns when end of tree is reached
        return;
    }
    postOrder(node->left);          // prints out left subtree
    postOrder(node->right);         // prints out right subtree
    std::cout << node->payload << "(" << node->count << "), ";           // prints out root
}

void BSTree::removeRec(BSTree* treeNode, std::string remove) {       // recursively removes string from BST
    Node* par = nullptr;            // set parent node to null
    Node* curr = treeNode->root;       
    while (curr != nullptr) {       // checks if reached end of subtree meaning string to remove is not found
        if (curr->payload == remove) {      // checks if string to remove is found
            if (curr->count >= 2) {             // if count is 2 or more than decrement the count for that string in tree 
                curr->count = curr->count - 1;
                return;
            }
            if (curr->left == nullptr && curr->right == nullptr) {      // checks if a node has 0 children
                if (par == nullptr) {       // if parent is nullptr meaning there is only 1 node in tree, set root to nullptr which emptys the tree
                    treeNode->root = nullptr;
                }
                else if (par->left == curr) {       // if parent node's left child is to be removed set left parent child to be empty
                    par->left = nullptr;
                }
                else {                      // if parent's right child is to be removed set right parent child to be empty
                    par->right = nullptr;
                }
            }
            else if (curr->left != nullptr) {       // checks if left child exists
                if (par == nullptr && curr->right != nullptr) {         // checks if the parent is nullptr and the right child exists
                    Node* succ = curr->left;
                    while (succ->right != nullptr) {        // find successor by going left once and going all the way right
                        succ = succ->right;                 // this finds the largest value in the left subtree
                    }
                    std::string succPayload = succ->payload;
                    removeRec(treeNode, succ->payload);     // recursively call to remove node that is being moved up
                    curr->payload = succPayload;            // move successor to removed string's position
                }
                else if (par == nullptr) {
                    treeNode->root = curr->left;            // if parent node is nullptr (at root), just set root to be the left child
                }
                else {
                    Node* succ = curr->left;
                    while (succ->right != nullptr) {        // find successor by going left once and going all the way right
                        succ = succ->right;                 // this finds the largest value in the left subtree
                    }
                    std::string succPayload = succ->payload;
                    removeRec(treeNode, succ->payload);     // recursively call to remove node that is being moved up
                    curr->payload = succPayload;            // move successor to removed string's position
                }
            }
            else {                  // if left child does not exist but a right child does exist
                if (par == nullptr) {           // is parent is nullptr meaning the string to be removed is at the root, set root as right child
                    treeNode->root = curr->right;
                }
                else {              // if removing the node is not at root
                    Node* succ = curr->right;
                    while (succ->left != nullptr) {         // finds successor by going right once and then all the way left
                        succ = succ->left;                  // this finds the smallest value in the right subtree to be successor
                    }
                    std::string succPayload = succ->payload;
                    removeRec(treeNode, succ->payload);     // recursively call to remove node that is being moved up
                    curr->payload = succPayload;        // move successor to removed string's position
                }      
            }
            return;
        }
        else if (curr->payload < remove) {      // if the string to be removed is greater than the node currently at, check the right subtree
            par = curr;
            curr = curr->right;
        }
        else {                  // if the string to be removed is greater than the node currently at, check the left subtree
            par = curr;
            curr = curr->left;
        }
    }
    return;
}