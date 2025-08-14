/*
Problem Statment:

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
Approach:
    1. using a backtracking approach to generate all subsets of the given set.
    2. start with an empty subset and recursively add each element to the current subset.

    backtrack function:
    - base case: if the current index is equal to the size of the input array, add the current subset to the result.
    - include the current element in the subset and recursively call backtrack for the next index.
    - exclude the current element from the subset and recursively call backtrack for the next index.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Include the current element
    current.push_back(nums[index]);
    backtrack(index + 1, nums, current, result);
    
    // Exclude the current element
    current.pop_back();
    backtrack(index + 1, nums, current, result);
}
vector<vector<int>> subset(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result; // Return the result containing all subsets
} 

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = subset(nums);
    
    // Print the subsets
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}