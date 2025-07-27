//Maximum sum of non-adjacent elements

/*
    Problem Statment:
        Given an array of integers, find the maximum sum of non-adjacent elements.
        You can choose not to pick any element, and the elements you pick should not be adjacent to each other.
*/

/*
    Recursive approach:
        1. Base case: If the index is greater than or equal to the size of the array, return 0.
           if (index >= n) return 0;

        2. Recursive case: 
           - Include the current element and skip the next one.
           - Exclude the current element and move to the next one.
           return max(arr[index] + maxSum(arr, index + 2, n), maxSum(arr, index + 1, n));

        time complexity: O(2^n) - exponential time complexity due to the repeated calculations of the same subproblems.
        space complexity: O(n) - due to the recursive call stack.

    Memoization approach:
        1. Create a vector to store the maximum sum for each index.
           vector<int> dp(n, -1);
        2. Create a helper function that uses memoization.
           int maxSumMemo(const vector<int>& arr, int index, int n, vector<int>& dp) {
               if (index >= n) return 0;
               if (dp[index] != -1) return dp[index];
               dp[index] = max(arr[index] + maxSumMemo(arr, index + 2, n, dp), maxSumMemo(arr, index + 1, n, dp));
               return dp[index];
           }
        3. Call the helper function and return the result.
              return maxSumMemo(arr, 0, n, dp);
        
        time complexity: O(n) - linear time complexity due to the memoization.
        space complexity: O(n) - due to the vector used for memoization and the recursive

    Tabulation approach:
        1. Create a vector to store the maximum sum for each index.
        vector<int> dp(n, 0);
        2. Initialize the base cases:
              dp[n - 1] = arr[n - 1]; // Last element
              dp[n - 2] = max(arr[n - 2], arr[n - 1]); // Max of last two elements
        3. Iterate from the second last index to the first index, calculating the maximum sum for each index using the previous two indices.
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
        }
        4. Return the maximum sum from the first index.
           return dp[0];
        
        time complexity: O(n) - linear time complexity due to the tabulation.
        space complexity: O(n) - due to the vector used for tabulation.
*/


#include <iostream>
#include <vector>
using namespace std;
// Recursive Approach
int maxSum(const vector<int>& arr, int index,int n){
    if(index >=n ) return 0; // Base case: If the index is greater than or equal to the size of the array, return 0.

    // Recursive case: Include the current element and skip the next one, or exclude the current element and move to the next one.
    return max(arr[index]+maxSum(arr, index + 2, n), maxSum(arr, index + 1, n));
}

// Memoization Approach
int maxSumMemo(const vector<int>& arr, int index, int n, vector<int>& dp){
    if(index >=n){
        return 0; // Base case: If the index is greater than or equal to the size of the array, return 0.
    }
    if(dp[index]!=-1) return dp[index]; // If the value is already calculated, return it.
    // Recursive case: Include the current element and skip the next one, or exclude the current element and move to the next one.
    dp[index]= max(arr[index] + maxSumMemo(arr, index + 2, n, dp), maxSumMemo(arr, index + 1, n, dp));
    return dp[index];
}

// Tabulation Approach
int maxSumTab(const vector<int>& arr, int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    int n = arr.size();

    // Recursive approach
    cout << "Maximum sum (Recursive): " << maxSum(arr, 0, n) << endl;

    // Memoization approach
    vector<int> dp(n, -1);
    cout << "Maximum sum (Memoization): " << maxSumMemo(arr, 0, n, dp) << endl;

    // Tabulation approach
    cout << "Maximum sum (Tabulation): " << maxSumTab(arr, n) << endl;

    return 0;
}