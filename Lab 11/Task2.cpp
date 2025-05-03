#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> counting_sort(const vector<int>& arr) {
    int max_value = *max_element(arr.begin(), arr.end());
    vector<int> count(max_value + 1, 0);
    vector<int> sorted_arr(arr.size());

    // Count occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Calculate cumulative counts
    for (int i = 1; i <= max_value; ++i) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    for (int i = arr.size() - 1; i >= 0; --i) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return sorted_arr;
}

int check_diff(vector<int>& arr) {
    vector<int> sorted_arr = counting_sort(arr);
    int num_of_differences = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != sorted_arr[i]) {
            num_of_differences++;
        }
    }
    return num_of_differences;
}

int main() {
    vector<int> arr = {1, 1, 4, 2, 1, 3};
    int num_of_differences = check_diff(arr);
    cout << "Number of differences: " << num_of_differences << endl;
    return 0;
}