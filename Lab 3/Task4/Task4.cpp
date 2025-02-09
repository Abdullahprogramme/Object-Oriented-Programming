#include <iostream> 
#include <stdexcept>

using namespace std;

// Douvle linked list node
class Node {
    public:
        int data; // The information stored
        Node* next; // Pointer to the next node
        Node* prev; // Pointer to the previous node
        
        // Constructor
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head; // Pointer to the first node
        Node* tail; // Pointer to the last node
        
    public:

        // Constructor
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // Destructor
        ~DoublyLinkedList() {
            Node* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Forward traversal
        void forwardTraversal() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        // Backward traversal
        void backwardTraversal() {
            Node* temp = tail;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }

        // Get value at a specific index, also checking for out of bounds
        int get(int index) {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                if (temp == nullptr) {
                    throw out_of_range("Index out of bounds");
                }
                temp = temp->next;
            }
            return temp->data;
        }

        // Set value at a specific index, also checking for out of bounds
        void set(int index, int data) {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                if (temp == nullptr) {
                    throw out_of_range("Index out of bounds");
                }
                temp = temp->next;
            }
            temp->data = data;
        }

        // Remove the first node
        void removeFirst() {
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }

        // Remove the last node
        void removeLast() {
            if (tail == nullptr) {
                return;
            }
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }

        // Add a value at the beginning
        void addFirst(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        // Add a value at the end
        void addLast(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
            }
            tail = newNode;
        }
        
};

int main() {
    DoublyLinkedList list;

    // Adding values to the list
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);

    // Forward traversal
    list.forwardTraversal();

    // Backward traversal
    list.backwardTraversal();

    // Get value at index 2
    cout << "Value at index 2: " << list.get(2) << endl;

    // Remove the first node
    list.removeFirst();

    // Forward traversal
    list.forwardTraversal();

    // Removing all nodes but last
    list.removeFirst();
    list.removeFirst();
    list.removeFirst();

    // Forward traversal
    list.forwardTraversal();

    // Add a value at the beginning
    list.addFirst(10);

    // Remove the last node
    list.removeLast();

    // Forward traversal
    list.forwardTraversal();

    return 0;
}   