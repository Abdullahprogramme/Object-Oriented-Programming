#ifndef Book_hpp
#define Book_hpp

#include <string>

using namespace std;

class Book {
    private:
        string title;
        string author;
        bool available;

    public:
        Book(string title, string author);

        string getTitle() const;
        string getAuthor() const;
        bool isAvailable() const;
        void borrowBook();
        void returnBook();
};

#endif /* Book_hpp */