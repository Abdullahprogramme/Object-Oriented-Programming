#include "Enemy.hpp"

using namespace std;

Enemy::Enemy() {
    health = 100;
    attack = 10;
}

Enemy::~Enemy() {
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
