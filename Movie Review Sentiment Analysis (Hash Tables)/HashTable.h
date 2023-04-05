#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

 private:
	list<WordEntry> *hashTable;			// list of WordEntry (hashTable)
	int size;		// size of list

 public:
	HashTable(int);			// default constructor of hash table
	bool contains(const std::string &);		// checks if passed in value is in hashTable
	double getAverage(const std::string &);		// gets the average of passed in string in hashTable
	void put(const std::string &, int);			// puts value into HashTable, and updates the score if already exists in HashTable
 
 private:
	int computeHash(const std::string &);		// computes the Hash of the value passed in to be inserted into table
};

#endif