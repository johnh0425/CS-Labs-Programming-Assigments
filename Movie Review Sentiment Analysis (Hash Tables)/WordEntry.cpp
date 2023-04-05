#include "WordEntry.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

/* WordEntry contructor
* input: the string text (word) and the intial score the
*         word should be assigned to
*  note that numAppearances should be set to 1 here
*/

WordEntry::WordEntry(const std::string &text, int score)		// default constructor for word entry
 : word(text), numAppearances(1), totalScore(score) {
	 
}

/* addNewAppearance
* input integer that is a new score for a word that is
* already in the hash table
* function should increase total score by s
* also should increase numAppearances
*/
void WordEntry::addNewAppearance(int s) {		// adds a new appearance for a word that is already in hash by incrementing number of appearces and adding to score
	totalScore += s;
	++numAppearances;
}

/*getWord
* this accessor function is needed
* particularly in the HashTable code to get the word to be
* used for the hash value
* simple accessor function  
*/
const std::string & WordEntry::getWord() {		// returns the word of the WordEntry 
    return word;
}

/* getAverage
*  returns the average score of the word
*  based on totalScore and numAppearances
*  note that typecasting -- turning one of the integers
*  to a double will be necessary to avoid integer division
*/
double WordEntry::getAverage() {			// returns the average of the WordEntry
	return static_cast<double>(totalScore) / numAppearances;
}