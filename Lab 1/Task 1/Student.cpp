#include <iostream>
#include <string>
#include <vector>
#include "Student.hpp"

using namespace std;

// Parameterized constructor definition
Student::Student(int id, float CGPA, string name, vector<string> &courses) {
    this->id = id;
    this->CGPA = CGPA;
    this->name = name;
    this->courses = courses;
}

// Custom default constructor definition
Student::Student() {
    cout << "Enter ID: "; 
    cin >> this->id;

    cout << "Enter CGPA: ";
    cin >> this->CGPA;

    cout << "Enter Name: ";
    getline(cin >> ws, this->name);

    cout << "Enter number of courses: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string course;
        cout << "Enter course " << i + 1 << ": ";
        cin >> course;
        this->courses.push_back(course);
    }
}

// Getter function for ID
int Student::getId() {
    return this->id;
}

// Getter function for CGPA
float Student::getCGPA() {
    return this->CGPA;
}

// Getter function for Name
string Student::getName() {
    return this->name;
}

// Function to show courses
void Student::showCourses() {
    cout << "Courses: ";
    for (int i = 0; i < this->courses.size(); i++) {
        cout << this->courses[i] << " ";
    }
    cout << endl;
}
