#include "SortedSet.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

SortedSet::SortedSet() : IntList() {
}

SortedSet::SortedSet(const SortedSet &set) :IntList(set) {
}

SortedSet::SortedSet(const IntList &list):IntList(list) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
    clear();
}

const bool SortedSet::in(int value) {
    IntNode *newNode = new IntNode(value);
    for (IntNode *i = head; i != nullptr; i = i -> next) {
        if (newNode -> value == i -> value) {
            return true;
        }
    }
    return false;
}

const SortedSet &SortedSet::operator|(SortedSet &rhs) {
    SortedSet *newSet = new SortedSet();
    if (!rhs.empty()) {
        for (IntNode *i = rhs.head; i != nullptr; i = i -> next) {
        newSet->push_front(i->value);
    }
    }
    if (!empty()) {
        for (IntNode *i = this->head; i != nullptr; i = i -> next) {
        newSet->push_front(i->value);
    }
    }
    return *newSet;
}

const SortedSet &SortedSet::operator&(SortedSet &rhs) {
    SortedSet *newSet = new SortedSet;
    for (IntNode *i = rhs.head; i != nullptr; i = i -> next) {
        for (IntNode *temp = this->head; temp != nullptr; temp = temp -> next) {
            if (i -> value == temp -> value) {
                newSet->push_front(i->value);
            }
        }
    }
    return *newSet;
}

void SortedSet::add(int value) {
    insert_ordered(value);
}

void SortedSet::push_front(int value) {
    insert_ordered(value);
}

void SortedSet::push_back(int value) {
    insert_ordered(value);
}

void SortedSet::insert_ordered(int value) {
    if (!in(value)) {
        IntList::insert_ordered(value);
    }
}

SortedSet &SortedSet::operator|=(SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet &SortedSet::operator&=(SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}