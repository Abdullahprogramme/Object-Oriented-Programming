#include <iostream>
#include <list>
#include <string>
#include <functional>

using namespace std;

// Student class
class Student {
    public:
        string name;
        double gpa;

        Student(string name, double gpa) : name(name), gpa(gpa) {}
};

// Comparator for sorting by name (alphabetical order)
class CompareByName {
    public:
        bool operator()(const Student& a, const Student& b) {
            return a.name < b.name;
        }
};

// Comparator for sorting by GPA (descending order)
class CompareByGPA {
    public:
        bool operator()(const Student& a, const Student& b) {
            return a.gpa > b.gpa;
        }
};

// GenericSorter class definition
template <typename T>
class GenericSorter {
    public:
        void insertionSort(list<T>& lst, function<bool(const T&, const T&)> cmp) {
            for (auto it = next(lst.begin()); it != lst.end(); ++it) {
                T key = *it;
                auto j = prev(it);

                
                while (j != lst.begin() && cmp(key, *j)) {
                    auto next_j = next(j);
                    *next_j = *j;
                    --j;
                }

                if (j == lst.begin() && cmp(key, *j)) {
                    auto next_j = next(j);
                    *next_j = *j;
                    *j = key;
                } else {
                    *next(j) = key;
                }
            }
        }
};

// Helper function to print a list of students
void printStudents(const list<Student>& students) {
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", GPA: " << student.gpa << endl;
    }
}

int main() {
    // Create a list of students
    list<Student> students = {
        {"Abdullah", 3.5},
        {"Zainab", 3.8},
        {"Ali", 3.2},
        {"Fatima", 3.9},
        {"Omar", 3.6}
    };

    // Create a GenericSorter instance
    GenericSorter<Student> sorter;

    // Sort by name
    cout << "Sorting by Name (Alphabetical):" << endl;
    sorter.insertionSort(students, CompareByName());
    printStudents(students);

    // Sort by GPA
    cout << "\nSorting by GPA (Descending):" << endl;
    sorter.insertionSort(students, CompareByGPA());
    printStudents(students);

    return 0;
}