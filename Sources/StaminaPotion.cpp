#include "../Headers/StaminaPotion.hpp"
#include "../Headers/Potion.hpp"
#include <string>

using namespace std;

StaminaPotion::StaminaPotion(string name, int staminaRestored) : Potion(name), staminaRestored(staminaRestored) {}

StaminaPotion::~StaminaPotion() {}

int StaminaPotion::getStaminaRestored() { // Getter for stamina restored
    return staminaRestored;
}

void StaminaPotion::setStaminaRestored(int staminaRestored) { // Setter for stamina restored
    this->staminaRestored = staminaRestored;
}