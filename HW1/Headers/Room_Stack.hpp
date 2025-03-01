// Stack to keep track the player’s path through the dungeon.

#ifndef ROOM_STACK_HPP
#define ROOM_STACK_HPP

#include "Room.hpp" 

class Stack {
    private:
        Room** stack;
        int top;
        int capacity;

    public:
        // Constructor
        Stack(int capacity);

        // Destructor
        ~Stack();

        // Methods
        void push(Room* room);
        Room* pop();
        Room* peek();
        bool isEmpty();
        bool isFull();
    
};

#endif // ROOM_STACK_HPP
