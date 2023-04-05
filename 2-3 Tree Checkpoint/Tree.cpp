#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Tree::Tree( ) {                 // default constructor of tree
    root = nullptr;             // creates a empty tree meaning root is nullptr
}

Tree::~Tree( ) {            // tree destructor
    deleteTree(root);       // deletes all nodes in tree
}

void Tree::deleteTree(Node* node) {
    if (node == nullptr) {              // returns when tree is deleted at the end
        return;
    }
    deleteTree(node->left);             // deletes left subtree
    deleteTree(node->right);            // deletes right subtree
    delete node;                        // deletes root
}

void Tree::insert(const std::string &movieName) {        // call recursive insert to insert movieName into tree
    if (root == nullptr) {                  // if root is nullptr meaning tree is empty, set root to be the passed in movie
        root = new Node(movieName);
        return;
    }   
    insertRec(root, movieName);         // call rescurive insert function if tree is not empty
}

void Tree::insertRec(Node *node, const std::string movieName) {          // inserts movie name into tree
    if ((movieName == node->small) || (movieName == node->large)) {         // if movie name exists in the tree just return
        return;
    }
    if (node->left != nullptr || node->middle != nullptr || node->right != nullptr) {       // checks if not at leaf
        if (movieName < node->small) {              // if passed in movie is less than the small value of node recursively insert by going to left child
            return insertRec(node->left, movieName);
        }
        else if (node->large == "" || movieName < node->large) {    // if passed in movie is in between small and large than recursively insert by going to middle child
            return insertRec(node->middle, movieName);
        }
        else {              // if passed in movie is larger than large value of node, recursively insert to right child
            return insertRec(node->right, movieName);
        }
    }
    else {          // if at leaf
        if (node->numKeys >= 2) {       // if node is full call the split function to split node
            node = split(this, node, node->parent, movieName);
        }
        else if (movieName > node->small) {     // if movieName is not full and greater than small value, insert into node as the large value
            node->large = movieName;
            node->numKeys++;
        }
        else {              // if movieName is not full and less than small value, insert into node as the small value
            node->large = node->small;
            node->small = movieName;
            node->numKeys++;
        }
        return;
    }
}

Node* Tree::split(Tree *tree, Node* node, Node* nodeParent, std::string movieName) {     // splits the node when inserting a new value into a full node
    Node* splitLeft;
    Node* splitRight;
    std::string newParent;
    if (node->numKeys < 2) {        // if node is not full just return
        return nodeParent;
    }

    if (movieName < node->small) {          // if movie to be inserted is less than the small, the original small value of node will percolate up
            splitLeft = new Node(movieName, node->left, node->middle);      // left child will be passed in movie Name
            splitRight = new Node(node->large, nullptr, node->right);       //middle child will be large value
            newParent = node->small;        // parent of these new children will be the small value
    }
    else if (movieName < node->large) {     // if movie to be inserted is less than large value but bigger than small value, than passed in movieName will percolate up
            splitLeft = new Node(node->small, node->left, node->middle);        // left child will be small value
            splitRight = new Node(node->large, nullptr, node->right);           // middle child will be large value
            newParent = movieName;          // parent of these new children will be the new movieName
    }
    else {          // if movie to be inserted is greater than the largest value in node, than the largest value in original node will percolate up
            splitLeft = new Node(node->small, node->left, node->middle);        // left child will be small value
            splitRight = new Node(movieName, nullptr, node->right);             // middle child will be passed in movieName
            newParent = node->large;        // parent of these new children will be the large value
    }

    if (nodeParent != nullptr) {            // check if there is a node to percolate up into
        if (nodeParent->numKeys >= 2) {
            throw runtime_error("Parent Node is full";)     // exception is thrown when inserting into a full parent node when percolating up
        }
        if (newParent < nodeParent->small) {        // insert the value that is percolated up from the split into parent node when not full (this is case when percolated up value is less than small value)
            nodeParent->large = nodeParent->small;
            nodeParent->small = newParent;
            nodeParent->middle = splitRight;
            nodeParent->left = splitLeft;
            nodeParent->numKeys++;
        }
        else {          // insert the value that is percolated up from the split into parent node (case when percolated value is larger than small)
            nodeParent->large = newParent;
            nodeParent->right = splitRight;
            nodeParent->middle = splitLeft;
            nodeParent->numKeys++;
        }
    }
    else {      // if no node to percolate up into, a new node must be created for that value that is percolating up (make it the root)
        nodeParent = new Node(newParent, splitLeft, splitRight);
        root = nodeParent;
    }
    splitLeft->parent = nodeParent;
    splitRight->parent = nodeParent;
    return nodeParent;
}

void Tree::preOrder( ) const {      // recursively calls the preOrder function that prints tree in preorder
    preOrderRec(root);
    std::cout << std::endl;
}
void Tree::preOrderRec(Node *node) const {
    if (node == nullptr) {      // if node is nullptr (tree is empty), no need to print
        return;
    }
    std::cout << node->small << ", ";       // print small value at current node
    preOrderRec(node->left);            // print left subtree
    if (node->numKeys >= 2) {           // if there is a large value print large value
        std::cout << node->large << ", ";
    }
    preOrderRec(node->middle);      // print middle subtree
    preOrderRec(node->right);       // print right subtree
}

