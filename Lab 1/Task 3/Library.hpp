#ifndef Library_hpp
#define Library_hpp

#include <vector>
#include "Book.hpp"
#include "Member.hpp"
#include "Librarian.hpp"

using namespace std;

class Library {
    private:
        vector<Book> books;
        vector<Member> members;
        Librarian librarian;

    public:
        Library(Librarian librarian);

        void addBook(string title, string author);
        void removeBook(string title);
        void addMember(string name);
        void borrowBook(string memberName, string bookTitle);
        void returnBook(string memberName);
        void displayBooks() const;
};

#endif // LIBRARY_HPP