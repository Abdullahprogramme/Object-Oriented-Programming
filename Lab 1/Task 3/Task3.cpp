#include <iostream>
#include "Library.hpp"

using namespace std;

int main() {
    Librarian librarian("Addulllah");
    Library library(librarian);

    library.addBook("Book 1", "Author 1");
    library.addBook("Book 2", "Author 2");
    library.addBook("Book 3", "Author 3");

    library.addMember("Person 1");
    library.addMember("Person 2");

    library.displayBooks();

    cout << endl;

    library.borrowBook("Person 1", "Book 1");
    library.borrowBook("Person 2", "Book 2");
    library.borrowBook("Person 1", "Book 3");

    library.displayBooks();

    cout << endl;

    library.returnBook("Person 1");
    library.returnBook("Person 2");

    library.displayBooks();

    return 0;
}