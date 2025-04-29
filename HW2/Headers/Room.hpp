#ifndef Room_hpp
#define Room_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Enemy1.hpp"
#include "Enemy2.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "../raylib.h"

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

class Player; // Forward declaration of Player class

class Room {
    private:
        string name;
        vector<vector<pair<char, void*>>> map; // 2D vector to represent the room layout
        vector<Enemy*> enemies; // Vector to hold enemies in the room
        
        Texture2D wallTexture; // Texture for walls
        Texture2D playerTexture; // Texture for player
        Texture2D enemy1Texture; // Texture for enemies
        Texture2D enemy2Texture; // Texture for enemies
        Texture2D HealthPotionTexture; // Texture for health potions
        Texture2D StaminaPotionTexture; // Texture for stamina potion
        Texture2D GunTexture; // Texture for gun
        Texture2D SwordTexture; // Texture for sword
        Texture2D ChestTexture; // Texture for chest

    public:
        bool allEnemiesDead; // Flag to check if all enemies are dead

        Room(string name, vector<vector<pair<char, void*>>> map, vector<Enemy*> enemies);
        ~Room();

        string getName(); // Getter for room name
        vector<vector<pair<char, void*>>> getMap(); // Getter for room map
        vector<Enemy*> getEnemies(); // Getter for enemies in the room

        void drawRoom(Player* player); // Function to draw the room
        void moveEnemies(); // Function to move enemies
        void movePlayer(Player* player); // Function to move the player
        void fightEnemies(Player* player); // Function to handle fighting enemies
};

#endif // Room_hpp