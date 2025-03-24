#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) : data(data), next(nullptr) {}
};

class CLL {
    private:
        Node* head;

    public:
        CLL() : head(nullptr) {}

        void InsertFirst(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }

        void InsertLast(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
        }

        void DeleteLast() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = head;
            delete toDelete;
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
            if (temp == nullptr || temp->next == head) {
                cout << "Invalid position" << endl;
                return;
            }
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }

        void Print() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

        ~CLL() {
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            delete temp;
        }

        friend ostream& operator<<(ostream& out, const CLL& cll) {
            Node* temp = cll.head;
            while (temp->next != cll.head) {
                out << temp->data << " ";
                temp = temp->next;
            }
            out << temp->data;
            return out;
        }

        friend istream& operator>>(istream& in, CLL& cll) {
            int n;
            in >> n;
            for (int i = 0; i < n; i++) {
                int data;
                in >> data;
                cll.InsertLast(data);
            }
            return in;
        }

        void Reverse() {
            if (head == nullptr || head->next == head) {
                return;
            }
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;
        
            do {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            } while (curr != head);
        
            head->next = prev;
            head = prev;
        }

        void ReverseRecursive(Node* prev, Node* curr, Node* next) {
            if (next == head) {
                curr->next = prev;
                head = curr;
                return;
            }
            curr->next = prev;
            ReverseRecursive(curr, next, next->next);
        }

        void ReverseRecursive() {
            if (head == nullptr) {
                return;
            }
            ReverseRecursive(nullptr, head, head->next);
        }
};

int main() {
    CLL cll;
    cll.InsertLast(1);
    cll.InsertLast(2);
    cll.InsertLast(3);
    cll.InsertLast(4);
    cll.InsertLast(5);
    cll.Print();
    cll.Reverse();
    
    cout << cll << endl;    

    return 0;
}
        