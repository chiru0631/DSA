//Subsequence Sum Equal to K

/*
    Problem Statement:
    Given an array of integers and a target sum k, find if there exists a subset of the array that sums up to k.
    You can use dynamic programming to solve this problem efficiently.
*/

/*
    Recurrsive Approach:
    1. Base Case: If k is 0, return true (empty subset).
    2.. if ind==0 return arr[ind] == k (only one element to consider).

    3. take or not take the current element:
       - If we take the current element, reduce k by arr[ind] and move to the next index.
       - If we do not take the current element, just move to the next index without changing k.
    bool notTake = subsetSum(ind - 1, k, arr);

    bool take = false;
    if (k >= arr[ind]) {
        take = subsetSum(ind - 1, k - arr[ind], arr);
    }
    return take || notTake;

    Memoization Approach:
    1. Create a 2D array dp of size (n x k) initialized to -1.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    baseCase:
    if (k == 0) return true;
    if (ind == 0) return arr[ind] == k;

    2. Check if the current state is already computed (dp[ind][k] != -1).
        if( dp[ind][k] != -1) return dp[ind][k];
    
    3. If not computed, calculate the result using the recursive approach and store it in dp[ind][k].
    bool notTake = subsetSum(ind - 1, k, arr, dp);
    bool take = false;
    if (k >= arr[ind]) {
        take = subsetSum(ind - 1, k - arr[ind], arr, dp);
    }
    dp[ind][k] = take || notTake;
    return dp[ind][k];


    tabulation Approach:
    1. Create a 2D array dp of size (n x k) initialized to false.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    2. base case:
        // if k is 0, then we can always form a subset with sum 0 (empty subset).
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if( arr[0] <= k) {
            dp[0][arr[0]] = true; // only one element to consider
        }
    
    //there are 2 changing variables: ind and k
    3. Iterate through the array and fill the dp table:
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= k; sum++) {
            bool notTake = dp[ind - 1][sum]; // not taking the current element
            bool take = false;
            if (sum >= arr[ind]) {
                take = dp[ind - 1][sum - arr[ind]]; // taking the current element
            }
            dp[ind][sum] = take || notTake;
        }
    }
*/

#include <iostream>
#include <vector>
using namespace std;

bool subsetsum_rec(int ind, int k,vector<int> &arr){
    //base case:
    if(k==0) return true;
    if(ind ==0 ) return arr[ind]==k;

    // recursive case:
    bool nottake =  subsetsum_rec(ind-1,k,arr);
    bool take=false;
    if(k>=arr[ind]){
         take= subsetsum_rec(ind-1,k-arr[ind],arr);
    }
    return take || nottake;
}

bool subsetsume_mem0(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return true;
    if(ind ==0 ) return arr[ind]==k;

    if(dp[ind][k] != -1) return dp[ind][k];

    // recursive case:
    bool nottake =  subsetsum_rec(ind-1,k,arr);
    bool take=false;
    if(k>=arr[ind]){
         take= subsetsum_rec(ind-1,k-arr[ind],arr);
    }
    dp[ind][k] = take || nottake;
    return dp[ind][k];
}

bool subsetSum_tabulation(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // base case:
    for (int i = 0; i < n; i++) {
        dp[i][0] = true; // sum 0 can always be formed with an empty subset
    }
    if (arr[0] <= k) {
        dp[0][arr[0]] = true; // only one element to consider
    }
    

    // fill the dp table
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= k; sum++) {
            bool notTake = dp[ind - 1][sum]; // not taking the current element
            bool take = false;
            if (sum >= arr[ind]) {
                take = dp[ind - 1][sum - arr[ind]]; // taking the current element
            }
            dp[ind][sum] = take || notTake;
        }
    }
    return dp[n - 1][k];

}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int k = 9;
    int n = arr.size();

    // Recursive approach
    cout << "Using Recursion: " << (subsetsum_rec(n - 1, k, arr) ? "Yes" : "No") << endl;

    // Memoization approach
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << "Using Memoization: " << (subsetsume_mem0(n - 1, k, arr, dp) ? "Yes" : "No") << endl;

    // Tabulation approach
    cout << "Using Tabulation: " << (subsetSum_tabulation(n, k, arr) ? "Yes" : "No") << endl;

    return 0;
}