#include "../Headers/Inventory.hpp" 
#include "../Headers/Treasure.hpp"
#include <iostream>
#include <string>

using namespace std;

Inventory::Inventory(int size, int capacity) {
    this->size = size;
    this->capacity = capacity;
    this->arr = new Treasure[capacity];
}

Inventory::~Inventory() {
    delete[] arr;
    cout << "Deleted inventory" << endl;
}

void Inventory::Resize() {
    Treasure* newArr = new Treasure[capacity * 2];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity *= 2;
}

// Adds a treasure to the inventory and resizes the inventory if it is full
void Inventory::Add(Treasure item) {
    if (size == capacity) {
        Resize();
    }
    arr[size] = item;
    size++;
}

// This is the overloaded operator for the Inventory class
// It checks if the name of the treasure in the inventory is the same as the name of the treasure being compared to the inventory
// If the names are the same, it returns true, otherwise it returns false
bool Inventory::operator==(const Treasure& other) const {
    return name == other.getName();
}

// Removes a treasure from the inventory
void Inventory::Remove(Treasure item) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return;
        }
    }
}

void Inventory::Print() {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << arr[i].getName() << " (Attack: " << arr[i].getAttack() << ", Defense: " << arr[i].getDefense() << ")" << endl;
    }
}
