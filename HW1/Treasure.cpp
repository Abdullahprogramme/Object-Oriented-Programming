#include "Treasure.hpp"

using namespace std;

Treasure::Treasure() {
    name = "";
    description = "";
}

Treasure::~Treasure() {}

string Treasure::getName() const {
    return name;
}

void Treasure::setName(string name) {
    this->name = name;
}

string Treasure::getDescription() const {
    return description;
}

void Treasure::setDescription(string description) {
    this->description = description;
}

int Treasure::getAttack() {
    return attack;
}

void Treasure::setAttack(int attack) {
    this->attack = attack;
}

int Treasure::getDefense() {
    return defense;
}

void Treasure::setDefense(int defense) {
    this->defense = defense;
}