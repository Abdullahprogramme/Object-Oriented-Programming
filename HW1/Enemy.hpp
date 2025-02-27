// This is the enemy class

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
using namespace std;

class Enemy {
    private:
        string name;
        int health;
        int attack;

    public:
        // Getters and setters
        string getName();
        void setName(string name);
        int getHealth();
        void setHealth(int health);
        int getAttack();
        void setAttack(int attack);

        // Constructor
        Enemy();

        // Destructor
        ~Enemy();
};

#endif // ENEMY_HPP