#include <iostream>

using namespace std;


class Dynamic_Stack {
    private:
        int top;
        int capacity;
        int *array;

    public:
        Dynamic_Stack(int size = 10) {
            capacity = size;
            top = -1;
            array = new int[size];
        }

        ~Dynamic_Stack() {
            delete[] array;
        }

        void resize(int size) {
            int *newArray = new int[size];
            for (int i = 0; i <= top; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = size;
        }

        void push(int x) {
            if (isFull()) {
                resize(2 * capacity);
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
    Dynamic_Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.print();

    stack.pop();
    stack.pop();
    stack.pop();

    stack.print();

    cout << "Size: " << stack.size() << endl;
    cout << "Capacity: " << stack.getCapacity() << endl;
    cout << "Top: " << stack.getTop() << endl;
    cout << "Array[0]: " << stack.getArray(0) << endl;
    cout << "Peek: " << stack.peek() << endl;

    return 0;
}