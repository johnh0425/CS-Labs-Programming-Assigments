#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;        // sets the maximum size of the array, inserts more than the set number will throw an exception
template<typename T>            // creates template of name T
class stack {                   // creats a class called stack
 private:
    T data[MAX_SIZE];           // array of variable T with size of 20
    int size;                   // indicates how many spots have been already taken
 public:            
    stack();
    void push(T val);
    void pop();
    void pop_two();
    T top();
    bool empty();

};

template<typename T> 
stack<T>::stack() {             // default constructor, creating a stack of size 0 meaning empty
    size = 0;
}

template<typename T> 
void stack<T>::push(T val) {        // pushes or adds a number to the stack
    if (size >= 20) {                  // if size if full meaning 20 or more, an exception should be thrown
        throw std::overflow_error("Called push on full stack.");     // throwing exceptions
    }
    data[size] = val;               // sets the value to the next available spot in the stack
    size++;                         // increment stack since the size of occupied just increased by 1
}

template<typename T> 
void stack<T>::pop() {              // takes one value off the stack
    if (size <= 0) {                // if the stack is empty, an exception should be thrown since you are popping out of empty stack
        throw std::out_of_range("Called pop on empty stack.");     // throwing exceptions
    }
    size--;                         // decrements size since you are decreasing the number of values occupied in stack by 1
}

template<typename T> 
void stack<T>::pop_two() {          // takes two values off the stack
    if (size == 0) {                // if size is 0, the stack is empty and an exception will be thrown for popping out of empty stack
        throw std::out_of_range("Called pop_two on empty stack.");     // throwing exceptions
    }
    else if (size == 1) {           // if size is 1, an exception should be thrown since you are taking off way more than what you have in the stack
        throw std::out_of_range("Called pop_two on a stack of size 1."); 
    }
    size = size - 2;                // decreaments the size by 2 since you are taking 2 values off the stack
}

template<typename T> 
T stack<T>::top() {                 // returns the top value in the stack
    if (size <= 0) {                // if size is 0 , meaning stack is empty and exception must be thrown since nothing can be returned
        throw std::underflow_error("Called top on empty stack.");     // throwing exceptions
    }
    return data[size - 1];          // returns the top of stack that being the last value (size - 1)
}

template<typename T> 
bool stack<T>::empty() {            // checks to see if stack is empty
    if (size == 0) {                // stack is empty if size is 0 which returns true 
        return true;                
    }
    else {                          // if not empty then stack is occupied returning false
        return false;   
    }
}

#endif
