#ifndef Maze_cpp
#define Maze_cpp

#include "../Headers/Enemy.hpp"
#include "../Headers/Enemy1.hpp"
#include "../Headers/Enemy2.hpp"
#include "../Headers/Room.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Gun.hpp"
#include "../Headers/Sword.hpp"
#include "../Headers/Weapon.hpp"
#include "../Headers/Potion.hpp"
#include "../Headers/HealthPotion.hpp"
#include "../Headers/StaminaPotion.hpp"
#include "../Headers/LinkedList.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "../raylib.h"
#include <vector>
#include <string>

class Maze {
    private:
        LinkedList* rooms;
        Player* player;
        Room* currentRoom;

    public:
        Maze() {
            // Room 1 and Room 2 initialization
            vector<vector<pair<char, void*>>> room1Map(20, vector<pair<char, void*>>(20, {EMPTY, nullptr})); // Initialize a 20x20 map with empty spaces
            vector<vector<pair<char, void*>>> room2Map(20, vector<pair<char, void*>>(20, {EMPTY, nullptr})); // Initialize a 20x20 map with empty spaces

            ifstream file1("Resources\\map1.txt"); // Open the file for room 1 (input)
            ifstream file2("Resources\\map2.txt"); // Open the file for room 2 (input)
            if (!file1.is_open() || !file2.is_open()) {
                throw runtime_error("Failed to open room files for reading."); // Throw an exception if files cannot be opened
            }

            vector<Enemy*> enemies1, enemies2; // Vectors to hold enemies for room 1 and room 2
            enemies1.push_back(new Enemy1("Enemy 1", 100, 10, "Enemy1")); // Create an enemy for room 1
            enemies1.push_back(new Enemy1("Enemy 2", 100, 10, "Enemy1")); // Create an enemy for room 1
            enemies1.push_back(new Enemy2("Enemy 3", 100, 10, "Enemy2")); // Create an enemy for room 1

            enemies2.push_back(new Enemy1("Enemy 4", 100, 10, "Enemy1")); // Create an enemy for room 2
            enemies2.push_back(new Enemy1("Enemy 5", 100, 10, "Enemy1")); // Create an enemy for room 2
            enemies2.push_back(new Enemy2("Enemy 6", 100, 10, "Enemy2")); // Create an enemy for room 2
            enemies2.push_back(new Enemy2("Enemy 7", 100, 10, "Enemy2")); // Create an enemy for room 2

            string line1, line2; // Strings to hold lines read from the files

            // Player initialization
            Player* player = new Player("Player", 100, 10); // Create a player with name, health, attack, and stamina

            int iteration1 = 0, iteration2 = 0; // Iteration variables for enemies
            for (int i = 0; i < 20; i++) {
                getline(file1, line1); // Read a line from room 1 file
                getline(file2, line2); // Read a line from room 2 file

                char c;
                for (int j = 0; j < 20; j++) {
                    c = line1[j]; // Character from room 1
                    if (c == '1') {
                        room1Map[i][j] = make_pair('1', enemies1[iteration1]); // Enemy 1
                        enemies1[iteration1]->position = {i, j}; // Set enemy position
                        iteration1++;
                    } else if (c == '2') {
                        room1Map[i][j] = make_pair('2', enemies1[iteration1]); // Enemy 2
                        enemies1[iteration1]->position = {i, j}; // Set enemy position
                        iteration1++;
                    } else if (c == 'P') {
                        room1Map[i][j] = {PLAYER, player}; // Player position
                        player->position = {i, j}; // Set player position
                    } else if (c == 'G') {
                        room1Map[i][j] = {GUN, new Gun("Gun", 100, 2)}; // Gun item
                    } else if (c == 's') {
                        room1Map[i][j] = {SWORD, new Sword("Sword", 100, 2)}; // Sword item
                    } else if (c == 'H') {
                        room1Map[i][j] = {HEALTH_POTION, new HealthPotion("Health Potion", 50)}; // Health potion item
                    } else if (c == 'S') {
                        room1Map[i][j] = {STAMINA_POTION, new StaminaPotion("Stamina Potion", 50)}; // Stamina potion item
                    } else if (c == '#') {
                        room1Map[i][j] = {WALL, nullptr}; // Wall
                    } else if (c == 'T') {
                        room1Map[i][j] = {'T', nullptr}; // Chest
                    } else {
                        room1Map[i][j] = {EMPTY, nullptr}; // Empty space
                    }

                    c = line2[j]; // Character from room 2
                    if (c == '1') {
                        room2Map[i][j] = make_pair('1', enemies2[iteration2]); // Enemy 1
                        enemies2[iteration2]->position = {i, j}; // Set enemy position
                        iteration2++;
                    } else if (c == '2') {
                        room2Map[i][j] = make_pair('2', enemies2[iteration2]); // Enemy 2
                        enemies2[iteration2]->position = {i, j}; // Set enemy position
                        iteration2++;
                    } else if (c == 'P') {
                        room2Map[i][j] = {PLAYER, nullptr}; // Player position
                    } else if (c == 'G') {
                        room2Map[i][j] = {GUN, new Gun("Gun", 100, 2)}; // Gun item
                    } else if (c == 's') {
                        room2Map[i][j] = {SWORD, new Sword("Sword", 100, 2)}; // Sword item
                    } else if (c == 'H') {
                        room2Map[i][j] = {HEALTH_POTION, new HealthPotion("Health Potion", 50)}; // Health potion item
                    } else if (c == 'S') {
                        room2Map[i][j] = {STAMINA_POTION, new StaminaPotion("Stamina Potion", 50)}; // Stamina potion item
                    } else if (c == '#') {
                        room2Map[i][j] = {WALL, nullptr}; // Wall
                    } else if (c == 'T') {
                        room2Map[i][j] = {'T', nullptr}; // Chest
                    } else {
                        room2Map[i][j] = {EMPTY, nullptr}; // Empty space
                    }
                }
            }

            file1.close(); // Close the file for room 1
            file2.close(); // Close the file for room 2

            LinkedList* rooms = new LinkedList(); // Create a linked list for the inventory
            rooms->add(new Room("Room 1", room1Map, enemies1)); // Add room 1 to the linked list
            rooms->add(new Room("Room 2", room2Map, enemies2)); // Add room 2 to the linked list
            currentRoom = rooms->getHead()->room; // Set the current room to the head of the list

            this->rooms = rooms;
            this->player = player;
        }

