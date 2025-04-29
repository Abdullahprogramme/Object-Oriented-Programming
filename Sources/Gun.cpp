#include "../Headers/Gun.hpp"
#include "../Headers/Weapon.hpp"
#include <string>

using namespace std;

Gun::Gun(string name, int damage, int durability) : Weapon(name, damage, durability) {}

Gun::~Gun() {}