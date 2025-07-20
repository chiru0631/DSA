//994. Rotting Oranges

/*
    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange.
    If this is impossible, return -1.
*/

/*

    i will use bfs traversal to solve this problem.

    Approach:
    1. get the number of nodes and edges from the grid. row=grid.size(), col=grid[0].size();
    2. create a queue to store row, column and time. queue<pair<pair<int,int>,int>>q;
    3. create a visited vector to keep track of visited nodes. vector<vector<int>> visited(row, vector<int>(col, 0));
    4. itrate through the grid and push all rotten oranges into the queue.
       if grid[i][j]==2, then push {i,j} into the queue and mark it as visited.
       for(i->n){
        for(j->m){
            if(grid[i][j]==2){
               q.push({{i,j},0});
               visited[i][j]=1;
            }
       }
}
    4. create a vector to store the directions for 4-directional movement.
       vector<int> dx={-1,0,1,0}; // up, right, down, left
       vector<int> dy={0,1,0,-1};
    5. create a variable time to keep track of time.
    6.while the queue is not empty {
        pop the front element from the queue.
        int x=q.front().first.first;
        int y=q.front().first.second;
        int t=q.front().second;
        q.pop();
        time=max(time,t); // update time
        // check all 4 directions
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy]==1 && visited[newx][newy]==0){
                q.push({{newx,newy},t+1});
                visited[newx][newy]=1; // mark as visited
                grid[newx][newy]=2; // mark as rotten
            }
        }
    }
    7. after the queue is empty, check if there are any fresh oranges left in the grid.
       if there are any fresh oranges left, return -1.
       for(i->n){
        for(j->m){
            if(grid[i][j]==1) return -1;
        }
    }
    return time;
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    int row=grid.size(),col=grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>> visited(row,vector<int>(col,0));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1; // mark as visited
            }
        }
    }

    vector<int> drow={-1,0,1,0};// directions for up, right, down, left
    vector<int> dcol={0,1,0,-1};// directions for up, right, down, left
    int time =0;
    while(!q.empty()){
        int currow=q.front().first.first;
        int curcol=q.front().first.second;
        int t=q.front().second;
        q.pop();
        time=max(time,t); // update time
        for(int i=0;i<4;i++){
            int newrow=currow+drow[i];
            int newcol=curcol+dcol[i];
            if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]==1 && visited[newrow][newcol]==0){
                q.push({{newrow,newcol},t+1});
                visited[newrow][newcol]=1; // mark as visited
                grid[newrow][newcol]=2; // mark as rotten
            } 
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return time;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int result = orangesRotting(grid);
    cout << "Minimum time until no fresh oranges remain: " << result << endl; // Output: 4
    
    return 0;
}