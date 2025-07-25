//51. N-Queens 

/*
    Problem Statement:
        The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

        Given an integer n, return all distinct solutions to the n-queens puzzle. 
        You may return the answer in any order.

        Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
        both indicate a queen and an empty space, respectively.

*/

/*
    Approach:
        rules for placing queens:
        1. No two queens can be in the same row.
        2. No two queens can be in the same column.
        3. No two queens can be in the same diagonal.

    we need 3 funtions:
        - isSafe: This function will be used to check if it is safe to place a queen at a given position.
        - solveNQueens: This function will be used to solve the N-Queens problem using backtracking.
        - solveNQueensUtil: This function will be used to generate the board configurations.
    
    solveNQueens :
    // parameters:
        - n: the size of the chessboard.
    Logic:
        1. vector of vector of strings to store the solutions.
        2. vector of strings to store the current board configuration.
        3. take a sting of size n with '.' to represent empty spaces.
        // string s(n, '.');// this will create a string of size n with '.' characters.
        4. for loop to fill the current board configuration with '.'.
        // for(int i=0;i<n;i++) current.push_back(s);// this will fill the current board configuration with '.'.
        if n = 3
        s="..." // this will create a string of size 3 with '.' characters.
        {s, s, s} // this will create a 3x3 chessboard with empty spaces.

        5. call the recursive function to generate the board configurations.
        // solveNQueensUtil(0, n, current, result):
        6. return the solutions.


    solveNQueensUtil :
        // parameters:
        - column: the current column index.
        - n: the size of the chessboard.
        - current: the current board configuration being generated.
        - result: to store the final list of solutions.
    Logic:
        1. if column is equal to n, we have found a valid configuration.
            - push the current board configuration into the result.
            - return. 
        2. iterate through the rows from 0 to n:
            - if it is safe to place a queen at (row, column, current, n):
                - place the queen by setting current[row][column] = 'Q'.
                - recursively call the function with the next column.
                // solveNQueensUtil(column + 1, n, current, result);
                - backtrack by setting current[row][column] = '.'.
        3. return;



    isSafe :    // parameters:
        - row: the current row index.
        - column: the current column index.
        - current: the current board configuration.
        - n: the size of the chessboard.
    Logic:
        take 2 variables to check the diagonals:
        duplicate the row and column indices to check the diagonals.

        while row >= 0 and column >= 0:
            - if current[row][column] is 'Q', it means there is a queen in the upper left diagonal.
            - decrement row and column to check the next diagonal.
        
        col= duplicate column index to check the upper right diagonal.
        row = duplicate row index to check the upper right diagonal.

        while col>0 :
            - if current[row][col] is 'Q', it means there is a queen in the upper right diagonal.
            - decrement decrement col.
        

        col= duplicate column index to check the upper right diagonal.
        row = duplicate row index to check the upper right diagonal.

        while row <n && col >= 0:
            - if current[row][col] is 'Q', it means there is a queen in the lower left diagonal.
            - increment row and decrement col to check the next diagonal.
        
        return true if no queens are found in the same row, column, or diagonal.


        Dry Run:
        n = 4

        initial board configuration:
        {
            "....",
            "....",
            "....",
            "...."
        }
            

*/

/*
    Time Complexity: O(n!), where n is the size of the chessboard. In the worst case, we may explore all possible configurations.
    Space Complexity: O(n^2), where n is the size of the chessboard. The space is used for the recursion stack and to store the board configurations.
*/

#include <iostream>
#include <vector>
using namespace std;

bool issafe(int column, int row, const vector<string>& current,int n){
    int col = column;
    int r = row;

    // Check upper left diagonal
    while(r>=0 && col >=0){
        if(current[r][col]=='Q') return false;
        r--;
        col--;
    }

    col = column;
    r = row;

    // check left diagonal
    while(col>=0){
        if(current[r][col]=='Q') return false;
        col--;
    }

    col = column;
    r = row;
    // check lower left diagonal
    while(r<n && col>=0){
        if(current[r][col]=='Q')
            return false;
        r++;
        col--;
    }

    return true; // No queens found in the same row, column, or diagonal
}



void solveNQueensUtil(int column, int n, vector<string>& current, vector<vector<string>>& result){
    if(column == n){
        result.push_back(current);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(column, row, current, n)){
            current[row][column]= 'Q';
            solveNQueensUtil(column+1,n,current,result);
            current[row][column]= '.'; // backtrack
        }
    }
}

vector<vector<string>> Nqueuens(int n){
    vector<vector<string>> result;
    vector<string> current;
    string s(n,'.');
    for(int i=0;i<n;i++) current.push_back(s);
    solveNQueensUtil(0, n, current, result);
    return result;
}

int main() {
    int n = 4; // Example size of the chessboard
    vector<vector<string>> solutions = Nqueuens(n);
    
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << "------------------" << endl; // Separator between solutions
    }
    
    return 0;
}



