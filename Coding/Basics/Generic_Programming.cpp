// Generic Programming

#include <iostream>
#include <string>
#include <algorithm>
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

// - Specialization of class template
template <>
class Pair<string> {
    private:
        string first;
        string second;

    public:
        Pair(string first, string second) : first(first), second(second) {}
        void Display() {
            cout << "First: " << first << ", Second: " << second << endl;
        }
};

// - Variadic templates
template <typename T, typename... Args>
void Print(T first, Args... args) {
    cout << first << " ";
    if constexpr (sizeof...(args) > 0) {
        Print(args...); // Recursive call with unpacked arguments
    }
}

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

void multiply(int a, int b) {
    cout << "Multiplication: " << a * b << endl;
}

void add(int a, int b) {
    cout << "Addition: " << a + b << endl;
}

void process(int a, int b, void (*func)(int, int)) {
    cout << "Processing: " << a << ", " << b << endl;
    func(a, b); // Call the function pointer
}

// - Array of function pointers
void Run_3(void (*funcArr[])(int, int), int size) {
    for (int i = 0; i < size; ++i) {
        funcArr[i](5, 10); // Call each function pointer in the array
    }
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

    /*
    Capture Clause:
    [] - no capture
    [&] - capture all by reference
    [=] - capture all by value
    [x] - capture x by value
    [&x] - capture x by reference
    [=, &x] - capture all by value and x by reference
    [&, x] - capture all by reference and x by value
    [this] - capture this pointer
    */

    int factor = 2;
    auto lambdaMultWithCapture = [factor](int a) -> int {
        return a * factor;
    };

    // writing this in pointer function style
    // int (*lambdaMultWithCapture)(int) = [factor](int a) {
    //     return a * factor;
    // };

    int num = 5;
    cout << "Multiplying " << num << " by factor " << factor << ": " << lambdaMultWithCapture(num) << endl;

    Pair<string> stringPairLambda("Hello", "World");
    auto lambdaDisplay = [&stringPairLambda]() {
        stringPairLambda.Display();
    };
    lambdaDisplay(); // Call the lambda function to display the string pair

    // Variadic template example
    cout << "Variadic template output: ";
    Print(1, 2.5, "Hello", 'A', 3.14); // Call the variadic template function with different types
    cout << endl;

    void (*funcPtr)(int, int) = multiply;
    process(5, 10, funcPtr); // Call the function pointer with two integers

    // Calling Run_3 with an array of function pointers
    void (*funcArr[])(int, int) = {multiply, add};
    int size = sizeof(funcArr) / sizeof(funcArr[0]);
    Run_3(funcArr, size); // Call the array of function pointers
    
    int arr[5] = {4, 10, 2, 1, -1};
    qsort(arr, 5, sizeof(arr[0]), [](const void *a, const void *b) {
        return (*(int*)a - *(int*)b); // Compare two integers
    });
    cout << "Sorted array: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
