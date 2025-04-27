#ifndef insertion_sort_hpp
#define insertion_sort_hpp

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class insertion_sort {
    public:
        void operator()(vector<T>& arr) {
            for (size_t i = 1; i < arr.size(); ++i) {
                T key = arr[i];
                size_t j = i;
                while (j > 0 && arr[j - 1] > key) {
                    arr[j] = arr[j - 1];
                    --j;
                }
                arr[j] = key;
            }
        }
};

#endif // insertion_sort_hpp