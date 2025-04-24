#include <iostream>
#include <array>
using namespace std;

/*
Time complexity:
    Worst case: O(n^2)
    Best case: O(n)
    Average case: O(n^2)
*/
void selection_iterative(array<int, 10> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

/*
Time complexity:
    Worst case: O(n^2)
    Best case: O(n)
    Average case: O(n^2)
*/
void selection_recursive(array<int, 10> &arr, int start) {
    if (start >= arr.size() - 1) {
        return;
    }
    int minIndex = start;
    for (int j = start + 1; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[start], arr[minIndex]);
    selection_recursive(arr, start + 1);
}

int main() {
    array<int, 10> arr = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    selection_iterative(arr);
    cout << "Sorted array (iterative): ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Resetting the array for recursive sort
    arr = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
    selection_recursive(arr, 0);
    cout << "Sorted array (recursive): ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}