#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include <string>
using namespace std;

class Elf : public Character {
    private:
        string family;

    public:
        Elf(const string &name, double health, double attackStrength, string familyName);
        void attack(Character&);

};

#endif