#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class GenericLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        // Constructor
        GenericLinkedList() : head(nullptr), tail(nullptr), size(0) {}

        // Destructor
        ~GenericLinkedList() {
            clear();
        }

        // Clear the list
        void clear() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        // Check if the list is empty
        bool isEmpty() const {
            if (head == nullptr) {
                return true;
            } else {
                return false;
            }
        }

        // Add a new element to the end of the list
        void add(T value) {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        // Delete the last element from the list
        void removeLast() {
            try {
                if (isEmpty()) {
                    throw runtime_error("List is empty. Cannot remove last element.");
                }
            } catch (const runtime_error& e) {
                cerr << e.what() << endl;
                return;
            }

            if (head == tail) { // If there's only one element
                delete head;
                head = nullptr;
                tail = nullptr;
            } else { // If there are more than one element
                Node<T>* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
            size--;
        }

        // Get the size of the list
        int getSize() const {
            return size;
        }

        void printList() const {
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
};

int main() {
    GenericLinkedList<int> intList;
    intList.add(1);
    intList.add(2);
    intList.add(3);

    cout << "Size of intList: " << intList.getSize() << endl; // Output: 3

    intList.removeLast();
    cout << "Size of intList after removing last element: " << intList.getSize() << endl; // Output: 2
    intList.printList();

    GenericLinkedList<string> stringList;
    stringList.add("Hello");
    stringList.add("World");

    cout << "Size of stringList: " << stringList.getSize() << endl; // Output: 2

    stringList.removeLast();
    cout << "Size of stringList after removing last element: " << stringList.getSize() << endl; // Output: 1

    stringList.printList();
    stringList.removeLast();
    stringList.removeLast(); // Attempt to remove from an empty list
    return 0;
}