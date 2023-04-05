#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

 private:
	std::string word;		// word to inserted into hash, use this to determine and compute hash for when inserting
	int numAppearances;		// number of appearances in hash, updates when inserting into hash when it already exists in hashTable
	int totalScore;			// score of word in hash, updates when already in hash and is being inserted
 public:
	WordEntry(const std::string &, int);		// default constructor 
	void addNewAppearance(int);			// adds a new appearance to a WordEntry when already in HashTable
	const std::string & getWord();			// gets the word of the WordEntry to check if in hashTable
	double getAverage();				// gets the average of the WordEntry in hashTable
};
#endif