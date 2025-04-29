#include "../Headers/Weapon.hpp"   
#include <string>

using namespace std;

Weapon::Weapon(string name, int damage, int durability) {
    this->name = name; // Initialize weapon name
    this->damage = damage; // Initialize weapon damage
    this->durability = durability; // Initialize weapon durability
}

Weapon::~Weapon() {}

string Weapon::getName() {
    return name; // Return weapon name
}

int Weapon::getDamage() {
    return damage; // Return weapon damage
}

int Weapon::getDurability() {
    return durability; // Return weapon durability
}

void Weapon::setName(string name) {
    this->name = name; // Set weapon name
}

void Weapon::setDamage(int damage) {
    this->damage = damage; // Set weapon damage
}

void Weapon::setDurability(int durability) {
    this->durability = durability; // Set weapon durability
}