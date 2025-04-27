#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Employee {
    public:
        int id;
        string name;
        string department;
        double salary;

        Employee(int id, string n, string d, double s) : id(id), name(n), department(d), salary(s) {}
        // Default constructor
        Employee() : id(0), name(""), department(""), salary(0.0) {}
};

class EmployeeManager {
    private:
        map<int, Employee> employees; // Map to store employees with ID as key

    public:
        void addEmployee(int id, string name, string department, double salary) {
            employees[id] = Employee(id, name, department, salary);
        }

        void removeEmployee(int id) {
            if (employees.find(id) != employees.end()) {
                employees.erase(id);
            } else {
                cout << "Employee with ID " << id << " not found." << endl;
            }
        }

        // Display all employee records
        void displayEmployees(function<void(const Employee&)> displayFunc = nullptr) const {
            for (const auto& [id, employee] : employees) {
                if (displayFunc) {
                    displayFunc(employee);
                } else {
                    cout << "ID: " << employee.id
                            << ", Name: " << employee.name
                            << ", Department: " << employee.department
                            << ", Salary: " << employee.salary << '\n';
                }
            }
        }

        // Sort employees based on a custom comparator
        void sortEmployees(function<bool(const Employee&, const Employee&)> comparator) const {
            vector<Employee> employeeList;
            for (const auto& [id, employee] : employees) {
                employeeList.push_back(employee);
            }

            sort(employeeList.begin(), employeeList.end(), comparator);

            for (const auto& employee : employeeList) {
                cout << "ID: " << employee.id
                        << ", Name: " << employee.name
                        << ", Department: " << employee.department
                        << ", Salary: " << employee.salary << '\n';
            }
        }

        // Find employees with salaries above a certain threshold
        void findHighSalaryEmployees(double threshold) const {
            cout << "Employees with salary above " << threshold << ":\n";
            for (const auto& [id, employee] : employees) {
                if (employee.salary > threshold) {
                    cout << "ID: " << employee.id
                            << ", Name: " << employee.name
                            << ", Department: " << employee.department
                            << ", Salary: " << employee.salary << '\n';
                }
            }
        }

        // Calculate the average salary of all employees
        double calculateAverageSalary() const {
            if (employees.empty()) return 0.0;

            double totalSalary = accumulate(employees.begin(), employees.end(), 0.0,
                                                [](double sum, const pair<int, Employee>& pair) {
                                                    return sum + pair.second.salary;
                                                });
            return totalSalary / employees.size();
        }
};

int main() {
    EmployeeManager manager;

    // Adding employees
    manager.addEmployee(1, "A", "HR", 50000);
    manager.addEmployee(2, "B", "Engineering", 70000);
    manager.addEmployee(3, "C", "Marketing", 60000);
    manager.addEmployee(4, "D", "Engineering", 80000);

    // Display all employees
    cout << "All Employees:\n";
    manager.displayEmployees();

    // Delete an employee
    manager.removeEmployee(2); // Remove Bob

    // Display all employees after deletion
    cout << "\nEmployees after deletion:\n";
    manager.displayEmployees();

    // Sort employees by salary (descending) using a lambda
    cout << "\nEmployees sorted by salary (descending):\n";
    manager.sortEmployees([](const Employee& e1, const Employee& e2) {
        return e1.salary > e2.salary;
    });

    // Find employees with salary above 60000
    cout << "\nEmployees with salary above 60000:\n";
    manager.findHighSalaryEmployees(60000);

    // Calculate and display the average salary
    double averageSalary = manager.calculateAverageSalary();
    cout << "\nAverage Salary: " << averageSalary << '\n';

    // Custom display using a function pointer
    cout << "\nCustom Display (Name and Salary only):\n";
    manager.displayEmployees([](const Employee& e) {
        cout << "Name: " << e.name << ", Salary: " << e.salary << '\n';
    });

    return 0;
}