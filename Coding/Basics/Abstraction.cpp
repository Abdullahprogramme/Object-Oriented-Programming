// Abstraction and pure virtual functions
// Pure virtual functions are functions that are declared in a base class but have no implementation. They are used to define an interface that derived classes must implement. 
// A class that contains at least one pure virtual function is called an abstract class. An abstract class cannot be instantiated, but it can be used as a base class for other classes. 
// Derived classes must implement all pure virtual functions of the base class, otherwise they will also be abstract classes.

#include <iostream>
#include <string>

using namespace std;

// Abstract class
class Base {
    private:
        string i;
        int j;

    public:
    
        Base() {}
        Base(string i, int j): i(i), j(j) {}

        void setI(string i) {
            this->i = i;
        }

        void setJ(int j) {
            this->j = j;
        }

        string getI() {
            return i;
        }

        int getJ() {
            return j;
        }

        // Pure virtual function
        virtual void do_something() = 0;  
};

// Derived class
class Derived : public Base {
    private:
        string k;

    public:

        Derived() {}
        Derived(string i, int j, string k): Base(i, j), k(k) {}
        
        void setK(string k) {
            this->k = k;
        }

        string getK() {
            return k;
        }

        // Override the pure virtual function
        void do_something() override {
            cout << getI() << " does something in derived class" << endl;
        }

        
};

int main() {
    // Base b; // Error: cannot instantiate an abstract class
    Derived d("Derived", 1, "Derived");
    d.do_something();
    

    // pointer to base class with dynamic binding
    Base *b_ptr = new Derived("Derived", 2, "Derived"); // dynamic binding
    b_ptr->do_something();

    // pointer to base class with static binding
    Base* b_ptr2;
    Derived d2;
    b_ptr2 = &d2; // static binding
    b_ptr2->do_something();

    return 0;
}