#ifndef MechanicShop_hpp
#define MechanicShop_hpp

#include <iostream>
#include <string>
#include "Car.hpp"

#include <ostream>
using namespace std;

class MechanicShop {
private:
    Car* cars;
    int numCars;

public:
    MechanicShop(int numCars);
    MechanicShop(const MechanicShop& other); // Deep copy constructor
    MechanicShop& operator=(const MechanicShop& other); // Deep copy assignment operator
    ~MechanicShop(); // Destructor

    void addCar(const Car& car, int index);
    Car getCar(int index) const;
};

#endif /* MechanicShop_hpp */
