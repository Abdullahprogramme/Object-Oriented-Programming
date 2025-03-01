#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class of Animal
class Animal {
    protected:
        int legs;
    
    public:
        Animal(int legs) {
            this->legs = legs;
        }

        ~Animal() {}


        virtual void walk () {
            cout << "Animal walks with " << legs << " legs." << endl;
        }

        virtual void eat() {
            cout << "Animal eats food." << endl;
        }
};

// Abstract class of Pet (Interface)
class Pet {
    private:
        string name;

    public:
        virtual ~Pet() {}

        string getName() const { 
            return name; 
        
        }

        void setName(string name) { 
            this->name = name; 
        }

        
        virtual void play() const = 0;
};

// Derived class of Spider 
class Spider : public Animal {
    public:
        Spider() : Animal(8) {}

        void walk() override {
            cout << "Spider walks with " << legs << " legs." << endl;
        }

        void eat() override {
            cout << "Spider eats insects." << endl;
        }
};

// Derived class of Cat
class Cat : public Animal, public Pet {
    public:
        Cat() : Animal(4) {}
        Cat(string name) : Animal(4) {
            setName(name);
        }

        void walk() override {
            cout << "Cat walks with " << legs << " legs." << endl;
        }

        void eat() override {
            cout << "Cat eats meat." << endl;
        }

        void play() const override {
            cout << "Cat plays with a ball of yarn." << endl;
        }

        string getName() const {
            return Pet::getName();
        }

        void setName(string name) {
            Pet::setName(name);
        }
};

// Derived class of Fish
class Fish : public Animal, public Pet {
    public:
        Fish() : Animal(0) {}

        void walk() override {
            cout << "Fish cannot walk." << endl;
        }

        void eat() override {
            cout << "Fish eats fish food." << endl;
        }

        void play() const override {
            cout << "Fish plays with bubbles." << endl;
        }

        string getName() const {
            return Pet::getName();
        }

        void setName(string name) {
            Pet::setName(name);
        }
};

int main() {
    // Implementing these classes using vectors
    vector<Animal*> animals { new Spider(), new Cat("Tom"), new Fish() };
    vector<Pet*> pets { new Cat("Jerry"), new Fish() };

    cout << "Animals:" << endl;
    for (Animal* animal : animals) {
        animal->walk();
        animal->eat();
        // Testing if we can call play() on Animal objects
        Pet* pet = dynamic_cast<Pet*>(animal);
        if (pet) {
            pet->play();
        }
        cout << endl;
    }

    cout << "Pets:" << endl;
    for (Pet* pet : pets) {
        cout << "Pet " << pet->getName() << " plays." << endl;
        pet->play();
        // Testing if we can call walk() and eat() on Pet objects
        Animal* animal = dynamic_cast<Animal*>(pet);
        if (animal) {
            animal->walk();
            animal->eat();
        }
        cout << endl;
    }

    for (Animal* animal : animals) {
        delete animal;
    }

    for (Pet* pet : pets) {
        delete pet;
    }

    return 0;
}