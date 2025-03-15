#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
    protected:
        string make, model;
        int year;
        double mileage;
        vector<string> serviceHistory;

    public:
        Vehicle(string make, string model, int year, double mileage)
            : make(make), model(model), year(year), mileage(mileage) {}

        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;

        bool operator<(const Vehicle& other) const {
            return mileage < other.mileage;
        }

        void addService(const string& service) {
            serviceHistory.push_back(service);
        }

        virtual ~Vehicle() = default;

        friend ostream& operator<<(ostream& os, const Vehicle& vehicle) {
            os << "Make: " << vehicle.make << "\n";
            os << "Model: " << vehicle.model << "\n";
            os << "Year: " << vehicle.year << "\n";
            os << "Mileage: " << vehicle.mileage << "\n";
            for (const string& service : vehicle.serviceHistory) {
                os << "Service: " << service << "\n";
            }
            return os;
        }
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

        friend ostream& operator<<(ostream& os, const HybridVehicle& vehicle) {
            os << static_cast<const Vehicle&>(vehicle);
            os << "Battery Level: " << vehicle.batteryLevel << endl;
            os << "Fuel Level: " << vehicle.fuelLevel << endl;
            os << "Current Mode: " << (vehicle.mode == HybridVehicle::ELECTRIC ? "Electric" : "Gas") << endl;
            return os;
        }
};

int main() {
    HybridVehicle hybrid("H1", "M1", 2021, 1000, 50, 50);
    hybrid.startEngine();
    hybrid.stopEngine();

    hybrid.charge(10);
    hybrid.refuel(10);

    HybridVehicle hybrid2("H2", "M2", 2021, 1000, 50, 50);
    hybrid2.startEngine();

    hybrid2.toggleMode();
    hybrid2.startEngine();

    cout << hybrid << endl;
    cout << hybrid2 << endl;

    hybrid2.addService("Oil Change");
    hybrid2.addService("Tire Rotation");

    cout << hybrid2 << endl;

    cout << "Is hybrid less mileage than hybrid2? " << (hybrid < hybrid2 ? "Yes" : "No") << endl;
    
    // Uncommenting below line will cause a compilation error due to encapsulation:
    // cout << hybrid.make; // Error: 'make' is protected within this context

    return 0;
}
