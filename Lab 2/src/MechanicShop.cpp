#include "../headers/MechanicShop.hpp"
#include "../headers/Car.hpp"
#include <iostream>

using namespace std;

// Constructor
MechanicShop::MechanicShop(int numCars) : numCars(numCars) {
    cars = new Car[numCars];
}

// Deep copy constructor
MechanicShop::MechanicShop(const MechanicShop& other) : numCars(other.numCars) {
    cars = new Car[numCars];
    for (int i = 0; i < numCars; ++i) {
        cars[i] = other.cars[i];
    }
}

// Deep copy assignment operator
MechanicShop& MechanicShop::operator=(const MechanicShop& other) {
    if (this == &other) {
        return *this;
    }

    delete[] cars;

    numCars = other.numCars;
    cars = new Car[numCars];
    for (int i = 0; i < numCars; ++i) {
        cars[i] = other.cars[i];
    }

    return *this;
}

// Destructor
MechanicShop::~MechanicShop() {
    delete[] cars;
}

// Add car
void MechanicShop::addCar(const Car& car, int index) {
    if (index >= 0 && index < numCars) {
        cars[index] = car;
    }
}

// Get car
Car MechanicShop::getCar(int index) const {
    if (index >= 0 && index < numCars) {
        return cars[index];
    }
    return Car("", "", 0, 0); // Return an empty car if index is invalid
}
