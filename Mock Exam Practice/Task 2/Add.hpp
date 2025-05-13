#ifndef Add_hpp
#define Add_hpp

#include <string>
#include <iostream>
#include "Operation.hpp"

using namespace std;

template <typename T>
class Add : public Operation<T> {
    private:
        T value;
        
    public:
        explicit Add(T val) : value(val) {}

        T apply(T input) const override {
            cout << name() << " applied to " << input << endl;
            return input + value;
        }

        string name() const override {
            return "Add(" + to_string(value) + ")";
        }
};

#endif /* Add_hpp */