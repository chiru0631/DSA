//partation with a given differecnce

/*
    Problem Statement:
    Given an integer array partition it into two subset such that their union is equal to the original array and the difference between the sum of the two subsets is equal to a given target.
    Example:
    Input: nums = [1, 2, 3, 4, 5], target = 1
    Output: true
    Explanation: One possible partition is [1, 2, 3] and [4, 5] which have a difference of 1.
*/

/*
    Approach: 
    1. Calculate the total sum of the array.
    2. we have 2 equations 
       sum1 + sum2 = total_sum
       sum1 - sum2 = target
    3. evaluate the above equations to find sum1 and sum2.
       sum1 = (total_sum + target) / 2
       sum2 = total_sum - sum1
    4. so we can apply subset sum problem to find if there exists a subset with sum equal to sum1.

    Recurrence Approach:
    ispossible(nums, ind, sum) {
        if (sum == 0) return true; // base case: if sum is 0, we can form it with an empty subset
        if (ind == 0) return nums[0] == sum; // base case: if we are at the first element

        // recursive case:
        bool notTaken = ispossible(nums, ind - 1, sum); // not taking the current element
        bool taken = false;
        if (nums[ind] <= sum) {
            taken = ispossible(nums, ind - 1, sum - nums[ind]); // taking the current element
        }
        return taken || notTaken; // return true if either case is true
    }

bool canPartition(vector<int>& nums, int target) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0);    
    if ((total_sum + target) % 2 != 0) return false; // if the sum is not even, we cannot partition it
    int sum1 = (total_sum + target) / 2; // calculate the required sum for one subset
    int n = nums.size();
    return ispossible(nums, n - 1, sum1); // call the recursive function
}

    Memoization Approach:
bool ispossible_memo(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return true; // base case: if sum is 0, we can form it with an empty subset
    if (ind == 0) return nums[0] == sum; // base case: if we are at the first element

    // check if already computed
    if (dp[ind][sum] != -1) return dp[ind][sum];

    // recursive case:
    bool notTaken = ispossible_memo(nums, ind - 1, sum, dp); // not taking the current element
    bool taken = false;
    if (nums[ind] <= sum) {
        taken = ispossible_memo(nums, ind - 1, sum - nums[ind], dp); // taking the current element
    }
    return dp[ind][sum] = taken || notTaken; // store the result in dp and return
}
*/


/*
time complexity: O(n * sum1)
space complexity: O(n * sum1) for memoization, O(sum1) for tabulation
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool ispossible_rec(vector<int>&nums, int ind, int sum){
    //base case:
    if(sum==0) return true; // if sum is 0, we can form it with an empty subset
    if(ind==0) return nums[0]==sum; // if we are at the first element

    //recursive case:
    bool nottake= ispossible_rec(nums,ind-1,sum);
    bool take= false;
    if(nums[ind]<=sum){
        take= ispossible_rec(nums,ind-1,sum-nums[ind]);
    }
    return take || nottake;
}

bool ispossible_memo(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp){
    if(sum==0) return true; // base case: if sum is 0, we can form it with an empty subset
    if(ind==0) return nums[0]==sum; // base case: if we are at the first element

    // check if already computed
    if(dp[ind][sum]!= -1) return dp[ind][sum];
    // recursive case:
    bool nottake = ispossible_memo(nums, ind - 1, sum, dp); // not taking the current element
    bool take = false;
    if(nums[ind] <= sum){
        take = ispossible_memo(nums, ind - 1, sum - nums[ind], dp); // taking the current element
    }
    return dp[ind][sum] = take || nottake; // store the result in dp and return
}

bool canPartition(vector<int>& nums, int target) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if ((total_sum + target) % 2 != 0) return false; // if the sum is not even, we cannot partition it
    int sum1 = (total_sum + target) / 2; // calculate the required sum for one subset
    int n = nums.size();

    // Memoization approach
    vector<vector<int>> dp(n, vector<int>(sum1 + 1, -1));
    return ispossible_memo(nums, n - 1, sum1, dp);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 1;
    if (canPartition(nums, target)) {
        cout << "Partition is possible with the given target difference." << endl;
    } else {
        cout << "Partition is not possible with the given target difference." << endl;
    }
    return 0;
}