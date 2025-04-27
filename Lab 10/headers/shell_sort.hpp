#ifndef shell_sort_hpp
#define shell_sort_hpp

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void shell_sort(vector<T>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

#endif // shell_sort_hpp