//Shortest Distance in a Binary Maze

/*
    Problem Statment:
        Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

        A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) 
        such that:

        - All the visited cells of the path are 0.
        - All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
        - The length of a clear path is the number of visited cells of this path.
*/

/*

    Approach : using BFS
    Given: grid- a binary matrix of size n x n
    src - source cell
    dest - destination cell


    n= grid.size(); // Get the size of the grid
    m= grid[0].size(); // Get the size of the first row of the grid
    1. Create a queue to perform BFS traversal.
       queue<pair<int,pair<int,int> >> q;// Queue to store pairs of (distance, (row, column))

    2. create a vector of vectors to store distances.
       vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
       
    3. check if the source cell is blocked (i.e., grid[0][0] == 1) or the destination cell is blocked (i.e., grid[n-1][m-1] == 1).
       if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

    4. dist[0][0] = 1; // Initialize the distance of the source cell to 1

       q.push({1, {0, 0}}); // Push the source cell into the queue with distance 1
    
    5. Define the directions for 8-directional movement.
        vector<int>drow={-1,-1,0,1,1,1,0,-1};
        vector<int>dcol={0,1,1,1,0,-1,-1,-1};
    
    6. While the queue is not empty, perform BFS:
       while (!q.empty()) {
          auto it= q.front();
          q.pop();
            int distance = it.first; // Get the current distance
            int row = it.second.first; // Get the current row
            int col = it.second.second; // Get the current column

            for(int i = 0; i < 8; i++) { // Iterate through all 8 directions
                int nrow = row + drow[i]; // Calculate the new row
                int ncol = col + dcol[i]; // Calculate the new column

                // Check if the new cell is within bounds and not blocked
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0) {
                    // If the distance to the new cell can be shortened
                    if (distance + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = distance + 1; // Update the distance
                        q.push({dist[nrow][ncol], {nrow, ncol}}); // Push the new cell into the queue
                    }
                }
            }
       }

       // Return the distance to the destination cell, or -1 if it is unreachable
       return dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1];
    }
};

*/

/*
    time complexity: O(n * m) - Each cell is processed at most once.
    space complexity: O(n * m) - The distance vector and queue can store up to n * m elements.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <utility> // for std::pair
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid,pair<int,int> src, pair<int,int> dst){
    queue<pair<int,pair<int,int>>> q; // Queue to store pairs of (distance, (row, column))
    int n= grid.size(); // Get the size of the grid
    int m= grid[0].size(); // Get the size of the first row of
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX)); // Create a distance vector initialized to INT_MAX
    if(grid[src.first][src.second] == 1 || grid[dst.first][dst.second] == 1) return -1; // If source or destination is blocked
    dist[src.first][src.second] = 1; // Initialize the distance of the source cell to 1
    q.push({1, {src.first, src.second}}); // Push the source cell into the queue with distance 1
    vector<int> drow = {-1, -1, 0, 1, 1, 1, 0, -1}; // Directions for row movement
    vector<int> dcol = {0, 1, 1, 1, 0, -1, -1, -1}; // Directions for column movement
    while(!q.empty()){
        auto it = q.front();// Get the front element of the queue
        q.pop();

        int distance = it.first; // Get the current distance
        int row = it.second.first; // Get the current row
        int col=it.second.second; // Get the current column

        for(int i=0;i<8;i++){
            int nrow= row + drow[i]; // Calculate the new row
            int ncol= col + dcol[i]; // Calculate the new column
            // Check if the new cell is within bounds and not blocked
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                // If the distance to the new cell can be shortened
                if(distance + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = distance + 1; // Update the distance
                    q.push({dist[nrow][ncol], {nrow, ncol}}); // Push the new cell into the queue
                }
            }
        }
    }
    // Return the distance to the destination cell, or -1 if it is unreachable
    return dist[dst.first][dst.second] == INT_MAX ? -1 : dist[dst.first][dst.second];


}

int main(){
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };
    pair<int,int> src = {0, 0}; // Starting cell
    pair<int,int> dst = {2, 2}; // Destination cell
    int result = shortestPathBinaryMatrix(grid, src, dst);
    cout << "Shortest path length: " << result << endl; // Output: Shortest path length: 4
    return 0;
}