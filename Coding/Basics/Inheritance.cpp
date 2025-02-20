// Inheritance

#include <iostream>

using namespace std;

class Animal {
    private:
        string name;
        int age;

    public:

        Animal() {}
        Animal(string name, int age): name(name), age(age) {}

        void setName(string name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        void speak() {
            cout << name << " speaks" << endl;
        }   
};

class Dog : public Animal {
    private:
        string breed;

    public:

        Dog() {}
        Dog(string name, int age, string breed): Animal(name, age), breed(breed) {}
        
        void setBreed(string breed) {
            this->breed = breed;
        }

        string getBreed() {
            return breed;
        }

        void bark() {
            cout << getName() << " barks" << endl;
        }

        void speak() {
            cout << getName() << " speaks in derived class" << endl;
        }
};

int main() {
    Dog d;
    d.setName("Tommy");
    d.setAge(5);
    d.setBreed("Labrador");

    cout << "Name: " << d.getName() << endl;
    cout << "Age: " << d.getAge() << endl;
    cout << "Breed: " << d.getBreed() << endl;

    d.speak();
    d.bark();

    Dog d1("Spike", 3, "Pug");

    cout << "Name: " << d1.getName() << endl;

    return 0;
}