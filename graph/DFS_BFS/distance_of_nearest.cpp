//542. 01 Matrix

/*
    Problem Statment:
    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
    The distance between two cells sharing a common edge is 1.
*/

/*
    we will use BFS traversal to solve this problem.
    Approach:
        1. take the rows and columns of the matrix.
        create a visited vector to keep track of visited nodes.
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX)); // distance matrix to store the distance of each cell from the nearest 0
        2. create a queue to store the cells with value 0.
        queue<pair<int, int>> q;
        3. iterate through the matrix and push all cells with value 0 into the queue
        for i =0 to row-1:
            for j=0 to col-1:
                if mat[i][j]==0:
                    q.push({i,j});
                    visited[i][j]=1; // mark as visited
                    dist[i][j]=0; // distance from nearest 0 is 0
        create drow and dcol vectors to store the directions for 4-directional movement.
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        4. while the queue is not empty:
            pop the front element from the queue.
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // check all 4 directions
            for i=0 to 3:
                int newx = x + drow[i];
                int newy = y + dcol[i];
                if newx >= 0 && newx < row && newy >= 0 && newy < col && visited[newx][newy] == 0:
                    visited[newx][newy] = 1; // mark as visited
                    dist[newx][newy] = dist[x][y] + 1; // update distance
                    q.push({newx, newy}); // push the cell into the queue
        5. return the distance matrix.


*/

/*
    Time complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix
    Space complexity: O(m * n) for the visited and distance matrices
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearestzero(vector<vector<int>>& mat){
    int row=mat.size();
    int col=mat[0].size();
    vector<vector<int>> visited(row, vector<int>(col,0));
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX)); // distance matrix to store the distance of each cell from the nearest 0
    queue<pair<int,int>>q;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==0){
                visited[i][j]=1;
                dist[i][j]=0; // distance from nearest 0 is 0
                q.push({i,j});
            }
        }
    }
    vector<int> drow={-1,0,1,0}; // directions for up, right, down, left
    vector<int> dcol={0,1,0,-1}; // directions for up, right, down, left
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx=x+drow[i];
            int newy=y+dcol[i];
            if(newx>=0 && newx<row && newy>=0 && newy<col && visited[newx][newy]==0 && dist[newx][newy] > dist[x][y] + 1){
                visited[newx][newy]=1; // mark as visited
                dist[newx][newy]=dist[x][y]+1; // update distance
                q.push({newx,newy}); // push the cell into the queue
            }
        }
    }
    return dist; // return the distance matrix
}

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = nearestzero(mat);
    
    // Output the distance matrix
    for (const auto& row : result) {
        for (int dist : row) {
            cout << dist << " ";
        }
        cout << endl;
    }
    
    return 0;
}