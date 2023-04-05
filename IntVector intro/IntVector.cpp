#include "IntVector.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    _data = nullptr;
    if (_size != 0) {
        _data = new int[_size];  
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = value;
        }
    }
}
IntVector::~IntVector() {
    delete[] _data;
    _data = nullptr;
}
unsigned IntVector::size() const {
    return _size;
}
unsigned IntVector::capacity() const {
    return _capacity;
}
bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}
const int &IntVector::at(unsigned index) const {
    int *ptr1 = _data;
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return ptr1[index];
    }
} 
const int &IntVector::front() const {
    return *_data;
}
const int &IntVector::back() const {
    int *ptr = _data;
    return ptr[_size - 1];
}   