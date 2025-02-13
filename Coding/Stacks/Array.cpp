#include <iostream>
#include <array>

using namespace std;

class Stack {
    private:
        int top;
        int capacity;
        array<int, 5> array;

    public:
        Stack() {
            top = -1;
            capacity = 5;
        }

        void push(int x) {
            if (isFull()) {
                cout << "Stack is full" << endl;
                return;
            }
            array[++top] = x;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return 0;
            }
            return array[top--];
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return 0;
            }
            return array[top];
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == capacity - 1;
        }

        int size() {
            return top + 1;
        }

        void print() {
            for (int i = top; i >= 0; i--) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        int getCapacity() {
            return capacity;
        }

        int getTop() {
            return top;
        }

        int getArray(int i) {
            return array[i];
        }

        void setArray(int i, int value) {
            array[i] = value;
        }

        void setTop(int value) {
            top = value;
        }

        void setCapacity(int value) {
            capacity = value;
        }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.print();
    cout << "Popped: " << stack.pop() << endl;
    stack.print();
    cout << "Peek: " << stack.peek() << endl;
    cout << "Size: " << stack.size() << endl;
    cout << "Capacity: " << stack.getCapacity() << endl;
    cout << "Top: " << stack.getTop() << endl;
    stack.setArray(0, 10);
    stack.setTop(0);
    stack.setCapacity(1);
    stack.print();
    return 0;
}