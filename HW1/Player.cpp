#include "Player.hpp"
   
using namespace std;

Player::Player() {
    health = 100;
    attack = 10;
    defense = 5;
    armor = 0;
    stamina = 100;
    current_weapon = nullptr;
    moves = 30;
    inventory = new Inventory(0, 10);
}

Player::~Player() {
    delete inventory;
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
    enemy->setHealth(enemy->getHealth() - (current_weapon != nullptr ? current_weapon->getAttack() : attack));
    this->stamina -= 10;
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
    
    if (armor > 0) {
        armor -= damage;
        if (armor < 0) {
            armor = 0;
        }
    } else {
        health -= damage;
    }

    this->stamina -= 5;
    this->moves--;
}

void Player::AddToInventory(Treasure item) {
    inventory->Add(item);
}

void Player::RemoveFromInventory(Treasure item) {
    inventory->Remove(item);
}

