#ifndef Potion_hpp
#define Potion_hpp

#include <iostream>
#include <string>

using namespace std;

class Potion {
    private: 
        string name;

    public:
        Potion(string name); // Constructor to initialize potion name
        virtual ~Potion(); // Destructor

        string getName(); // Getter for potion name
        void setName(string name); // Setter for potion name

};

#endif // Potion_hpp