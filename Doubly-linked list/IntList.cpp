#include "IntList.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Default List Constructor
IntList::IntList() {
    head = nullptr;         // sets both head and tail to nullptr meaning an empty list
    tail = nullptr;
}

// List Destructor
IntList::~IntList() {
    while (head != nullptr) {       // Stops calling pop front when list is empty
        pop_front();
    }
}

// Creates a new node and place it in the front of list
void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);     // Allocate new node
    if (!empty()) {         // checks case when list is empty
        head->prev = newNode;
    }
    newNode->next = head;
    newNode->prev = nullptr;
    this->head = newNode;
    if (tail == nullptr) {      // points tail to new node when it was empty
        tail = head;
    }
}

// Removes the first node in list
void IntList::pop_front() {
    if (empty()) {          // checks if list is empty
        return;
    }
    IntNode* nextHead = head->next;
    delete head;
    head = nextHead;
    if (nextHead == nullptr) {      // checks to see if list is empty after removing node
        return;
    }
    nextHead->prev = nullptr;
    if (head == nullptr) {      // sets tail node equal to head if list is empty
        tail = nullptr;
    }
}

// Creates a new node and places it in the back of list
void IntList::push_back(int value) {
    if (head == nullptr) {              // checks if list is empty
        push_front(value);
    }
    else {                    // pushes new allocated node to the back of list
        IntNode* newNode = new IntNode(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        newNode->next = nullptr;
    }
}

// Removes last node from list
void IntList::pop_back() {
    IntNode* newTail = tail->prev;
    if (head == nullptr) {          // checks to see if list is empty
        return;
    }
    else if (head == tail) {     // checks to see if there is only 1 node in list, if so you need to set head and tail to nullptr
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else {                          // removes last node from list
        newTail->next = nullptr;
        delete tail;
        tail = newTail;
    }
}

// checks to see if list is empty
bool IntList::empty() const {
    if (head == nullptr) {          // return true when empty
        return true;
    }
    else {                      // return false when not empty
        return false;
    }
}

// Prints out the list seperated by spaces when using << operator
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* print = rhs.head;
    if (rhs.head == nullptr) {      // checks if list is empty
        return out;
    }
    else {  
        while (print->next != nullptr) {     // stops on last node
            out << print->data << " ";
            print = print->next;
        }
        out << print->data;          // prints out last node of list
        return out;
    }
}

// Prints list in reverse
void IntList::printReverse() const {
    if (head == nullptr) {              // checks if list is empty
        return;
    }
    for (IntNode* printRev = tail; printRev->prev != nullptr; printRev = printRev->prev) {      // Stops on the first node of list
        std::cout << printRev->data << " ";
    }
    std::cout << head->data;     // prints out the first node
}

// Prints the first node (head) of list
void IntList::front() {
    std::cout << head->data;
}

// Prints the last node (tail) of list
void IntList::back() {
    std::cout << tail->data;
}