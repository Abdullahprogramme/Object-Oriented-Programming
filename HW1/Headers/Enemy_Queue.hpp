// Queue to maintain enemies

#ifndef ENEMY_QUEUE_HPP
#define ENEMY_QUEUE_HPP

#include "Enemy.hpp"

class Enemy_Queue {
    private:
        // an dynamic array of Enemy object pointers
        Enemy** enemy_array;
        int front;
        int rear;
        int capacity;
        int count;

    public:
        // Constructor
        Enemy_Queue(int size);

        // Destructor
        ~Enemy_Queue();

        // Methods
        void enqueue(Enemy* enemy);
        Enemy* dequeue();
        Enemy* peek();
        int size();
        bool isEmpty();
        bool isFull();

};

#endif // ENEMY_QUEUE_HPP
