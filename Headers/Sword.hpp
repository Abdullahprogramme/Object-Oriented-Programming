#ifndef Sword_hpp
#define Sword_hpp

#include <iostream>
#include <string>
#include "Weapon.hpp"

using namespace std;

class Sword : public Weapon {
    public:
        Sword(string name, int damage, int durability); // Constructor to initialize sword attributes
        ~Sword(); // Destructor
};

#endif // Sword_hpp