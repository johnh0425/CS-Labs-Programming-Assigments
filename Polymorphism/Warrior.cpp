#include "Warrior.h"    
#include <iostream>
#include <string>
using namespace std;

Warrior::Warrior(const string &name,
        double health,
        double attackStrength,
        string allg)
 : Character(WARRIOR, name, health, attackStrength), allegiance(allg)
{}

void Warrior::attack(Character &fighter) {
    double atk;
    if (fighter.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(fighter);
        if(opp.allegiance == allegiance) {
            cout << "Warrior " << getName() << " does not attack Warrior " << fighter.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else {
            atk = (health / MAX_HEALTH) * attackStrength;
            fighter.damage(atk);
            cout << "Warrior " << getName() << " attacks " << fighter.getName() << " --- SLASH!!" << endl;
            cout << fighter.getName() << " takes " << atk << " damage." << endl; 
        }
    }
    else {
        atk = (health / MAX_HEALTH) * attackStrength;
        fighter.damage(atk);
        cout << "Warrior " << getName() << " attacks " << fighter.getName() << " --- SLASH!!" << endl;
        cout << fighter.getName() << " takes " << atk << " damage." << endl;
    }
    
}