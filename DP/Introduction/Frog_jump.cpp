//Frog Jump Problem 

/*
    Problem Statement:
        Given an integer array height[] where height[i] represents the height of the i-th stair, 
        a frog starts from the first stair and wants to reach the top. 
        From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
        The cost of a jump is the absolute difference in height between the two stairs. 
        Determine the minimum total cost required for the frog to reach the top.
*/

/*
    // recursive approach:
        1. BaseCase: If the frog is at the last stair, return 0 (no cost).
           if (i == n - 1) return 0;

        2. Recursive case: Calculate the cost of jumping to the next stair and the cost of jumping to the stair after that.
        int jump1 = abs(height[i] - height[i + 1]) + frogJump(height, i + 1, n);
        int jump2 = abs(height[i] - height[i + 2]) + frogJump(height, i + 2, n);
        return min(jump1, jump2);

        time complexity: O(2^n) - exponential time complexity due to the repeated calculations of the same subproblems.
        space complexity: O(n) - due to the recursive call stack.

    // memoization approach:
        1. Create a vector to store the minimum cost for each stair.
           vector<int> dp(n, -1);

        2. Create a helper function that uses memoization.
           int frogJumpMemo(vector<int>& height, int i, int n, vector<int>& dp) {
               if (i == n - 1) return 0;
               if (dp[i] != -1) return dp[i];
               int jump1 = abs(height[i] - height[i + 1]) + frogJumpMemo(height, i + 1, n, dp);
               int jump2 = abs(height[i] - height[i + 2]) + frogJumpMemo(height, i + 2, n, dp);
               return dp[i] = min(jump1, jump2);
           }

        3. Call the helper function and return the result.
           return frogJumpMemo(height, 0, n, dp);

        time complexity: O(n) - linear time complexity due to the memoization.
        space complexity: O(n) - due to the vector used for memoization and the recursive call stack.

    // tabulation approach:
        1. Create a vector to store the minimum cost for each stair.
          vector<int> dp(n, 0);
        2. write the base case:
           dp[n - 1] = 0; // No cost to reach the last stair
        3. Iterate from the second last stair to the first stair, calculating the minimum cost for each stair.
           for (int i = n - 2; i >= 0; i--) {
               int jump1 = abs(height[i] - height[i + 1]) + dp[i + 1];
               int jump2 = (i + 2 < n) ? abs(height[i] - height[i + 2]) + dp[i + 2] : INT_MAX;
               dp[i] = min(jump1, jump2);
           }
        4. Return the minimum cost to reach the top from the first stair.
           return dp[0];
        
        time complexity: O(n) - linear time complexity due to the tabulation.
        space complexity: O(n) - due to the vector used for tabulation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int frogJump(const vector<int>& height, int i, int n) {
    if (i == n - 1) return 0;
    
    int jump1 = frogJump(height, i + 1, n) + abs(height[i] - height[i + 1]);
    int jump2 = (i + 2 < n) ? frogJump(height, i + 2, n) + abs(height[i] - height[i + 2]) : INT_MAX;

    return min(jump1, jump2);
}

//Memoization Approach
int frogJumpMemo(const vector<int>& height, int i, int n, vector<int>& dp){
    if(i==n-1) return 0; // Base case: If the frog is at the last stair, return 0;
    if(dp[i]!=-1) return dp[i]; // If the result is already calculated, return it

    int jump1 = frogJumpMemo(height, i + 1, n, dp) + abs(height[i] - height[i + 1]); // Cost of jumping to the next stair

    int jump2= (i + 2 < n) ? frogJumpMemo(height, i + 2, n, dp) + abs(height[i] - height[i + 2]) : INT_MAX; // Cost of jumping to the stair after that

    return dp[i] = min(jump1, jump2); // Store the result in dp and return the minimum cost
}

// Tabulation Approach

int frogJumpTab(const vector<int> height){
    int n=height.size();
    vector<int> dp(n,-1);
    dp[n-1]=0; // Base case: No cost to reach the last stair
    for(int i=n-2;i>=0;i--){// Iterate from the second last stair to first stair
        int jump1 = dp[i+1]+abs(height[i]-height[i+1]); // Cost of jumping to the next stair
        int jump2 = (i + 2 < n) ? dp[i + 2] + abs(height[i] - height[i + 2]) : INT_MAX; // Cost of jumping to the stair after that
        dp[i] = min(jump1, jump2); // Store the result in dp
    }
    return dp[0]; // Return the minimum cost to reach the top from the first stair
}

int main() {
    vector<int> height = {10, 30, 40, 20, 50};
    int n = height.size();

    // Using Recursive Approach
    cout << "Minimum cost using Recursive Approach: " << frogJump(height, 0, n) << endl;

    // Using Memoization Approach
    vector<int> dp(n, -1);
    cout << "Minimum cost using Memoization Approach: " << frogJumpMemo(height, 0, n, dp) << endl;

    // Using Tabulation Approach
    cout << "Minimum cost using Tabulation Approach: " << frogJumpTab(height) << endl;

    return 0;
}

