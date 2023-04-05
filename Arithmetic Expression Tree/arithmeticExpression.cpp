#include "arithmeticExpression.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int arithmeticExpression::priority(char op){        // returns the priority of a character
    int priority = 0;
    if(op == '('){                      // parentheses have priority of 3
        priority =  3;
    }
    else if(op == '*' || op == '/'){        // * and / have priotiy of 2
        priority = 2;
    }
    else if(op == '+' || op == '-'){        // + and - have priority of 1
        priority = 1;
    }
    return priority;
}

std::string arithmeticExpression::infix_to_postfix(){        // turns a in order expression of post order
    stack<char> s;                      // stack of chars called s
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){     // loops through expression
        c = infixExpression.at(i);              // gets each character of expression at a time
        if(c == ' '){                           // ignores spaces
            continue;   
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);      // if c is a ( push to stack
            }
            else if(c == ')'){              
                while(s.top() != '('){      // while the top of stack is not a ( add the top character in stack to oss string and pop each time
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){      // while the stack is not empty and priority of c is less than or equal to the top of stack
                    if(s.top() == '('){    
                        break;
                    }
                    oss << s.top();         // add top character to string oss followed by a pop of the stack each time
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){      // add rest of stack to string oss followed by pop until stack is empty
        oss << s.top();
        s.pop();
    }
    return oss.str();           // return the new post order string
}

void arithmeticExpression::visualizeTree(const std::string &outputFilename){     // helps visualize the tree
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        std::cout<<"Error opening "<< outputFilename<<std::endl;      // if file does not open, out error
        return;
    }
    outFS<<"digraph G {"<<std::endl;
    visualizeTree(outFS,root);      // calls visualizeTree function to visualize the tree
    outFS<<"}";
    outFS.close();
    std::string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    std::string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

arithmeticExpression::arithmeticExpression(const std::string &expression) {      // default constructor
    infixExpression = expression;           
    root = nullptr;
}

void arithmeticExpression::buildTree() {        // builds the tree from a post order expression
    std::string buildT = infix_to_postfix();
    stack<TreeNode*> stack;         // creats a stack of type TreeNode
    char ch;
    for (unsigned int i = 0; i < buildT.size(); ++i) {      // loops until reaches end of string
        ch = buildT.at(i);
        if (ch == ' ') {        // skips spaces
            continue;
        }

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {        // if character is a operator
            TreeNode* oper = new TreeNode(ch, ch);      // create a new TreeNode
            if(!stack.empty()) {            // if stack is not empty set the operator right pointer to point to top of stack and pop
                oper->right = stack.top();
                stack.pop();
            }
            if(!stack.empty()) {   // if stack is not empty set the operator left pointer to point to top of stack and pop
                oper->left = stack.top();
                stack.pop();
            }
            stack.push(oper);       // push the operator node to stack
        }
        else {
            TreeNode* variable = new TreeNode(ch, ch);      // if not an operator just push to stack
            stack.push(variable);
        }
    }
    root = stack.top();         // sets the root to point to the last element in stack and pop afterward
    stack.pop();
}

void arithmeticExpression::infix() {        // call recursively to infix to print tree in order
    infix(root);
}

void arithmeticExpression::prefix() {       // call recursively to prefix to print tree in preorder
    prefix(root);
}

void arithmeticExpression::postfix() {      // call recursively to postfix to print tree in postorder
    postfix(root);
}

void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode *node) {     //  sets up visualize tree
    if (node->right == nullptr && node->left == nullptr) {      // if right and left pointers are null just return
        return;
    }
    if (node->left != nullptr) {        // if the left is not nullptr, print to file the key pointing to the left child
        outFS << "\"" << node->key << "\"" << " -> " << "\"" << node->left->key << "\"" << ";" << std::endl;
    }
    if (node->right != nullptr) {       // if the right is not nullptr, print to file the key pointing to the right child
        outFS << "\"" << node->key << "\"" << " -> " << "\"" << node->right->key << "\"" << ";" << std::endl;
    }
    visualizeTree(outFS, node->right);      // recursively call for right subtree
    visualizeTree(outFS, node->left);       // recursively call for left subtree
}

void arithmeticExpression::infix(TreeNode *node) {      // prints tree in order
    if (node == nullptr) {      // if the node is nullptr return
        return;
    }
    if (node->left != nullptr && node->right != nullptr) {      // if children are not nullptr print the parentheses
        std::cout << "(";   
        infix(node->left);      // left subtree first
        std::cout << node->key;     // print root
        infix(node->right);         // right subtree last
        std::cout << ")";
    }
    else {
        infix(node->left);      // left subtree first
        std::cout << node->key;     // print root
        infix(node->right);         // right subtree last
    }
}

void arithmeticExpression::prefix(TreeNode *node) {     // prints the tree in prefix order
    if (node == nullptr) {      // if node is nullptr, just return
        return;
    }
    std::cout << node->key;     // print root first
    prefix(node->left);     // left subtree second
    prefix(node->right);        // right subtree last
}

void arithmeticExpression::postfix(TreeNode *node) {        // prints the tree in postfix order
    if (node == nullptr) {          // if node is nullptr, just return
        return; 
    }
    postfix(node->left);        // prints left subtree first
    postfix(node->right);       // prints right subtree second
    std::cout << node->key;         // prints root
}