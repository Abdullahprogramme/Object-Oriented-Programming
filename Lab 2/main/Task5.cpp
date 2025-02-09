#include "../headers/Car.hpp"
#include "../headers/MechanicShop.hpp"
#include <iostream>

using namespace std;

int main() {
    // Create cars
    Car car1("Toyota", "Camry", 2010, 3);
    car1.setRepairCost(0, 200);
    car1.setRepairCost(1, 150);
    car1.setRepairCost(2, 300);

    Car car2("Honda", "Civic", 2015, 2);
    car2.setRepairCost(0, 100);
    car2.setRepairCost(1, 250);

    // Display car details
    cout << car1;
    cout << car2;

    // Calculate total repair cost
    cout << "Total repair cost for car1: " << calculateTotalRepairCost(car1) << "\n";
    cout << "Total repair cost for car2: " << calculateTotalRepairCost(car2) << "\n";

    // Combine repair costs of two cars
    Car car3 = car1 + car2;
    cout << "Combined car repair costs:\n" << car3;

    // Create a mechanic shop and add cars
    MechanicShop shop(2);
    shop.addCar(car1, 0);
    shop.addCar(car2, 1);

    // Display cars in the shop
    cout << "Cars in the mechanic shop:\n";
    cout << shop.getCar(0);
    cout << shop.getCar(1);

    // Copy constructor
    MechanicShop shop2(shop);
    cout << "Cars in the copied mechanic shop:\n";
    cout << shop2.getCar(0);
    cout << shop2.getCar(1);

    return 0;
}