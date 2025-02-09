#include "../headers/Matrix2x2.hpp"
#include <iostream>

using namespace std;

Matrix2x2::Matrix2x2() {
    a11 = 0;
    a12 = 0;
    a21 = 0;
    a22 = 0;
}

Matrix2x2::Matrix2x2(double a11, double a12, double a21, double a22) {
    this->a11 = a11;
    this->a12 = a12;
    this->a21 = a21;
    this->a22 = a22;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &m) const {
    return Matrix2x2(a11 + m.a11, a12 + m.a12, a21 + m.a21, a22 + m.a22);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &m) const {
    return Matrix2x2(a11 - m.a11, a12 - m.a12, a21 - m.a21, a22 - m.a22);
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &m) const {
    Matrix2x2 result;

    result.a11 = a11 * m.a11 + a12 * m.a21; // row 1, column 1
    result.a12 = a11 * m.a12 + a12 * m.a22; // row 1, column 2
    result.a21 = a21 * m.a11 + a22 * m.a21; // row 2, column 1
    result.a22 = a21 * m.a12 + a22 * m.a22; // row 2, column 2

    return result;
}

ostream& operator<<(ostream &out, const Matrix2x2 &m) {
    out << m.a11 << " " << m.a12 << endl;
    out << m.a21 << " " << m.a22 << endl;

    return out; 
}

ostream& Matrix2x2::operator<<(ostream &out) const {
    out << a11 << " " << a12 << endl;
    out << a21 << " " << a22 << endl;

    return out;
}

void Matrix2x2::display( string title, Matrix2x2& m) const {
    cout << title << endl;
    cout << m;
}