#include "../Headers/Queue.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

Queue::Queue() : front(0), rear(-1), size(0) {
    // Constructor initializes the queue with front at 0, rear at -1, and size at 0
}

void Queue::setFront(int front) {
    this->front = front;
}

int Queue::getFront() const {
    return front;
}

void Queue::setRear(int rear) {
    this->rear = rear;
}

int Queue::getRear() const {
    return rear;
}

void Queue::setSize(int size) {
    this->size = size;
}

int Queue::getSize() const {
    return size;
}

void Queue::enqueue(Enemy *enemy) {
    if (isEmpty()) {
        front = 0; // Set front to 0 if the queue is empty
    }

    if (size == 4) {
        throw overflow_error("Queue is full"); // Throw an error if the queue is full
    }

    enemies[(++rear) % 4] = enemy; // Add the enemy to the rear of the queue
    size++; // Increment the size of the queue
}

Enemy* Queue::dequeue() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty"); // Throw an error if the queue is empty
    }

    Enemy* enemy = enemies[front]; // Get the enemy at the front of the queue
    front = (front + 1) % 4; // Move the front pointer to the next position
    size--; // Decrement the size of the queue

    return enemy; // Return the dequeued enemy
}

Enemy* Queue::peek() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty"); // Throw an error if the queue is empty
    }

    return enemies[front]; // Return the enemy at the front of the queue without removing it
}

bool Queue::isEmpty() {
    return size == 0; // Check if the queue is empty
}

