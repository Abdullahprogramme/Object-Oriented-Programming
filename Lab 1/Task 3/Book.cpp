#include "Book.hpp"

using namespace std;

Book::Book(std::string title, std::string author) : title(title), author(author), available(true) {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return available;
}

void Book::borrowBook() {
    available = false;
}

void Book::returnBook() {
    available = true;
}