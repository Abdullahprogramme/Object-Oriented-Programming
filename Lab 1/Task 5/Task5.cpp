#include "Counter.hpp"
#include <iostream>
using namespace std;

int InstanceCounter::count = 0;

int main() {

    InstanceCounter a;
    cout << "Number of instances created: " << InstanceCounter::getCount() << endl;

    InstanceCounter b;
    cout << "Number of instances created: " << InstanceCounter::getCount() << endl;

    InstanceCounter c;
    cout << "Number of instances created: " << InstanceCounter::getCount() << endl;

    return 0;
}