#ifndef ExpensivePower_hpp
#define ExpensivePower_hpp

#include <string>
#include "Operation.hpp"

using namespace std;

template <typename T>
class ExpensivePower : public Operation<T> {
    private:
        int exponent;

    public:
        explicit ExpensivePower(int exp) : exponent(exp) {}

        T apply(T input) const override {
            cout << name() << " applied to " << input << endl;
            T result = static_cast<T>(1);
            for (int i = 0; i < exponent; ++i) {
                result *= input;
            }
            return result;
        }

        string name() const override {
            return "ExpensivePower(" + to_string(exponent) + ")";
        }
};

#endif /* ExpensivePower_hpp */