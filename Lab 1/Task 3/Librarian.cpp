#include "Librarian.hpp"
#include <algorithm>

using namespace std;

Librarian::Librarian(string name) : name(name) {}

string Librarian::getName() const {
    return name;
}

void Librarian::addBook(vector<Book>& books, string title, string author) {
    books.push_back(Book(title, author));
}

void Librarian::removeBook(vector<Book>& books, string title) {
    books.erase(remove_if(books.begin(), books.end(), [&](Book& book) {
        return book.getTitle() == title;
    }), books.end());
}