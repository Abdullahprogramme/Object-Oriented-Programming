#ifndef Fraction_hpp
#define Fraction_hpp

#include <iostream>

class Fraction {
    private:
        int numerator, denominator;

    public:
        Fraction(); // Default constructor
        Fraction(int numerator, int denominator); // Parameterized constructor

        friend Fraction& addFraction(const Fraction& f1, const Fraction& f2);
        friend Fraction& multiplyFraction(const Fraction& f1, const Fraction& f2);  

        void display() const;
};

#endif /* Fraction_hpp */