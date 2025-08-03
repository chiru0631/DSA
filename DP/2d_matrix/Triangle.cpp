//Triangle problem in C++

/*
    Problem Statement:
    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
    For example, given the following triangle
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

/*
    Approach using recursion:
    1. Base Case:
        - If you reach the last row, return the value of that cell.
        - If you go out of bounds, return a large value (infinity).
        if(row == n - 1) return triangle[row][col]; // reached the last row
        if(row >= n || col < 0 || col >= triangle[row].size()) return INT_MAX; // out of bounds
    2. Recursive Case:
        - Calculate the minimum path sum for the two adjacent cells in the next row.
        - Return the current cell value plus the minimum of the two adjacent cells.
        int down = minPathSum(row + 1, col, triangle); // move down
        int downRight = minPathSum(row + 1, col + 1, triangle); // move down-right
        return triangle[row][col] + min(down, downRight);

    Approach using memorization:
    1. Create a 2D vector `dp` of size n x n initialized to -1.
    2. Base Case:
        - If you reach the last row, return the value of that cell.
        - If you go out of bounds, return a large value (infinity).

    3. Check if `dp[row][col]` is not -1, if so return `dp[row][col]`.
    4. If not, calculate the minimum path sum recursively:
        int down = minPathSum(row + 1, col, triangle, dp); // move down
        int downRight = minPathSum(row + 1, col + 1, triangle, dp); // move down-right
        dp[row][col] = triangle[row][col] + min(down, downRight); // store the result in dp
        return dp[row][col];
    
    Approach using tabulation:
    1. Create a 2D vector `dp` of size n x n initialized to 0.
    2. Set the base case: `dp[n-1][j] = triangle[n-1][j]` for all j (last row).
    3. Iterate from the second last row to the top:
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
    4. The minimum path sum will be in `dp[0][0]`. 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangle_rec(int row, int col, vector<vector<int>>& triangle){
    if(row == triangle.size()-1) return triangle[row][col]; // reached the last row
    if(row >= triangle.size() || col < 0 || col >= triangle[row].size()) return INT_MAX; // out of bounds

    int down = triangle_rec(row + 1, col, triangle); // move down
    int downRight = triangle_rec(row + 1, col + 1, triangle); // move down-right
    return triangle[row][col] + min(down, downRight); // add the current cell value to the minimum of the two paths
}

int triangle_mem(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if( row == triangle.size()-1) return triangle[row][col]; // reached the last row
    if( row >= triangle.size() || col<0 || col>= triangle[row].size()) return INT_MAX; // out of bounds

    if(dp[row][col]!=-1)return dp[row][col]; // if already computed, return the stored value

    int down = triangle_mem(row + 1, col, triangle, dp); // move down
    int downRight = triangle_mem(row + 1, col + 1, triangle, dp); // move down-right
    dp[row][col] = triangle[row][col] + min(down, downRight); // store the result in dp
    return dp[row][col];
}

int triangle_tabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: last row
    for (int j = 0; j < triangle[n - 1].size(); j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Fill the dp table from bottom to top
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0]; // The minimum path sum will be in the top cell
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // Using recursion
    cout << "Minimum Path Sum (Recursion): " << triangle_rec(0, 0, triangle) << endl;

    // Using memorization
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    cout << "Minimum Path Sum (Memorization): " << triangle_mem(0, 0, triangle, dp) << endl;

    // Using tabulation
    cout << "Minimum Path Sum (Tabulation): " << triangle_tabulation(triangle) << endl;

    return 0;
}
