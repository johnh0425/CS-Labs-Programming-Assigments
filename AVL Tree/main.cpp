#include <iostream>
#include "AVLTree.h"

using namespace std;

int menu() {
  int choice = 0;
  std::cout << std::endl << "Enter menu choice: ";
  std::cout << std::endl;
  std::cout 
    << "1. Insert" << std::endl
    << "2. Print" << std::endl
    << "3. Quit" << std::endl;
  std::cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  std::cin.clear();
  std::cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  int choice = menu();

  std::string entry;
  std::string filename;

  while (choice != 3) {

    if (choice == 1) {
      std::cout << "Enter string to insert: ";
      getline(std::cin, entry);
      std::cout << std::endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();
    } 
    else if (choice == 4) {
      std::cout << "Enter file name: ";
      getline(std::cin, filename);
      std::cout << std::endl;
      tree.visualizeTree(filename);
    }
    //fix buffer just in case non-numeric choice entered
    if (choice != 1 || choice != 2 || choice != 3) {
        choice = menu();
    }
  }

  return 0;
}

/*
// Testing
// testing skinny tree scenario
AVLTree treetest1;
treetest1.insert("apple");
treetest1.insert("banana");
treetest1.insert("cow");
treetest1.insert("dog");
treetest1.insert("earth");
treetest1.printBalanceFactor();

// testing perfect tree scenario
AVLTree treetest2;
treetest2.insert("group");
treetest2.insert("cat");
treetest2.insert("moose");
treetest2.insert("apple");
treetest2.insert("dog");
treetest2.insert("juice");
treetest2.insert("tree");
treetest2.printBalanceFactor();

// testing double rotation scenario
AVLTree treetest3;
treetest3.insert("group");
treetest3.insert("apple")
treetest3.insert("moose");
treetest3.insert("ocotpus");
treetest3.insert("new");
treetest3.printBalanceFactor();

*/
