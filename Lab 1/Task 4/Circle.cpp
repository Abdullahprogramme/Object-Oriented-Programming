#include <cmath>
#include "Circle.hpp"

void Circle::setRadius(float r) {
    radius = r;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::circumference() const {
    return 2 * M_PI * radius;
}