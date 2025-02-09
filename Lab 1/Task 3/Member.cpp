#include "Member.hpp"
#include <iostream>

using namespace std;

Member::Member(std::string name) : name(name) {}

string Member::getName() const {
    return name;
}

bool Member::borrowBook(Book* book) {
    if (borrowedBooks.size() < 3 && book->isAvailable()) {
        borrowedBooks.push(book);
        book->borrowBook();
        return true;
    }
    return false;
}

bool Member::returnBook() {
    if (!borrowedBooks.empty()) { // Checking the queue is not empty
        Book* book = borrowedBooks.front(); // Get the book at the front of the queue
        borrowedBooks.pop(); // Remove the book from the queue
        book->returnBook(); // Return the book
        return true;
    }
    return false;
}

void Member::displayBorrowedBooks() const {
    queue<Book*> tempQueue = borrowedBooks;
    while (!tempQueue.empty()) {
        Book* book = tempQueue.front();
        tempQueue.pop();
        cout << book->getTitle() << " by " << book->getAuthor() << endl;
    }
}