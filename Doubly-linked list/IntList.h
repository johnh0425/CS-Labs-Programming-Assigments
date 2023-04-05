#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

// IntNode struct
struct IntNode {
    int data;       
    IntNode *prev;      // prev pointer (points to the prev node)
    IntNode *next;      // next pointer (points to the next node)
    IntNode(int data) : data(data), prev(0), next(0) {}        // newly allocated node will have data along with prev and next set to nullptr
};

// IntList class
class IntList {
 private:
	IntNode *head;          // head pointer (first node of list)
	IntNode *tail;          // tail pointer (last node of list)
 public:
    // Default List Constructor
    IntList();
    // Destructor
    ~IntList();
    void front();       // prints head
    void back();        // prints tail
    void push_front(int value);         // creates a new node with the data "value" and pushes it to the front of list
    void pop_front();                   // deletes front node of list
    void push_back(int value);          // creates a new node with the data "value" and pushes it to back of list
    void pop_back();                    // deletes last node of list
    bool empty() const;                 // checks if list is empty
    friend ostream & operator<<(ostream &out, const IntList &rhs);      // creates a operator << that allows from printing out list
    void printReverse() const;      // prints out list in reverse
};

#endif