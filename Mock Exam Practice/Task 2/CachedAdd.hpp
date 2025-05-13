#ifndef CachedAdd_hpp
#define CachedAdd_hpp

#include <string>
#include "Operation.hpp"

using namespace std;

template <typename T>
class CachedAdd : public Operation<T> {
    private:
        mutable T lastResult;
        mutable bool isCached;

    public:
        CachedAdd() : lastResult(0), isCached(false) {}
        
        T apply(T input) const override {
            T result = input + (isCached ? lastResult : static_cast<T>(0)); // Use cached value if available
            lastResult = result; // Update the cache with the new result
            isCached = true; // Mark the cache as valid
            return result;
        }

        string name() const override {
            return "CachedAdd";
        }
    
        void clearCache() const {
            isCached = false;
        }
};

#endif /* CachedAdd_hpp */