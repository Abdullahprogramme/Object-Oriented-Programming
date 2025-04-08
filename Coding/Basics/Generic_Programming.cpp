// Generic Programming

#include <iostream>
#include <string>
using namespace std;

// Templates: 
// - Function templates
template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// - Function template with two template parameters
template <typename T1, typename T2>
void Display(T1 a, T2 b) {
    // specialization for int and double types
    if constexpr (is_same<T1, int>::value && is_same<T2, double>::value) {
        cout << "Integer: " << a << ", Double: " << b << endl;
    } else if constexpr (is_same<T1, double>::value && is_same<T2, int>::value) {
        cout << "Double: " << a << ", Integer: " << b << endl;
    } else {
        cout << "a: " << a << ", b: " << b << endl;
    }
}

// - Class template
template <typename T>
class Pair {
    private:
        T first;
        T second;

    public:
        Pair(T first, T second) : first(first), second(second) {}
        void Display() {
            cout << "First: " << first << ", Second: " << second << endl;
        }
};

// - Function pointer
void Run_1(void (*swapFunc)(int &, int &)) {
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapFunc(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    double x = 1.5, y = 2.5;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    Swap(x, y); // Directly call the template function for non-int types
    cout << "After swap: x = " << x << ", y = " << y << endl;

    string str1 = "Hello", str2 = "World";
    cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << endl;
    Swap(str1, str2); // Directly call the template function for non-int types
    cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << endl;
}

// - Class pointer
template <typename T>
void Run_2(Pair<T> *pair) {
    pair->Display();
}

int main() {
    Run_1(Swap); // Pass the function pointer for int type

    Pair<int> intPair(1, 2);
    Pair<double> doublePair(1.1, 2.2);
    Pair<string> stringPair("Hello", "World");
    Run_2(&intPair); // Pass the class pointer for int type
    Run_2(&doublePair); // Pass the class pointer for double type
    Run_2(&stringPair); // Pass the class pointer for string type

    // - Lambda function
    auto lambdaSwap = [](int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    };

    int a = 5, b = 10;  
    cout << "Before lambda swap: a = " << a << ", b = " << b << endl;
    lambdaSwap(a, b);
    cout << "After lambda swap: a = " << a << ", b = " << b << endl;

    int factor = 2;
    auto lambdaMultWithCapture = [factor](int a) {
        return a * factor;
    };

    int num = 5;
    cout << "Multiplying " << num << " by factor " << factor << ": " << lambdaMultWithCapture(num) << endl;

    return 0;
}