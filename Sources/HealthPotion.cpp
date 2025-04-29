#include "../Headers/HealthPotion.hpp"
#include "../Headers/Potion.hpp"
#include <string>

using namespace std;

HealthPotion::HealthPotion(string name, int healthRestored) : Potion(name), healthRestored(healthRestored) {}

HealthPotion::~HealthPotion() {}

int HealthPotion::getHealthRestored() { // Getter for health restored
    return healthRestored;
}

void HealthPotion::setHealthRestored(int healthRestored) { // Setter for health restored
    this->healthRestored = healthRestored;
}