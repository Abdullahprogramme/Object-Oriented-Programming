// Basics of OOP

// 4 Pillars of OOP
// 1. Encapsulation: Grouping related variables and functions together
// 2. Abstraction: Hiding the complexity and showing only the essentials
// 3. Inheritance: Inheriting properties and methods from a parent class.
// 4. Polymorphism: More than one function in different classes taking the same name and functionalities.

#include <iostream>

using namespace std;


class Example {
    private:
        int x;
        double y;

    public:
        void print() {
            cout << "Hello World" << endl;
        }
};

int main() {
    Example e;
    e.print();
    return 0;
}