        ~Maze() {
            delete rooms; // Clean up the linked list of rooms
            delete player; // Clean up the player
        }

        void startGame() {
            currentRoom = rooms->getHead()->room; // Set the current room to the head of the list
        
            const float enemyMoveInterval = 1.0f; // Time interval for enemy movement (in seconds)
            float enemyMoveTimer = 0.0f; // Timer to track enemy movement
        
            SetTargetFPS(60); // Set the game to run at 60 FPS
        
            while (!WindowShouldClose()) { // Main game loop
                float deltaTime = GetFrameTime(); // Get the time elapsed since the last frame
                enemyMoveTimer += deltaTime; // Increment the enemy movement timer
        
                BeginDrawing();
                ClearBackground(BLACK);
        
                // Check if the player is dead
                if (player->is_player_dead) {
                    End(); // End the game if the player is dead
                    break; // Exit the game loop
                }
        
                // Check if all rooms are cleared
                if (rooms->isLast() && currentRoom->allEnemiesDead) {
                    End(); // End the game if all rooms are cleared
                    break; // Exit the game loop
                }
        
                currentRoom->drawRoom(player); // Draw the current room
                currentRoom->movePlayer(player); // Move the player in the current room
                currentRoom->fightEnemies(player); // Handle fighting enemies in the current room
        
                // Move enemies at a fixed interval
                if (enemyMoveTimer >= enemyMoveInterval) {
                    currentRoom->moveEnemies(); // Move enemies in the current room
                    enemyMoveTimer = 0.0f; // Reset the timer
                }
        
                // Check if all enemies are dead and it's not the last room
                if (currentRoom->allEnemiesDead && !rooms->isLast()) {
                    moveToNextRoom(); // Move to the next room
                }
        
                // Exit the game if ESC is pressed
                if (IsKeyPressed(KEY_ESCAPE)) {
                    break; // Exit the game loop
                }
        
                EndDrawing();
            }
        
            CloseWindow(); // Close the window when the game ends
            return; // Exit the game
        }

        void Intro() {
            
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(BLACK);

                // Display the introduction screen
                DrawText("Welcome to the Maze Game!", 190, 200, 20, WHITE);
                DrawText("Press ENTER to start", 190, 250, 20, WHITE);

                if (IsKeyPressed(KEY_ENTER)) {
                    break; // Start the game when ENTER is pressed
                }
                EndDrawing();
            }

            return; // Exit the introduction screen
        }

        void End() {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(BLACK);

                // Display the end screen
                DrawText("Game Over!", 190, 200, 20, WHITE);
                DrawText("Press ESC to exit", 190, 250, 20, WHITE);

                if (IsKeyPressed(KEY_ESCAPE)) {
                    break; // Exit the game when ESC is pressed
                }
                EndDrawing();
            }

            return; // Exit the end screen
        }

        void moveToNextRoom() {
            rooms->next(); // Move to the next room in the linked list
            currentRoom = rooms->getCurrent()->room; // Set the current room to the next room

            // resetting the player position
            for (int i = 0; i < currentRoom->getMap().size(); i++) {
                for (int j = 0; j < currentRoom->getMap()[i].size(); j++) {
                    if (currentRoom->getMap()[i][j].first == PLAYER) {
                        player->position = {i, j}; // Set the player's position in the new room
                    }
                }
            }

        }

        void moveToPreviousRoom() {
            rooms->prev(); // Move to the previous room in the linked list
            currentRoom = rooms->getCurrent()->room; // Set the current room to the previous room
        }
        
};

#endif // Maze_cpp