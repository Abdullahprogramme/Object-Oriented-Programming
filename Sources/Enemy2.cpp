#include "../Headers/Enemy2.hpp"
#include "../Headers/Enemy.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

Enemy2::Enemy2(string name, int health, int attack, string type) : Enemy(name, health, attack, type = "Enemy2") {}

Enemy2::~Enemy2() {}

void Enemy2::move(vector<vector<pair<char, void*>>>& map) {
    // Clear the old position
    map[this->position.first][this->position.second] = {' ', nullptr};

    int player_x = -1, player_y = -1;
    try {
        // Find the player's position
        int rows = map.size();
        if (rows == 0) throw std::runtime_error("Error: Map is empty.");
        int cols = map[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (map[i][j].first == 'P') { 
                    player_x = i;
                    player_y = j;
                    break;
                }
            }
            if (player_x != -1) break;
        }

        // Check if player exists
        if (player_x == -1 || player_y == -1) {
            throw runtime_error("Error: Player not found on the map.");
        }

    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        return;
    }

    // Find the new target position
    findTarget(map, player_x, player_y);

    // Update the map with the new position
    map[this->position.first][this->position.second] = {type == "Enemy1" ? '1' : '2', this};

}

void Enemy2::findTarget(vector<vector<pair<char, void*>>>& map, int player_x, int player_y) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    pair<int, int> best_position = this->position;
    int min_distance = INT_MAX;

    auto is_valid_position = [&map](int x, int y) {
        return x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y].first == ' ';
    };

    // Check all four directions
    for (const auto& dir : directions) {
        int new_x = position.first + dir.first;
        int new_y = position.second + dir.second;

        if (is_valid_position(new_x, new_y)) {
            int distance_to_player = abs(new_x - player_x) + abs(new_y - player_y); // Manhattan distance
            if (distance_to_player < min_distance) {
                min_distance = distance_to_player;
                best_position = {new_x, new_y};
            }
        }
    }

    // Update the enemy's position to the best position
    this->position = best_position;
}