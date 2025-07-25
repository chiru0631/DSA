//46. Permutations

/*
    Problem Statement:
        Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


*/
/*
    Approach:
        we will use for loop and recursion to generate the permutations.
    we will be using 2 functions:
        - permuteHelper: This function will be used to generate the permutations.
        - permute: This function will be used to find the permutations by calling the permuteHelper function.
    permute :
         // Parameters:
        - nums: the input array of integers.
    Logic:
        1. vector of vector of integers to store the permutations.
        2. vector of integers to store the current permutation.
        3. call the recursive function to generate the permutations.
        // permuteHelper(0, nums, current, result):
        4. return the permutations.
    

    permuteHelper :
       // Parameters:
        - index: the current index in the array.
        - nums: the input array of integers.
        - current: the current permutation being generated.
        - result: to store the final list of permutations.
    Logic:
        1. if index is equal to the size of the array, we have found a valid permutation.
            - push the current permutation into the result.
            - return.
        2. iterate through the array starting from the current index:
            - swap the current element with the element at the index.
              swap(current[index], current[i]);
            - push the current element into the current permutation.
              current.push_back(nums[i]);
            - recursively call the function with the next index.
              permuteHelper(index + 1, nums, current, result);
            - pop the last element from the current permutation (backtrack).
              current.pop_back();
            - swap back to restore the original order.
        3. return;
*/

/*
    Time Complexity: O(n!), where n is the number of elements in the input array. This is because there are n! permutations of n distinct elements.
    Space Complexity: O(n), where n is the number of elements in the input array. The space is used for the recursion stack and to store the permutations.
*/

#include <iostream>
#include <vector>
using namespace std;

void permuteHelper(int index, vector<int> &nums, vector<vector<int>> &result) {
    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        permuteHelper(index + 1, nums, result);
        swap(nums[index], nums[i]); // Backtrack
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    permuteHelper(0, nums, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);
    
    for (const auto &perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}