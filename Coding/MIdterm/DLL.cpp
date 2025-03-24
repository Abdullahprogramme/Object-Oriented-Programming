#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {} // Fixed constructor
};

class DLL {
private:
    Node* head;
    Node* tail;

public:
    DLL() : head(nullptr), tail(nullptr) {}

    void InsertFirst(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void InsertLast(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void InsertAt(int data, int pos) {
        if (pos == 0) {
            InsertFirst(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }

    void DeleteFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
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

    void DeleteLast() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void DeleteAt(int pos) {
        if (pos == 0) {
            DeleteFirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->prev = temp;
        } else {
            tail = temp;
        }
        delete toDelete;
    }

    void Print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DLL() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    friend ostream& operator<<(ostream& out, const DLL& dll) {
        Node* temp = dll.head;
        while (temp != nullptr) {
            out << temp->data << " ";
            temp = temp->next;
        }
        out << endl;
        return out;
    }

    friend istream& operator>>(istream& in, DLL& dll) {
        int n;
        in >> n;
        for (int i = 0; i < n; i++) {
            int data;
            in >> data;
            dll.InsertLast(data);
        }
        return in;
    }

    void Reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
    }

    void ReverseRecursive(Node* node) {
        if (node == nullptr) return;
        
        Node* temp = node->next;
        node->next = node->prev;
        node->prev = temp;
        
        if (node->prev == nullptr) {
            head = node;
            return;
        }
        ReverseRecursive(node->prev);
    }

    void ReverseRecursive() {
        if (head == nullptr) return;
        tail = head;
        ReverseRecursive(head);
    }
};

int main() {
    DLL dll;
    cin >> dll;
    cout << "Original List: " << dll;
    
    dll.Reverse();
    cout << "Reversed List: " << dll;

    dll.DeleteFirst();
    cout << "After Deleting First: " << dll;

    dll.DeleteLast();
    cout << "After Deleting Last: " << dll;

    return 0;
}
