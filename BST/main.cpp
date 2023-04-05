#include <iostream>
#include <limits>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {      // prints the preorder, inorder, and postorder of the binary tree
  std::cout << "Preorder = ";
  tree->preOrder( );
  std::cout << std::endl;
  std::cout << "Inorder = ";
  tree->inOrder( );
  std::cout << std::endl;
  std::cout << "Postorder = ";
  tree->postOrder( );
  std::cout << std::endl;
}

int menu() {
  int choice = 0;
  std::cout << std::endl << "Enter menu choice: ";
  std::cout << std::endl;
  std::cout 
    << "1. Insert" << std::endl
    << "2. Remove" << std::endl
    << "3. Print" << std::endl
    << "4. Search" << std::endl
    << "5. Smallest" << std::endl
    << "6. Largest" << std::endl
    << "7. Height" << std::endl
    << "8. Quit" << std::endl;
  std::cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  std::cin.clear();
  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
    BSTree tree;

    int choice = menu();

    std::string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          std::cout << "Enter string to insert: " << std::endl;     // tests inserting new string to tree
          getline(std::cin, entry);
          tree.insert(entry);     
        }

        else if (choice == 2) {
          std::cout << "Enter string to remove: " << std::endl;     // tests removing string from tree
          getline(std::cin, entry);
          tree.remove(entry);
        }

        else if (choice == 3) {
          printOrders(&tree);         // tests printing the orders of the tree
        } 

        else if (choice == 4) {
          std::cout << "Enter string to search for: " << std::endl;
          getline(std::cin, entry);
          if (tree.search(entry)) {       // test searching for string in tree  
            std::cout << "Found" << std::endl;
          }
          else {
            std::cout << "Not Found" << std::endl;
          }
        } 

        else if (choice == 5) {
          std::cout << "Smallest: ";
          if (tree.smallest() != "") { 
            std::cout << tree.smallest() << std::endl;      // testing return smallest data in tree
          }
          else {
            std::cout << std::endl;
          }
        } 

        else if (choice == 6) {
          std::cout << "Largest: ";
          if (tree.largest() != "") {
            std::cout << tree.largest() << std::endl;     // test returning largest data in tree
          }
          else {
            std::cout << std::endl;
          }
        } 

        else if (choice == 7) {
          std::cout << "Enter string: " << std::endl;
          getline(std::cin, entry);
          std::cout << "Height of subtree rooted at " << entry << ": " << tree.height(entry) << std::endl;    // test returning height of a string
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}

// #include "BSTree.h"
// #include "Node.h"
// #include <iostream>
// using namespace std;

// int main() {
//     // Constructs an empty tree
//     BSTree tree1;

//     // test insert and search
//     cout << "Testing insert" << endl;
//     cout << "Inserting moon" << endl;
//     tree1.insert("moon");
//     cout << "Inserting lake" << endl;
//     tree1.insert("lake");
//     cout << "Inserting truck" << endl;
//     tree1.insert("truck");
//     cout << "Inserting cat" << endl;
//     tree1.insert("cat");
//     cout << "Inserting apple" << endl;
//     tree1.insert("apple");
//     cout << "Inserting crow" << endl;
//     tree1.insert("crow");
//     cout << "Inserting lake" << endl;
//     tree1.insert("lake");
//     cout << "Inserting sun" << endl;
//     tree1.insert("sun");
//     cout << "Inserting cat" << endl;
//     tree1.insert("cat");

//     cout << endl;
//     // testing printing orders
//     cout << "Printing in order: ";
//     tree1.inOrder();
//     cout << endl;
//     cout << "Printing pre order: ";
//     tree1.preOrder();
//     cout << endl;
//     cout << "Printing post order: ";
//     tree1.postOrder();
//     cout << endl;

//     cout << endl;
//     // testing search for string not in tree
//     cout << "Searching for dog (not in tree)" << endl;
//     if (tree1.search("dog")) {
//         cout << "Dog is found in tree" << endl;
//     }
//     else {
//         cout << "Dog is NOT found in tree" << endl;
//     }
//     // testing search for string in tree
//     cout << "Searching for cat (in tree)" << endl;
//     if (tree1.search("cat")) {
//         cout << "Cat is found in tree" << endl;
//     }
//     else {
//         cout << "Cat is NOT found in tree" << endl;
//     }

//     cout << endl;
//     // testing larget and smallest
//     cout << "Printing largest in tree: " << tree1.largest() << endl;
//     cout << "Printing smallest in tree: " << tree1.smallest() << endl;

//     cout << endl;
//     // Testing height
//     cout << "Printing height of moon(0): " << tree1.height("moon") << endl;
//     cout << "Printing height of truck(1): " << tree1.height("truck") << endl;
//     cout << "Printing height of crow(3): " << tree1.height("crow") << endl;
//     cout << "Printing height of lake(1): " << tree1.height("lake") << endl;
//     cout << "Printing height of cat(2): " << tree1.height("cat") << endl;
//     cout << "Printing height of apple(3): " << tree1.height("apple") << endl;

//     cout << endl;
//     // Testing remove
//     cout << "Removing crow" << endl;
//     tree1.remove("crow");
//     cout << "List in order after removing crow: ";
//     tree1.inOrder();
//     cout << endl;
//     cout << "Removing lake" << endl;
//     tree1.remove("lake");
//     cout << "List in order after removing lake: ";
//     tree1.inOrder();
//     cout << endl;
//     cout << "Removing dog" << endl;
//     tree1.remove("dog");
//     cout << "List in order after removing dog: ";
//     tree1.inOrder();
//     cout << endl;









// }