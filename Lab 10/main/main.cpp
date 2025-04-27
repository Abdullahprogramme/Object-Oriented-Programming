#include <iostream>
#include <vector>
#include <functional>
#include <random>   
#include "../headers/StopWatch.hpp"
#include "../headers/insertion_sort.hpp"
#include "../headers/selection_sort.hpp"
#include "../headers/shell_sort.hpp"
#include "../headers/Binary_tree.hpp"

using namespace std;

// Class to evaluate performance
class PerformanceTester {
private:
    int size;
    int runs;
    mt19937 rng;  // Mersenne Twister random engine
    uniform_int_distribution<int> dist;  // Distribution for numbers

    // Generate random data
    vector<int> generate_random_data() {
        vector<int> data(size);
        for (int& x : data) {
            x = dist(rng);  // Use modern random
        }
        return data;
    }

public:
    PerformanceTester(int array_size, int runs_per_sort)
        : size(array_size), runs(runs_per_sort),
          rng(random_device{}()),  // Proper seeding
          dist(0, 9999)                  // Numbers between 0 and 9999
    {}

    // Evaluate a functor-based sorting algorithm
    template <typename SortFunction>
    void evaluate_functor(SortFunction& sorter, const string& name) {
        double total_time = 0.0;
        cout << "\nTesting: " << name << endl;

        for (size_t i = 0; i < static_cast<size_t>(runs); ++i) {
            vector<int> data = generate_random_data();
            Stopwatch sw;
            sw.start();
            sorter(data);
            sw.stop();
            total_time += sw.get_elapsed_time_milliseconds();
            sw.reset();
        }

        cout << "Average time over " << runs << " runs: "
             << (total_time / runs) << " ms" << endl;
    }

    // Evaluate a function pointer / lambda-based sorting algorithm
    void evaluate_function(const function<void(vector<int>&)>& sort_function, const string& name) {
        double total_time = 0.0;
        cout << "\nTesting: " << name << endl;

        for (size_t i = 0; i < static_cast<size_t>(runs); ++i) {
            vector<int> data = generate_random_data();
            Stopwatch sw;
            sw.start();
            sort_function(data);
            sw.stop();
            total_time += sw.get_elapsed_time_milliseconds();
            sw.reset();
        }

        cout << "Average time over " << runs << " runs: " << (total_time / runs) << " ms" << endl;
    }
};

int main() {
    const int array_size = 100000;
    const int runs_per_sort = 5;

    PerformanceTester tester(array_size, runs_per_sort);

    // Create sorting objects
    insertion_sort<int> insertion;
    selection_sort<int> selection;
    BinaryTree<int> binary_tree;

    // Evaluate each sort
    tester.evaluate_functor(insertion, "Insertion Sort");
    tester.evaluate_functor(selection, "Selection Sort");
    tester.evaluate_function(shell_sort<int>, "Shell Sort");
    tester.evaluate_functor(binary_tree, "Binary Tree Sort");

    return 0;
}
