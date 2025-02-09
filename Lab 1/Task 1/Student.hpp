#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    
    private:
        int id;
        float CGPA;
        string name;

    public:
        // Parameterized constructor declaration
        Student(int id, float CGPA, string name, vector<string> &courses);
        // Custom default constructor declaration
        Student();

        vector<string> courses;
        
        // Getters
        int getId();
        float getCGPA();
        string getName();
        void showCourses();

};

#endif /* Student_hpp */