#include "DLL.hpp"

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
        temp = next;
    }
}

void DLL::add_room(Room* room) {
    DLL_node* new_node = new DLL_node;
    new_node->room = room;
    new_node->next = nullptr;
    new_node->previous = nullptr;

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        current = new_node;
    } else {
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
}

void DLL::next_room() {
    if (current->next != nullptr) {
        current = current->next;
    }
}

void DLL::previous_room() {
    if (current->previous != nullptr) {
        current = current->previous;
    }
}

Room* DLL::get_current() {
    return current->room;
}