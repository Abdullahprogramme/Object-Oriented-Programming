#ifndef Matrix2x2_hpp
#define Matrix2x2_hpp

#include <ostream>
using namespace std;

class Matrix2x2 {
    private:
        double a11, a12, a21, a22;

    public:
        Matrix2x2(); // default constructor
        Matrix2x2(double a11, double a12, double a21, double a22); // parameterized constructor

        // overloaded operators
        Matrix2x2 operator+(const Matrix2x2 &m) const;
        Matrix2x2 operator-(const Matrix2x2 &m) const;
        Matrix2x2 operator*(const Matrix2x2 &m) const;
        friend ostream& operator<<(ostream &out, const Matrix2x2 &m); // friend function variation
        ostream& operator<<(ostream &out) const; // member function variation

        void display(string title, Matrix2x2& m) const;
};

#endif // /* Matrix2x2_hpp */