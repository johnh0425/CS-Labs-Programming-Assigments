#include "Tree.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void printOrders(Tree *tree) {
  std::cout << "Preorder = ";
  tree->preOrder( );      // print tree in pre order
  std::cout << "Inorder = ";
  tree->inOrder( );       // print tree in order
  std::cout << "Postorder = ";
  tree->postOrder( );     // print tree in post order
}

int menu() {
  int choice = 0;
  std::cout << std::endl << "Enter menu choice: ";    // prints out menu options
  std::cout << std::endl;
  std::cout 
    << "1. Insert" << std::endl
    << "2. Remove" << std::endl
    << "3. Print" << std::endl
    << "4. Search" << std::endl
    << "5. Quit" << std::endl;
  std::cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  std::cin.clear();
  std::cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  Tree tree;

  int choice = menu();

  std::string entry;
  
  while (choice != 5) {
    if (choice == 1) {
      std::cout << "Enter movie title to insert: ";
      getline(std::cin, entry);
      std::cout << std::endl;
      
      tree.insert(entry);       // inserts entry into tree
      
    } else if (choice == 2) {
      try {
        std::cout << "Enter movie title to remove: ";
        getline(std::cin, entry);       
        std::cout << std::endl;
      
        tree.remove(entry);     // removes entry from tree
      }
      catch (runtime_error &excpt) {    // catch the exception thrown when parent node is full during removal
        cout << excpt.what() << endl;
      }
    } else if (choice == 3) {
      printOrders(&tree);         // prints tree in preorder, inorder, and postorder
      
    } else if (choice == 4) {
      std::cout << "Enter movie title to search for: ";
      getline(std::cin, entry);
      std::cout << std::endl;
      
      if (tree.search(entry)) {           // searchs for entry in tree
        std::cout << "Found" << std::endl;  
      } else {
        std::cout << "Not Found" << std::endl;
      }
    }

    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }
  
  return 0;
}

/*  Testcases
Testing case for straight diagonal right tree
1
a
1
b
1
c
1
d
1
e
3
5

Testing remove 
1
b
1
c
1
d
2
c
3
1
e
1
f
1
g
2
d
3
5

Testing deleting root
1
b
1
a
1
c
2
b
3
5


*/