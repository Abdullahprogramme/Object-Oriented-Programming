// Polymorphism

#include <iostream>

using namespace std;

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

        virtual void do_something() {
            cout << i << " does something" << endl;
        }  

        void func() {
            cout << "Base func" << endl;
        }
};

class Base2 {
    public:
        void func() {
            cout << "Base2 func" << endl;
        }
};

class Derived : public Base, public Base2 {
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

        void do_something() override {
            cout << getI() << " does something in derived class" << endl;
        }
};

int main() {
    Base b("Base", 1);
    Derived d("Derived", 2, "Derived");

    b.do_something();
    d.do_something();

    cout << endl;

    Base *b_ptr = new Derived("Derived", 2, "Derived");
    b_ptr->do_something();

    cout << endl;

    Derived d2("Derived", 2, "Derived");
    d2.Base2::func();

    return 0;
}
