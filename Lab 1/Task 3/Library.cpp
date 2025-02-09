#include "Library.hpp"
#include <iostream>

using namespace std;

Library::Library(Librarian librarian) : librarian(librarian) {}

void Library::addBook(string title, string author) {
    librarian.addBook(books, title, author);
}

void Library::removeBook(string title) {
    librarian.removeBook(books, title);
}

void Library::addMember(string name) {
    members.push_back(Member(name));
}

void Library::borrowBook(string memberName, string bookTitle) {
    for (auto& member : members) { // Iterate through members
        if (member.getName() == memberName) { // If member found
            for (auto& book : books) {  // Iterate through books if member found
                if (book.getTitle() == bookTitle && book.isAvailable()) { // If book found and available
                    if (member.borrowBook(&book)) {
                        cout << memberName << " borrowed " << bookTitle << endl;
                    } else {
                        cout << memberName << " cannot borrow more than 3 books." << endl;
                    }
                    return;
                }
            }
            cout << bookTitle << " is not available." << endl;
            return;
        }
    }
    cout << "Member " << memberName << " not found." << endl;
}

void Library::returnBook(std::string memberName) {
    for (auto& member : members) { // Iterate through members
        if (member.getName() == memberName) { // If member found
            if (member.returnBook()) {
                cout << memberName << " returned a book." << endl;
            } else {
                cout << memberName << " has no books to return." << endl;
            }
            return;
        }
    }
    cout << "Member " << memberName << " not found." << endl;
}

void Library::displayBooks() const {
    for (const auto& book : books) {
        cout << book.getTitle() << " by " << book.getAuthor() << " - " 
                  << (book.isAvailable() ? "Available" : "Borrowed") << endl;
    }
}