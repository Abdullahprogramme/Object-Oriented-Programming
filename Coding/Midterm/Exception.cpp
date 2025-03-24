#include <iostream>
#include <exception>   
using namespace std;

class MyException : public exception {
    public:
        virtual const char* what() const noexcept {
            return "Something bad happened!";
        }
};

class Test {
    public:
        void goesWrong(int i) {
            if (i < 0) {
                throw MyException();
            } else if (i == 0) {
                throw "Something else went wrong!";
            } else if (i == 1) {
                throw 8;
            } else {
                throw runtime_error("Unknown error");
            }
        }
};

int main() {
    Test test;
    
    try {
        try {
            test.goesWrong(-1);
        } catch(MyException &e) {
            cout << e.what() << endl;
            throw; // Rethrow the exception
        } catch(const char* e) {
            cout << e << endl;
            throw; // Rethrow the exception
        } catch(int e) {
            cout << "Error code: " << e << endl;
            throw; // Rethrow the exception
        } catch(const runtime_error &e) {
            cout << e.what() << endl;
            throw; // Rethrow the exception
        }
    } catch(...) {
        cout << "Default exception" << endl;
    }
    
    return 0;
}