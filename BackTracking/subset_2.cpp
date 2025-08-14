/*
    Problem Statement:
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
    Approach:
    1. Sort the input array to handle duplicates easily.
    2. Use a backtracking approach to generate all subsets.
    3. Skip duplicates by checking if the current element is the same as the previous one.

    backtrack function:
    - base case: push the current subset into the result.
    itreate through the array starting from the current index.
    - check if the current i in loop is not same as i-1 if so continue
    - push the current element into the subset.
    - recursively call backtrack for the next index.
    - pop the current element from the subset to backtrack.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subset_2(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
    result.push_back(current);// Add the current subset to the result

    for(int i = index; i<nums.size();i++){
        if(i>index && nums[i] == nums[i-1]){
            continue; // Skip duplicates
        }
        current.push_back(nums[i]);
        subset_2(i + 1, nums, current, result); // Recur for the next index
        current.pop_back(); // Backtrack to explore subsets without the current element
    }
}

int main() {
    vector<int> nums = {1, 2, 2};
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> current;

    subset_2(0, nums, current, result);

    // Print the subsets
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
