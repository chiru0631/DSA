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
    2. Base Case:
       - If k == 0, then dp[i][0] = true for all i (empty subset).
       - If ind == 0, then dp[0][k] = (arr[0] == k).
    3. Fill the dp table:
       - Iterate through all indices and all possible sums.
       - For each element, decide to include it or not.
       - Update the dp table accordingly.
    4. Return the result:
       - The answer will be in dp[n-1][k].
*/