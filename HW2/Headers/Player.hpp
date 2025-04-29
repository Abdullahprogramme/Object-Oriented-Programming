#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <vector>
#include <utility> 
#include "Inventory.hpp"
#include "Weapon.hpp"
#include "Enemy.hpp"
#include "Room.hpp"

using namespace std;

class Room; // Forward declaration of Room class
class Inventory; // Forward declaration of Inventory class

class Player {
    private:
        string name;
        int health;
        int attack;
        int stamina;
        Inventory* inventory; // Player's inventory
        Weapon* currentWeapon; // Current weapon equipped by the player

    public:
        pair<int, int> position; // Player's position in the game world
        bool is_player_dead = false; // Flag to check if the player is dead
        
        Player(string name, int health, int attack);
        ~Player();

        string getName(); // Getter for player name
        int getHealth(); // Getter for player health
        int getAttack(); // Getter for player attack
        int getStamina(); // Getter for player stamina
        Inventory* getInventory(); // Getter for player's inventory
        Weapon* getCurrentWeapon(); // Getter for current weapon

        void setName(string name); // Setter for player name
        void setHealth(int health); // Setter for player health
        void setAttack(int attack); // Setter for player attack
        void setStamina(int stamina); // Setter for player stamina
        void setInventory(Inventory* inventory); // Setter for player's inventory
        void setCurrentWeapon(Weapon* weapon); // Setter for current weapon

        void showInventory(); // Function to display the player's inventory
        bool fight(Enemy* enemy); // Function to fight an enemy
        void move(vector<vector<pair<char, void*>>>& map, Room* room); // Function to move the player
};

#endif // Player_hpp