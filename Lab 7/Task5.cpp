#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Password rules:
// 1. The password must be at least 8 characters long.
// 2. The password must contain at least one digit.
// If the password does not meet these requirements, the program should throw an exception

void checkPassword(const string& password) {
    if (password.length() < 8) {
        throw runtime_error("Password must be at least 8 characters long.");
    }
    else {
        bool digitFound = false;
        for (char c : password) {
            if (isdigit(c)) {
                digitFound = true;
                break;
            }
        }
        if (!digitFound) {
            throw runtime_error("Password must contain at least one digit.");
        }
    }

    cout << "Password is strong and valid." << endl;
}

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    try {
        checkPassword(password);
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}