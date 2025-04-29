#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include "StaminaPotion.hpp"
#include "Player.hpp"

using namespace std;

class Player;

class Inventory {
    private:
        int size; // Size of the inventory
        Potion** potions; // Array of pointers to potions
        int potionCount; // Number of potions in the inventory

    public:
        Inventory(); // Constructor to initialize inventory size
        ~Inventory(); // Destructor
        void increaseSize(); // Function to increase the size of the inventory

        void addPotion(Potion* potion); // Function to add a potion to the inventory
        void removePotion(Potion* potion); // Function to remove a potion from the inventory
        void usePotion(const string& potionName, Player* player); // Function to use a potion from the inventory
        void displayPotions(Player* player); // Function to display potions in the inventory
};

#endif // Inventory_hpp