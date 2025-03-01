#include "../Headers/DLL.hpp"

#include <iostream>
using namespace std;

DLL::DLL() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

DLL::~DLL() {
    DLL_node* temp = head;
    while (temp != nullptr) {
        DLL_node* next = temp->next;
        delete temp;
        cout << "Deleted DLL node" << endl;
        temp = next;
    }
}

void DLL::add_room(Room* room) {
    //allocate memory for new node
    DLL_node* new_node = new DLL_node;
    new_node->room = room;
    new_node->next = nullptr;
    new_node->previous = nullptr;

    // if list is empty, set head and tail to new node
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        current = new_node;
    } else { // otherwise, add new node to end of list
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
}

void DLL::next_room() {
    if (current->next != nullptr) {
        current = current->next;
    } else {
        cout << "No next room" << endl;
    }
}

void DLL::previous_room() {
    if (current->previous != nullptr) {
        current = current->previous;
    } else {
        cout << "No previous room" << endl;
    }
}

Room* DLL::get_current() {
    return current->room;
}

Room* DLL::peek_next() {
    if (current->next != nullptr) {
        return current->next->room;
    } else {
        return nullptr;
    }
}