void Tree::inOrder( ) const {       // recursively calls the inOrder function that prints tree in order
    inOrderRec(root);
    std::cout << std::endl;
}

void Tree::inOrderRec(Node *node) const {       // prints tree in order
    if (node == nullptr) {      // if node is nullptr (tree is empty), no need to print
        return;
    }
    inOrderRec(node->left);     // print left subtree
    std::cout << node->small << ", ";       // print small value at current node
    inOrderRec(node->middle);           // prints middle subtree
    if (node->numKeys >= 2) {       // if there is a large value print large value
        std::cout << node->large << ", ";
    }
    inOrderRec(node->right);        // prints right subtree
}   

void Tree::postOrder( ) const {   // recursively calls the postOrder function that prints tree post order
    postOrderRec(root);
    std::cout << std::endl;
}

void Tree::postOrderRec(Node *node) const {         // prints tree in post order
    if (node == nullptr) {          // if node is nullptr (tree is empty), no need to print
        return;
    }
    postOrderRec(node->left);               // prints left subtree
    postOrderRec(node->middle);                // prints middle subtree
    std::cout << node->small << ", ";           // print small value at current node
    postOrderRec(node->right);              // prints right subtree
    if (node->numKeys >= 2) {           // if there is a large value print large value
        std::cout << node->large << ", ";
    }
}

void Tree::remove(const std::string &movieName) {        // recursively calls remove function to remove a movie name from tree
    removeRec(this, movieName);
}

void Tree::removeRec(Tree *tree, std::string movieName) {        // removes a movie name from tree
    Node *fusedNode;
    if (tree->root->left == nullptr && tree->root->middle == nullptr && tree->root->right == nullptr && tree->root->numKeys == 1 && tree->root->small == movieName) {
        delete tree->root;              //  if tree only has 1 node, delete the one node and set root to nullptr because tree is now empty
        tree->root = nullptr;
        return;
    }
    Node* curr = tree->root;        // start at tree root and go down the tree to find the node to remove
    while (curr != nullptr) {       // stop when the bottom of tree is reached
        if (curr->numKeys == 1 && movieName == curr->small && curr == tree->root) {     // 
            curr->small = curr->middle->small;
            curr->middle = nullptr;
            fusedNode = new Node(curr->left->small, curr->small);
            tree->root = fusedNode;
            return;
        }
        else if (curr->numKeys == 1 && curr != tree->root && movieName == curr->small) {        // if current node is not the root and is 1 key and is the value that needs to be deleted
            if (curr == curr->parent->left && curr->left == nullptr && curr->middle == nullptr) {       // if is a leaf node just delete
                curr = curr->parent;
                delete curr->left;
                curr->left = nullptr;
            }
            else if (curr == curr->parent->middle && curr->left == nullptr && curr->middle == nullptr) {        // if need to delete middle child
                curr = curr->parent;
                delete curr->middle;
                curr->middle = nullptr;
            }

            if (curr->left == nullptr) {            // fuse the node with its left child is nullptr
                fusedNode = new Node(curr->small, curr->middle->small);
            }
            else if (curr->middle == nullptr) {         // fuse the node when middle child is nullptr
                fusedNode = new Node(curr->left->small, curr->small);
            }
            tree->root = fusedNode;
            return;
        }
        if (curr->numKeys == 2) {       // if there are 2 values in node, and you need to delete one, just move the deleted one to to large and delete large
            if (curr->small == movieName) {     // case when the small value needs to be removed
                curr->numKeys--;
                curr->small = curr->large;
                curr->large = "";
            }
            else if (curr->large == movieName) {        // case when the large value needs to be removed
                curr->numKeys--;
                curr->large = "";
            }
        }
        if (movieName < curr->small) {      // if movie name to be deleted is not at current node, but less than small, go to left child
            curr = curr->left;
        }
        else if(curr->large == "" || movieName < curr->large) {     // if movie name is to be deleted and not at current node, but less than large, and greater than large, go to middle child
            curr = curr->middle;
        }
        else {          // if movie name is to be deletd and not at current, but greater than large value, go to right child
            curr = curr->right;
        }
    }
}


bool Tree::search (const std::string &movieName) const {     // recursively call the search function to search for movie name in tree
    return searchRec(root, movieName);
} 

bool Tree::searchRec(Node *node, std::string movieName) const {      // searches and returns if movie passed in is in tree
    if (node != nullptr) {      
        if (node->small == movieName || node->large == movieName) {     // if name found then return true
            return true;
        }
        if (movieName < node->small) {          // if movie is less than the small value at node, go to left child
            return searchRec(node->left, movieName);
        }
        else if (node->large == "" || movieName < node->large) {        // if movie is greater than small, and less than large, go to middle child
            return searchRec(node->middle, movieName);
        }
        else {          // if movie is greater than large, go to right child to search for it
            return searchRec(node->right, movieName);
        }
    }
    return false;       // return false when not found
}
