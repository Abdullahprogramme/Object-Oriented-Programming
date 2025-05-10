#include "../headers/Algorithm.hpp"
#include "../headers/AlgorithmAnalyzer.hpp"
#include "../headers/BenchmarkResult.hpp"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        for (size_t j = 0; j < arr.size() - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
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

void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortWrapper(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == target)
            return i;
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void linearSearchWrapper(vector<int>& data) {
    int target = data[data.size() / 2]; // Searching for the middle element
    int result = linearSearch(data, target);
    if (result != -1)
        cout << "Linear Search: Element found at index " << result << endl;
    else
        cout << "Linear Search: Element not found" << endl;
}

void binarySearchWrapper(vector<int>& data) {
    int target = data[data.size() / 2]; // Searching for the middle element
    int result = binarySearch(data, target);
    if (result != -1)
        cout << "Binary Search: Element found at index " << result << endl;
    else
        cout << "Binary Search: Element not found" << endl;
}

int main() {
    AlgorithmAnalyzer<int> analyzer;

    analyzer.registerAlgorithm(Algorithm<int>("A1", "Bubble Sort", "Sorting", "O(n^2)", "O(1)", bubbleSort));
    analyzer.registerAlgorithm(Algorithm<int>("A2", "Insertion Sort", "Sorting", "O(n^2)", "O(1)", insertionSort));
    analyzer.registerAlgorithm(Algorithm<int>("A3", "Selection Sort", "Sorting", "O(n^2)", "O(1)", selectionSort));
    analyzer.registerAlgorithm(Algorithm<int>("A4", "Quick Sort", "Sorting", "O(n log n)", "O(log n)", quickSortWrapper));
    analyzer.registerAlgorithm(Algorithm<int>("A5", "Merge Sort", "Sorting", "O(n log n)", "O(n)", mergeSortWrapper));
    analyzer.registerAlgorithm(Algorithm<int>("A6", "Linear Search", "Searching", "O(n)", "O(1)", linearSearchWrapper));
    analyzer.registerAlgorithm(Algorithm<int>("A7", "Binary Search", "Searching", "O(log n)", "O(1)", binarySearchWrapper));

    analyzer.benchmarkAlgorithm("A1", 1000);
    analyzer.benchmarkAlgorithm("A2", 1000);
    analyzer.benchmarkAlgorithm("A3", 1000);
    analyzer.benchmarkAlgorithm("A4", 1000);
    analyzer.benchmarkAlgorithm("A5", 1000);
    analyzer.benchmarkAlgorithm("A6", 1000);
    analyzer.benchmarkAlgorithm("A7", 1000);
    
    analyzer.compareAlgorithms({"A1", "A2", "A3"}, 1000);

    analyzer.compareAlgorithms({"A1", "A2"}, 2000);

    analyzer.displayResults();

    return 0;
}
