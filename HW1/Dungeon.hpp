// This is the dungeon class

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string>
#include "Room.hpp"
#include "Player.hpp"
#include "DLL.hpp"
#include "Room_Stack.hpp"
#include "Enemy_Queue.hpp"

using namespace std;

class Dungeon {
    private:
        DLL* dungeon; // actual dungeon
        DLL* To_Check; // Just made to check the end of the game
        Room* current_room;
        Player* player;
        Stack* room_stack;

    public:
        Room* to_check;
        // Constructor
        Dungeon();

        // Destructor
        ~Dungeon();

        // Methods
        void add_room(Room* room);
        void next_room();
        void previous_room();
        void next_to_check();
        void previous_to_check();
        void show_choices();
        void start();
        void useItem();
        void show_choice_treasures();

        bool isGameOver();
};

#endif // DUNGEON_HPP
