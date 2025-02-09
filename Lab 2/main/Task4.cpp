#include "../headers/Matrix2x2.hpp"
#include <iostream>

using namespace std;

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    // display the matrices
    m1.display("Matrix 1", m1);
    m2.display("Matrix 2", m2);
    
    Matrix2x2 m3;

    m3 = m1 + m2;
    m3.display("Sum of Matrix 1 and Matrix 2", m3);

    m3 = m1 - m2;
    m3.display("Difference of Matrix 1 and Matrix 2", m3);

    m3 = m1 * m2;
    m3.display("Product of Matrix 1 and Matrix 2", m3);

    return 0;
}