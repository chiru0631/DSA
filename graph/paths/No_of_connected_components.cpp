//

/*
    LeetCode Problem: Number of Islands
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
    return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water.
*/

/*
    Approach:
    1. Create a vector of vector visited to keep track of visited cells.
       vector<vector<bool>> visited(m, vector<bool>(n, false));

    2. iterate through each cell in the grid.
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               if (grid[i][j] == '1' && !visited[i][j]) {
                   // If the cell is land and not visited, perform DFS or BFS to mark all connected land cells as visited.
                   dfs(grid, visited, i, j, m, n);
                   count++; // Increment the island count
               }
           }
       }

    3. Return the count of islands.
       return count;

    
    dfs code:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return; // Out of bounds or water or already visited
        }
        visited[i][j] = true; // Mark the cell as visited
        // Explore all four directions
        dfs(grid, visited, i + 1, j, m, n); // Down
        dfs(grid, visited, i - 1, j, m, n); // Up
        dfs(grid, visited, i, j + 1, m, n); // Right
        dfs(grid, visited, i, j - 1, m, n); // Left
    }
*/

/*
    time complexity: O(m * n)
    space complexity: O(m * n)
*/

#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) {
        return; // Out of bounds or water or already visited
    }
    visited[i][j] = true; // Mark the cell as visited
    // Explore all four directions
    dfs(grid, visited, i + 1, j, m, n); // Down
    dfs(grid, visited, i - 1, j, m, n); // Up
    dfs(grid, visited, i, j + 1, m, n); // Right
    dfs(grid, visited, i, j - 1, m, n); // Left
}

int numIsland(vector<vector<char>>& grid){
    int n= grid.size(); // Number of rows
    int m= grid[0].size(); // Number of columns

    vector<vector<bool>> visited(n, vector<bool>(m, false)); // Visited matrix
    int count = 0; // Count of islands

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                count++; // Increment island count
                // Perform DFS to mark all connected land cells as visited
                dfs(grid, visited, i, j, n, m);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '1', '1'},
        {'0', '0', '0', '1', '0'},
        {'0', '1', '1', '0', '0'},
        {'1', '0', '0', '0', '1'}
    };

    cout << "Number of islands: " << numIsland(grid) << endl; // Output: 5
    return 0;
}


