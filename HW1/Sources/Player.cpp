#include "../Headers/Player.hpp"
   
#include <iostream>
using namespace std;

Player::Player() {
    health = 50;
    attack = 5;
    defense = 5;
    armor = 0;
    stamina = 100;
    current_weapon = nullptr;
    moves = 20;
    inventory = new Inventory(0, 10);
}

Player::~Player() {
    delete inventory;
    cout << "Deleted player" << endl;
}

int Player::getHealth() {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
}

int Player::getDefense() {
    return defense;
}

void Player::setDefense(int defense) {
    this->defense = defense;
}

int Player::getArmor() {
    return armor;
}

void Player::setArmor(int armor) {
    this->armor = armor;
}

int Player::getStamina() {
    return stamina;
}

void Player::setStamina(int stamina) {
    this->stamina = stamina;
}

int Player::getMoves() {
    return moves;
}

void Player::setMoves(int moves) {
    this->moves = moves;
}

void Player::setCurrentWeapon(Treasure* current_weapon) {
    this->current_weapon = current_weapon;
}

Inventory* Player::getInventory() {
    return inventory;
}

void Player::Attack(Enemy* enemy) {
    // While attacking checks if the player has a weapon equipped
    // If the player has a weapon equipped, the weapon's attack is used
    enemy->setHealth(enemy->getHealth() - (current_weapon != nullptr ? current_weapon->getAttack() : attack));
    this->stamina -= 5;
    if (enemy->getHealth() <= 0) {
        enemy->setHealth(0);
    }   
    this->moves--;
}

void Player::Defend(Enemy* enemy) {
    int damage = enemy->getAttack() - defense;
    if (damage < 0) {
        damage = 0;
    }
    
    // While defending checks if the player has armor equipped
    // If the player has armor equipped, the armor's defense is used
    if (armor > 0) {
        armor -= damage;
        if (armor < 0) {
            health += armor;
            armor = 0;
        }
    } else {
        health -= damage;
    }

    this->stamina -= 2;
    this->moves--;
}

// calls the Add function from the Inventory class
void Player::AddToInventory(Treasure item) {
    inventory->Add(item);
}

// calls the Remove function from the Inventory class
void Player::RemoveFromInventory(Treasure item) {
    inventory->Remove(item);
}

