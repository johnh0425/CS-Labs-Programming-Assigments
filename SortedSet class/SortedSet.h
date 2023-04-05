#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"
using namespace std;

class SortedSet : public IntList {
    public:
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    const bool in(int value);
    const SortedSet &operator|(SortedSet &rhs);
    const SortedSet &operator&(SortedSet &rhs);
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet &operator|=(SortedSet &rhs);
    SortedSet &operator&=(SortedSet &rhs);
};

#endif