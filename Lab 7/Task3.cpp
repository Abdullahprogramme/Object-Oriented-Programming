#include <iostream>
#include <string>

using namespace std;

// Base class
class Employee {
    protected:
        string name;
        string code;

    public:
        Employee(string name, string code) : name(name), code(code) {}
};

// Derived class from Employee
class Consultant : virtual public Employee {
    protected:
        int yearsOfExperience;

    public:
        Consultant(string name, string code, int yearsOfExperience) : Employee(name, code), yearsOfExperience(yearsOfExperience) {}
};

// Derived class from Employee
class Manager : virtual public Employee {
    protected:
        int noOfTeams;

    public:
        Manager(string name, string code, int noOfTeams) : Employee(name, code), noOfTeams(noOfTeams) {}
};

// Final Derived class from Consultant and Manager
class ConsultantManager : public Consultant, public Manager {
    public:
        ConsultantManager(string name, string code, int yearsOfExperience, int noOfTeams)
            : Employee(name, code), Consultant(name, code, yearsOfExperience), Manager(name, code, noOfTeams) {}

        void Display() const {
            cout << "Name: " << name << endl;
            cout << "Code: " << code << endl;
            cout << "Years of Experience: " << yearsOfExperience << endl;
            cout << "Number of Teams: " << noOfTeams << endl;
        }
};

int main() {
    ConsultantManager obj("Ali", "S-123", 17, 5);
    obj.Display();
    return 0;
}