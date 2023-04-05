#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	// declare a few needed variables for inputing the data
	std::string line;    
	int score;
	std::string message = " ";
	
	// open input file
	ifstream myfile("movieReviews.txt");
	if (myfile.fail()) {
	    std::cout << "could not open file" << std::endl;
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
	        std::string sub;
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
	    std::cout << "enter a review -- Press return to exit: " << std::endl;
	    getline(std::cin, message);
	
	    // used for calculating the average
	    double sum = 0;
	    int count = 0;
	    
	    double sentiment = 0.0;
	    
	    size_t len = message.size();
	    // get each individual word from the input
	    while(len != string::npos) {
	        std::string sub;
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
	        std::cout << "The review has an average value of " << sentiment << std::endl;
	        if (sentiment >= 3.0) {
	        	std::cout << "Positive Sentiment" << std::endl;
	        }
	        else if (sentiment >= 2.0) {
	        	std::cout << "Somewhat Positive Sentiment" << std::endl;
	        }
	        else if (sentiment >= 1.0) {
	        	std::cout << "Somewhat Negative Sentiment" << std::endl;
	        }
	        else {
	        	std::cout << "Negative Sentiment" << std::endl;
	        }
	        std::cout << std::endl;
	    }
	}
	
	return 0;
}