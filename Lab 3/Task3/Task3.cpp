#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
        int x, y;

    public:
        // Constructor
        Point(int x, int y): x(x), y(y) {}


        // Overloaded operators: +, -, *, ==, =
        Point operator+(const Point& p) {
            return Point(x + p.x, y + p.y);
        }

        Point operator-(const Point& p) {
            return Point(x - p.x, y - p.y);
        }

        Point operator*(const int p) {
            return Point(x * p, y * p);
        }

        bool operator==(const Point& p) {
            return x == p.x && y == p.y;
        }

        Point& operator=(const Point& p) {
            x = p.x;
            y = p.y;
            return *this;
        }

        // for output
        friend ostream& operator<<(ostream& os, const Point& p) {
            os << "Point(" << p.x << ", " << p.y << ")";
            return os;
        }

        friend double calculateLength(const Point& p1) {
            return sqrt(pow(p1.x, 2) + pow(p1.y, 2));
        }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    Point p3 = p1 + p2;
    Point p4 = p1 - p2;
    Point p5 = p1 * 3;

    cout << "p1 + p2 = " << p3 << endl;
    cout << "p1 - p2 = " << p4 << endl;
    cout << "p1 * 3 = " << p5 << endl;

    cout << "Is p1 == p2? " << (p1 == p2 ? "Yes" : "No") << endl;
    cout << "Is p1 == p1? " << (p1 == p1 ? "Yes" : "No") << endl;

    cout << "Length of p1: " << calculateLength(p1) << endl;
    cout << "Length of p1: " << calculateLength(p2) << endl;

    cout << (p1 + p2) - p1 * 2 << endl;

    return 0;
}