// Doubly linked list to navigate throught the rooms

#ifndef DLL_HPP
#define DLL_HPP

#include "Room.hpp"

class DLL_node {
    public:
        Room* room;
        DLL_node* next;
        DLL_node* previous;

        DLL_node() {
            delete room; // Free the memory allocated for the Room object
        }
};


class DLL {
    private:
        DLL_node* head;
        DLL_node* tail;
        DLL_node* current;

    public:
        // Constructor
        DLL();

        // Destructor
        ~DLL();

        // Methods
        void add_room(Room* room);
        void next_room();
        void previous_room();
        Room* get_current();
};

#endif // DLL_HPP
