#include <iostream>
using namespace std;

class A {
    public:
        virtual void test() {
            cout << "A::test()" << endl;
        }

        virtual ~A() {}

        virtual void test2() {
            cout << "A::test2()" << endl;
        }
};

class B : virtual public A {
    public:
        void test() override {
            cout << "B::test()" << endl;
        }

        void test2() override {
            cout << "B::test2()" << endl;
        }
};

class C : virtual public A {
    public:
        void test() override {
            cout << "C::test()" << endl;
        }

        void test2() override {
            cout << "C::test2()" << endl;
        }
};

class D : public B, public C {
    public:
        void test() override {
            cout << "D::test()" << endl;
        }

        void test2() override {
            cout << "D::test2()" << endl;
        }

        void callTest() {
            test();       // Calls D's test()
            B::test();    // Calls B's test()
            C::test();    // Calls C's test()
        }

        void callTest2(bool useB) {
            if (useB) {
                B::test2();  // Explicitly call B's test2()
            } else {
                C::test2();  // Explicitly call C's test2()
            }
        }
};

int main() {
    D d;
    d.test();
    d.callTest();
    
    cout << "Calling test2() from B:" << endl;
    d.callTest2(true); // Calls B::test2()

    cout << "Calling test2() from C:" << endl;
    d.callTest2(false); // Calls C::test2()

    return 0;
}
