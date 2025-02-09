#include "../headers/Car.hpp"
#include <iostream>

using namespace std;

Car::Car() : make(""), model(""), year(0), numRepairs(0) {
    // default constructor implementation
}

// Constructor
Car::Car(const string& make, const string& model, int year, int numRepairs) : make(make), model(model), year(year), numRepairs(numRepairs) {
    repairCosts = new double[numRepairs];
}

// Deep copy constructor
Car::Car(const Car& other) : make(other.make), model(other.model), year(other.year), numRepairs(other.numRepairs) {
    repairCosts = new double[numRepairs];
    for (int i = 0; i < numRepairs; ++i) {
        repairCosts[i] = other.repairCosts[i];
    }
}

// Deep copy assignment operator
Car& Car::operator=(const Car& other) {
    if (this == &other) {
        return *this;
    }

    delete[] repairCosts;

    make = other.make;
    model = other.model;
    year = other.year;
    numRepairs = other.numRepairs;
    repairCosts = new double[numRepairs];
    for (int i = 0; i < numRepairs; ++i) {
        repairCosts[i] = other.repairCosts[i];
    }

    return *this;
}

// Destructor
Car::~Car() {
    delete[] repairCosts;
}

// Set repair cost
void Car::setRepairCost(int index, double cost) {
    if (index >= 0 && index < numRepairs) {
        repairCosts[index] = cost;
    }
}

// Get repair cost
double Car::getRepairCost(int index) const {
    if (index >= 0 && index < numRepairs) {
        return repairCosts[index];
    }
    return -1; // Invalid index
}

// Get number of repairs
int Car::getNumRepairs() const {
    return numRepairs;
}

// Friend function to calculate total repair cost
double calculateTotalRepairCost(const Car& car) {
    double total = 0;
    for (int i = 0; i < car.numRepairs; ++i) {
        total += car.repairCosts[i];
    }
    return total;
}

// Overload << operator to display car details and repair costs
ostream& operator<<(ostream& os, const Car& car) {
    os << "Car: " << car.make << " " << car.model << " (" << car.year << ")\n";
    os << "Repair Costs: ";
    for (int i = 0; i < car.numRepairs; ++i) {
        os << car.repairCosts[i] << " ";
    }
    os << "\n--------------\n";
    return os;
}

// Overload + operator to combine repair costs of two cars
Car Car::operator+(const Car& other) const {
    int newNumRepairs = numRepairs + other.numRepairs;
    Car newCar(make, model, year, newNumRepairs);
    for (int i = 0; i < numRepairs; ++i) {
        newCar.repairCosts[i] = repairCosts[i];
    }
    for (int i = 0; i < other.numRepairs; ++i) {
        newCar.repairCosts[numRepairs + i] = other.repairCosts[i];
    }
    return newCar;
}