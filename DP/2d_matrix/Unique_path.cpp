//Unique Path

/*
    Problem Statement:
    your task is to find the number of unique paths from the top-left corner to the bottom-right corner of a grid.
    You can only move either down or right at any point in time.
    The grid is represented as a 2D matrix of size m x n, where m is the number of rows and n is the number of columns.
*/

/*
    Approach using Dynamic Programming:
    recusive approach:
        /*
             how to write the recursive function:
                1)express in terms of row and column:
                2)explore all the possible paths:
                3)sum up the results of the recursive calls

    1. base case:
    if(row == m - 1 && col == n - 1) return 1; // reached the bottom-right corner
    if(row >= m || col >= n) return 0; // out of bounds

    2. recursive case:
    down = uniquePaths(row + 1, col, m, n); // move down
    right = uniquePaths(row, col + 1, m, n); // move right
    return down + right; // sum the paths from both directions


    Memorization:
    1. Create a 2D vector `dp` of size m x n initialized to -1.
    BASE CASE:
    if(row == m - 1 && col == n - 1) return 1
    if(row >= m || col >= n) return 0   

    2. Check if `dp[row][col]` is not -1, if so return `dp[row][col]`.
    3. If not, calculate the number of unique paths recursively:
    down = uniquePaths(row + 1, col, m, n, dp); // move down
    right = uniquePaths(row, col + 1, m, n, dp); // move right
    4. Store the result in `dp[row][col]` and return it.
    dp[row][col] = down + right;
    return dp[row][col];     
    
    
    Tabulation:
        // steps to convert the recursive solution to tabulation:
            1) declare the base case
            2) create a loop for all changing variables
            3) copy the recursive logic into the loop
        
    1. Create a 2D vector `dp` of size m x n initialized to 0.
    2. Set the base case: `dp[m-1][n-1] = 1` (bottom-right corner).
    3. Iterate from the bottom-right corner to the top-left corner:
    for (int row = m - 1; row >= 0; --row) {
        for (int col = n - 1; col >= 0; --col) {
            if (row == m - 1 && col == n - 1) continue; // skip the bottom-right corner
            int down = (row + 1 < m) ? dp[row + 1][col] : 0; // move down
            int right = (col + 1 < n) ? dp[row][col + 1] : 0; // move right
            dp[row][col] = down + right; // sum the paths from both directions
        }
    }
*/

#include <iostream>
#include <vector>
using namespace std;

int uniquepath_rec(int row , int col, int m,int n){
    //base case
    if( row == m - 1 && col == n - 1) return 1; // reached the bottom-right corner
    if(row >= m || col >=n) return 0; // out of bounds

    //recursive case
    int down = uniquepath_rec(row + 1, col, m, n); // move down
    int right = uniquepath_rec(row, col + 1, m, n); // move right
    return down + right; // sum the paths from both directions
}

int uniquepath_mem(int row, int col, int m, int n, vector<vector<int>>& dp){
    //basecase
    if(row == m - 1 && col == n - 1) return 1; // reached the bottom-right corner
    if(row >= m || col >= n) return 0; // out of bounds

    if(dp[row][col]!=-1) return dp[row][col]; // if already computed, return the stored value

    //recursive case
    int down = uniquepath_mem(row + 1, col, m, n, dp); // move down
    int right = uniquepath_mem(row, col + 1, m, n, dp); // move right
    dp[row][col] = down + right; // store the result in dp
    return dp[row][col];
}

int uniquepath_tab(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = 1; // base case

    for (int row = m - 1; row >= 0; --row) {
        for (int col = n - 1; col >= 0; --col) {
            if (row == m - 1 && col == n - 1) continue; // skip the bottom-right corner
            int down = (row + 1 < m) ? dp[row + 1][col] : 0; // move down
            int right = (col + 1 < n) ? dp[row][col + 1] : 0; // move right
            dp[row][col] = down + right; // sum the paths from both directions
        }
    }
    return dp[0][0];
}

int main() {
    int m = 3, n = 7; // Example grid size
    cout << "Unique Paths (Recursive): " << uniquepath_rec(0, 0, m, n) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp for memorization
    cout << "Unique Paths (Memorization): " << uniquepath_mem(0, 0, m, n, dp) << endl;

    cout << "Unique Paths (Tabulation): " << uniquepath_tab(m, n) << endl;

    return 0;
}