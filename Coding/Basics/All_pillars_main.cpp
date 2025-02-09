// Using the main function to call all the functions in the pillars of OOP

#include "All_Pillars.h"
#include <iostream>

using namespace std;

int main() {
    Animal animal("Generic Animal", 5); // Creating an instance of Animal
    Dog dog("Buddy", 3); // Creating an instance of Dog

    // Using encapsulation methods
    cout << "Animal Name: " << animal.getName() << endl;
    animal.setName("New Animal");
    cout << "Animal Name: " << animal.getName() << endl;
    cout << "Animal Age: " << animal.getAge() << endl;
    animal.speak(); // Polymorphism: calling the speak method of Animal

    cout << endl << endl;

    // Using encapsulation methods
    cout << "Dog Name: " << dog.getName() << endl;
    cout << "Dog Age: " << dog.getAge() << endl;
    dog.setAge(4);
    cout << "Dog Age: " << dog.getAge() << endl;    
    dog.speak(); // Polymorphism: calling the overridden speak method of Dog

    // Explicitly calling destructors (not usually recommended in real code)
    animal.~Animal();
    dog.~Dog();

    return 0;
}