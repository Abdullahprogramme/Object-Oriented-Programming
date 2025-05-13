#ifndef CachedMultiply_hpp
#define CachedMultiply_hpp

#include <string>
#include "Operation.hpp"

using namespace std;

template <typename T>
class CachedMultiply : public Operation<T> {
    private:
        mutable T lastResult;
        mutable bool isCached;

    public:
        CachedMultiply() : lastResult(1), isCached(false) {}
        
        T apply(T input) const override {
            T result = input * (isCached ? lastResult : static_cast<T>(1));
            lastResult = result;
            isCached = true;
            return result;
        }

        string name() const override {
            return "CachedMultiply";
        }

        void clearCache() const {
            isCached = false;
        }
};

#endif /* CachedMultiply_hpp */