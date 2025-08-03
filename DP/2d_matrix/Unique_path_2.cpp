//Unique Path 2

/*
    Problem Statement:
    Your task is to find the number of unique paths from the top-left corner to the bottom-right corner of a grid,
    where some cells may be blocked. the blocked are represebted by -1 in 2d matrix.
    You can only move either down or right at any point in time.
*/

/*
    Approach using Dynamic Programming:
    1. Base Case:
        - If the starting cell (0, 0) is blocked, return 0.
        - If the destination cell (m-1, n-1) is blocked, return 0.
    2. Recursive Case:
        - Use a 2D vector `dp` to store the number of unique paths to each cell.
        - If a cell is blocked, set `dp[i][j]` to 0.
        - Otherwise, calculate the number of unique paths to that cell by summing the paths from the cell above and the cell to the left.

        dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
    3. Return the value in the bottom-right corner (dp[m-1][n-1]).

*/

#include <iostream>
#include <vector>
using namespace std;

int uniquepath2(int m, int n, vector<vector<int>>& grid){
    if(grid[0][0] == -1 || grid[m-1][n-1] == -1) return 0; // if start or end is blocked

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1; // starting point
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0) continue; // skip the starting cell
            // if the cell is blocked, set dp[i][j] to 0
            if(grid[i][j] == -1) dp[i][j] = 0; // blocked cell
            else {
                dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
            }

        }

    }
    return dp[m - 1][n - 1]; // return the number of unique paths to the bottom-right corner
}

int main() {
    int m = 3, n = 7; // Example grid size
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, -1, 0, 0, 0, -1, 0},
        {0, 0, 0, -1, 0, 0, 0}
    };
    
    cout << "Unique Paths (With Obstacles): " << uniquepath2(m, n, grid) << endl;//output = 1
    return 0;
}