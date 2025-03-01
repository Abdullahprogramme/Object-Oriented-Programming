#include <iostream>

using namespace std;

// Abstract class Marks
class Marks {
public:
    virtual ~Marks() {}
    virtual double getPercentage() const = 0;
};

// Class A for student A
class A : public Marks {
private:
    double subject1;
    double subject2;
    double subject3;

public:
    A(double s1, double s2, double s3) : subject1(s1), subject2(s2), subject3(s3) {}

    double getPercentage() const override {
        return (subject1 + subject2 + subject3) / 3.0;
    }
};

// Class B for student B
class B : public Marks {
private:
    double subject1;
    double subject2;
    double subject3;
    double subject4;

public:
    B(double s1, double s2, double s3, double s4) : subject1(s1), subject2(s2), subject3(s3), subject4(s4) {}

    double getPercentage() const override {
        return (subject1 + subject2 + subject3 + subject4) / 4.0;
    }
};

int main() {
    A studentA(85, 90, 88);
    B studentB(75, 80, 78, 82);

    cout << "Percentage of marks for student A: " << studentA.getPercentage() << "%" << endl;
    cout << "Percentage of marks for student B: " << studentB.getPercentage() << "%" << endl;

    return 0;
}