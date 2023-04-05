#include <iostream>
#include <vector>
#include <string>
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
 private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
 public:
    ShoppingCart();
    ShoppingCart(string cName, string cDate);
    string customerName() const;
    string date() const;
    void addItem(ItemToPurchase itemToPurchase);
    void removeItem(string itemName);
    void modifyItem(ItemToPurchase itemToPurchase);
    int numItemsInCart();
    int costOfCart();
    void printTotal();
    void printDescriptions();
};
#endif