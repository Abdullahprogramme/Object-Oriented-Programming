#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() {
            cout << "Animal Sound" << endl;
        }

        void Speak() {
            cout << "Animal Speak" << endl;
            sound();
        }
};

class Mammal : public Animal {
    public:
        void sound() override {
            cout << "Mammal Sound" << endl;
        }

        void Speak() {
            cout << "Mammal Speak" << endl;
        }
};

class Dog : public Mammal {
    public:
        void WaggTail() {
            cout << "Dog Wagg Tail" << endl;
        }
};

class Cat : public Animal {
    public:
        void Climb() {
            cout << "Cat Climb" << endl;
        }
};

int main() {
    Animal* animalPtr = new Animal();
    Mammal* mammalPtr = new Mammal();
    Dog* dogPtr = new Dog();
    Cat* catPtr = new Cat();
    void* voidPtr1 = animalPtr;
    void* voidPtr2 = dogPtr;

    // Correct static casts
    Animal* animalFromVoid1 = static_cast<Animal*>(voidPtr1); // Correct
    Dog* dogFromVoid2 = static_cast<Dog*>(voidPtr2); // Correct

    // Incorrect static casts
    // Mammal* mammalFromVoid1 = static_cast<Mammal*>(voidPtr1); // Compiler error
    // Cat* catFromVoid2 = static_cast<Cat*>(voidPtr2); // Compiler error

    // Correct static casts
    Mammal* mammalFromAnimal = static_cast<Mammal*>(animalPtr); // Runtime error
    Animal* animalFromDog = static_cast<Animal*>(dogPtr); // Correct

    // Incorrect static casts
    // Dog* dogFromCat = static_cast<Dog*>(catPtr); // Compiler error

    // Demonstrating the results
    animalFromVoid1->Speak(); // Animal Speak
    dogFromVoid2->WaggTail(); // Dog Wagg Tail

    // Uncommenting the following lines will cause runtime errors or compiler errors
    // mammalFromVoid1->Speak();
    // catFromVoid2->Climb();
    // mammalFromAnimal->Speak();
    // dogFromCat->WaggTail();

    // Clean up
    delete animalPtr;
    delete mammalPtr;
    delete dogPtr;
    delete catPtr;

    return 0;
}