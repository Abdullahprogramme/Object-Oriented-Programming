#ifndef Multiply_hpp
#define Multiply_hpp

#include <string>
#include "Operation.hpp"

using namespace std;

template <typename T>
class Multiply : public Operation<T> {
    private:
        T value;
        
    public:
        explicit Multiply(T val) : value(val) {}

        T apply(T input) const override {
            cout << name() << " applied to " << input << endl;
            return input * value;
        }

        string name() const override {
            return "Multiply(" + to_string(value) + ")";
        }
};

#endif /* Multiply_hpp */