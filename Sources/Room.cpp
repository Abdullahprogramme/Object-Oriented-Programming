#include "../Headers/Room.hpp"
#include "../Headers/Enemy1.hpp"
#include "../Headers/Enemy2.hpp"
#include "../Headers/Enemy.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Gun.hpp"
#include "../Headers/Sword.hpp"
#include "../Headers/Weapon.hpp"
#include "../Headers/Potion.hpp"
#include "../Headers/HealthPotion.hpp"
#include "../Headers/StaminaPotion.hpp"
#include "../Headers/Queue.hpp"
#include "../raylib.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm> 

using namespace std;

#define WALL 'W' // Character representing a wall
#define PLAYER 'P' // Character representing the player
#define ENEMY1 '1' // Character representing enemy type 1
#define ENEMY2 '2' // Character representing enemy type 2
#define HEALTH_POTION 'H' // Character representing a health potion
#define STAMINA_POTION 'S' // Character representing a stamina potion
#define GUN 'G' // Character representing a gun
#define SWORD 's' // Character representing a sword
#define EMPTY ' ' // Character representing an empty space

Room::Room(string name, vector<vector<pair<char, void*>>> map, vector<Enemy*> enemies) : name(name), map(map), enemies(enemies) {
    // Load textures for different elements in the room
    wallTexture = LoadTexture("Resources\\wall.png");
    playerTexture = LoadTexture("Resources\\player.png");
    enemy1Texture = LoadTexture("Resources\\enemy1.png");
    enemy2Texture = LoadTexture("Resources\\enemy2.png");
    HealthPotionTexture = LoadTexture("Resources\\health.png");
    StaminaPotionTexture = LoadTexture("Resources\\stamina.png");
    GunTexture = LoadTexture("Resources\\gun.png");
    SwordTexture = LoadTexture("Resources\\sword.png");
    ChestTexture = LoadTexture("Resources\\chest.png");

    allEnemiesDead = false; // Initialize the flag to false
}

Room::~Room() {
    // Unload textures to free up resources
    UnloadTexture(wallTexture);
    UnloadTexture(playerTexture);
    UnloadTexture(enemy1Texture);
    UnloadTexture(enemy2Texture);
    UnloadTexture(HealthPotionTexture);
    UnloadTexture(StaminaPotionTexture);
    UnloadTexture(GunTexture);
    UnloadTexture(SwordTexture);

    // Clean up dynamically allocated enemies
    for (auto enemy : enemies) {
        delete enemy;
    }

    for (auto& row : map) {
        for (auto& cell : row) {
            if (cell.second != nullptr) {
                if (cell.first == GUN || cell.first == SWORD) {
                    delete static_cast<Weapon*>(cell.second); // Clean up weapons
                } else if (cell.first == HEALTH_POTION || cell.first == STAMINA_POTION) {
                    delete static_cast<Potion*>(cell.second); // Clean up potions
                }
            }
        }
    }
    
}

string Room::getName() {
    return name; // Return the name of the room
}

vector<vector<pair<char, void*>>> Room::getMap() {
    return map; // Return the room map
}

vector<Enemy*> Room::getEnemies() {
    return enemies; // Return the list of enemies in the room
}

