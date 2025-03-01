#include "../Headers/Enemy_Queue.hpp"

#include <iostream>
using namespace std;

Enemy_Queue::Enemy_Queue(int size) {
    // a dynamic array of Enemy object pointers
    enemy_array = new Enemy*[size];
    front = 0;
    rear = -1;
    capacity = size;
    count = 0;
}

Enemy_Queue::~Enemy_Queue() {
    for (int i = 0; i < capacity; i++) {
        delete enemy_array[i];
        cout << "Deleted enemy " << i << endl;
    }
    delete[] enemy_array;
    cout << "Deleted enemy array" << endl;
}

void Enemy_Queue::enqueue(Enemy* enemy) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        enemy_array[++rear] = enemy;
        count++;
    }
}

Enemy* Enemy_Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return nullptr;
    } else {
        count--;
        return enemy_array[front++];
    }
}

Enemy* Enemy_Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return nullptr;
    } else {
        return enemy_array[front];
    }
}

int Enemy_Queue::size() {
    return count;
}

bool Enemy_Queue::isEmpty() {
    return (size() == 0);
}

bool Enemy_Queue::isFull() {
    return (size() == capacity);
}
