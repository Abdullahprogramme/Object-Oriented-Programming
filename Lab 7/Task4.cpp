#include <iostream>
#include <stdexcept>

using namespace std;

// Base class
class Shape {
    public:
        // Pure virtual function
        virtual void Draw() const = 0;

        // Virtual destructor
        virtual ~Shape() {}
};

// Derived class from Shape
class Circle : public Shape {
    public:
        void Draw() const {
            cout << "Drawing Circle" << endl;
        }
};

// Derived class from Shape
class Square : public Shape {
    public:
        void Draw() const {
            cout << "Drawing Square" << endl;
        }
};

int main() {
    // Create an object that is not a Circle (or use a base class object).
    Shape* shape = new Square();

    try {
        Circle& circle = dynamic_cast<Circle&>(*shape);
        circle.Draw();
    } catch (const bad_cast& e) {
        cout << "Caught a bad cast exception: " << e.what() << endl;
    }
}