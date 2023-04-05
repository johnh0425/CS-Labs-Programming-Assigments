#include "IntList.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList() {
    delete head;
    head = nullptr;
    tail = nullptr;
}
void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head;
    this->head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}
void IntList::pop_front() {
    if (empty()) {
        return;
    }
    else {
        IntNode *temp = head -> next;
        delete head;
        head = temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}
bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
const int &IntList::front() const {
    return head->value;
}
const int &IntList::back() const {
    IntNode *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->value;
}
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *temp = rhs.head;
    if (rhs.head == nullptr) {
        return out;
    }
    else {
        while (temp->next != nullptr) {
            out << temp->value << " ";
            temp = temp->next;
        }
        out << temp->value;
        return out;
    }
}