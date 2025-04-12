#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort the array in non-decreasing order
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    cout << "Array sorted in non-decreasing order: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to reverse the array
void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
    cout << "Array reversed: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to rotate the array
void rotateArray(vector<int>& arr) {
    rotate(arr.begin(), arr.begin() + 1, arr.end());
    cout << "Array rotated: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find the minimum element in the array
void findMinElement(vector<int>& arr) {
    auto minElement = min_element(arr.begin(), arr.end());
    cout << "Minimum element: " << *minElement << endl;
}

// Function to find the maximum element in the array
void findMaxElement(vector<int>& arr) {
    auto maxElement = max_element(arr.begin(), arr.end());
    cout << "Maximum element: " << *maxElement << endl;
}

// Function to count occurrences of a specific value in the array
void countOccurrences(vector<int>& arr) {
    int value;
    cout << "Enter the value to count occurrences: ";
    cin >> value;
    int countValue = count(arr.begin(), arr.end(), value);
    cout << "Occurrences of " << value << ": " << countValue << endl;
}

// Custom algorithm function that takes a function pointer
void custom_algorithm(vector<int>& arr, void (*operation)(vector<int>&)) {
    operation(arr);
}

int main() {
    vector<int> arr = {5, 3, 8, 6, 3, 2, 7};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Demonstrate the usage of function pointers
    cout << "\nChoose an operation to perform on the array:" << endl;
    cout << "1. Sort Array" << endl;
    cout << "2. Reverse Array" << endl;
    cout << "3. Rotate Array" << endl;
    cout << "4. Find Minimum Element" << endl;
    cout << "5. Find Maximum Element" << endl;
    cout << "6. Count Occurrences" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            custom_algorithm(arr, sortArray);
            break;
        case 2:
            custom_algorithm(arr, reverseArray);
            break;
        case 3:
            custom_algorithm(arr, rotateArray);
            break;
        case 4:
            custom_algorithm(arr, findMinElement);
            break;
        case 5:
            custom_algorithm(arr, findMaxElement);
            break;
        case 6:
            custom_algorithm(arr, countOccurrences);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}