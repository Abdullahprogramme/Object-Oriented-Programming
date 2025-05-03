#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

class BucketSorter {
    private:
        vector<string> words; // Vector to hold the words to be sorted

        // Insertion sort function to sort individual buckets
        void insertionSort(vector<string>& bucket) {
            for (int i = 1; i < bucket.size(); ++i) {
                string key = bucket[i];
                int j = i - 1;
                while (j >= 0 && bucket[j] > key) {
                    bucket[j + 1] = bucket[j];
                    j--;
                }
                bucket[j + 1] = key;
            }
        }
        
        void bucketSort() {
            vector<string>& arr = this->words; // Reference to the words vector

            // Create 26 buckets
            vector<vector<string>> buckets(26);
        
            // Distribute the strings into buckets based on their first character
            for (const string& str : arr) {
                if (!str.empty()) {
                    char firstChar = str[0];
                    if (firstChar >= 'a' && firstChar <= 'z') {
                        buckets[firstChar - 'a'].push_back(str);
                    }
                }
            }
        
            // Sort each bucket and concatenate the results
            arr.clear();
            for (auto& bucket : buckets) {
                insertionSort(bucket);
                arr.insert(arr.end(), bucket.begin(), bucket.end());
            }
        }
        
    public:
        // Function to read a file and return its contents as a vector of strings
        BucketSorter(const string& filename) {
            ifstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Could not open file: " + filename);
            }

            vector<string> words;

            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                string word;
                while (iss >> word) {
                    // Remove punctuation or special characters from the word
                    word.erase(remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); }), word.end());

                    // Convert to lowercase for case-insensitive sorting
                    transform(word.begin(), word.end(), word.begin(), ::tolower);

                    words.push_back(word);
                }
            }
            file.close();
            this->words = words;
        }

        void saveToFile(const string& filename, const vector<string>& arr) {
            ofstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Could not open file: " + filename);
            }

            for (const string& str : arr) {
                file << str << " "; // Save each string followed by a space
            }
            file.close();
        }

        vector<string> operator()() {
            bucketSort(); // Sort the words using bucket sort
            return words; // Return the sorted words
        }

};

int main() {
    try {

        string filename;
        cout << "Enter the filename to sort: ";
        cin >> filename;

        // Read words from the input file
        BucketSorter sorter(filename);

        // Sort the words using bucket sort
        vector<string> words = sorter();

        string outputFilename;
        cout << "Enter the output filename: ";
        cin >> outputFilename;

        // Save the sorted words to the output file
        sorter.saveToFile(outputFilename, words);

        cout << "Sorting completed successfully. Check the output file: " << outputFilename << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
