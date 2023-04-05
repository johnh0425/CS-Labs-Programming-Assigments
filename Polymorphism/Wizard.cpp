#include "Wizard.h"    
#include <iostream>
#include <string>
using namespace std;

Wizard::Wizard(const string &name,
        double health,
        double attackStrength,
        int r)
 : Character(WIZARD, name, health, attackStrength), rank(r)
{ }

void Wizard::attack(Character &fighter) {
    double atk;
    if (fighter.getType() == WIZARD) {
        Wizard &opp= dynamic_cast<Wizard &>(fighter);
        atk = (static_cast<double> (rank) / opp.rank) * attackStrength;
        fighter.damage(atk);
        cout << "Wizard " << getName() << " attacks " << fighter.getName() << " --- POOF!!" << endl;
        cout << fighter.getName() << " takes " << atk << " damage." << endl; 
    }
    else {
        atk = attackStrength;
        fighter.damage(atk);
        cout << "Wizard " << getName() << " attacks " << fighter.getName() << " --- POOF!!" << endl;
        cout << fighter.getName() << " takes " << atk << " damage." << endl; 
    }
    
}