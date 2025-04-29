#include "../Headers/Enemy1.hpp"
#include "../Headers/Enemy.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Enemy1::Enemy1(string name, int health, int attack, string type) : Enemy(name, health, attack, type = "Enemy1") {}

Enemy1::~Enemy1() {}

void Enemy1::move(vector<vector<pair<char, void*>>>& map) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    while (true) {
        int random_direction = rand() % 4; // Randomly select a direction
        int new_x = position.first + directions[random_direction].first;
        int new_y = position.second + directions[random_direction].second;

        auto if_occupied = [&map](int x, int y) {
            return map[x][y].first != ' '; // Check if the position is occupied
        };

        // Check if the new position is within bounds and not blocked
        if (new_x >= 0 && new_x < map.size() && new_y >= 0 && new_y < map[0].size() && !if_occupied(new_x, new_y)) {

            map[this->position.first][this->position.second] = {' ', nullptr}; // Clear the old position
            map[new_x][new_y] = {type == "Enemy1" ? '1' : '2', this}; // Update the new position with the enemy type
            // Move to the new position
            this->position = {new_x, new_y};
            break;
        }
    }

}

void Enemy1::findTarget(vector<vector<pair<char, void*>>>& map, int player_x, int player_y) {
    // Implementation for finding the target (player) in the map
    // This function should be overridden in the derived class
}