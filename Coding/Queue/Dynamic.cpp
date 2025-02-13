#include <iostream>

using namespace std;

class Dynamic_Queue {
    private:
        int *arr;
        int front;
        int rear;
        int size;

    public:

        Dynamic_Queue() {
            front = -1;
            rear = -1;
            size = 5;
            arr = new int[size];
        }

        ~Dynamic_Queue() {
            delete[] arr;
        }

        bool isFull() {
            return (rear == size - 1);
        }

        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        void enqueue(int x) {
            if (isFull()) {
                cout << "Queue is full" << endl;
            } else {
                if (isEmpty()) {
                    front = 0;
                    rear = 0;
                } else {
                    rear++;
                }
                arr[rear] = x;
            }
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front++;
                }
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                for (int i = front; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Dynamic_Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}