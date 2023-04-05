#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H  
#include <string>

using namespace std;

class ItemToPurchase{
 public:
    ItemToPurchase();
    ItemToPurchase(string nm, string desc, int p, int quan);
    void setName(string nm);
    void setPrice(int p);
    void setQuantity(int quan);
    void setDescription(string desc);
    string name() const;
    int price() const;
    int quantity() const;
    string description() const;
    void printItemCost() const;
    void printItemDescription() const;


 private:
    string _name;
    int _price;
    int _quantity;
    string _description;

};
#endif