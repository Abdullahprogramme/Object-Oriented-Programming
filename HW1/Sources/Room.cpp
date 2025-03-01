#include "../Headers/Room.hpp"
#include "../Headers/Enemy.hpp"
#include "../Headers/Treasure.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Enemy_Queue.hpp"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Room::Room() {
    name = "Default Room";
    description = "This is a default room";
    enemies = nullptr;
    num_enemies = 0;
    treasures = nullptr;
    num_treasures = 0;
    enemy_queue = nullptr;
    EnemiesDefeated = false; 
}

Room::~Room() {
    delete enemies;
    delete treasures;
    delete enemy_queue;
    cout << "Deleted room" << endl;
}

string Room::getName() {
    return name;
}

void Room::setName(string name) {
    this->name = name;
}

string Room::getDescription() {
    return description;
}

void Room::setDescription(string description) {
    this->description = description;
}

int Room::getNumEnemies() {
    return num_enemies;
}

void Room::setNumEnemies(int num_enemies) {
    this->num_enemies = num_enemies;
}

int Room::getNumTreasures() {
    return num_treasures;
}

void Room::setNumTreasures(int num_treasures) {
    this->num_treasures = num_treasures;
}

void Room::setEnemies(Enemy* enemies) {
    this->enemies = enemies;
}

Enemy* Room::getEnemies() {
    return enemies;
}

Treasure* Room::getTreasure() {
    return treasures;
}

void Room::setTreasures(Treasure* treasures) {
    this->treasures = treasures;
}

void Room::setEnemyQueue(Enemy_Queue* enemy_queue) {
    this->enemy_queue = enemy_queue;
}

void Room::printEnemies() {
    cout << "In this room, you will face the following enemies: " << endl;
    if (enemies == nullptr) {
        cout << "No enemies in the room" << endl;
    } else {
        cout << left << setw(20) << "Name" << setw(10) << "Health" << setw(10) << "Attack" << endl;
        for (unsigned int i = 0; i < 3; i++) {
            Enemy* enemy = enemy_queue->dequeue();
            if (enemy == nullptr) {
                enemy_queue->enqueue(enemy);
                continue;
            }
            cout << left << setw(20) << enemy->getName() << setw(10) << enemy->getHealth() << setw(10) << enemy->getAttack() << endl;
            enemy_queue->enqueue(enemy);
        }
    }   
}

void Room::attackEnemies(Player* player) {
    if (enemies == nullptr) {
        cout << "No enemies in the room" << endl;
        return;
    }

    unsigned int initial_num_enemies = num_enemies;
    bool allEnemiesDefeated = true;

    // looping through the available enemies in the room
    for (unsigned int i = 0; i < initial_num_enemies; ++i) {

        // getting the enemy from the queue and if the enemy is null(meaning it has been defeated), we continue to the next enemy
        Enemy* enemy = enemy_queue->dequeue();
        if (enemy == nullptr) {
            continue;
        }

        cout << "Attacking " << enemy->getName() << ".... and it";
        player->Attack(enemy);

        // checking if the enemy has been defeated
        if (enemy->getHealth() <= 0) {
            cout << " has been defeated" << endl;
            enemy_queue->enqueue(nullptr);
            allEnemiesDefeated = true;
        } else { // if the enemy has not been defeated, we enqueue the enemy back into the queue
            cout << " has " << enemy->getHealth() << " health left" << endl;
            enemy_queue->enqueue(enemy);
            allEnemiesDefeated = false;
        }

        if (enemy->getHealth() > 0) {
            cout << "Enemy " << enemy->getName() << " attacks you" << endl;
            player->Defend(enemy);
            if (player->getHealth() <= 0) {
                cout << "You have been defeated" << endl;
                return;
            }
        }
    }

    // making the current weapon null after the attack
    if (player->getCurrentWeapon() != nullptr) {
        cout << "--------------------------------" << endl;
        cout << "You have used your current weapon, it has been discarded" << endl;
        cout << "--------------------------------" << endl;
    }
    player->setCurrentWeapon(nullptr);

    if (allEnemiesDefeated == true) {
        cout << "All enemies have been defeated, this room has been cleared" << endl;
        EnemiesDefeated = true;
    } else {
        cout << "There are still enemies left after the battle, you probably need to come back and attack them" << endl;
    }
}
