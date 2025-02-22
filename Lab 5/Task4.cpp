#include <iostream>
#include <string>

using namespace std;

class Animal {
    protected:
        string name;
        int age;

    public:
        virtual void makeSound() {
            cout << "makes a generic animal sound" << endl;
        }

        virtual void displayInfo() = 0;

        Animal(string name, int age) {
            this->name = name;
            if (age < 0) {
                this->age = 0;
            } else {
                this->age = age;
            }
        }
};

class Lion : public Animal {
    public:
        Lion(string name, int age) : Animal(name, age) {}

        void makeSound() override {
            cout << name << " roars loudly!" << endl;
        }

        void displayInfo() override {
            cout << name << " makes a generic animal sound" << endl;
        }
};

class Snake : public Animal {
    private:
        bool veneomous;

    public:
        Snake(string name, int age) : Animal(name, age) {}

        void makeSound() override {
            cout << name << " hisses softly!" << endl;
        }

        void displayInfo() override {
            cout << "Venomous: " << (veneomous ? "Yes" : "No") << endl;
        }
};

class Monkey : public Animal {
    public:
        Monkey(string name, int age) : Animal(name, age) {}

        void makeSound() override {
            cout << name << " screeches loudly!" << endl;
        }

        void displayInfo() override {
            cout << name << " jumps a lot" << endl;
        }
};

int main() {
    Lion l("lion", 5);
    Snake s("snake", 2);
    Monkey m("monkey", 3);

    cout << "Animal sounds:" << endl;
    l.makeSound();
    s.makeSound();
    m.makeSound();

    cout << endl << "Animal info:" << endl;

    l.displayInfo();
    s.displayInfo();
    m.displayInfo();

    return 0;
}