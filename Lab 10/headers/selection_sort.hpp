#ifndef selection_sort_hpp
#define selection_sort_hpp

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class selection_sort {
    public:
        void operator()(vector<T>& arr) {
            for (size_t i = 0; i < arr.size() - 1; ++i) {
                size_t min_index = i;
                for (size_t j = i + 1; j < arr.size(); ++j) {
                    if (arr[j] < arr[min_index]) {
                        min_index = j;
                    }
                }
                swap(arr[i], arr[min_index]);
            }
        }
};

#endif // selection_sort_hpp