#include <iostream>
#include <string>

using namespace std;

// Abstract class of employee
class Employee {
    protected:
        string name;
        double salary;

    public:
        Employee(string &name, double salary) {
            this->name = name;
            this->salary = salary;
        }

        virtual ~Employee() {}

        string getName() const { return name; }
        double getSalary() const { return salary; }

        virtual double calculateBonus() const = 0;
};

// Abstract class IPromotable
class IPromotable {
    public:
        virtual ~IPromotable() {}
        virtual void promote(double newSalary) = 0;
};


// Derived class of Manager
class Manager : public Employee, public IPromotable {
    public:
        Manager(string name, double salary) : Employee(name, salary) {}

        double calculateBonus() const override {
            return  salary * 0.1;
        }

        void promote(double newSalary) override {
            salary = newSalary;
        }
};

// Derived class of Programmer
class Programmer : public Employee , public IPromotable {
    public:
        Programmer(string name, double salary) : Employee(name, salary) {}

        double calculateBonus() const override {
            return  salary * 0.05;
        }

        void promote(double newSalary) override {
            salary = newSalary;
        }
};

int main() {
    Manager manager("Alice", 80000);
    Programmer programmer("Bob", 60000);

    cout << "Manager " << manager.getName() << " has a salary of " << manager.getSalary() << " and a bonus of " << manager.calculateBonus() << endl;
    cout << "Programmer " << programmer.getName() << " has a salary of " << programmer.getSalary() << " and a bonus of " << programmer.calculateBonus() << endl;

    manager.promote(90000);
    programmer.promote(70000);

    cout << "After promotion, Manager " << manager.getName() << " has a salary of " << manager.getSalary() << endl;
    cout << "After promotion, Programmer " << programmer.getName() << " has a salary of " << programmer.getSalary() << endl;

    return 0;
}