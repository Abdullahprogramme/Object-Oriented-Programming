#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "Room.hpp"
using namespace std;

class Node {
    public:
        Room* room;
        Node* next;

        Node();
        Node(Room* room);
        Node(Room* room, Node* next);
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        Node* current;
        int size;

    public:
        LinkedList();
        ~LinkedList();

        void add(Room* room);
        void next();
        void prev();
        int getSize();
        Node* getHead();
        Node* getCurrent();
        bool isLast();
};

#endif // LinkedList_hpp