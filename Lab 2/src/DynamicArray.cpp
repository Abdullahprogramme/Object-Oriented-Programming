#include "../headers/DynamicArray.hpp"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(int size) {
    this->size = size;
    arr = new int[size];
} // constructor with size

DynamicArray::~DynamicArray() {
    delete[] arr;
} // destructor for freeing memory

DynamicArray::DynamicArray(const DynamicArray &obj) {
    size = obj.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = obj.arr[i];
    }
} // Deep copy constructor

// DynamicArray::DynamicArray(const DynamicArray &obj) = default; // Shalllow copy constructor

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
} // copy assignment operator

void DynamicArray::set(int index, int value) {
    arr[index] = value;
} // set value at index

int DynamicArray::get(int index) const {
    return arr[index];
} // get value at index

void DynamicArray::display() const {
    for (int i = 0; i < size; i++) {
        cout << get(i) << " ";
    }
    cout << endl;
} // display the array
