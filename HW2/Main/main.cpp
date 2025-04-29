#include "../Sources/Maze.cpp"

#include "../raylib.h"
#include <vector>

using namespace std;

int main() {
    const int screenWidth = 600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Dungeon Game");


    Maze maze; // Create a maze object
    maze.Intro(); // Display the introduction screen
    maze.startGame(); // Start the game loop
    maze.End(); // End the game loop

    maze.~Maze(); // Clean up the maze object

    CloseWindow(); // Close the window and clean up resources
    return 0; // Return success
}