#include "AVLTree.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

AVLTree::AVLTree() {        // default constructor
    root = nullptr;         // sets root to nullptr for empty tree
}

AVLTree::~AVLTree() {
    deleteTree(root);           // deletes tree starting from the leaf up to the root
}

void AVLTree::deleteTree(Node* node) {
    if (node == nullptr) {              // returns when tree is deleted at the end
        return;
    }
    deleteTree(node->left);             // deletes left subtree
    deleteTree(node->right);            // deletes right subtree
    delete node;                        // deletes root
}

void AVLTree::insert(const std::string &insertion) {         // insert a string to tree
    Node* insertNode = new Node(insertion);             // allocates a new node to insert
    if (this->root == nullptr) {                    // checks if tree is empty
        root = insertNode;                          // if empty sets the root to be the inserted node
        insertNode->parent = nullptr;               // sets the root's parent to nullptr
        return;
    }
    Node* curr = this->root;                 
    while (curr != nullptr) {                       // stops when bottom of tree is reached
        if (insertNode->data == curr->data) {       // return when string already is in tree
            return;
        }  
        if (insertNode->data < curr->data) {        // goes to the left subtree when string to be inserted is less than the current node
            if (curr->left == nullptr) {            // checks to left child is empty meaning the bottom of tree
                curr->left = insertNode;            // insert the node as the left child
                insertNode->parent = curr;
                curr = nullptr;
            }
            else {  
                curr = curr->left;                  // go to the left node if bottom of tree is not reached
            }
        }
        else {
            if (curr->right == nullptr) {           // goes to the right subtree when string to be inserted is greater than the current node
                curr->right = insertNode;           // insert node to right child
                insertNode->parent = curr;
                curr = nullptr;
            }
            else {
                curr = curr->right;                 // goes to the right child if bottom of tree is not reached
            }
        }
    }
    insertNode = insertNode->parent;            // sets the inserted node's parent
    while (insertNode != nullptr) {                
        Rebalance(insertNode);                  // rebalances the tree
        insertNode = insertNode->parent;
    }
}

void AVLTree::Rebalance(Node* node) {           // rebalances tree if unbalanced
    AVLTreeUpdateHeight(node);                  // updates the node's height
    if (balanceFactor(node) == -2) {            // if node is uneven at the right side
        if (balanceFactor(node->right) == 1) {          // checks for case if a double rotation is needed
            rotateRight(node->right);               // make a right rotation
        }
        rotateLeft(node);           // make a left rotation
    }
    else if (balanceFactor(node) == 2) {            // if node is uneven at the left side
        if (balanceFactor(node->left) == -1) {      // checks for case if a double rotation is needed
            rotateLeft(node->left);                 // make a left rotation
        }
        rotateRight(node);                  // make a right rotation
    }
}

void AVLTree::AVLTreeUpdateHeight(Node *node) {         // updates the height of the passed in node
    int leftHeight = -1;                    // default height of left is set to -1
    if (node->left != nullptr) {
        leftHeight = node->left->height;        // sets left height to be the height of the node's left
    }
    int rightHeight = -1;                   // defualt height of right is set to -1
    if (node->right != nullptr) {
        rightHeight = node->right->height;      // sets right height to be the height of the node's right
    }
    node->height = max(leftHeight, rightHeight) + 1;        // returns the max height between the left height or right height
}

void AVLTree::printBalanceFactors() {       // recursive calls the in order print function
    printBalanceFactors(root);
    std::cout << std::endl;
}

void AVLTree::printBalanceFactors(Node *node) {     // prints tree in order
    if (node == nullptr) {          // returns when end of tree is reached
        return;
    }
    printBalanceFactors(node->left);            // prints out left subtree
    std::cout << node->data << "(" << balanceFactor(node) << ")" << ", ";       // print out root
    printBalanceFactors(node->right);           // prints out right subtree
}

int AVLTree::balanceFactor(Node* node) {        // finds the balance factor at passed in node
    int leftHeight = -1;
    if (node->left != nullptr) {
        leftHeight = node->left->height;        // finds the height of the left child
    }
    int rightHeight = -1;
    if (node->right != nullptr) {
        rightHeight = node->right->height;          // finds the height of the right child
    }
    return leftHeight - rightHeight;        // returns calculated balance factor
}

void AVLTree::rotateLeft(Node* node) {          // rotate the tree left at node
    Node* rightLeftChild = node->right->left;
    if (node->parent != nullptr) {
        AVLTreeReplaceChild(node->parent, node, node->right);       // replaces the child as needed for a rotation
    }
    else {
        this->root = node->right;
        this->root->parent = nullptr;
    }
    AVLTreeSetChild(node->right, "left", node);     // set the left child after rotation
    AVLTreeSetChild(node, "right", rightLeftChild);         // set the right child after rotation
}

void AVLTree::rotateRight(Node* node) {             // rotate the tree right at node
    Node* leftRightChild = node->left->right;
    if (node->parent != nullptr) {
        AVLTreeReplaceChild(node->parent, node, node->left);            // replaces the child as needed for a rotation
    }
    else {
        this->root = node->left;
        this->root->parent = nullptr;
    }
    AVLTreeSetChild(node->left, "right", node);             // set the right child after rotation
    AVLTreeSetChild(node, "left", leftRightChild);          // set the left child after rotation
}

void AVLTree::AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild) {
    if (parent->left == currentChild) {
        AVLTreeSetChild(parent, "left", newChild);      // sets the left child to the new child during a rotation
    }
    else if (parent->right == currentChild) {
        AVLTreeSetChild(parent, "right", newChild);     // sets the right child to the new child during a rotation
    }
}

void AVLTree::AVLTreeSetChild(Node* parent, std::string whichChild, Node *child) {       // sets the child during a rotation
    if (whichChild != "left" && whichChild != "right") {
        return;
    }
    if(whichChild == "left") {      // sets the parent's left child to be the passed in child
        parent->left = child;
    }
    else {
        parent->right = child;      // sets the parent's right child to be the passed in child
    }
    if (child != nullptr) {
        child->parent = parent;     // if passed in child is null, set the child's parent equal to the passed in parent
    }
    AVLTreeUpdateHeight(parent);        // update the height of the parent
}

void AVLTree::visualizeTree(const std::string &outputFilename){      // helps visualize the tree
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        std::cout<<"Error"<<std::endl;                    // if file does not open, out error
        return;
    }
    outFS<<"digraph G {"<<std::endl;
    visualizeTree(outFS,root);          // calls visualizeTree function to visualize the tree
    outFS<<"}";
    outFS.close();
    std::string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    std::string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){     //  sets up visualize tree
    if(n){
        if(n->left){                    // print left subtree
            visualizeTree(outFS,n->left);   
            outFS<<n->data <<" -> " <<n->left->data<<";"<<std::endl;    
        }

        if(n->right){               // prints right subtree
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<std::endl;    
        }
    }
}