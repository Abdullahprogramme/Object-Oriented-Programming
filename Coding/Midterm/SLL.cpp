#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) : data(data), next(nullptr) {}
};

class SLL {
    private:
        Node* head;
    
    public:
        SLL() : head(nullptr) {}

        void InsertFirst(int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void InsertLast(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void InsertAt(int data, int pos) {
            if (pos == 0) {
                InsertFirst(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                if (temp == nullptr) {
                    cout << "Invalid position" << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Invalid position" << endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void DeleteFirst() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void DeleteLast() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        void DeleteAt(int pos) {
            if (pos == 0) {
                DeleteFirst();
                return;
            }
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                if (temp == nullptr) {
                    cout << "Invalid position" << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Invalid position" << endl;
                return;
            }
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
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

        ~SLL() {
            Node* temp = head;
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }

        friend ostream& operator<<(ostream& out, const SLL& sll) {
            Node* temp = sll.head;
            while (temp != nullptr) {
                out << temp->data << " ";
                temp = temp->next;
            }
            return out;
        }

        friend istream& operator>>(istream& in, SLL& sll) {
            int n;
            in >> n;
            for (int i = 0; i < n; i++) {
                int data;
                in >> data;
                sll.InsertLast(data);
            }
            return in;
        }

        void Reverse() {
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        void ReverseRecursive(Node* prev, Node* curr) {
            if (curr == nullptr) {
                head = prev;
                return;
            }
            Node* next = curr->next;
            curr->next = prev;
            ReverseRecursive(curr, next);
        }

        void ReverseRecursive() {
            ReverseRecursive(nullptr, head);
        }
};

int main() {
    SLL sll;
    cin >> sll;
    cout << sll;
    sll.Reverse();
    cout << sll;
    
    return 0;
}