// This is the room class
#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include "Enemy.hpp"
#include "Treasure.hpp"
#include "Player.hpp"
#include "Enemy_Queue.hpp"

using namespace std;

class Room {
    private:
        string name;
        string description;
        Enemy* enemies;
        int num_enemies;
        Treasure* treasures;
        int num_treasures;
        Enemy_Queue* enemy_queue;

    public:
        // Getters and setters
        string getName();
        void setName(string name);
        string getDescription();
        void setDescription(string description);
        int getNumEnemies();
        void setNumEnemies(int num_enemies);
        int getNumTreasures();
        void setNumTreasures(int num_treasures);
        void setEnemies(Enemy* enemies);
        Enemy* getEnemies();
        Treasure* getTreasure();
        void setTreasures(Treasure* treasures);
        void setEnemyQueue(Enemy_Queue* enemy_queue);

        // Constructor
        Room();

        // Destructor
        ~Room();

        // Methods
        void printEnemies();
        void attackEnemies(Player* player);

};

#endif // ROOM_HPP
