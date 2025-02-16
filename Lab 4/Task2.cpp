#include <iostream>

using namespace std;

class Leaderboard {
    private:
        int* scores;
        int capacity;
        int size;

        // Function to resize the scores array
        // Time complexity: O(n) where n is the number of players
        void resize() {
            int newCapacity = capacity * 2;
            int* newScores = new int[newCapacity];

            for (int i = 0; i < size; i++) {
                newScores[i] = scores[i];
            }
            delete[] scores;
            scores = newScores;
            capacity = newCapacity;
        }

    public:
        // Constructor
        Leaderboard(int initialCapacity = 5) {
            capacity = initialCapacity;
            size = 0;
            scores = new int[capacity];
        }

        // Destructor
        ~Leaderboard() {
            delete[] scores;
        }

        // Function to add a player to the leaderboard
        // Time complexity: O(1)
        void addPlayer(int score) {
            if (size == capacity) {
                resize();
            }
            scores[size++] = score;
        }

        // Function to update the score of a player
        // Time complexity: O(1)
        void updateScore(int index, int newScore) {
            if (index >= 0 && index < size) {
                scores[index] = newScore;
            } else {
                cout << "Invalid index!" << endl;
            }
        }

        // Function to display the leaderboard scores
        // Time complexity: O(n) where n is the number of players
        void display() {
            cout << "Leaderboard Scores: ";
            for (int i = 0; i < size; i++) {
                cout << scores[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Leaderboard lb;

    // Add players to the leaderboard
    lb.addPlayer(100);
    lb.addPlayer(200);
    lb.addPlayer(150);
    lb.addPlayer(175);
    lb.addPlayer(120);
    lb.display();
    
    lb.addPlayer(180); // Triggers resize
    lb.display();
    
    lb.updateScore(2, 300);
    lb.display();
    
    return 0;
}
