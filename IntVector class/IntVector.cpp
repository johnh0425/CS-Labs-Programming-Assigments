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
        _data = new int[_capacity];  
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
int &IntVector::at(unsigned index) {
    int *ptr1 = _data;
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return ptr1[index];
    }
}
void IntVector::insert(unsigned index, int value) {
    _size = _size + 1;
    if (_size > _capacity) {
        expand();
    }
    if (index >= _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    for (unsigned int i = index; i <= _size - 1; ++i) {
        _data[i + 1] = _data[i];
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index; i < _size - 1; ++i) {
        _data[i] = _data[i+1];
    }
    _size = _size - 1;
}

const int &IntVector::front() const {
    return *_data;
}

int & IntVector::front() {
    return *_data;
}

const int &IntVector::back() const {
    int *ptr = _data;
    return ptr[_size - 1];
}   

int &IntVector::back() {
    int *ptr = _data;
    return ptr[_size - 1];
}

void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if ((_capacity * 2) > ((n - _capacity)+ _capacity)) {
            expand();
        }
        else {
            expand(n - _capacity);
        }
    }
    _size = n;
    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = value;
    }
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) {
        expand();
    }
    _size = _size + 1;
    _data[_size - 1] = value;
}

void IntVector::pop_back() {
    _size = _size - 1;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size >= _capacity) {
        if ((_capacity * 2) > ((size - _capacity)+ _capacity)) {
            expand();
        }
        else {
            expand(size - _capacity);
        }
    }
    if (_size > size) {
        _size = size;
    }
    else if (_size < size) {
        for (unsigned int i = _size; i < size; ++i) {
            _data[i] = value;
        }
        _size = size;
    }

}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        _capacity = n;
    }
}

void IntVector::expand() {
    if (_capacity == 0) {
        _capacity = 1;
        _data = new int[_capacity];  
    }
    else {
        _capacity = _capacity * 2;

        // create a new array with capacity
        int *data = new int[_capacity];

        // copy old array content up till _size inside new array
        for (unsigned int i = 0; i < _size; ++i) {
            data[i] = _data[i];
        }
        // delete the old array
        delete[] _data;

        // assign to old array new arrays adress
        _data = data;
    }
}

void IntVector::expand(unsigned amount) {
    _capacity = _capacity + amount;
    int *data = new int[_capacity];
    for (unsigned int i = 0; i < _size; ++i) {
        data[i] = _data[i];
    }
    delete[] _data;
    _data = data;

}
    

