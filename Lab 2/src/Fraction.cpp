#include "../headers/Fraction.hpp"
#include <iostream>

using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction& addFraction(const Fraction& f1, const Fraction& f2) {
    Fraction* result = new Fraction();
    result->numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result->denominator = f1.denominator * f2.denominator;
    return *result;
}

Fraction& multiplyFraction(const Fraction& f1, const Fraction& f2) {
    Fraction* result = new Fraction();
    result->numerator = f1.numerator * f2.numerator;
    result->denominator = f1.denominator * f2.denominator;
    
    // Simplify the fraction
    int gcd = 1;
    for (int i = 1; i <= result->numerator && i <= result->denominator; i++) {
        if (result->numerator % i == 0 && result->denominator % i == 0) {
            gcd = i;
        }
    }

    result->numerator /= gcd;
    result->denominator /= gcd;

    return *result;
}

void Fraction::display() const {
    cout << this->numerator << "/" << this->denominator << endl;
}