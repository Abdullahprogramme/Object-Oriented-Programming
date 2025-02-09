#include <iostream>
#include "Circle.hpp"

using namespace std;

int main() {
    Circle c;
    c.setRadius(5);
    cout << "Radius of the circle: " << c.getRadius() << endl;
    cout << "Circumference of the circle: " << c.circumference() << endl;
    return 0;
}