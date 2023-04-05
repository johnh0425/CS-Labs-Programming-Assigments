#include "HashTable.h"
#include "WordEntry.h"
#include <string>
#include <iterator>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {		
	size = s;			// sets the size with the parameter
    hashTable = new list<WordEntry>[size];		// constructs a new list
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const std::string &s) {
    int sum = 0;		
    for (char c: s) {		// computes the hash of passed in word so it gets put in the right bucket
		sum = sum * 2;
		sum += c;
    }
    return abs(sum) % size;		// returns the absolute value of sum modulo size so, hash computed is not negative and is not greater than the size of list
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const std::string &s, int score) {
    int bucket = computeHash(s);		// calculates bucket to be placed in
    list<WordEntry>::iterator currentElement = hashTable[bucket].begin();	// sets up iterator to iterate through list
    while (currentElement != hashTable[bucket].end()) {		// stops when end of list is reached
        if (currentElement->getWord() == s) {		// if WordEntry already exists in table, just add a new appearance
            currentElement->addNewAppearance(score);
            return;
        }
		currentElement++;		// keep incrementing when word is found or end is reached
    }
	WordEntry newEntry = WordEntry(s, score);		// if not in list, push word to next empty slot
    hashTable[bucket].push_back(newEntry);
    return;
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const std::string &s) {		// gets the average of word in hashTable
    int bucket = computeHash(s);		// calculates bucket that word should be in
    list<WordEntry>::iterator currentElement = hashTable[bucket].begin();	// sets up iterator to iterate through list
    while (currentElement != hashTable[bucket].end()) {		// stops when end of list is reached
        if ((currentElement->getWord() == s)) {		// if word is found in the table, just call getAverage function on word
            return currentElement->getAverage();
        }
		++currentElement;		// keep incrementing when word is found or end is reached
    }
	return 2.0;		// return 2.0 when word is not in table
}


/* contains
* input: string word
* output: true if word is in the hash table
* false if word is not in the hash table
*/
bool HashTable::contains(const std::string &s) {			// determines if a word is in hashTable
    int bucket = computeHash(s);	// calculates bucket that word should be in
    list<WordEntry>::iterator currentElement = hashTable[bucket].begin();	// sets up iterator to iterate through list
    while (currentElement != hashTable[bucket].end()) {		// stops when end of list is reached
        if ((currentElement->getWord() == s)) {		// if word is found in the table, return true to indicate the word is in table
            return true;
        }
		++currentElement;		// keep incrementing when word is found or end is reached
    }
    return false;		// returns false if word is not in table
}

/*
int main() {
	// declare a few needed variables for inputing the data
	string line;    
	int score;
	string message = " ";
	
	// open input file
	ifstream myfile("movieReviews.txt");
	if (myfile.fail()) {
	    cout << "could not open file" << endl;
	    exit(1);
	}

	//create hash table
	HashTable table(20071);
	while (!myfile.eof()) {
	    myfile >> score;     // get score
	    myfile.get();        // get blank space
	    getline(myfile, line);
	    int len = line.size();
	    while(len > 0) {     // identify all individual strings
	        string sub;
	        len = line.find(" ");
	        if (len > 0) {
	            sub = line.substr(0, len);
	            line = line.substr(len + 1, line.size());
	        }
	        else {
	            sub = line.substr(0, line.size() - 1);
	        }
	        table.put(sub, score); // insert string with the score
	    }
	}
	// after data is entered in hash function
	// prompt user for a new movie review
	while(message.length() > 0) {
	    cout << "enter a review -- Press return to exit: " << endl;
	    getline(cin, message);
	
	    // used for calculating the average
	    double sum = 0;
	    int count = 0;
	    
	    double sentiment = 0.0;
	    
	    size_t len = message.size();
	    // get each individual word from the input
	    while(len != string::npos) {
	        string sub;
	        len = message.find(" ");
	        if (len != string::npos) {
	            sub = message.substr(0, len);
	            message = message.substr(len + 1, message.size());
	        }
	        else {
	            sub = message;
	        }
	        // calculate the score of each word
	        sum += table.getAverage(sub);
	        ++count;
	    }
	
	    if (message.size() > 0) {
	    	sentiment = sum / count;
	        cout << "The review has an average value of " << sentiment << endl;
	        if (sentiment >= 3.0) {
	        	cout << "Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 2.0) {
	        	cout << "Somewhat Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 1.0) {
	        	cout << "Somewhat Negative Sentim	ent" << endl;
	        }
	        else {
	        	cout << "Negative Sentiment" << endl;
	        }
	        cout << endl;
	    }
	}
	
	return 0;
}*/