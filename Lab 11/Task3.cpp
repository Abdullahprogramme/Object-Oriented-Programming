#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class RadixStringSorter {
    public:

        void counting_sort(vector<string>& arr, int pos, bool ascending = true) {
            int n = arr.size();
            vector<int> count(256, 0);
            vector<string> sorted_arr(n);

            // Count occurrences of each character at the given position
            for (int i = 0; i < n; ++i) {
                int char_index = (pos < arr[i].length()) ? (int)arr[i][pos] : 0;
                count[char_index]++;
            }

            // Calculate cumulative counts
            if (ascending) {
                for (int i = 1; i < 256; ++i) {
                    count[i] += count[i - 1];
                }
            } else {
                for (int i = 254; i >= 0; --i) {
                    count[i] += count[i + 1];
                }
            }

            // Build the sorted array
            for (int i = n - 1; i >= 0; --i) {
                int char_index = (pos < arr[i].length()) ? arr[i][pos] : 0;
                sorted_arr[count[char_index] - 1] = arr[i];
                count[char_index]--;
            }

            arr = sorted_arr;
        }

        // Radix ascending sort function
        void sort_ascending(vector<string>& arr) {
            int max_length = 0;
            for (const string& str : arr) {
                max_length = max(max_length, (int)str.length());
            }

            for (int pos = max_length - 1; pos >= 0; --pos) {
                counting_sort(arr, pos, true);
            }
        }

        // Radix descending sort function
        void sort_descending(vector<string>& arr) {
            int max_length = 0;
            for (const string& str : arr) {
                max_length = max(max_length, (int)str.length());
            }

            for (int pos = max_length - 1; pos >= 0; --pos) {
                counting_sort(arr, pos, false);
            }
        }

        // Sort by a specific character position
        void sort_by_position(vector<string>& arr, int char_pos) {
            counting_sort(arr, char_pos, true);
        }
};

// Helper function to print a vector of strings
void print_strings(const vector<string>& arr) {
    for (const string& str : arr) {
        cout << str << endl;
    }
}

int main() {
    vector<string> strings = {"apple", "banana", "grape", "kiwi", "orange", "pear"};

    RadixStringSorter sorter;

    // Sort in ascending order
    cout << "Ascending Order:" << endl;
    sorter.sort_ascending(strings);
    print_strings(strings);

    // Sort in descending order
    cout << "\nDescending Order:" << endl;
    sorter.sort_descending(strings);
    print_strings(strings);

    // Sort by a specific character position (e.g., 2nd character)
    cout << "\nSort by 2nd Character:" << endl;
    sorter.sort_by_position(strings, 1); // 1-based index
    print_strings(strings);

    return 0;
}