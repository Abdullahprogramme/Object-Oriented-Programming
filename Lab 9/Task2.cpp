#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BalancedBraces {
    public:

        // Functor to check if braces are balanced in a string
        bool operator()(const string& str) const {
            // Using the algorithm library to check for balanced braces
            int balance = 0;
            for (char ch : str) {
                if (ch == '{' || ch == '(') {
                    balance++;
                } else if (ch == '}' || ch == ')') {
                    balance--;
                }
                if (balance < 0) {
                    return false; // More closing braces than opening braces
                }
            }
            return balance == 0; // All braces should be balanced
        }
};

int main() {
    // Example usage of the BalancedBraces functor
    vector<string> testStrings = {
        "{(a + b) * (c + d)}",
        "{(a + b) * (c + d)",
        "((a + b) * (c + d))}",
        "{a + b} * {c + d}",
        "{a + b) * (c + d}"
    };

    for_each(testStrings.begin(), testStrings.end(), [](const string& str) {
        BalancedBraces check;
        if (check(str)) {
            cout << str << " is balanced." << endl;
        } else {
            cout << str << " is not balanced." << endl;
        }
    });

    return 0;
}