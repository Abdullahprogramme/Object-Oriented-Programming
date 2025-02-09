// Two classes to show all four pillars of OOP
// All_Pillars.cpp so just method definitions

// Two classes to show all four pillars of OOP
// All_Pillars.cpp so just method definitions

#include "All_Pillars.h"
#include <iostream>

using namespace std;

// Animal class
Animal::Animal(string name, int age) { // Constructor
    this->name = name;
    this->age = age;
}

Animal::~Animal() { // Destructor
    cout << "Animal destructor called" << endl;
}

void Animal::setName(string name) { // Encapsulation: public method to set private member
    this->name = name;
}

string Animal::getName() { // Encapsulation: public method to get private member
    return name;
}

void Animal::setAge(int age) { // Encapsulation: public method to set private member
    this->age = age;
}

int Animal::getAge() { // Encapsulation: public method to get private member
    return age;
}

void Animal::speak() { // Polymorphism: base class method
    cout << "Animal speaks" << endl;
}

// Dog class
Dog::Dog(string name, int age) : Animal(name, age) { // Inheritance: calling base class constructor
}

Dog::~Dog() { // Destructor
    cout << "Dog destructor called" << endl;
}

void Dog::speak() { // Polymorphism: overriding base class method
    cout << "Dog barks" << endl;
}