#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

template <typename T>
class NumberStats {
    private:
        vector<T> numbers;
        T sum = 0;
        T min = numeric_limits<T>::max();
        T max = numeric_limits<T>::min();
        double average = 0.0;

    public:
        void addNumber(T number) {
            numbers.push_back(number);
            sum += number;
            if (number < min) {
                min = number;
            }
            if (number > max) {
                max = number;
            }
        }

        T getSum() const {
            return accumulate(numbers.begin(), numbers.end(), static_cast<T>(0));
        }

        T getMin() const {
            return min;
        }

        T getMax() const {
            return max;
        }

        double getAverage() const {
            return numbers.empty() ? 0.0 : static_cast<double>(getSum()) / numbers.size();
        }
};

int main() {
    NumberStats<int> intStats;
    intStats.addNumber(5);
    intStats.addNumber(10);
    intStats.addNumber(3);

    cout << "Sum: " << intStats.getSum() << endl;
    cout << "Min: " << intStats.getMin() << endl;
    cout << "Max: " << intStats.getMax() << endl;
    cout << "Average: " << intStats.getAverage() << endl;

    NumberStats<double> doubleStats;
    doubleStats.addNumber(5.5);
    doubleStats.addNumber(10.2);
    doubleStats.addNumber(3.8);

    cout << "Sum: " << doubleStats.getSum() << endl;
    cout << "Min: " << doubleStats.getMin() << endl;
    cout << "Max: " << doubleStats.getMax() << endl;
    cout << "Average: " << doubleStats.getAverage() << endl;

    return 0;
}