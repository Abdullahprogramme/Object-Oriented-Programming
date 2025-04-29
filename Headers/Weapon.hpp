#ifndef Weapon_hpp
#define Weapon_hpp

#include <iostream>
#include <string>

using namespace std;

class Weapon {
    private:
        string name; // Name of the weapon
        int damage; // Damage dealt by the weapon
        int durability; // Durability of the weapon

    public:
        Weapon(string name, int damage, int durability); // Constructor to initialize weapon attributes
        virtual ~Weapon(); // Destructor

        string getName(); // Getter for weapon name
        int getDamage(); // Getter for weapon damage
        int getDurability(); // Getter for weapon durability

        void setName(string name); // Setter for weapon name
        void setDamage(int damage); // Setter for weapon damage
        void setDurability(int durability); // Setter for weapon durability
};

#endif // Weapon_hpp