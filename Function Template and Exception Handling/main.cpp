#include <iostream>
#include<vector>
#include <stdexcept>
using namespace std;

template<typename T>    // Function Template
unsigned min_index(const vector<T> &vals, unsigned index) {     // finds the index of the smallest value
    unsigned minInd = index;
    for (unsigned int i = index; i < vals.size(); i++) {        // loops from the passed in index to end of list, finding smallest value
        if (vals.at(minInd) > vals.at(i)) {
            minInd = i;                                 // sets smallest value ind to minInd and returns it
        }
    }
    return minInd;
}

template<typename T>        // Function Template
void selection_sort(vector<T> &vals) {                  // sorts the passed in vector from smallest to biggest
    for (unsigned int i = 0; i < vals.size(); i++) { 
        T sort = vals.at(i);                           
        unsigned min = min_index(vals, i);
        vals.at(i) = vals.at(min);                  // swaps the smallest value index passed from min_index function with i as i loops through list
        vals.at(min) = sort;
    }
}

template<typename T>        // Function Template
T getElement(vector<T> vals, int index) {           // gets the value at the index passed in
    unsigned ind;
    ind = index;
    try {
        if (ind > vals.size()) {            // if index passed in is greater than the size of vector, an exception will be thrown
            throw std::out_of_range("out of range exception occurred");     // throwing exceptions
        }
    }
    catch (const std::out_of_range& excpt) {        // catches exception if thrown
        std::cout << excpt.what() << std::endl;
    }
    return vals.at(index);          // returns the value at the index passed in
}

vector<char> createVector() {       // creates a new vector of char with a random size
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);          // pushes back a char until the vector size is reached
        c++;
    }
    return vals;        // returns vector
}

int main(){
    //Part B
     srand(time(0));
     vector<char> vals = createVector();        // calls function that creates new vector
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){           // loop ends after 10 inputs
         std::cout << "Enter a number: " << std::endl;
         std::cin >> index;
         curChar = getElement(vals,index);      // finds value at inputted index
         std::cout << "Element located at " << index << ": is " << curChar << std::endl;  // returns value at inputted index
    }

    // Selection Sort Tests
    vector<int> integers;       // creates vector of type intgers and pushes back values in unsorted order
    integers.push_back(10);
    integers.push_back(3);
    integers.push_back(5);
    integers.push_back(12);
    std::cout << "Unsorted Integer List: ";      // prints unsorted vector
    for (unsigned int i = 0; i < integers.size(); i++) {
        std::cout << integers.at(i) << " ";
    }
    std::cout << std::endl;
    selection_sort(integers);       // sorts unsorted integer vector
    std::cout << "Sorted Integer List: ";
    for (unsigned int i = 0; i < integers.size(); i++) {        // prints sorted vector
        std::cout << integers.at(i) << " ";
    }
    std::cout << std::endl;

    vector<std::string> words;        // creates vector of type string and pushes back values in unsorted order
    words.push_back("back");
    words.push_back("far");
    words.push_back("air");
    words.push_back("curve");
    words.push_back("fever");
    std::cout << "Unsorted String List: ";
    for (unsigned int i = 0; i < words.size(); i++) {      // prints unsorted vector
        std::cout << words.at(i) << " ";
    }
    std::cout << std::endl;
    selection_sort(words);     // sorts string vector
    std::cout << "Sorted String List: ";
    for (unsigned int i = 0; i < words.size(); i++) {      // prints sorted vector
        std::cout << words.at(i) << " ";
    }
    std::cout << std::endl;

    vector<double> decimal;        // creates vector of type double and pushes back values in unsorted order
    decimal.push_back(4.6);
    decimal.push_back(3.23);
    decimal.push_back(1.7);
    decimal.push_back(3.2);
    decimal.push_back(0.8);
    std::cout << "Unsorted String List: ";
    for (unsigned int i = 0; i < decimal.size(); i++) {      // prints unsorted vector
        std::cout << decimal.at(i) << " ";
    }
    std::cout << std::endl;
    selection_sort(decimal);     // sorts double vector
    std::cout << "Sorted String List: ";
    for (unsigned int i = 0; i < decimal.size(); i++) {      // prints sorted vector
        std::cout << decimal.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
