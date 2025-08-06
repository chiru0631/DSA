//Target Sum

/*
    Problem Statement:
    Given an integer array nums and ans integer target,
    assign either '+' or '-' sign to each element of nums such that the sum of the elements equals target.
    return true if it is possible to achieve the target sum, otherwise return false.

    Example:
    Input: nums = [1, 2, 3, 4, 5], target = 1
    Output: true
    Explanation: One possible assignment is +1 +2 +3 -4 -5 = 1
*/

/*
    Approach:
    recusive approach:
    //base case:
    if(ind==0){
        if(nums[0]==target || -nums[0]==target) return true; // if the first element is equal to target or its negative
        return false; // if we cannot form the target with the first element
    }

    //recursive case:
    bool negative = target_sum_rec(nums, ind-1, target-nums[ind]); // taking the current element as negative
    bool positive = target_sum_rec(nums, ind-1, target+nums[ind]); // taking the current element as positive
    return negative || positive;


    //memoization approach:

    vector<vector<int>> dp(ind, vector<int>(target + 1, -1)); // create a dp array to store the results
    //base case:
    if(ind==0){
        if(nums[0]==target || -nums[0]==target) return true; // if the first element is equal to target or its negative
        return false; // if we cannot form the target with the first element
    }

    //check if already computed
    if(dp[ind][target] != -1) return dp[ind][target];

    //recursive case:
    bool negative = target_sum_memo(nums, ind-1, target-nums[ind], dp); // taking the current element as negative
    bool positive = target_sum_memo(nums, ind-1, target+nums[ind], dp); // taking the current element as positive
    return dp[ind][target] = negative || positive; // store the result in dp and return it

    tabulation approach:
    vector<vector<bool>> dp(ind, vector<bool>(target + 1, false)); // create a dp array to store the results
    //base case:
    for(int i=0; i<ind; i++){
        if(nums[i]==target || -nums[i]==target) dp[i][target] = true;
    }
    //fill the dp array
    for(int i=1; i<ind; i++){
        for(int j=0; j<=target; j++){
            bool negative = (j-nums[i] >= 0) ? dp[i-1][j-nums[i]] : false;
            bool positive = (j+nums[i] <= target) ? dp[i-1][j+nums[i]] : false;
            dp[i][j] = negative || positive;
        }
    }
    return dp[ind-1][target];
*/

#include <iostream>
#include <vector>
using namespace std;

bool target_sum_rec(vector<int> &nums, int ind, int target){
    //basecase:
    if(ind==0){
        return (nums[0]==target || -nums[0]==target); // if the first element is equal to target or its negative
    }

    //recursive case:
    bool negative = target_sum_rec(nums, ind-1, target-nums[ind]); // taking the current element as negative
    bool positive = target_sum_rec(nums, ind-1, target+nums[ind]); // taking the current element as positive
    return negative || positive;
}

bool target_sum_mem0(vector<int> &nums, int ind, int target, vector<vector<int>>& dp){
    //basecase:
    if(ind==0){
        return (nums[0]==target || -nums[0]==target); // if the first element is equal to target or its negative
    }
    //check if already computed
    if(dp[ind][target] != -1) return dp[ind][target];

    //recursive case:
    bool negative = target_sum_mem0(nums, ind-1, target-nums[ind], dp); // taking the current element as negative
    bool positive = target_sum_mem0(nums, ind-1, target+nums[ind], dp); // taking the current element as positive
    return dp[ind][target] = negative || positive; // store the result in dp and return it

}

bool target_sum_tabulation(vector<int> &nums, int n, int target) {
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // base case:
    for (int i = 0; i < n; i++) {
        if (nums[i] == target || -nums[i] == target) {
            dp[i][target] = true;
        }
    }

    // fill the dp table
    for (int ind = 1; ind < n; ind++) {
        for (int amt = 0; amt <= target; amt++) {
            bool negative = (amt - nums[ind] >= 0) ? dp[ind - 1][amt - nums[ind]] : false;
            bool positive = (amt + nums[ind] <= target) ? dp[ind - 1][amt + nums[ind]] : false;
            dp[ind][amt] = negative || positive;
        }
    }
    return dp[n - 1][target];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 1;
    int n = nums.size();

    // Recursive approach
    cout << "Recursive: " << (target_sum_rec(nums, n - 1, target) ? "True" : "False") << endl;

    // Memoization approach
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << "Memoization: " << (target_sum_mem0(nums, n - 1, target, dp) ? "True" : "False") << endl;

    // Tabulation approach
    cout << "Tabulation: " << (target_sum_tabulation(nums, n, target) ? "True" : "False") << endl;

    return 0;
}