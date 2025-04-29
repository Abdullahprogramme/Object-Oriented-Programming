#include "../Headers/Sword.hpp"
#include "../Headers/Weapon.hpp"
#include <string>

using namespace std;

Sword::Sword(string name, int damage, int durability) : Weapon(name, damage, durability) {}

Sword::~Sword() {}

