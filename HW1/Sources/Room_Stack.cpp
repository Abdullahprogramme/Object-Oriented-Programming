#include "../Headers/Room_Stack.hpp"

#include <iostream>
using namespace std;

Stack::Stack(int capacity) : capacity(capacity), top(-1) {
    stack = new Room*[capacity];
    for (int i = 0; i < capacity; ++i) {
        stack[i] = nullptr; // Initialize pointers to nullptr
    }
}

Stack::~Stack() {
    for (int i = 0; i < capacity; i++) {
        if (stack[i] != nullptr) {
            delete stack[i]; // Delete each dynamically allocated Room object
            cout << "Deleted room " << i << endl;
        }
    }
    delete[] stack;
    cout << "Deleted stack" << endl;
}

void Stack::push(Room* room) { 
    if (isFull()) {
        cout << "Stack is full" << endl;
    } else {
        stack[++top] = room;
    }
}

Room* Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return nullptr;
    } else {
        return stack[top--];
    }
}

Room* Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return nullptr;
    } else {
        return stack[top];
    }
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}
