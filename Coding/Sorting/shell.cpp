#include <iostream>
#include <array>
using namespace std;

/*
Time complexity:
    Worst case: O(n^2)
    Best case: O(n)
    Average case: O(n^2)
*/
void shell_iterative(array<int, 10> &arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    array<int, 10> arr = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    shell_iterative(arr);
    cout << "Sorted array (iterative): ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}