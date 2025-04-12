#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class GenericComplex {
    private:
        T real;
        T imag;

    public:
        // Constructor
        GenericComplex(T r = 0, T i = 0) : real(r), imag(i) {}

        // Overload the + operator
        GenericComplex operator+(const GenericComplex& other) const {
            return GenericComplex(real + other.real, imag + other.imag);
        }

        // Overload the - operator
        GenericComplex operator-(const GenericComplex& other) const {
            return GenericComplex(real - other.real, imag - other.imag);
        }

        // Overload the * operator
        GenericComplex operator*(const GenericComplex& other) const {
            return GenericComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        // Overload the / operator
        GenericComplex operator/(const GenericComplex& other) const {
            T denominator = other.real * other.real + other.imag * other.imag;
            if (denominator == 0) {
                throw runtime_error("Division by zero error in complex division.");
            }

            return GenericComplex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
        }

        // Print the complex number
        void print() const {
            cout << real;
            if (imag >= 0) {
                cout << " + " << imag << "i" << endl;
            } else {
                cout << " - " << -imag << "i" << endl;
            }
        }

};

template <>
class GenericComplex<int> {
    private:
        int real;
        int imag;

    public:
        // Constructor
        GenericComplex(int r = 0, int i = 0) : real(r), imag(i) {}

        // Overload the + operator
        GenericComplex operator+(const GenericComplex& other) const {
            return GenericComplex(real + other.real, imag + other.imag);
        }

        // Overload the - operator
        GenericComplex operator-(const GenericComplex& other) const {
            return GenericComplex(real - other.real, imag - other.imag);
        }

        // Overload the * operator
        GenericComplex operator*(const GenericComplex& other) const {
            return GenericComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        // Overload the / operator
        GenericComplex operator/(const GenericComplex& other) const {
            int denominator = other.real * other.real + other.imag * other.imag;
            if (denominator == 0) {
                throw runtime_error("Division by zero error in complex division.");
            }

            return GenericComplex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
        }

        // Print the complex number
        void print() const {
            cout << real;
            if (imag >= 0) {
                cout << " + " << imag << "i" << endl;
            } else {
                cout << " - " << -imag << "i" << endl;
            }
        }
};

template <>
class GenericComplex<float> {
    private:
        float real;
        float imag;

    public:
        // Constructor
        GenericComplex(float r = 0, float i = 0) : real(r), imag(i) {}

        // Overload the + operator
        GenericComplex operator+(const GenericComplex& other) const {
            return GenericComplex(real + other.real, imag + other.imag);
        }

        // Overload the - operator
        GenericComplex operator-(const GenericComplex& other) const {
            return GenericComplex(real - other.real, imag - other.imag);
        }

        // Overload the * operator
        GenericComplex operator*(const GenericComplex& other) const {
            return GenericComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        // Overload the / operator
        GenericComplex operator/(const GenericComplex& other) const {
            float denominator = other.real * other.real + other.imag * other.imag;
            if (denominator == 0) {
                throw runtime_error("Division by zero error in complex division.");
            }

            return GenericComplex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
        }

        // Print the complex number
        void print() const {
            cout << real;
            if (imag >= 0) {
                cout << " + " << imag << "i" << endl;
            } else {
                cout << " - " << -imag << "i" << endl;
            }
        }
};


int main () {
    cout << "Generic Complex Number Operations" << endl;
    GenericComplex<double> complex1(3.0, 4.0);
    GenericComplex<double> complex2(1.0, 2.0);
    
    GenericComplex<double> result = complex1 + complex2;
    cout << "Addition: ";
    result.print();

    result = complex1 - complex2;
    cout << "Subtraction: ";
    result.print();

    cout << "Integer Complex Number Operations" << endl;
    GenericComplex<int> intComplex1(3, 4);
    GenericComplex<int> intComplex2(1, 2);

    GenericComplex<int> intResult = intComplex1 + intComplex2;
    cout << "Addition: ";
    intResult.print();

    try {
        intResult = intComplex1 / intComplex2;
        cout << "Division: ";
        result.print();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "Float Complex Number Operations" << endl;
    GenericComplex<float> floatComplex1(3.0f, 4.0f);
    GenericComplex<float> floatComplex2(1.0f, 2.0f);

    GenericComplex<float> floatResult = floatComplex1 * floatComplex2;
    cout << "Multiplication: ";
    floatResult.print();

    return 0;
}