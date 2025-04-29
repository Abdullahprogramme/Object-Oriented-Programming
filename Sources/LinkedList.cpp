#include "../Headers/LinkedList.hpp"
#include "../Headers/Room.hpp"
#include <string>

using namespace std;

Node::Node() : room(nullptr), next(nullptr) {}

Node::Node(Room* room) : room(room), next(nullptr) {}

Node::Node(Room* room, Node* next) : room(room), next(next) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

LinkedList::~LinkedList() {
    Node* currentptr = head;
    while (currentptr != nullptr) {
        Node* nextNode = current->next;
        delete currentptr->room; 
        delete currentptr;
        currentptr = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    current = nullptr;
    currentptr = nullptr;
    size = 0;
}

void LinkedList::add(Room* room) {
    Node* newNode = new Node(room);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        current = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::next() {
    if (current != nullptr) {
        current = current->next;
    }
}

void LinkedList::prev() {
    if (head != nullptr) {
        Node* current = head;
        while (current->next != nullptr && current->next->next != nullptr) {
            current = current->next;
        }
        head = current;
    }
}

int LinkedList::getSize() {
    return size;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getCurrent() {
    return current;
}

bool LinkedList::isLast() {
    return current == nullptr || current->next == nullptr;
}