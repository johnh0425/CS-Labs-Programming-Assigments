#include "IntVector.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    IntVector v1 = IntVector(49, 5);
    IntVector v2;
    IntVector v3 = IntVector(5);

    // Test resize(100)
    
    cout << "Vector 1 is: ";
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ",";
    }
    cout << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    v1.resize(100);
    cout << "Vector 1 is: ";
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ",";
    }
    cout << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    
    // Test assign()
    /*
    cout << "Vector 1 is: ";
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ",";
    }
    cout << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    v1.assign(100, 5);
    cout << "Vector 1 is: ";
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ",";
    }
    cout << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
*/

}