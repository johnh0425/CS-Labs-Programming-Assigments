#include "Character.h"    
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
    
Character::Character(HeroType t, const string &n, double h, double a) {
    type = t;
    name = n;
    health = h;
    attackStrength = a;
}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::damage(double d) {
    health = health - d;
}

bool Character::isAlive() const {
    if (getHealth() > 0) {
        return true;
    }
    else {
        return false;
    }
}