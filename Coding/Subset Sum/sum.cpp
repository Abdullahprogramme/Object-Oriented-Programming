#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Find subsets of a vector that sum to a target value
void findSubsets(const vector<int>& nums, int target, vector<int>& current, int start, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current); // Found a valid subset
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (nums[i] > target) continue; // Skip if the number is greater than the remaining target
        current.push_back(nums[i]);
        findSubsets(nums, target - nums[i], current, i + 1, result);
        current.pop_back();
    }
}

// Function to find all subsets of a vector that sum to a target value
void findSubsetsWithSum(const vector<int>& nums, int target) {
    vector<int> current;
    vector<vector<int>> result;
    findSubsets(nums, target, current, 0, result);

    auto it = unique(result.begin(), result.end());
    result.erase(it, result.end()); // Remove duplicates

    if (result.empty()) {
        cout << "No subsets found." << endl;
    } else {
        for (const auto& subset : result) {
            cout << "{ ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }
}

// Main function to test the subset sum function
int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    int target = 5;
    cout << "Finding subsets of {0, 1, 2, 3, 4, 5} that sum to " << target << ":" << endl;
    findSubsetsWithSum(nums, target);
    return 0;
}
