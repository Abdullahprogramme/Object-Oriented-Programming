#include <iostream>
#include <string>

using namespace std;

class StringProcessor {

    public:

        // Reverses the input string
        string process(const string& input) {
            string reversed = "";
            for (int i = input.length() - 1; i >= 0; i--) {
                reversed += input[i];
            }
            return reversed;

            // reverse(input.begin(), input.end());
        }
        
        // Concatenates the two strings with a space.
        string process(const string& str1, const string& str2) {
            return str1 + " " + str2;
        }

        // Repeats the input string repeat times
        string process(const string& input, int repeat) {
            string repeated = "";
            for (int i = 0; i < repeat; i++) {
                repeated += input;
            }
            return repeated;

            // return string(repeat, input);
        }
};

int main() {
    StringProcessor processor;
    cout << processor.process("Hello") << endl;
    cout << processor.process("Hello", "World") << endl;
    cout << processor.process("Hello", 3) << endl;
    return 0;
}