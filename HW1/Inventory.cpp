#include <string>
#include "Inventory.hpp" 
#include "Treasure.hpp"
#include <iostream>

using namespace std;

Inventory::Inventory(int size, int capacity) {
    this->size = size;
    this->capacity = capacity;
    this->arr = new Treasure[capacity];
}

Inventory::~Inventory() {
    for (int i = 0; i < size; i++) {
        delete &arr[i];
    }
    delete[] arr;
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

void Inventory::Add(Treasure item) {
    if (size == capacity) {
        Resize();
    }
    arr[size] = item;
    size++;
}

bool Inventory::operator==(const Treasure& other) const {
    return name == other.getName();
}

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