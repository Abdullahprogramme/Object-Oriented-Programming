#include <iostream>
#include <algorithm>

using namespace std;

// Defining the function pointer type
typedef int (*ftype)(void* A, int n);

// Function to find the position based on the function pointer
int findpos(void* A, int n, ftype fp) {
    return fp(A, n);
}

#include <algorithm>

int findMinPos(void* A, int n) {
    int* arr = static_cast<int*>(A);
    return min_element(arr, arr + n) - arr;
}

int findMaxPos(void* A, int n) {
    int* arr = static_cast<int*>(A);
    return max_element(arr, arr + n) - arr;
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the position of the minimum element
    int minPos = findpos(arr, n, findMinPos);
    cout << "Position of the minimum element: " << minPos << endl;

    // Find the position of the maximum element
    int maxPos = findpos(arr, n, findMaxPos);
    cout << "Position of the maximum element: " << maxPos << endl;

    return 0;
}