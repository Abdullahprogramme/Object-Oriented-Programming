#ifndef CachedSine_hpp
#define CachedSine_hpp

#include <cmath>
#include <string>
#include "Operation.hpp"

using namespace std;

template <typename T>
class CachedSine : public Operation<T> {
    private:
        mutable T lastInput;
        mutable T lastOutput;
        mutable bool isCached;

    public:
        CachedSine() : lastInput(0), lastOutput(0), isCached(false) {}

        T apply(T input) const override {
            if (isCached && input == lastInput) {
                return lastOutput;
            }

            lastInput = input;
            lastOutput = sin(input);
            isCached = true;
            return lastOutput;
        }

        string name() const override {
            return "CachedSine";
        }

        void clearCache() const {
            isCached = false;
        }   
};

#endif /* CachedSine_hpp */