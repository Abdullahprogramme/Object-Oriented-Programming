// This is the Player class

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Inventory.hpp"
#include "Enemy.hpp"
#include "Treasure.hpp"

class Player {
    private:
        int health;
        int attack;
        int defense;
        int armor;
        int stamina;
        int moves;
        Treasure* current_weapon;
        Inventory* inventory;

    public:
        // Getters and setters
        int getHealth();
        void setHealth(int health);
        int getDefense();
        void setDefense(int defense);
        int getArmor();
        void setArmor(int armor);
        int getStamina();
        void setStamina(int stamina);
        int getMoves();
        void setMoves(int moves);
        void setCurrentWeapon(Treasure* current_weapon);
        Treasure* getCurrentWeapon() { return current_weapon; }
        Inventory* getInventory();


        // Constructor
        Player();

        // Destructor
        ~Player();

        // Methods
        void Attack(Enemy* enemy);
        void Defend(Enemy* enemy);
        void AddToInventory(Treasure item);
        void RemoveFromInventory(Treasure item);
};

#endif // PLAYER_HPP