void Room::drawRoom(Player* player) {
    // Clear the screen with a white background
    ClearBackground(RAYWHITE);

    // Define the size of each cell
    const int cellSize = 30;
    const int gridWidth = 600; // 20 * 30
    const int gridHeight = 600; // 20 * 30
    const int panelHeight = 200; // Total height of the top panel
    const int statsHeight = 100; // Height for player stats
    const int weaponHeight = 100; // Height for current weapon

    // Draw the top panel (200px height)
    DrawRectangle(0, 0, gridWidth, panelHeight, LIGHTGRAY);

    // Draw player stats box (first 100px height)
    DrawRectangle(10, 10, gridWidth - 20, statsHeight - 10, WHITE);
    DrawRectangleLines(10, 10, gridWidth - 20, statsHeight - 10, BLACK);
    DrawText("Player Stats", 20, 20, 20, BLACK);
    if (player != nullptr) {
        DrawText(("Health: " + to_string(player->getHealth())).c_str(), 20, 50, 20, BLACK);
        DrawText(("Stamina: " + to_string(player->getStamina())).c_str(), 200, 50, 20, BLACK);
        DrawText(("Attack: " + to_string(player->getAttack())).c_str(), 400, 50, 20, BLACK);
    } else {
        DrawText("Player not initialized!", 20, 50, 20, RED);
    }

    // Draw current weapon box (next 100px height)
    int weaponBoxY = statsHeight;
    DrawRectangle(10, weaponBoxY + 10, gridWidth - 20, weaponHeight - 10, WHITE);
    DrawRectangleLines(10, weaponBoxY + 10, gridWidth - 20, weaponHeight - 10, BLACK);
    DrawText("Current Weapon", 20, weaponBoxY + 20, 20, BLACK);
    if (player != nullptr && player->getCurrentWeapon() != nullptr) {
        DrawText(player->getCurrentWeapon()->getName().c_str(), 20, weaponBoxY + 50, 20, BLACK);
        DrawText(("Damage: " + to_string(player->getCurrentWeapon()->getDamage())).c_str(), 200, weaponBoxY + 50, 20, BLACK);
        DrawText(("Durability: " + to_string(player->getCurrentWeapon()->getDurability())).c_str(), 400, weaponBoxY + 50, 20, BLACK);
    } else {
        DrawText("None", 20, weaponBoxY + 50, 20, BLACK);
    }

    // Draw the room map (20x20 grid, 600x600px)
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            char element = map[i][j].first; // Get the character representing the element
            void* data = map[i][j].second; // Get the associated data (if any)

            // Determine the position to draw the element
            Vector2 position = { static_cast<float>(j * cellSize), static_cast<float>(i * cellSize + panelHeight) };

            // Draw the corresponding texture based on the character
            switch (element) {
                case WALL:
                    DrawTextureEx(wallTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case PLAYER:
                    DrawTextureEx(playerTexture, position, 0.0f, 0.06f, WHITE);
                    break;  
                case ENEMY1:
                    DrawTextureEx(enemy1Texture, position, 0.0f, 0.06f, WHITE);
                    break;
                case ENEMY2:
                    DrawTextureEx(enemy2Texture, position, 0.0f, 0.06f, WHITE);
                    break;
                case HEALTH_POTION:
                    DrawTextureEx(HealthPotionTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case STAMINA_POTION:
                    DrawTextureEx(StaminaPotionTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case GUN:
                    DrawTextureEx(GunTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case SWORD:
                    DrawTextureEx(SwordTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case 'T':
                    DrawTextureEx(ChestTexture, position, 0.0f, 0.06f, WHITE);
                    break;
                case EMPTY: 
                    // Draw nothing for empty spaces
                    break;
                default:
                    // Handle any other cases if needed
                    break;
            }
        }
    }

    // Draw grid lines for the room
    for (int i = 0; i <= 20; i++) {
        DrawLine(0, i * cellSize + panelHeight, gridWidth, i * cellSize + panelHeight, BLACK); // Horizontal lines
        DrawLine(i * cellSize, panelHeight, i * cellSize, gridHeight + panelHeight, BLACK); // Vertical lines
    }
}

void Room::moveEnemies() {
    for (auto enemy : enemies) {
        enemy->move(map); // Move each enemy in the room
    }
}

void Room::movePlayer(Player* player) {
    // Clear the old position of the player
    player->move(map, this); // Move the player in the room
}

void Room::fightEnemies(Player* player) {
    Queue enemyQueue; // Create a queue to hold enemies

    vector<pair<int, int>> directions = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {0, 0},   // Same cell
        {1, 1},   // Diagonal down-right
        {-1, -1}, // Diagonal up-left
        {1, -1},  // Diagonal down-left
        {-1, 1}   // Diagonal up-right
    };

    // Enqueue all enemies around the player
    for (auto [dx, dy] : directions) {
        int newX = player->position.first + dx;
        int newY = player->position.second + dy;

        // Check if the new position is within bounds and contains an enemy
        if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size()) {
            char element = map[newX][newY].first;
            if (element == ENEMY1 || element == ENEMY2) {
                Enemy* enemy = static_cast<Enemy*>(map[newX][newY].second); // Cast to Enemy type
                enemyQueue.enqueue(enemy); // Add enemy to the queue
            }
        }
    }

    bool is_player_defeated = false; // Flag to check if the player is defeated

    // Handle combat with enemies in the queue
    while (!enemyQueue.isEmpty()) {
        Enemy* enemy = enemyQueue.dequeue(); // Get the next enemy from the queue
        is_player_defeated = player->fight(enemy); // Player fights the enemy

        if (is_player_defeated) {
            player->is_player_dead = true; // Set player as dead if defeated
            break; // Exit if the player is defeated
        }

        // Remove the enemy from the map after defeat
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (map[i][j].second == enemy) {
                    map[i][j] = {EMPTY, nullptr}; // Remove the enemy from the map
                    break;
                }
            }
        }

        // Remove the enemy from the list of enemies
        enemies.erase(remove(enemies.begin(), enemies.end(), enemy), enemies.end());

        // Check if all enemies are dead
        allEnemiesDead = enemies.empty();

        // Clean up the enemy object
        delete enemy;
    }
}

