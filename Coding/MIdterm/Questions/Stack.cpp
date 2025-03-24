#include <iostream>
using namespace std;

class Stack {
    private:
        int* stack;
        int top;
        int capacity;

    public:
        Stack(int capacity) {
            this->capacity = capacity;
            stack = new int[capacity];
            top = -1;
        }

        void push(int value) {
            if (top == capacity - 1) {
                cout << "Stack Overflow" << endl;
                return;
            }
            stack[++top] = value;
        }

        int pop() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return stack[top--];
        }

        int peek() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return stack[top];
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == capacity - 1;
        }

        ~Stack() {
            delete[] stack;
        }

        void print() {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack* stack = new Stack(5);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->print();

    cout << stack->pop() << endl;

    stack->print();

    cout << stack->peek() << endl;

    cout << stack->isEmpty() << endl;

    cout << stack->isFull() << endl;

    delete stack;

    return 0;
}