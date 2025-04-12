#include <iostream>

using namespace std;

template <typename T, typename... Args>
auto sumAll(T first, Args... args) {
    if constexpr (sizeof...(args) == 0) {
        return first;
    } else {
        return first + sumAll(args...);
    }
}

int main() {
    cout << sumAll(1, 2, 3, 4, 5) << endl; // Output: 15
    cout << sumAll(1.5, 2.5, 3.5) << endl; // Output: 7.5
    cout << sumAll(1, 2.5, 3) << endl;     // Output: 6.5
    return 0;
}