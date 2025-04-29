#ifndef Enemy1_hpp
#define Enemy1_hpp

#include <string>
#include <vector>
#include <utility>
#include "Enemy.hpp"

using namespace std;

class Enemy1 : public Enemy {
    public:
        Enemy1(string name, int health, int attack, string type);
        ~Enemy1();

        void move(vector<vector<pair<char, void*>>>& map) override; // Override the move function
        void findTarget(vector<vector<pair<char, void*>>>& map, int player_x, int player_y) override; // Override the findTarget function
};

#endif // Enemy1_hpp