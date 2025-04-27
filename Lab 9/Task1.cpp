#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Structure to represent an element
struct Element {
    string name;
    string symbol;
    int atomicNumber;
};

// Functor to sort elements by atomic number (ascending) and name (alphabetical)
struct SortByAtomicNumberAndName {
    bool operator()(const Element& e1, const Element& e2) const {
        if (e1.atomicNumber == e2.atomicNumber) {
            return e1.name < e2.name; // Secondary: Alphabetical order of name
        }
        return e1.atomicNumber < e2.atomicNumber; // Primary: Atomic number
    }
};

// Functor to filter elements with names longer than 5 characters
struct NameLengthGreaterThanFive {
    bool operator()(const Element& e) const {
        return e.name.length() > 5;
    }
};

int main() {
    // Step 1: Initialize the elements vector
    vector<Element> elements = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Boron", "B", 5},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10}
    };

    // Step 2: Sort elements using the custom functor
    sort(elements.begin(), elements.end(), SortByAtomicNumberAndName());

    // Step 3: Count elements with names longer than 5 characters
    int longNameCount = count_if(elements.begin(), elements.end(), NameLengthGreaterThanFive());

    // Step 4: Transform element symbols to uppercase
    vector<string> uppercaseSymbols;
    transform(elements.begin(), elements.end(), back_inserter(uppercaseSymbols),
                   [](const Element& e) {
                       string upperSymbol = e.symbol;
                       transform(upperSymbol.begin(), upperSymbol.end(), upperSymbol.begin(), ::toupper);
                       return upperSymbol;
                   });

    // Output results
    cout << "Sorted Elements:\n";
    for (const auto& e : elements) {
        cout << "Name: " << e.name << ", Symbol: " << e.symbol << ", Atomic Number: " << e.atomicNumber << '\n';
    }

    cout << "\nNumber of elements with names longer than 5 characters: " << longNameCount << '\n';

    cout << "\nUppercase Symbols:\n";
    for (const auto& symbol : uppercaseSymbols) {
        cout << symbol << '\n';
    }

    return 0;
}