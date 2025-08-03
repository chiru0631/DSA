/*
    Find the maximum falling path sum in a 2D matrix.
    Problem Statement:
    Given an m x n integer matrix matrix, return the maximum falling path sum.
    A falling path starts at any element in the first row and chooses the element 
    in the next row that is either directly below or diagonally left/right. 
    Specifically, the next element from position (row, col) will be 
    (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Also, you can only move down or diagonally left/right at any point in time.
*/

/*
    Recursive Approach:
    1. Base Case:
        - If you reach the last row, return the value of that cell.
        - If you go out of bounds, return a large value (negative infinity).
        if(row == matrix.size() - 1) return matrix[row][col]; // reached the last row
        if(row >= matrix.size() || col < 0 || col >= matrix[row].size()) return INT_MIN; // out of bounds

    2. Recursive Case:
        - Calculate the maximum falling path sum for the three possible moves (down, down-left, down-right).
        - Return the current cell value plus the maximum of the three paths.
        int down = maxFallingPathSum(row + 1, col, matrix); // move down
        int downLeft = maxFallingPathSum(row + 1, col - 1, matrix); // move down-left
        int downRight = maxFallingPathSum(row + 1, col + 1, matrix); // move down-right
        return matrix[row][col] + max(down, max(downLeft, downRight));

    Approach using Memorization:
    1. Create a 2D vector `dp` of size m x n initialized to -1.
    2. Base Case:
        - If you reach the last row, return the value of that cell.
        - If you go out of bounds, return a large value (negative infinity).
    3. Check if `dp[row][col]` is not -1, if so return `dp[row][col]`.
    4. If not, calculate the maximum falling path sum recursively:
        int down = maxFallingPathSum(row + 1, col, matrix, dp); // move down
        int downLeft = maxFallingPathSum(row + 1, col - 1, matrix, dp); // move down-left
        int downRight = maxFallingPathSum(row + 1, col + 1, matrix, dp); // move down-right
        dp[row][col] = matrix[row][col] + max(down, max(downLeft, downRight)); // store the result in dp
        return dp[row][col];
    
    Approach using Tabulation:
    1. Create a 2D vector `dp` of size m x n initialized to 0.
    2. Set the base case: `dp[m-1][j] = matrix[m-1][j]` for all j (last row).
    3. Iterate from the second last row to the top:
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = dp[i + 1][j]; // move down
                int downLeft = (j > 0) ? dp[i + 1][j - 1] : INT_MIN; // move down-left
                int downRight = (j < n - 1) ? dp[i + 1][j + 1] : INT_MIN; // move down-right
                dp[i][j] = matrix[i][j] + max(down, max(downLeft, downRight));
            }
        }   
    4. The maximum falling path sum will be the maximum value in the first row of `dp`.
    5. Return the maximum falling path sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int rec(int row, int col, vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    if (col < 0 || col >= n) return INT_MIN;
    if (row == m - 1) return matrix[row][col];

    int down = rec(row + 1, col, matrix);
    int downLeft = rec(row + 1, col - 1, matrix);
    int downRight = rec(row + 1, col + 1, matrix);

    return matrix[row][col] + max({down, downLeft, downRight});
}


int mem(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int m = matrix.size(), n = matrix[0].size();
    if (col < 0 || col >= n) return INT_MIN;
    if (row == m - 1) return matrix[row][col];
    if (dp[row][col] != -1) return dp[row][col];

    int down = mem(row + 1, col, matrix, dp);
    int downLeft = mem(row + 1, col - 1, matrix, dp);
    int downRight = mem(row + 1, col + 1, matrix, dp);

    return dp[row][col] = matrix[row][col] + max({down, downLeft, downRight});
}


int tabulation(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case: fill last row
    for (int j = 0; j < n; j++) {
        dp[m - 1][j] = matrix[m - 1][j];
    }

    // Fill from second-last row upwards
    for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int down = dp[i + 1][j];
            int downLeft = (j > 0) ? dp[i + 1][j - 1] : INT_MIN;
            int downRight = (j < n - 1) ? dp[i + 1][j + 1] : INT_MIN;

            dp[i][j] = matrix[i][j] + max({down, downLeft, downRight});
        }
    }

    // Final answer = max in first row
    return *max_element(dp[0].begin(), dp[0].end());
}

int main() {
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int m = matrix.size(), n = matrix[0].size();

    
    int maxRec = INT_MIN;
    for (int j = 0; j < n; j++) {
        maxRec = max(maxRec, rec(0, j, matrix));
    }
    cout << "Maximum Falling Path Sum (Recursive): " << maxRec << endl;

    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxMemo = INT_MIN;
    for (int j = 0; j < n; j++) {
        maxMemo = max(maxMemo, mem(0, j, matrix, dp));
    }
    cout << "Maximum Falling Path Sum (Memoization): " << maxMemo << endl;

    
    cout << "Maximum Falling Path Sum (Tabulation): " << tabulation(matrix) << endl;

    return 0;
}
