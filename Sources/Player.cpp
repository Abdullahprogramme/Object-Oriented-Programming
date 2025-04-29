#include "../Headers/Player.hpp"
#include "../Headers/Inventory.hpp"
#include "../Headers/Weapon.hpp"
#include "../Headers/Enemy.hpp"
#include <string>
#include <vector>
#include <utility> 
#include <chrono>
#include <thread>

using namespace std;

Player::Player(string name, int health, int attack) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->stamina = 100; // Default stamina
    this->inventory = new Inventory();
    this->currentWeapon = nullptr;
}

Player::~Player() {
    delete inventory; // Clean up inventory
    if (currentWeapon != nullptr) {
        delete currentWeapon; // Clean up current weapon if it exists
    }
}

string Player::getName() {
    return name; // Return player name
}

int Player::getHealth() {
    return health; // Return player health
}

int Player::getAttack() {
    return attack; // Return player attack
}

int Player::getStamina() {
    return stamina; // Return player stamina
}

Inventory* Player::getInventory() {
    return inventory; // Return player's inventory
}

Weapon* Player::getCurrentWeapon() {
    return currentWeapon; // Return current weapon
}

void Player::setName(string name) {
    this->name = name; // Set player name
}

void Player::setHealth(int health) {
    this->health = health; // Set player health
}

void Player::setAttack(int attack) {
    this->attack = attack; // Set player attack
}

void Player::setStamina(int stamina) {
    this->stamina = stamina; // Set player stamina
}

void Player::setInventory(Inventory* inventory) {
    this->inventory = inventory; // Set player's inventory
}

void Player::setCurrentWeapon(Weapon* weapon) {
    this->currentWeapon = weapon; // Set current weapon
}

bool Player::fight(Enemy* enemy) {
    if (currentWeapon == nullptr || currentWeapon->getDurability() <= 0) {
        setHealth(0); // Set player's health to 0 to indicate defeat
        return true; // Player is defeated if no weapon is equipped or weapon is broken
    }

    stamina -= 10; // Decrease stamina for the attack
    enemy->setHealth(enemy->getHealth() - (attack + currentWeapon->getDamage())); // Calculate damage dealt to enemy
    currentWeapon->setDurability(currentWeapon->getDurability() - 1); // Decrease weapon durability

    if (currentWeapon->getDurability() <= 0) {
        delete currentWeapon; // Clean up the weapon if it breaks
        currentWeapon = nullptr; // No weapon equipped anymore
    } else {
        // cout << "Your " << currentWeapon->getName() << " has " << currentWeapon->getDurability() << " durability left." << endl;
    }

    if (enemy->getHealth() <= 0) {
        return false; // Enemy defeated
    } else {
        this_thread::sleep_for(chrono::seconds(1)); // Simulate delay for enemy attack
        setHealth(getHealth() - enemy->getAttack()); // Calculate damage dealt to player

        if (getHealth() <= 0) {
            return true; // Player defeated
            // Handle player defeat (e.g., game over)
        }

        return false; // Player not defeated
    }
}

void Player::move(vector<vector<pair<char, void*>>>& map, Room* room) {
    int PosX = position.first;
    int PosY = position.second;

    // Define movement directions
    vector<pair<int, int>> directions = {
        {-1, 0}, // Up
        {1, 0},  // Down
        {0, -1}, // Left
        {0, 1}   // Right
    };

    // Define corresponding keys
    vector<int> keys = {
        KEY_UP,
        KEY_DOWN,
        KEY_LEFT,
        KEY_RIGHT
    };

    for (int i = 0; i < directions.size(); ++i) {
        if (IsKeyPressed(keys[i])) {
            int newX = PosX + directions[i].first;
            int newY = PosY + directions[i].second;

            // Check if the new position is within bounds
            if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size()) {
                auto& movePos = map[newX][newY];

                // Check if the new position is a weapon
                if (movePos.first == 'G' || movePos.first == 's') {
                    Weapon* weapon = static_cast<Weapon*>(movePos.second);
                    currentWeapon = weapon; // Equip the new weapon

                    // Remove the weapon from the map and place the player
                    map[PosX][PosY] = {EMPTY, nullptr}; // Clear old position
                    movePos = {PLAYER, this}; // Place player in the new position
                    position = {newX, newY}; // Update player position
                }
                // Check if the new position is a potion
                else if (movePos.first == 'H' || movePos.first == 'S') {
                    Potion* potion = static_cast<Potion*>(movePos.second);
                    inventory->addPotion(potion); // Add potion to inventory

                    // Remove the potion from the map and place the player
                    map[PosX][PosY] = {EMPTY, nullptr}; // Clear old position
                    movePos = {PLAYER, this}; // Place player in the new position
                    position = {newX, newY}; // Update player position
                }
                // Check if the new position is a chest
                else if (movePos.first == 'T') {
                    showInventory(); // Show inventory UI
                    // Player stays in the same position
                }
                // Check if the new position is a wall
                else if (movePos.first == WALL) {
                    // Player stays in the same position
                }
                // Check if the new position is empty
                else if (movePos.first == EMPTY) {
                    map[PosX][PosY] = {EMPTY, nullptr}; // Clear old position
                    movePos = {PLAYER, this}; // Place player in the new position
                    position = {newX, newY}; // Update player position
                }
                // Check if the new position is an enemy
                else if (movePos.first == ENEMY1 || movePos.first == ENEMY2) {
                    // Handle enemy encounter (e.g., combat logic)
                }
            }
            break;
        }
    }
}

void Player::showInventory() {
    inventory->displayPotions(this); // Display potions in the inventory
}