// Code example to use unordered_map in C++


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    // Syntax: unordered_map<key_type, value_type> name;
    std::unordered_map<std::string, int> wordCount = {
        {"apple", 0},
    };

    // Adding a new key-value pair
    // Syntax: unordered_map name[key] = value;
    wordCount["banana"] = 0;

    std::vector<std::string> words = {"apple", "banana", "orange", "apple", "banana", "apple"};
    for (const auto& word : words) {
        // Increment the count for each word
        wordCount[word]++; // same as wordCount[word] = wordCount[word] + 1;
    }

    // Some common methods on unordered_map
    // 1. Check if a key exists
    std::cout << "Contains 'apple': " << (wordCount.find("apple") != wordCount.end()) << "\n";
    std::cout << "Contains 'grape': " << (wordCount.find("grape") != wordCount.end()) << "\n";

    // 2. Get the size of the map
    std::cout << "Size of wordCount: " << wordCount.size() << "\n";

    // 3. Accessing elements using at() method
    wordCount.at("banana") = 2; // Update the count for "banana"


    // Using lambda and for_each to print frequent words
    // Syntax: std::for_each(container.begin(), container.end(), lambda_function);
    std::for_each(wordCount.begin(), wordCount.end(), [](const auto& pair) {
        if (pair.second > 1) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    });

    // clear the map
    wordCount.clear();

    std::unordered_map<std::string, int> scores = {{"Ali", 95}, {"Sara", 87}, {"Zain", 95}};

    // Using a function pointer to print scores
    void (*printScore)(const std::pair<std::string, int>&) = [](const std::pair<std::string, int>& entry) {
        if (entry.second == 95) {
            std::cout << entry.first << " ";
        }
    };
    // Syntax: std::for_each(container.begin(), container.end(), function_pointer);
    std::for_each(scores.begin(), scores.end(), printScore);

    /* What will be the output?
        A. Zain Sara
        B. Ali Zain
        C. Ali Sara Zain
        D. Order is not guaranteed
    */

}