#include "Heap.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Heap::Heap() {          // default constructor
    numItems = 0;           // sets the size of array to 0 meaning empty heap
}

void Heap::enqueue ( PrintJob* newJob) {            // Insert Printjob to the end of array
    if (numItems >= 10) {       // returns if array is full
        return;
    }
    else {
        int currInd = numItems;
        arr[numItems] = newJob;     // adds PrintJob to the end of array
        while (currInd > 0) {
            int parentInd = (currInd - 1) / 2;          // percolates new PrintJob up to follow max heap rules
            if (arr[currInd]->getPriority() <= arr[parentInd]->getPriority()) {         // if new PrintJob is less the parent, that heap rules are met
                return;
            }
            else {
                PrintJob* swap = arr[parentInd];            // swap new PrintJob and parent
                arr[parentInd] = arr[currInd];
                arr[currInd] = swap;
                currInd = parentInd;
            }
        }
        numItems++;             // increments array size
    }
}

void Heap::dequeue ( ) {            // removes a PrintJob from heap
    if (numItems == 0) {            // if array is empty, return since there is nothing to remove
        return;
    }
    PrintJob* swap = arr[0];        // move the PrintJob to be removed to the end of array
    arr[0] = arr[numItems-1];
    arr[numItems-1] = swap;
    numItems--;                 // decrement the array size to the PrintJob at the end

    for (int i = numItems / 2 - 1; i >= 0; i--) {
        trickleDown(i, numItems);               // call trickle down to follow max heap rules after removing a PrintJob
    }
}

PrintJob* Heap::highest ( ) {           // returns the root of the heap
    if (numItems == 0) {
        return nullptr;
    }
    else {  
        return arr[0];              // returns index 0 which is heap root
    }   
}

void Heap::print ( ) {          // print PrintJob at the root of the heap, index 0
    if (numItems == 0) {
        return;
    }
    std::cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " 
    << arr[0]->getPages() << std::endl;
}

void Heap::trickleDown(int moveDownIndex, int size) {       // called by dequeue function to follow max heap rule after removing PrintJob
    int childIndex = 2 * moveDownIndex + 1;
    int value = arr[moveDownIndex]->getPriority(); 
    while (childIndex < size) {                         
        int maxValue = value;
        int maxIndex = -1;
        for (int i = 0; i < 2 && i + childIndex < size; i++) {
            if (arr[i + childIndex]->getPriority() > maxValue) {    // finds the largest value between parent and child, if child is larger, then the maxIndex is set to be swapped later
                maxValue = arr[i + childIndex]->getPriority();
                maxIndex = i + childIndex;
            }
        }
        if (maxValue == value) {            // ends loop if the max value is in the correct position in the heap
            return;
        }
        else {
            PrintJob* swap = arr[moveDownIndex];                // swaps the index to be moved down with the index with the max value
            arr[moveDownIndex] = arr[maxIndex];
            arr[maxIndex] = swap;
            moveDownIndex = maxIndex;
            childIndex = 2 * moveDownIndex + 1;
        }
    }
}