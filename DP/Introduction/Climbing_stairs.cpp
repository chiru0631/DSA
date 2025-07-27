//Climbing Stairs Problem

/*
    Problem Statement:
        given a number n, find the number of distinct ways to climb to the top of a staircase with n steps.
        we are at 0th step and we can take either 1 step or 2 steps at a time.
        we have to reach the nth step.

    How do we undersatnd dp:
      1. Try to represent the problem in terms of indexes.
      2. do all the possible operations on the indexes according to the problem statement.
      3. sum all the possible operations to get the final answer.
*/

/*
    //Recursive Approach:
        1. Base case: If n is 0, return 1 (one way to stay at the ground); if n is 1, return 1 (one way to reach the first step).
        if (n == 0) return 1;
        if (n == 1) return 1;
        2. Recursive case: Return the sum of the ways to reach the (n-1)th step and the (n-2)th step.
           This is because we can reach the nth step from either the (n-1)th step or the (n-2)th step.
        return climbStairs(n - 1) + climbStairs(n - 2);

        time complexity: O(2^n) - exponential time complexity due to the repeated calculations of the same subproblems.
        space complexity: O(n) - due to the recursive call stack.

    //Memoization Approach:
     1. Create a vector to store the number of ways to reach each step.
        vector<int> dp(n + 1, -1);
     2. Create a helper function that uses memoization.
        int climbStairsMemo(int n, vector<int>& dp) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (dp[n] != -1) return dp[n];
            dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
            return dp[n];
        }
     3. Call the helper function and return the result.
        return climbStairsMemo(n, dp);

        time complexity: O(n) - linear time complexity due to the memoization.
        space complexity: O(n) - due to the vector used for memoization and the recursive call stack.
    
    //Tabulation Approach:
     1. Create a vector to store the number of ways to reach each step.
        vector<int> dp(n + 1, 0);
    2. Initialize the base cases:
        dp[0] = 1; // One way to stay at the ground
        dp[1] = 1; // One way to reach the first step
    3. Iterate from 2 to n, calculating the number of ways to reach each step using the previous two steps.
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    4. Return the number of ways to reach the nth step.
        return dp[n];

        time complexity: O(n) - linear time complexity due to the tabulation.
        space complexity: O(n) - due to the vector used for tabulation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int climbStairs(int n){
    if( n==0) return 1; // One way to stay at the ground
    if(n==1) return 1; // One way to reach the first step
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Memoization Approach
int climbStairsMemo(int n, vector<int>& dp){
    if(n==0) return 1; // One way to stay at the ground
    if(n==1) return 1; // One way to reach the first step
    if(dp[n]!=-1) return dp[n]; // Return the already calculated value
    dp[n]=climbStairsMemo(n-1,dp)+climbStairsMemo(n-2,dp);
    return dp[n];
}

// Tabulation Approach
int climbStairsTab(int n){
    //first write the base cases
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];

    }
    return dp[n];
}

int main() {
    int n = 3; // Example input for the number of steps

    // Using Recursive Approach
    cout << "Number of ways to climb " << n << " steps (Recursive): " << climbStairs(n) << endl;

    // Using Memoization Approach
    vector<int> dp(n + 1, -1);
    cout << "Number of ways to climb " << n << " steps (Memoization): " << climbStairsMemo(n, dp) << endl;

    // Using Tabulation Approach
    cout << "Number of ways to climb " << n << " steps (Tabulation): " << climbStairsTab(n) << endl;

    return 0;
}