#include <iostream>
#include <string>
#include "Student.hpp"

using namespace std;

int main() {
    // Creating an object of Student class
    Student student1;

    // Displaying the details of the student
    cout << "Student Details: " << endl;
    cout << "ID: " << student1.getId() << endl;
    cout << "CGPA: " << student1.getCGPA() << endl;
    cout << "Name: " << student1.getName() << endl;
    student1.showCourses();


    vector<string> courses = {"CSE101", "CSE102", "CSE103"};
    Student student2(1, 3.5, "Abdullah", courses);

    cout << "Student Details: " << endl;
    cout << "ID: " << student2.getId() << endl;
    cout << "CGPA: " << student2.getCGPA() << endl;
    cout << "Name: " << student2.getName() << endl;
    student2.showCourses();

    return 0;
}