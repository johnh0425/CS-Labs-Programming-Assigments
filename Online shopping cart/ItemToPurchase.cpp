#include "ItemToPurchase.h"
#include <iostream>
#include <string>
using namespace std;

ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(string nm, string desc, int p, int quan) {
    _name = nm;
    _description = desc;
    _price = p;
    _quantity = quan;
}

void ItemToPurchase::setName(string nm) {
    _name = nm;
}

void ItemToPurchase::setPrice(int p){
    _price = p;
}

void ItemToPurchase::setQuantity(int quan) {
    _quantity = quan;
}

void ItemToPurchase::setDescription(string desc) {
    _description = desc;
}

string ItemToPurchase::name() const {
    return _name;
}

int ItemToPurchase::price() const {
    return _price;
}

int ItemToPurchase::quantity() const {
    return _quantity;
}

string ItemToPurchase::description() const {
    return _description;
}

void ItemToPurchase::printItemCost() const {
    int p = price();
    int q = quantity();
    string n = name();
    int totalCost = p * q;
    cout << n << " " << q << " @ $" << p << " = $" << totalCost;
}

void ItemToPurchase::printItemDescription() const {
    cout << name() << ": " << description();
}