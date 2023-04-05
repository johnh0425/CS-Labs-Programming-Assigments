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
    return tail->value;
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

IntList::IntList(const IntList &cpy) :head(nullptr), tail(nullptr) {  
    if (cpy.head != nullptr) {
        for (IntNode *temp = cpy.head; temp != nullptr; temp = temp -> next) {
            push_back(temp->value);
        }
    }

}

IntList & IntList::operator=(const IntList &rhs) {
    if (this == &rhs) {
        return *this;
    }
    else if (rhs.head == nullptr) {
        clear();
        return *this;
    }
    else {
        clear();
        for (IntNode *temp = rhs.head; temp != nullptr; temp = temp -> next) {
            push_back(temp->value);
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    if (this->head == nullptr) {
        this->head = newNode;
        tail = newNode;
        newNode->next = nullptr;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        newNode->next = nullptr;
    }
}

void IntList::clear() {
    for (IntNode *temp = head; temp != nullptr; temp = head) {
        head = temp -> next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::selection_sort() { // this will be on your final 
    int tempVal = 0;
    for (IntNode *i = head; i != nullptr; i = i -> next) {
        IntNode *smallest = i;
        for (IntNode *temp = i; temp != nullptr; temp = temp -> next) {
            if (smallest->value > temp->value) {
                smallest = temp;
            }
        }
        tempVal = smallest -> value;
        smallest -> value = i -> value;
        i -> value = tempVal;
    }
}

void IntList::insert_ordered(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        push_front(value);
        return;
    }
    else if (newNode -> value <= head -> value){
        push_front(value);
        return;
    }
    else if(newNode -> value >= tail -> value) {
        push_back(value);
        return;
    }
    else {
        IntNode *prev = head;
        for (IntNode *curr = prev -> next; curr != nullptr; curr = curr -> next) {
            if ((newNode -> value) <= (curr -> value)) {
                newNode->next = curr;
                prev->next = newNode;
                break;
            }
            prev = curr;
        }
    }
}

void IntList::remove_duplicates() {
    for (IntNode *i = head; i != nullptr; i = i -> next) {
        IntNode *prev = i;
        for (IntNode *curr = prev->next; curr != nullptr; curr = prev -> next) {
            if (i -> value == curr -> value) {
                prev -> next = curr -> next;
                delete curr;
                if (curr == tail) {
                    tail = prev;
                }
            }
            else {
                prev = prev -> next;
            }
        }

    }
}   
