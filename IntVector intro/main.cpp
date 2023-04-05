#include "IntVector.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    IntVector v1 = IntVector(5, 5);
    IntVector v2;
    IntVector v3 = IntVector(5);
    if (v1.empty()) {
        cout << "Vector is empty." << endl;
    }
    else if (!v1.empty()) {
        cout << "Vector is not empty." << endl;
    }
    if (v2.empty()) {
        cout << "Vector is empty." << endl;
    }
    else if (!v2.empty()) {
        cout << "Vector is not empty." << endl;
    }
    if (v3.empty()) {
        cout << "Vector is empty." << endl;
    }
    else if (!v3.empty()) {
        cout << "Vector is not empty." << endl;
    }

    cout << "The size of vector 1 is: " << v1.size() << endl;
    cout << "The size of vector 2 is: " << v2.size() << endl;
    cout << "The size of vector 3 is: " << v3.size() << endl;

    cout << "The capacity of vector 1 is: " << v1.capacity() << endl;
    cout << "The capacity of vector 2 is: " << v2.capacity() << endl;
    cout << "The capacity of vector 3 is: " << v3.capacity() << endl;

    cout << "First index of vector 1 is: " << v1.front() << endl;
    cout << "Last index of vector 1 is: " << v1.back() << endl;
    cout << "First index of vector 3 is: " << v1.front() << endl;
    cout << "Last index of vector 3 is: " << v1.back() << endl;

    cout << "Vector 1 is: ";
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ",";
    }
    cout << endl;

    cout << "Vector 3 is: ";
    cout << v3.at(3) << endl;

    cout << "Vector 2 is: ";
    cout << v2.at(3) << endl;

}