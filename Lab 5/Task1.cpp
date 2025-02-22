#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        string name;
        int age;

    public:
        // Constructor
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
};

class Student : public Person {
    private:
        int studentID;

    public:
        // Constructor  
        Student(string name, int age, int studentID) : Person(name, age) {
            this->studentID = studentID;
        }

        void display() {
            cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
        }
};

int main() {
        Student s1("Ammar", 20, 44810);
        Student s2("Afnan", 12, 15480);
        Student s3("Adam", 30, 48125);

        s1.display();
        s2.display();
        s3.display();
}