#include "../Headers/Enemy.hpp"

#include <iostream>
using namespace std;

Enemy::Enemy() {
    health = 100;
    attack = 10;
}

Enemy::~Enemy() {
    cout << "Deleted enemy" << endl;
}

string Enemy::getName() {
    return name;
}

void Enemy::setName(string name) {
    this->name = name;
}

int Enemy::getHealth() {
    return health;
}

void Enemy::setHealth(int health) {
    this->health = health;
}

int Enemy::getAttack() {
    return attack;
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}
