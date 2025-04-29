#include "../Headers/Enemy.hpp"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(string name, int health, int attack, string type) : name(name), health(health), attack(attack), type(type) {}

string Enemy::getName() {
    return name;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getAttack() {
    return attack;
}

void Enemy::setHealth(int health) {
    this->health = health;
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

void Enemy::setName(string name) {
    this->name = name;
}