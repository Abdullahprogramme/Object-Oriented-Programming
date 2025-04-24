#include <iostream>
#include <array>
using namespace std;

/*
Time complexity:
    Worst case: O(n^2)
    Best case: O(n)
    Average case: O(n^2)
*/
void insertion_iterative(array<int, 10> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
Time complexity:
    Worst case: O(n^2)
    Best case: O(n)
    Average case: O(n^2)
*/
void insertion_recursive(array<int, 10> &arr, int n) {
    if (n <= 1) {
        return;
    }
    insertion_recursive(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main() {
    array<int, 10> arr = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    insertion_iterative(arr);
    cout << "Sorted array (iterative): ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Resetting the array for recursive sort
    arr = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
    insertion_recursive(arr, arr.size());
    cout << "Sorted array (recursive): ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}