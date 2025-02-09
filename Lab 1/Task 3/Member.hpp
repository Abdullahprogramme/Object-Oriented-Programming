#ifndef Member_hpp
#define Member_hpp

#include <string>
#include <queue>
#include "Book.hpp"

using namespace std;

class Member {
    private:
        string name;
        queue<Book*> borrowedBooks;

    public:
        Member(string name);

        std::string getName() const;
        bool borrowBook(Book* book);
        bool returnBook();
        void displayBorrowedBooks() const;
};

#endif // MEMBER_HPP