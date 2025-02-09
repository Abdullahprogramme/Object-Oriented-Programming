#include "../headers/Fraction.hpp"
#include <iostream>

using namespace std;

int main() {
    int numerator1 = 1, denominator1 = 2;
    int numerator2 = 1, denominator2 = 3;

    Fraction f1 = Fraction(numerator1, denominator1);
    Fraction f2 = Fraction(numerator2, denominator2);

    Fraction result1 = addFraction(f1, f2);
    Fraction result2 = multiplyFraction(f1, f2);

    cout << "Addition: ";
    result1.display();

    cout << "Multiplication: ";
    result2.display();

    return 0;
}