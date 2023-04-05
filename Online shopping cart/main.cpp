#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
void printMenu(ShoppingCart shoppingCart);

int main() {
    ShoppingCart s1;
    string name;
    string date;
    char input;
    cout << "Enter customer's name: ";
    getline(cin, name);
    cout << endl;
    cout << "Enter today's date: ";
    getline(cin, date);
    cout << endl;
    cout << endl;
    s1 = ShoppingCart(name, date);
    cout << "Customer name: " << s1.customerName() << endl;
    cout << "Today's date: " << s1.date() << endl;
    cout << endl;

    printMenu(s1);
    cin >> input;
    while (input != 'a' && input != 'd' && input != 'c' && input != 'i' && input != 'o' && input != 'q') {
        cout << "Choose an option: " << endl;
        cin >> input;
    }
    while (input != 'q'){
        if (input == 'a') {
            ItemToPurchase i1;
            string n;
            string d;
            int p;
            int q;
            cout << endl;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin, n);
            cout << "Enter the item description: " << endl;
            getline(cin, d);
            cout << "Enter the item price: " << endl;
            cin >> p;
            cout << "Enter the item quantity: " << endl;
            cin >> q;
            i1 = ItemToPurchase(n, d, p, q);
            s1.addItem(i1);
            cout << endl;
        }
        else if (input == 'd') {
            string n;
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore(1000, '\n');
            getline(cin, n);
            s1.removeItem(n);
            cout << endl;
        }
        else if (input == 'c') {
            ItemToPurchase i1;
            string n;
            int q;
            cout << endl;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin, n);
            cout << "Enter the new quantity: " << endl;
            cin >> q;
            i1 = ItemToPurchase();
            i1.setName(n);
            i1.setQuantity(q);
            s1.modifyItem(i1);
            cout << endl;
        }
        else if (input == 'i') {
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            s1.printDescriptions();
            cout << endl;
        }
        else if (input == 'o') {
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            s1.printTotal();
            cout << endl;
        }
        printMenu(s1);
        cin >> input;
        while (input != 'a' && input != 'd' && input != 'c' && input != 'i' && input != 'o' && input != 'q') {
            cout << "Choose an option: " << endl;
            cin >> input;
        }
    }
}

void printMenu(ShoppingCart shoppingCarts) {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option: " << endl;
    }