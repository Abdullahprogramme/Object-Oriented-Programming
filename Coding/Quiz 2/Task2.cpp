#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
    protected:
        string make, model;
        int year;
        double mileage;

    public:
        Vehicle(string make, string model, int year, double mileage)
            : make(make), model(model), year(year), mileage(mileage) {}

        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;

        bool operator<(const Vehicle& other) const {
            return mileage < other.mileage;
        }

        virtual ~Vehicle() = default;
};

class ElectricVehicle : virtual public Vehicle {
    protected:
        double batteryLevel;

    public:
        ElectricVehicle(string make, string model, int year, double mileage, double battery)
            : Vehicle(make, model, year, mileage), batteryLevel(battery) {}

        void charge(double amount) {
            batteryLevel = min(100.0, batteryLevel + amount);
        }

        void startEngine() override {
            cout << "Electric engine starting...\n";
        }

        void stopEngine() override {
            cout << "Electric engine stopping...\n";
        }
};

class GasVehicle : virtual public Vehicle {
    protected:
        double fuelLevel;

    public:
        GasVehicle(string make, string model, int year, double mileage, double fuel)
            : Vehicle(make, model, year, mileage), fuelLevel(fuel) {}

        void refuel(double amount) {
            fuelLevel = min(100.0, fuelLevel + amount);
        }

        void startEngine() override {
            cout << "Gas engine starting...\n";
        }

        void stopEngine() override {
            cout << "Gas engine stopping...\n";
        }
};

class HybridVehicle : public ElectricVehicle, public GasVehicle {
    private:
        enum Mode { ELECTRIC, GAS } mode;

    public:
        HybridVehicle(string make, string model, int year, double mileage, double battery, double fuel)
            : Vehicle(make, model, year, mileage), ElectricVehicle(make, model, year, mileage, battery),
            GasVehicle(make, model, year, mileage, fuel), mode(ELECTRIC) {}

        void toggleMode() {
            mode = (mode == ELECTRIC) ? GAS : ELECTRIC;
            cout << "Switched to " << (mode == ELECTRIC ? "Electric" : "Gas") << " mode.\n";
        }

        void startEngine() override {
            if (mode == ELECTRIC) ElectricVehicle::startEngine();
            else GasVehicle::startEngine();
        }

        void stopEngine() override {
            if (mode == ELECTRIC) ElectricVehicle::stopEngine();
            else GasVehicle::stopEngine();
        }
};

int main() {
    HybridVehicle hybrid("Toyota", "Prius", 2023, 15000, 80.0, 30.0);

    hybrid.startEngine();
    hybrid.toggleMode();
    hybrid.startEngine();
    
    return 0;
}
