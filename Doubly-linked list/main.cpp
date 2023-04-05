#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
    // Constructs an empty list called list1
    IntList list1;

    // test push_front and push_back
    std::cout << "Testing Pushfront and Pushback" << std::endl;
    std::cout << "Pushback 10" << std::endl;
    list1.push_back(10);
    std::cout << "Pushback 20" << std::endl;
    list1.push_back(20);
    std::cout << "Pushfront 40" << std::endl;
    list1.push_front(40);
    std::cout << "Pushfront 30" << std::endl;
    list1.push_front(30);
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "Head: ";
    list1.front();
    std::cout << std::endl;
    std::cout << "Tail: ";
    list1.back();
    std::cout << std::endl;
    std::cout << "Pushback 20" << std::endl;
    list1.push_back(20);
    std::cout << "Pushfront 40" << std::endl;
    list1.push_front(40);
    std::cout << "list1: " << list1 << std::endl;

    // test pop_back and pop_front
    std::cout << "Testing Popback and Popfront" << std::endl;
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "Popping back" << std::endl;
    list1.pop_back();
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "Head: ";
    list1.front();
    std::cout << std::endl;
    std::cout << "Tail: ";
    list1.back();
    std::cout << std::endl;
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "Popping front" << std::endl;
    list1.pop_front();
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "Head: ";
    list1.front();
    std::cout << std::endl;
    std::cout << "Tail: ";
    list1.back();
    std::cout << std::endl;
    std::cout << "Popping front" << std::endl;
    list1.pop_front();
    std::cout << "Popping front" << std::endl;
    list1.pop_front();
    std::cout << "Popping back" << std::endl;
    list1.pop_back();
    std::cout << "Popping back" << std::endl;
    list1.pop_back();

    // Testing Print in Reverse
    std::cout << "Testing Print in Reverse" << std::endl;
    std::cout << "Pushback 10" << std::endl;
    list1.push_back(10);
    std::cout << "Pushback 20" << std::endl;
    list1.push_back(20);
    std::cout << "Pushfront 40" << std::endl;
    list1.push_front(40);
    std::cout << "list: " << list1 << std::endl;
    std::cout << "Print in reverse: ";
    list1.printReverse();
    std::cout << std::endl;


    std::cout << "Destructor Called" << std::endl;
    return 0;
}