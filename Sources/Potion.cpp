#include "../Headers/Potion.hpp"
#include <string>

using namespace std;

Potion::Potion(string name) : name(name) {}

Potion::~Potion() {}

string Potion::getName() { // Getter for potion name
    return name;
}

void Potion::setName(string name) { // Setter for potion name
    this->name = name;
}