//130. Surrounded Regions

/*
    problem: https://leetcode.com/problems/surrounded-regions/
    Problem Statement:
        You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

        Connect: A cell is connected to adjacent cells horizontally or vertically.
        Region: To form a region connect every 'O' cell.

        Surround: The region is surrounded with 'X' cells if you can connect the region with 'X'
        cells and none of the region cells are on the edge of the board.

        To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/

/*
    we have to use DFS traversal to solve this problem.
    Approach:
    1. the problem requires 2 functions:
        - capture function to capture the surrounded regions.
        - dfs function to traverse the board and mark the cells.

    2. capture function:
        1.take the number of rows and columns from the board.
        int row=board.size(), col=board[0].size();
        2. create a visited vector to keep track of visited cells.
        vector<vector<int>> visited(row, vector<int>(col, 0));
        3. iterate through the first and last row and mark all 'O's as visited.
           for j=0 to col-1:
            if board[0][j]=='O' and visited[0][j]==0:
                dfs(0, j, board, visited);
            if board[row-1][j]=='O' and visited[row-1][j]==0:
                dfs(row-1, j, board, visited);
        4. iterate through the first and last column and mark all 'O's as visited.
           for i=0 to row-1:
            if board[i][0]=='O' and visited[i][0]==0:
                dfs(i, 0, board, visited);
            if board[i][col-1]=='O' and visited[i][col-1]==0:
                dfs(i, col-1, board, visited);
        5. iterate through the board and replace all 'O's with 'X's if they are not visited.
           for i=0 to row-1:
            for j=0 to col-1:
                if board[i][j]=='O' and visited[i][j]==0:
                    board[i][j]='X';
        6. return the modified board.

    3. dfs function:
        1. mark the current node as visited.
        visited[sr][sc]=1;
        2. iterate through the 4 directions using drow and dcol vectors.
           for i=0 to 3:
            int newrow = sr + drow[i];
            int newcol = sc + dcol[i];
            if newrow >= 0 && newrow < row && newcol >= 0 && newcol < col && board[newrow][newcol]=='O' && visited[newrow][newcol]==0:
                dfs(newrow, newcol, board, visited); // recursively call dfs for the adjacent cell
        3. return; // return from the dfs function

*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int sr, int sc, vector<vector<char>>& board, vector<vector<int>>& visited, vector<int>& drow, vector<int>& dcol) {
    visited[sr][sc] = 1;
    for (int i = 0; i < 4; i++) {
        int newrow = sr + drow[i];
        int newcol = sc + dcol[i];
        if (newrow >= 0 && newrow < board.size() && newcol >= 0 && newcol < board[0].size() && 
            board[newrow][newcol] == 'O' && visited[newrow][newcol] == 0) {
            dfs(newrow, newcol, board, visited, drow, dcol);
        }
    }
}

vector<vector<char>> capture(vector<vector<char>>& board) {
    int row = board.size(), col = board[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    for (int j = 0; j < col; j++) {
        if (board[0][j] == 'O' && visited[0][j] == 0)
            dfs(0, j, board, visited, drow, dcol);
        if (board[row - 1][j] == 'O' && visited[row - 1][j] == 0)
            dfs(row - 1, j, board, visited, drow, dcol);
    }

    for (int i = 0; i < row; i++) {
        if (board[i][0] == 'O' && visited[i][0] == 0)
            dfs(i, 0, board, visited, drow, dcol);
        if (board[i][col - 1] == 'O' && visited[i][col - 1] == 0)
            dfs(i, col - 1, board, visited, drow, dcol);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O' && visited[i][j] == 0) {
                board[i][j] = 'X';
            }
        }
    }

    return board;
}
int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<char>> result = capture(board);

    // Output the modified board
    for (const auto& row : result) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}