#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        string make;
        string model;
        int year;
        double* repairCosts; // To demonstrate deep copy
        int numRepairs;

    public:
        Car(); // Default constructor
        Car(const string& make, const string& model, int year, int numRepairs);
        Car(const Car& other); // Deep copy constructor
        Car& operator=(const Car& other); // Deep copy assignment operator
        ~Car(); // Destructor

        void setRepairCost(int index, double cost);
        double getRepairCost(int index) const;
        int getNumRepairs() const;

        friend double calculateTotalRepairCost(const Car& car);
        friend ostream& operator<<(ostream& os, const Car& car);
        Car operator+(const Car& other) const;
};

#endif /* Car_hpp */