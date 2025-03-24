#include <iostream>
using namespace std;

class Base {
    private:
        int x;
        int y;

    public:
        Base() : x(0), y(0) {}
        explicit Base(int x, int y) : x(x), y(y) {}

        void Print() {
            cout << x << " " << y << endl;
        }
};

class Derived1 : public Base {
    private:
        int z;

    public:
        Derived1() : Base(), z(0) {}
        Derived1(int x, int y, int z) : Base(x, y), z(z) {}

        void Print() {
            Base::Print();
            cout << z << endl;
        }
};

class Derived2 : protected Base {
    private:
        int z;

    public:
        Derived2() : Base(), z(0) {}
        Derived2(int x, int y, int z) : Base(x, y), z(z) {}

        void Print() {
            Base::Print();
            cout << z << endl;
        }
};

class Derived3 : private Base {
    private:
        int z;

    public:
        Derived3() : Base(), z(0) {}
        Derived3(int x, int y, int z) : Base(x, y), z(z) {}

        void Print() {
            Base::Print();
            cout << z << endl;
        }
};

int main() {
    Base b(1, 2);
    b.Print();

    Derived1 d1(3, 4, 5);
    d1.Print();

    Derived2 d2(6, 7, 8);
    d2.Print();

    Derived3 d3(9, 10, 11);
    d3.Print();

    return 0;
}