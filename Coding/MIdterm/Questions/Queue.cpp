#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    private:
        Node* front;
        Node* rear;

    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        void enqueue(int data) {
            Node* newNode = new Node(data);
            if (rear == nullptr) {
                front = newNode;
                rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }

        int dequeue() {
            if (front == nullptr) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            int data = temp->data;
            delete temp;
            return data;
        }

        int peek() {
            if (front == nullptr) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void print() {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        ~Queue() {
            while (front != nullptr) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        // Move the nth element in the queue to the first element
        void MoveNth_To_Front(int n) {
            if (n <= 1 || front == nullptr) {
                return;
            }
            Node* prev = nullptr;
            Node* current = front;
            for (int i = 1; current != nullptr && i < n; i++) {
                prev = current;
                current = current->next;
            }
            if (current == nullptr) {
                return;
            }
            prev->next = current->next;
            current->next = front;
            front = current;
            if (rear == current) {
                rear = prev;
            }
        }
};

int main() {
    Queue* queue = new Queue();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6);
    queue->enqueue(7);
    queue->enqueue(8);
    queue->enqueue(9);
    queue->enqueue(10);
    queue->print();
    queue->MoveNth_To_Front(5);
    queue->print();
    queue->MoveNth_To_Front(1);
    queue->print();
    queue->MoveNth_To_Front(10);
    queue->print();
    queue->MoveNth_To_Front(11);
    queue->print();
    queue->MoveNth_To_Front(0);
    queue->print();
    queue->MoveNth_To_Front(-1);

    delete queue;

    return 0;
}