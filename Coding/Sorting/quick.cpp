#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Quick Sort Complexity Analysis
// Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the array is already sorted or reverse sorted)
// Space Complexity: O(log n) due to the recursion stack
// Note: The worst-case time complexity can be improved to O(n log n) by using a randomized pivot selection or the median-of-three method.

int main() {
    vector<int> arr = {1, 7, 3, 9, 5, 2, 8, 4, 6, 1213, 12, 54, -1, 3, -343};

    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}