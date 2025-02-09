#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <iostream>

class DynamicArray {
    private:
        int *arr;
        int size;

    public:
        DynamicArray(int size); // constructor with size
        DynamicArray(const DynamicArray &obj); // Deep copy constructor
        DynamicArray& operator=(const DynamicArray& other); // copy assignment operator
        ~DynamicArray(); // destructor for freeing memory

        void set(int index, int value); // set value at index
        int get(int index) const; // get value at index

        void display() const; // display the array
};

#endif /* DynamicArray_hpp */