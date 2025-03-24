#include <iostream>
using namespace std;

class Base {
    private:
        int a;

    public:
        Base(int a) : a(a) {}
        virtual void Display() {
            cout << "Base: " << a << endl;
        }

        virtual ~Base() {}

        void Print() {
            cout << "Print from Base" << endl;
        }
};

class Derived : public Base {
    private:
        int b;

    public:
        Derived(int a, int b) : Base(a), b(b) {}
        void Display() override {
            cout << "Derived: " << b << endl;
        }

        void Print() {
            cout << "Print from Derived" << endl;
        }
};

int main() {
    Base* b = new Derived(10, 20);
    b->Display();
    b->Print();
    delete b;
    
    Base b1 = Base(50);
    b1.Display();
    b1.Print();

    Derived d = Derived(60, 70);
    d.Display();
    d.Print();

    Base* b2 = new Base(80);
    b2->Display();
    b2->Print();
    delete b2;

    Base* b3;
    Derived d1 = Derived(90, 100);
    b3 = &d1;
    b3->Display();
    b3->Print();
    

    Base& obj = d1;
    obj.Display();
    obj.Print();

    return 0;
}