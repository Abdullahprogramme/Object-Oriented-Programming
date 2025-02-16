#include <iostream>

using namespace std;

class Queue {
    int front, rear, size;
    int* queue;

    public:

        // Parameterized constructor
        Queue(int size) {
            front = rear = -1;
            this->size = size;
            queue = new int[size];
        }

        // Function to check if the queue is full
        bool isFull() {
            return (rear == size - 1);
        }

        // Function to check if the queue is empty
        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        // Function to resize the queue
        // Time complexity: O(n) where n is the number of elements in the queue
        void resize(int newSize) {
            int* newQueue = new int[newSize];
            for (int i = 0; i <= rear; i++) {
                newQueue[i] = queue[i];
            }
            delete[] queue;
            queue = newQueue;
            size = newSize;
        }

        // Function to add an element to the queue
        // Time complexity: O(1)
        void enqueue(int value) {
            if (isFull()) {
                resize(size * 2);
            }
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            queue[rear] = value;
        }

        // Function to remove an element from the queue
        // Time complexity: O(1)
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }

        // Function to get the front element of the queue
        // Time complexity: O(1)
        int getFront() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return queue[front];
        }

        // Function to get the rear element of the queue
        // Time complexity: O(1)
        int getRear() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return queue[rear];
        }

        // Function to display the elements of the queue
        // Time complexity: O(n) where n is the number of elements in the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }

        // Destructor
        ~Queue() {
            delete[] queue;
        }

};

int main() {
    Queue q(5);

    // Enqueue 5 elements
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
    }

    q.display();
    cout << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    for (int i = 6; i <= 10; i++) {
        q.enqueue(i);
    }

    q.display();
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    return 0;
}
