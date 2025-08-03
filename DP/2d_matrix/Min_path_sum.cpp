//Min path sum in a 2D matrix

/*
    Problem Statement:
    Given a 2D matrix of integers, find the minimum path sum from the top-left corner to the bottom-right corner.
    You can only move either down or right at any point in time.


    
*/

/*
    Approach uning recursion:
    1. Base Case:
        - If you reach the bottom-right corner, return the value of that cell.
        - If you go out of bounds, return a large value (infinity).
    2. Recursive Case:
        down = minPathSum(row + 1, col, m, n); // move down
        right = minPathSum(row, col + 1, m, n); // move right
        return grid[row][col] + min(down, right); // add the current cell value to the minimum of the two paths

    Approach using Memorization:
    1. Create a 2D vector `dp` of size m x n initialized to -1.
    2. Base Case:
        - If you reach the bottom-right corner, return the value of that cell.
        - If you go out of bounds, return a large value (infinity).
    3. Check if `dp[row][col]` is not -1, if so return `dp[row][col]`.
    4. If not, calculate the minimum path sum recursively:
        down = minPathSum(row + 1, col, m, n, dp); // move down
        right = minPathSum(row, col + 1, m, n, dp); // move right
        dp[row][col] = grid[row][col] + min(down, right); // store the result in dp
        return dp[row][col];
        
    Approach using Tabulation:

    1. Create a 2D vector `dp` of size m x n initialized to 0.
    2. Set the base case: `dp[m-1][n-1] = grid[m-1][n-1]` (bottom-right corner).
    3. Fill the last row and last column:
        - For the last row, we can only come from the left.
        - For the last column, we can only come from above.
    4. Fill the rest of the dp table:
        - For each cell, the minimum path sum is the current cell value plus the minimum of the cell below and the cell to the right.
    5. The answer will be in `dp[0][0]` (top-left corner).

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == m - 1 && j == n - 1) continue; // skip the bottom-right corner
            int down = (i + 1 < m) ? dp[i + 1][j] : INT_MAX; // move down
            int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX; // move right
            dp[i][j] = grid[i][j] + min(down, right); // sum the paths from both directions
        }
        
    }
    return dp[0][0]; // return the minimum path sum to the top-left corner

*/

/*
    time complexity:
    - Recursive: O(2^(m+n)), exponential time due to overlapping subproblems
    - Memorization: O(m*n) for the dp table.
    - Tabulation: O(m*n) for the dp table.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum_rec(int row, int col, int m, int n, vector<vector<int>>& grid) {
    // base case
    if(row == m-1 && col == n-1) return grid[row][col]; // reached the bottom-right corner
    if(row >= m || col >= n) return INT_MAX; // out of bounds
    // recursive case
    int down = minPathSum_rec(row + 1, col, m, n, grid); // move down
    int right = minPathSum_rec(row, col + 1, m, n, grid); // move right
    return grid[row][col] + min(down, right); // add the current cell value to the minimum of the two paths
}

int minPathSum_mem(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // base case
    if(row == m-1 && col == n-1) return grid[row][col]; // reached the bottom-right corner
    if(row >= m || col >= n) return INT_MAX; // out of bounds

    if(dp[row][col] != -1) return dp[row][col]; // if already computed, return the stored value

    // recursive case
    int down = minPathSum_mem(row + 1, col, m, n, grid, dp); // move down
    int right = minPathSum_mem(row, col + 1, m, n, grid, dp); // move right
    dp[row][col] = grid[row][col] + min(down, right); // store the result in dp
    return dp[row][col];
}

int minPathSum_tab(int m, int n, vector<vector<int>>& grid) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = grid[m - 1][n - 1]; // base case

    // fill the last row
    for (int j = n - 2; j >= 0; --j) {
        dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
    }

    // fill the last column
    for (int i = m - 2; i >= 0; --i) {
        dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
    }

    // fill the rest of the dp table
    for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0]; // return the minimum path sum to the top-left corner
}

int main() {
    int m = 3, n = 3; // Example grid size
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Using recursion
    cout << "Minimum Path Sum (Recursion): " << minPathSum_rec(0, 0, m, n, grid) << endl;

    // Using memorization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Minimum Path Sum (Memorization): " << minPathSum_mem(0, 0, m, n, grid, dp) << endl;

    // Using tabulation
    cout << "Minimum Path Sum (Tabulation): " << minPathSum_tab(m, n, grid) << endl;

    return 0;
}   
