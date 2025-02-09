#ifndef Librarian_hpp
#define Librarian_hpp

#include <string>
#include <vector>
#include "Book.hpp"

using namespace std;

class Librarian {
    private:
        string name;

    public:
        Librarian(string name);

        string getName() const;
        void addBook(vector<Book>& books, string title, string author);
        void removeBook(vector<Book>& books, string title);
};

#endif /* Librarian_hpp */