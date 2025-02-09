#ifndef Circle_hpp
#define Circle_hpp

#include <cmath>

class Circle {
    private:
        float radius;

    public:
        void setRadius(float r);
        double getRadius() const;
        double circumference() const;
};

#endif /* Circle_hpp */