#ifndef Enemy_hpp
#define Enemy_hpp

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Enemy {
    private:
        string name;
        int health;
        int attack;

    public:
        pair<int, int> position; // Position of the enemy on the map
        string type; // Type of the enemy (e.g., "Goblin", "Orc")

        Enemy(string name, int health, int attack, string type);
        virtual ~Enemy() = default; // Virtual destructor for proper cleanup of derived classes

        string getName();
        int getHealth();
        int getAttack();
        void setHealth(int health);
        void setAttack(int attack);
        void setName(string name);
        
        virtual void move(vector<vector<pair<char, void*>>>& map) = 0; // Pure virtual function for movement
        virtual void findTarget(vector<vector<pair<char, void*>>>& map, int player_x, int player_Y) = 0; // Pure virtual function for finding target
};

#endif // Enemy_hpp