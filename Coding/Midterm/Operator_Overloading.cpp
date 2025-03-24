#include <iostream>
using namespace std;

class Fraction {
    private:
        int num, den;

    public:
        Fraction(int num, int den) : num(num), den(den) {}

        bool operator>(const Fraction& other) const {
            return num * other.den > other.num * den;
        }

        friend ostream& operator<<(ostream& out, const Fraction& f) {
            out << f.num << "/" << f.den;
            return out;
        }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    cout << (f1 > f2) << endl;
    cout << f1 << endl;
    return 0;
}
