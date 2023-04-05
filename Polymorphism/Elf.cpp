#include "Elf.h"    
#include <iostream>
#include <string>
using namespace std;

Elf::Elf(const string &name,
        double health,
        double attackStrength,
        string familyName)
 : Character(ELF, name, health, attackStrength), family(familyName)
{ }

void Elf::attack(Character &fighter) {
    double atk;
    if (fighter.getType() == ELF) {
        Elf &opp= dynamic_cast<Elf &>(fighter);
        if(opp.family == family) {
            cout << "Elf " << getName() << " does not attack Elf " << fighter.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else {
            atk = (health / MAX_HEALTH) * attackStrength;
            fighter.damage(atk);
            cout << "Elf " << getName() << " shoots an arrow at " << fighter.getName() << " --- TWANG!!" << endl;
            cout << fighter.getName() << " takes " << atk << " damage." << endl; 
        }
    }
    else {
        atk = (health / MAX_HEALTH) * attackStrength;
        fighter.damage(atk);
        cout << "Elf " << getName() << " shoots an arrow at " << fighter.getName() << " --- TWANG!!" << endl;
        cout << fighter.getName() << " takes " << atk << " damage." << endl;
    }
    
}