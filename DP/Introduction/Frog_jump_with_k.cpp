//Frog Jump with K Distance Problem

/*
    Problem Statement:
        Given an integer array height[] where height[i] represents the height of the i-th stair, 
        a frog starts from the first stair and wants to reach the top. 
        From any stair i, the frog can jump to any of the next k stairs (i+1 to i+k). 
        The cost of a jump is the absolute difference in height between the two stairs. 
        Determine the minimum total cost required for the frog to reach the top.
*/

/*
    Recursive Approach:
        1. Base Case: If the frog is at the last stair, return 0 (no cost).
           if (i == n - 1) return 0;

        2. Recursive case: Calculate the cost of jumping to the next k stairs.
           int minCost = INT_MAX;
           for (int j = 1; j <= k && i + j < n; j++) {
               int cost = abs(height[i] - height[i + j]) + frogJump(height, i + j, n, k);
               minCost = min(minCost, cost);
           }
           return minCost;

        time complexity: O(k^n) - exponential time complexity due to the repeated calculations of the same subproblems.
        space complexity: O(n) - due to the recursive call stack.

    Memoization Approach:
        1. Create a vector to store the minimum cost for each stair.
           vector<int> dp(n, -1);

        2. Create a helper function that uses memoization.
           int frogJumpMemo(vector<int>& height, int i, int n, int k, vector<int>& dp) {
               if (i == n - 1) return 0;
               if (dp[i] != -1) return dp[i];
               int minCost = INT_MAX;
               for (int j = 1; j <= k && i + j < n; j++) {
                   int cost = abs(height[i] - height[i + j]) + frogJumpMemo(height, i + j, n, k, dp);
                   minCost = min(minCost, cost);
               }
               return dp[i] = minCost;
           }

        3. Call the helper function and return the result.
           return frogJumpMemo(height, 0, n, k, dp);

        time complexity: O(n*k) - linear time complexity due to the memoization.
        space complexity: O(n) - due to the vector used for memoization and the recursive call stack.

    Tabulation Approach:
        1. Create a vector to store the minimum cost for each stair.
        vector<int> dp(n, 0);
        2. Initialize the base case:
           dp[n - 1] = 0; // No cost to reach the last stair
        3. Iterate from the second last stair to the first stair, calculating the minimum cost for each stair.
           for (int i = n - 2; i >= 0; i--) {
               int minCost = INT_MAX;
               for (int j = 1; j <= k && i + j < n; j++) {
                   int cost = abs(height[i] - height[i + j]) + dp[i + j];
                   minCost = min(minCost, cost);
               }
               dp[i] = minCost;
           }    
        4. Return the minimum cost to reach the top from the first stair.
        return dp[0];
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int frogJump(vector<int>& height, int i, int n,int k){
    if(i==n-1){
        return 0; // No cost to reach the last stair
    }

    int minCost= INT_MAX;
    for(int j=1;j<=k && i+j<n;j++){
        int cost= abs(height[i]-height[i+j])+frogJump(height,i+j,n,k);
        minCost=min(minCost,cost);
    }
    return minCost;
}

// Memoization Approach
int frogJumpmemo(vector<int>& height, int i, int n,int k, vector<int>&dp){
    if(i==n-1){
        return 0; // No cost to reach the last stair
    }
    if(dp[i]!=-1) return dp[i]; // Return the already calculated value

    int minCost= INT_MAX;
    for(int j=1;j<=k && i+j<n;j++){
        int cost= abs(height[i]-height[i+j])+frogJumpmemo(height,i+j,n,k,dp);
        minCost=min(minCost,cost);
    }
    return dp[i]=minCost;
}

// Tabulation Approach
int frogJumpTab(vector<int>& height, int n, int k) {
    vector<int> dp(n,-1);
    dp[n-1]=0; // Base case: No cost to reach the last stair
    for(int j=n-2;j>=0;j--){
        int minCost = INT_MAX;
        for(int i=1; i<=k && j+i<n; i++){
            int cost = abs(height[j] - height[j+i]) + dp[j+i];
            minCost = min(minCost, cost);
        }
        dp[j] = minCost; // Store the result in dp
    }
    return dp[0]; // Return the minimum cost to reach the top from the first stair

}

int main() {
    vector<int> height = {10, 30, 40, 20, 50};
    int n = height.size();
    int k = 2; // Maximum jump distance

    // Using Recursive Approach
    cout << "Minimum cost using Recursive Approach: " << frogJump(height, 0, n, k) << endl;

    // Using Memoization Approach
    vector<int> dp(n, -1);
    cout << "Minimum cost using Memoization Approach: " << frogJumpmemo(height, 0, n, k, dp) << endl;

    // Using Tabulation Approach
    cout << "Minimum cost using Tabulation Approach: " << frogJumpTab(height, n, k) << endl;

    return 0;
}