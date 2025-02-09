// Two classes to show all four pillars of OOP
// All_Pillars.h so just class and method declarations

#ifndef All_Pillars_h
#define All_Pillars_h

#include <iostream>

using namespace std;

class Animal {
    private:
        string name; // Encapsulation: private members
        int age;    

    public:
        Animal(string name, int age); // Constructor
        ~Animal(); // Destructor
        void setName(string name); // Encapsulation: public methods to access private members
        string getName();
        void setAge(int age);
        int getAge();
        virtual void speak(); // Polymorphism: virtual function for method overriding
};

class Dog : public Animal { // Inheritance: Dog class inherits from Animal class
    public:
        Dog(string name, int age); // Constructor
        ~Dog(); // Destructor
        void speak(); // Polymorphism: overriding the speak method
};

#endif /* All_Pillars_h */