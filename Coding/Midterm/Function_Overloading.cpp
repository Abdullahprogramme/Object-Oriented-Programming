#include <iostream>
using namespace std;

bool Compare(int a, int b) {
    return a > b;
}

bool Compare(double a, double b) {
    return a > b;
}

int main() {
    cout << Compare(1, 2) << endl;
    cout << Compare(1.1, 2.2) << endl;
    return 0;
}