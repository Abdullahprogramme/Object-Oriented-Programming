#include "../headers/DynamicArray.hpp"
#include <iostream>

using namespace std;

int main() {
    // Create an object and fill it with values
    DynamicArray arr1(5);
    for (int i = 0; i < 5; ++i) {
        arr1.set(i, i + 1);
    }

    // Copy it using the default copy constructor (shallow copy)
    DynamicArray arr2 = arr1;

    // Observe the effect on the copied object
    cout << "Array 1: " << endl;
    arr1.display();
    cout << "Array 2: " << endl;
    arr2.display();

    // Modify the original object
    arr1.set(0, 10);
    
    cout << "Shallow Copy:" << endl;
    cout << "arr1[0]: " << arr1.get(0) << endl;
    cout << "arr2[0]: " << arr2.get(0) << endl;

    cout << "Array 1: " << endl;
    arr1.display();
    cout << "Array 2: " << endl;
    arr2.display();
    

    cout << "----------------" << endl;

    // Implement a deep copy constructor and repeat step 3
    DynamicArray arr3(arr1);

    // Confirm that the copied object is independent
    cout << "Array 1: " << endl;
    arr1.display();
    cout << "Array 3: " << endl;
    arr3.display();
    // Modify the original object
    arr1.set(0, 20);
    
    cout << "Deep Copy:" << endl;
    cout << "arr1[0]: " << arr1.get(0) << endl;
    cout << "arr3[0]: " << arr3.get(0) << endl;

    return 0;
}