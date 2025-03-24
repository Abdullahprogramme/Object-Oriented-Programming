#include <iostream>
using namespace std;

class A {
    private:
        int* data;
    
    public:
        A() {
            data = new int[10];
        }

        // Shallow copy constructor
        // A(const A& other) : data(other.data) {}

        // Deep copy constructor
        A(const A& other) {
            data = new int[10];
            for (int i = 0; i < 10; i++) {
                data[i] = other.data[i];
            }
        }

        ~A() {
            delete[] data;
        }

        A& operator=(const A& other) {
            if (this != &other) {
                delete[] data;
                data = new int[10];
                for (int i = 0; i < 10; i++) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
};

int main() {
    A a;
    A b = a;  // Calls deep copy constructor
    A c(a);   // Calls deep copy constructor
    A d;
    d = a;    // Calls deep copy assignment operator
    return 0;
}