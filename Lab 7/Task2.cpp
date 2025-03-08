#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void testException(int x) {
    if (x == 1) throw 10;
    else if (x == 2) throw 2.5;
    else if (x == 3) throw 'A';
    else throw string("Unknown Error");
}

int main() {
    //  Catching all these errors using the try catch blocks and output what was caught.
    try {
        testException(1);
    } catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }

    try {
        testException(2);
    } catch (double e) {
        cout << "Caught a double exception: " << e << endl;
    }

    try {
        testException(3);
    } catch (char e) {
        cout << "Caught a char exception: " << e << endl;
    }

    try {
        testException(4);
    } catch (string e) {
        cout << "Caught a string exception: " << e << endl;
    }

    return 0;
}